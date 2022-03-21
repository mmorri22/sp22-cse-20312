#!/bin/sh
# Test file for PC05
#
# This test script will download every provided input/output puzzle for PC05. 
# Then it will run PC05 and compare generated output files to downloaded 
# files to check if PC05 produces the expected output. 


# Variables for the script
SCRIPT_OUT="puzzle_test.out"

# Create folders for input/output files 
mkdir -p wrk
mkdir -p ref
# wrk will contain the generated output files from user's PC05
# ref will contain the input files and the corresponding output files from github

# Declare variables
WORTH=300
POINTS=0
SECONDS=0

rm $SCRIPT_OUT
echo "Downloading test inputs and outputs ..."

# Download every puzzle input and it's corresponding output file
# 	Files will be saved in ref subfolder
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle0.txt -q -O ./ref/puzzle0.txt 
echo "puzzle0.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle1.txt -q -O ./ref/puzzle1.txt
echo "puzzle1.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle2.txt -q -O ./ref/puzzle2.txt
echo "puzzle2.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle3.txt -q -O ./ref/puzzle3.txt
echo "puzzle3.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle4.txt -q -O ./ref/puzzle4.txt 
echo "puzzle4.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle5.txt -q -O ./ref/puzzle5.txt 
echo "puzzle5.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle6.txt -q -O ./ref/puzzle6.txt 
echo "puzzle6.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle7.txt -q -O ./ref/puzzle7.txt 
echo "puzzle7.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle8.txt -q -O ./ref/puzzle8.txt 
echo "puzzle8.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle_bad.txt -q -O ./ref/puzzle_bad.txt
echo "puzzle_bad.txt downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle0.out -q -O ./ref/puzzle0.out > /dev/null
echo "puzzle0.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle1.out -q -O ./ref/puzzle1.out > /dev/null
echo "puzzle1.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle2.out -q -O ./ref/puzzle2.out > /dev/null
echo "puzzle2.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle3.out -q -O ./ref/puzzle3.out > /dev/null
echo "puzzle3.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle4.out -q -O ./ref/puzzle4.out > /dev/null
echo "puzzle4.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle5.out -q -O ./ref/puzzle5.out > /dev/null
echo "puzzle5.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle6.out -q -O ./ref/puzzle6.out > /dev/null
echo "puzzle6.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle7.out -q -O ./ref/puzzle7.out > /dev/null
echo "puzzle7.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle8.out -q -O ./ref/puzzle8.out > /dev/null
echo "puzzle8.out downloaded"
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle_bad.out -q -O ./ref/puzzle_bad.out > /dev/null
echo "puzzle_bad.out downloaded"

echo "Download completed"

# Compile PC05
echo "Testing ..." >> $SCRIPT_OUT 
make clean > /dev/null
make PC05 > /dev/null

# For each test, run PC05 with the puzzleX.txt input files and 
# have each output file in the wrk sufolder. If the generated
# .out files are equivalent, delete the files for that test. 
#
# test 0
echo "Running test input for " "puzzle_0.txt: "
echo "Running test input for " "puzzle_0.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle0.txt wrk/puzzle0.out >> $SCRIPT_OUT
diff ref/puzzle0.out wrk/puzzle0.out
if [ $? -ne 0 ]; then
	echo "puzzle0.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle0.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle0.out wrk/puzzle0.out ref/puzzle0.txt
fi

# test 1
echo "Running test input for " "puzzle_1.txt: "
echo "Running test input for " "puzzle_1.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle1.txt wrk/puzzle1.out >> $SCRIPT_OUT
diff ref/puzzle1.out wrk/puzzle1.out
if [ $? -ne 0 ]; then
	echo "puzzle1.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle1.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle1.out wrk/puzzle1.out ref/puzzle1.txt
fi

