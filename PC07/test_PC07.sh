#!/bin/sh
# Author: Matthew Morrison
# Email : matt.morrison@nd.edu
# Spring 2022 - Data Structures - Programming Challenge 07 - Grading Script
#
# This script will help TAs evaluate the course PQC programming standards

# Variables for the script
SCRIPT_OUT="grade.out"
REDIRECT="redirect.out"

# Point Breakdown Variables
STUDENT_GRADE=0
TOTAL=200
INIT=10
CHECK_O_PTS=25
CHECK_EXE_PTS=25
CHECK_CLEAN=25
PC_07_PQC_TEST=50
COMPILATION_TEST=85


# Delete the script.out so student can test multiple times
# and we can still use >> to append while running a test
if test -f $SCRIPT_OUT; then
    rm $SCRIPT_OUT
fi

# Delete redirect so we start fresh
# Redirect is a temporary file that will contain intermediate outputs 
# These outputs will be used to evaluate the program 
if test -f $REDIRECT; then
    rm $REDIRECT
fi

# Write initial messages to the output file
INTRO_MESSAGE="Grading script for Spring 2022 - Programming Challenge 07"
NAME_MESSAGE="Type in the student's name (or just press Enter):"
ID_MESSAGE="Type in the student's Notre Dame netID name (or just press Enter):"

echo "-----------------------------" >> $SCRIPT_OUT
echo $INTRO_MESSAGE >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT

# Get the student's name and ND netID
echo $NAME_MESSAGE
read STUDENT_NAME
echo $ID_MESSAGE
read STUDENT_ID

# Print the name and ID to the script.out
echo "Student's Name: $STUDENT_NAME" >> $SCRIPT_OUT
echo "Student's ID  : $STUDENT_ID" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT 
echo "These tests evaluate if you met the Production Quality Compilation Standards."  >> $SCRIPT_OUT
echo "To get the best results, run 'make clean' before running this script next time."  >> $SCRIPT_OUT
echo "If you are a student, don't forget to run 'make clean' before you push!"  >> $SCRIPT_OUT


#######################
# Check if there are no .o or executable files 
#######################
echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing for clean pushing to GitHub" >> $SCRIPT_OUT

# Variables 
LIST_OUTPUTS="ls *"


# Test for object files 
CHECK_O_TEST="test -f objects/*.o"

# Test for the executable 
CHECK_EXE="test -f exe/PC07"    

# Next, we check for the object files  
if test -f "objects/PC07.o" || test -f "objects/passcode.o"; then
    echo "One or more object file exist." >> $SCRIPT_OUT
	echo "Executables must be cleaned prior to GitHub push." >> $SCRIPT_OUT
	echo "Automatic 50 point deduction, per project description" >> $SCRIPT_OUT
	echo "0 / $CHECK_O_PTS" >> $SCRIPT_OUT
	echo "Here are the files currently in the project folder." >> $SCRIPT_OUT
	CHECK_O_TEST_RESULT=$( $LIST_OUTPUTS ) 
	echo "$CHECK_O_TEST_RESULT" >> $SCRIPT_OUT

else
	echo "Student successfully pushed to GitHub with no object files" >> $SCRIPT_OUT
	((STUDENT_GRADE += $CHECK_O_PTS))
	echo "$CHECK_O_PTS / $CHECK_O_PTS" >> $SCRIPT_OUT
fi


# Next, we check for the executable 
if test -f "exe/PC07"; then
    echo "PC07 Executable Exists." >> $SCRIPT_OUT
	echo "Executables must be cleaned prior to GitHub push." >> $SCRIPT_OUT
	echo "Automatic 50 point deduction, per project description" >> $SCRIPT_OUT
	echo "0 / $CHECK_EXE_PTS" >> $SCRIPT_OUT
	echo "Here are the files currently in the project folder." >> $SCRIPT_OUT
	CHECK_PC07_TEST_RESULT=$( $LIST_OUTPUTS ) >> $SCRIPT_OUT
	echo "$CHECK_PC07_TEST_RESULT" >> $SCRIPT_OUT

else
	echo "Student successfully pushed to GitHub with no executables" >> $SCRIPT_OUT
	((STUDENT_GRADE += $CHECK_EXE_PTS))
	echo "$CHECK_EXE_PTS / $CHECK_EXE_PTS" >> $SCRIPT_OUT
fi



#######################
# Test the make clean command 
#######################
echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing make clean" >> $SCRIPT_OUT

MAKE_CLEAN_TEST="make clean"

MAKE_CLEAN_TEST_RESULT=$( $MAKE_CLEAN_TEST )

# Send command to redirect 
echo $MAKE_CLEAN_TEST_RESULT >> $REDIRECT

# Will pass if they ran rm
if grep -e "Nothing to be done" $REDIRECT 

