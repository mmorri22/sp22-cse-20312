# Clean previously existing folders with tests
rm -rf tests solutions outputs

# Variables for the script
SCRIPT_OUT="test_points.out"
REDIRECT="redirect.out"

# Point Breakdown Variables
STUDENT_GRADE=0
TOTAL=300
TEST_1_5_PTS=20
TEST_1_10_PTS=20
TEST_1_100_PTS=20
TEST_1_500_PTS=20
TEST_2_500_PTS=20
TEST_3_200_PTS=20
TEST_3_500_PTS=20
TEST_4_100_PTS=20
TEST_4_200_PTS=20
TEST_5_100_PTS=20
TEST_5_200_PTS=20
TEST_5_500_PTS=20
TEST_6_100_PTS=20
TEST_6_200_PTS=20
TEST_6_500_PTS=20


# Write initial messages to the output file
INTRO_MESSAGE="Testing script for Spring 2022 - Programming Challenge 02"
NAME_MESSAGE="Type in the student's name (or just press Enter):"
ID_MESSAGE="Type in the student's Notre Dame netID name (or just press Enter):"


# Get the student's name and ND netID
echo $NAME_MESSAGE
read STUDENT_NAME
echo $ID_MESSAGE
read STUDENT_ID

# Clean and print to the file
rm $SCRIPT_OUT
rm $REDIRECT

echo "-----------------------------" >> $SCRIPT_OUT
echo $INTRO_MESSAGE >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT

# Print the name and ID to the script.out
echo "Student's Name: $STUDENT_NAME" >> $SCRIPT_OUT
echo "Student's ID  : $STUDENT_ID" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT 

# Setup files and folder v
rm -rf tests solutions outputs
mkdir tests
mkdir solutions
mkdir outputs

# Download script tests
cd tests
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test1.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test2.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test3.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test4.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test5.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test6.txt
cd ../solutions
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test1_5gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test1_10gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test1_100gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test1_500gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test2_500gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test3_200gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test3_500gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test4_100gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test4_200gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test5_100gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test5_200gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test5_500gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test6_100gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test6_200gen.out
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC02/test6_500gen.out
cd ..
make PC02
exe/./PC02 tests/test1.txt 5 outputs/test1_5gen.out
exe/./PC02 tests/test1.txt 10 outputs/test1_10gen.out
exe/./PC02 tests/test1.txt 100 outputs/test1_100gen.out
exe/./PC02 tests/test1.txt 500 outputs/test1_500gen.out
exe/./PC02 tests/test2.txt 500 outputs/test2_500gen.out
exe/./PC02 tests/test3.txt 200 outputs/test3_200gen.out
exe/./PC02 tests/test3.txt 500 outputs/test3_500gen.out
exe/./PC02 tests/test4.txt 100 outputs/test4_100gen.out
exe/./PC02 tests/test4.txt 200 outputs/test4_200gen.out
exe/./PC02 tests/test5.txt 100 outputs/test5_100gen.out
exe/./PC02 tests/test5.txt 200 outputs/test5_200gen.out
exe/./PC02 tests/test5.txt 200 outputs/test5_500gen.out
exe/./PC02 tests/test6.txt 100 outputs/test6_100gen.out
exe/./PC02 tests/test6.txt 200 outputs/test6_200gen.out
exe/./PC02 tests/test6.txt 200 outputs/test6_500gen.out

# Test the script 
if diff -s "solutions/test1_5gen.out" "outputs/test1_5gen.out">/dev/null; then
	echo "Success! Identical to the test1_5gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_1_5_PTS / $TEST_1_5_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_1_5_PTS))
	
elif diff -q "solutions/test1_5gen.out" "outputs/test1_5gen.out"; then
	echo "Differences found between test1_5gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_1_5_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test1_10gen.out" "outputs/test1_10gen.out">/dev/null; then
	echo "Success! Identical to the test1_10gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_1_10_PTS / $TEST_1_10_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_1_10_PTS))
	
elif diff -q "solutions/test1_10gen.out" "outputs/test1_10gen.out"; then
	echo "Differences found between test1_10gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_1_10_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test1_100gen.out" "outputs/test1_100gen.out">/dev/null; then
	echo "Success! Identical to the test1_100gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_1_100_PTS / $TEST_1_100_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_1_100_PTS))
	
elif diff -q "solutions/test100_5gen.out" "outputs/test100_5gen.out"; then
	echo "Differences found between test1_100gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_1_100_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test1_500gen.out" "outputs/test1_500gen.out">/dev/null; then
	echo "Success! Identical to the test1_500gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_1_500_PTS / $TEST_1_500_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_1_500_PTS))
	
elif diff -q "solutions/test1_500gen.out" "outputs/test1_500gen.out"; then
	echo "Differences found between test1_500gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_1_100_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test2_500gen.out" "outputs/test2_500gen.out">/dev/null; then
	echo "Success! Identical to the test2_500gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_2_500_PTS / $TEST_2_500_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_1_500_PTS))
	