# test 2
echo "Running test input for " "puzzle_2.txt: "
echo "Running test input for " "puzzle_2.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle2.txt wrk/puzzle2.out >> $SCRIPT_OUT
diff ref/puzzle2.out wrk/puzzle2.out
if [ $? -ne 0 ]; then
	echo "puzzle2.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle2.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle2.out wrk/puzzle2.out ref/puzzle2.txt
fi

# test 3
echo "Running test input for " "puzzle_3.txt: "
echo "Running test input for " "puzzle_3.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle3.txt wrk/puzzle3.out >> $SCRIPT_OUT
diff ref/puzzle3.out wrk/puzzle3.out
if [ $? -ne 0 ]; then
	echo "puzzle3.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle3.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle3.out wrk/puzzle3.out ref/puzzle3.txt
fi

# test 4
echo "Running test input for " "puzzle_4.txt: "
echo "Running test input for " "puzzle_4.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle4.txt wrk/puzzle4.out >> $SCRIPT_OUT
diff ref/puzzle4.out wrk/puzzle4.out
if [ $? -ne 0 ]; then
	echo "puzzle4.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle4.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle4.out wrk/puzzle4.out ref/puzzle4.txt
fi

# test 5
echo "Running test input for " "puzzle_5.txt: "
echo "Running test input for " "puzzle_5.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle5.txt wrk/puzzle5.out >> $SCRIPT_OUT
diff ref/puzzle5.out wrk/puzzle5.out
if [ $? -ne 0 ]; then
	echo "puzzle5.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle5.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle5.out wrk/puzzle5.out ref/puzzle5.txt
fi

# test 6
echo "Running test input for " "puzzle_6.txt: "
echo "Running test input for " "puzzle_6.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle6.txt wrk/puzzle6.out >> $SCRIPT_OUT
diff ref/puzzle6.out wrk/puzzle6.out
if [ $? -ne 0 ]; then
	echo "puzzle6.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle6.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle6.out wrk/puzzle6.out ref/puzzle6.txt
fi

# test 7
echo "Running test input for " "puzzle_7.txt: "
echo "Running test input for " "puzzle_7.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle7.txt wrk/puzzle7.out >> $SCRIPT_OUT
diff ref/puzzle7.out wrk/puzzle7.out
if [ $? -ne 0 ]; then
	echo "puzzle7.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle7.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle7.out wrk/puzzle7.out ref/puzzle7.txt
fi

# test 8
echo "Running test input for " "puzzle_8.txt: "
echo "Running test input for " "puzzle_8.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle8.txt wrk/puzzle8.out >> $SCRIPT_OUT
diff ref/puzzle8.out wrk/puzzle8.out
if [ $? -ne 0 ]; then
	echo "puzzle8.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle8.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle8.out wrk/puzzle8.out ref/puzzle8.txt
fi

# test bad
echo "Running test input for " "puzzle_bad.txt: "
echo "Running test input for " "puzzle_bad.txt: " >> $SCRIPT_OUT 
exe/./PC05 ref/puzzle_bad.txt wrk/puzzle_bad.out >> $SCRIPT_OUT
diff ref/puzzle_bad.out wrk/puzzle_bad.out
if [ $? -ne 0 ]; then
	echo "puzzle_bad.txt Failure: 0/30" >> $SCRIPT_OUT 
else
	echo "puzzle_bad.txt Success: 30/30" >> $SCRIPT_OUT 
	let POINTS=$POINTS+30
	rm -rf ref/puzzle_bad.out wrk/puzzle_bad.out ref/puzzle_bad.txt
fi


# Print the score of PC05 out of total tests
echo "Score: $POINTS / $WORTH" >> $SCRIPT_OUT 

echo "Score: $POINTS / $WORTH"
echo "View $SCRIPT_OUT for student test details"

# delete folders if empty
if [ ! "$(ls -A wrk)" ]; then
	rm -r wrk
fi

if [ ! "$(ls -A ref)" ]; then
	rm -r ref
fi