then
	
	echo "$MAKE_CLEAN_TEST did not pass" >> $SCRIPT_OUT
	echo "0 / $CHECK_CLEAN" >> $SCRIPT_OUT

else

	echo "Student successfully implement $MAKE_CLEAN_TEST" >> $SCRIPT_OUT
	echo "$CHECK_CLEAN / $CHECK_CLEAN" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $CHECK_CLEAN))

fi



#######################
# Test the make PC07 command 
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing make PC07" >> $SCRIPT_OUT

make clean >> $SCRIPT_OUT

# make decode comparison variables
MAKE_CLEAN_FORCE="rm -rf objects/* exe/*"
MAKE_PC07_TEST="make PC07"
MAKE_GPP="g++"
MAKE_WALL="-Wall"
MAKE_WEXTRA="-Wextra"
MAKE_WCONVERSION="-Wconversion"
MAKE_WERROR="-Werror"
MAKE_STD_CPP11="-std=c++11"
MAKE_PC07_CLEAN_FORCE=$( $MAKE_CLEAN_FORCE )
MAKE_PC07_TEST_RESULT=$( $MAKE_PC07_TEST )

# Delete redirect and send make result to redirect 
echo $MAKE_PC07_CLEAN_FORCE >> $REDIRECT
echo $MAKE_PC07_TEST_RESULT >> $REDIRECT

# Send results to the script
echo "$MAKE_PC07_TEST output  : " >> $SCRIPT_OUT
echo $MAKE_PC07_TEST_RESULT >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
# Add points to overall score or mark as 0 if not for make lucky

# Will pass if their compilation output contains gcc -Wall -Wextra -Wconversion -Werror and -std=c11
if grep -e "$MAKE_GPP" $REDIRECT && grep -e "$MAKE_WEXTRA" $REDIRECT && grep -e "$MAKE_WCONVERSION" $REDIRECT && grep -e "$MAKE_WERROR" $REDIRECT && grep -e "$MAKE_STD_CPP11" $REDIRECT

then 
	echo "$MAKE_PC07_TEST test passed" >> $SCRIPT_OUT
	echo "Student made a good faith attempt to compile with these flags:" >> $SCRIPT_OUT
	echo "$MAKE_GPP $MAKE_WEXTRA $MAKE_WCONVERSION $MAKE_WERROR $MAKE_STD_CPP11" >> $SCRIPT_OUT
	echo "Successful compilation is not required to earn these points" >> $SCRIPT_OUT
	echo "$PC_07_PQC_TEST / $PC_07_PQC_TEST" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $PC_07_PQC_TEST))
	
else
	echo "$MAKE_PC07_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $PC_07_PQC_TEST" >> $SCRIPT_OUT
	echo "To the grading TA - Manually check if the make PC07 does not contain these flags." >> $SCRIPT_OUT
	echo "If it actually works, reward them back the 100 points and delete theese comment." >> $SCRIPT_OUT
	echo "If not, then they violated the PQC rules, and deduct another 300 points." >> $SCRIPT_OUT
	
fi



#######################
# Check if the code successfull compiled 
#######################

# Now the executable SHOULD exist! 
echo "-----------------------------" >> $SCRIPT_OUT
if grep -e "all warnings being treated as errors" $REDIRECT; then

    echo "PC07 did not successfully compile." >> $SCRIPT_OUT
	echo "Executables must be cleaned prior to GitHub push." >> $SCRIPT_OUT
	echo "Automatic 50 point deduction, per project description" >> $SCRIPT_OUT
	echo "0 / $COMPILATION_TEST" >> $SCRIPT_OUT
	echo "Here are the files currently in the project folder." >> $SCRIPT_OUT
	CHECK_O_TEST_RESULT=$( $LIST_OUTPUTS )

else

	echo "PC07 Successfully Compiled!" >> $SCRIPT_OUT
	((STUDENT_GRADE += $COMPILATION_TEST))
	echo "$COMPILATION_TEST / $COMPILATION_TEST" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT

# Delete temporary compilation results
if test -f $REDIRECT; then
    rm $REDIRECT
fi


# Final Grade to both the screen and the script file.
echo "-----------------------------" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
echo "PC07 Standards Grade Portion for $STUDENT_NAME ($STUDENT_ID): $STUDENT_GRADE / $TOTAL " >> $SCRIPT_OUT
echo "PC07 Standards Grade Portion for $STUDENT_NAME ($STUDENT_ID): $STUDENT_GRADE / $TOTAL "
echo "Run 'vim $SCRIPT_OUT' to see the result of the test script"


# Clean so student's don't unintentionally push object files
# That we created. They shouldn't lost points because of us.
make clean > $REDIRECT

# Delete re-directions
rm $REDIRECT