else 
	echo "Differences found between test2_500gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_2_500_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test3_200gen.out" "outputs/test3_200gen.out">/dev/null; then
	echo "Success! Identical to the test3_200gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_3_200_PTS / $TEST_3_200_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_3_200_PTS))
	
else 
	echo "Differences found between test3_200gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_3_200_PTS" >> $SCRIPT_OUT
fi

# Test the script 
if diff -s "solutions/test3_500gen.out" "outputs/test3_500gen.out">/dev/null; then
	echo "Success! Identical to the test3_500gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_3_500_PTS / $TEST_3_500_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_3_500_PTS))
	
elif diff -q "solutions/test3_500gen.out" "outputs/test3_500gen.out"; then
	echo "Differences found between test3_500gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_3_500_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test4_100gen.out" "outputs/test4_100gen.out">/dev/null; then
	echo "Success! Identical to the test4_100gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_4_100_PTS / $TEST_4_100_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_4_100_PTS))
	
elif diff -q "solutions/test4_100gen.out" "outputs/test4_100gen.out"; then
	echo "Differences found between test4_100gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_4_100_PTS" >> $SCRIPT_OUT
fi

# Test the script 
if diff -s "solutions/test4_200gen.out" "outputs/test4_200gen.out">/dev/null; then
	echo "Success! Identical to the test4_200gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_4_200_PTS / $TEST_4_200_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_4_200_PTS))
	
elif diff -q "solutions/test4_200gen.out" "outputs/test4_200gen.out"; then
	echo "Differences found between test4_200gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_4_200_PTS" >> $SCRIPT_OUT
fi



# Test the script 
if diff -s "solutions/test5_100gen.out" "outputs/test5_100gen.out">/dev/null; then
	echo "Success! Identical to the test5_100gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_5_100_PTS / $TEST_5_100_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_5_100_PTS))
	
elif diff -q "solutions/test5_100gen.out" "outputs/test5_100gen.out"; then
	echo "Differences found between test5_100gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_5_100_PTS" >> $SCRIPT_OUT
fi

# Test the script 
if diff -s "solutions/test5_200gen.out" "outputs/test5_200gen.out">/dev/null; then
	echo "Success! Identical to the test5_200gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_5_200_PTS / $TEST_5_200_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_5_200_PTS))
	
elif diff -q "solutions/test5_200gen.out" "outputs/test5_200gen.out"; then
	echo "Differences found between test5_200gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_5_200_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test5_500gen.out" "outputs/test5_500gen.out">/dev/null; then
	echo "Success! Identical to the test5_500gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_5_500_PTS / $TEST_5_500_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_5_500_PTS))
	
elif diff -q "solutions/test5_500gen.out" "outputs/test5_500gen.out"; then
	echo "Differences found between test5_200gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_5_500_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test6_100gen.out" "outputs/test6_100gen.out">/dev/null; then
	echo "Success! Identical to the test6_100gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_6_100_PTS / $TEST_6_100_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_6_100_PTS))
	
elif diff -q "solutions/test6_100gen.out" "outputs/test6_100gen.out"; then
	echo "Differences found between test6_100gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_6_100_PTS" >> $SCRIPT_OUT
fi

# Test the script 
if diff -s "solutions/test6_200gen.out" "outputs/test6_200gen.out">/dev/null; then
	echo "Success! Identical to the test6_200gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_6_200_PTS / $TEST_6_200_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_6_200_PTS))
	
elif diff -q "solutions/test6_200gen.out" "outputs/test6_200gen.out"; then
	echo "Differences found between test6_200gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_6_200_PTS" >> $SCRIPT_OUT
fi


# Test the script 
if diff -s "solutions/test6_500gen.out" "outputs/test6_500gen.out">/dev/null; then
	echo "Success! Identical to the test6_500gen.out solution" >> $SCRIPT_OUT
	echo "$TEST_6_500_PTS / $TEST_6_500_PTS" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $TEST_6_500_PTS))
	
else 
	echo "Differences found between test6_500gen.out and the soluction" >> $SCRIPT_OUT
	echo "0 / $TEST_6_500_PTS" >> $SCRIPT_OUT
fi


# Final Grade to both the screen and the script file.
echo "-----------------------------" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
echo "PC02 Testing Grade Portion for $STUDENT_NAME ($STUDENT_ID): $STUDENT_GRADE / $TOTAL " >> $SCRIPT_OUT
echo "PC02 Testing Grade Portion for $STUDENT_NAME ($STUDENT_ID): $STUDENT_GRADE / $TOTAL "
echo "Run 'vim $SCRIPT_OUT' to see the result of the test script"


# Clean so student's don't unintentionally push object files
# That we created. They shouldn't lost points because of us.
make clean > $REDIRECT

# Delete re-directions
rm $REDIRECT