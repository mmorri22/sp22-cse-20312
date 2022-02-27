#!/bin/sh
# Test file for PC05
#
# This test script will download every provided input/output puzzle for PC05. 
# Then it will run PC05 and compare generated output files to downloaded 
# files to check if PC05 produces the expected output. 

# Create folders for input/output files 
mkdir -p wrk
mkdir -p ref
# wrk will contain the generated output files from user's PC05
# ref will contain the input files and the corresponding output files from github

# Declare variables
WORTH=10
POINTS=0
SECONDS=0

echo "Downloading test inputs and outputs ..."

# Download every puzzle input and it's corresponding output file
# 	Files will be saved in ref subfolder
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle0.txt -q -O ./ref/puzzle0.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle1.txt -q -O ./ref/puzzle1.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle2.txt -q -O ./ref/puzzle2.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle3.txt -q -O ./ref/puzzle3.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle4.txt -q -O ./ref/puzzle4.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle5.txt -q -O ./ref/puzzle5.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle6.txt -q -O ./ref/puzzle6.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle7.txt -q -O ./ref/puzzle7.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle8.txt -q -O ./ref/puzzle8.txt > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle0.out -q -O ./ref/puzzle0.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle1.out -q -O ./ref/puzzle1.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle2.out -q -O ./ref/puzzle2.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle3.out -q -O ./ref/puzzle3.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle4.out -q -O ./ref/puzzle4.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle5.out -q -O ./ref/puzzle5.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle6.out -q -O ./ref/puzzle6.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle7.out -q -O ./ref/puzzle7.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle8.out -q -O ./ref/puzzle8.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle_bad.out -q -O ./ref/puzzle_bad.out > /dev/null
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC05/puzzle_bad.txt -q -O ./ref/puzzle_bad.txt > /dev/null

echo "Download completed"

# Compile PC05
echo "Testing ..."
make clean > /dev/null
make PC05 > /dev/null

# For each test, run PC05 with the puzzleX.txt input files and 
# have each output file in the wrk sufolder. If the generated
# .out files are equivalent, delete the files for that test. 
#
# test 0
printf "   %-5s ... " "Sample 0, 1 point"
exe/./PC05 ref/puzzle0.txt wrk/puzzle0.out > /dev/null
diff ref/puzzle0.out wrk/puzzle0.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle0.out wrk/puzzle0.out ref/puzzle0.txt
fi

# test 1
printf "   %-5s ... " "Sample 1, 1 point"
exe/./PC05 ref/puzzle1.txt wrk/puzzle1.out > /dev/null
diff ref/puzzle1.out wrk/puzzle1.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle1.out wrk/puzzle1.out ref/puzzle1.txt
fi

# test 2
printf "   %-5s ... " "Sample 2, 1 point"
exe/./PC05 ref/puzzle2.txt wrk/puzzle2.out > /dev/null
diff ref/puzzle2.out wrk/puzzle2.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle2.out wrk/puzzle2.out ref/puzzle2.txt
fi

# test 3
printf "   %-5s ... " "Sample 3, 1 point"
exe/./PC05 ref/puzzle3.txt wrk/puzzle3.out > /dev/null
diff ref/puzzle3.out wrk/puzzle3.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle3.out wrk/puzzle3.out ref/puzzle3.txt
fi

# test 4
printf "   %-5s ... " "Sample 4, 1 point"
exe/./PC05 ref/puzzle4.txt wrk/puzzle4.out > /dev/null
diff ref/puzzle4.out wrk/puzzle4.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle4.out wrk/puzzle4.out ref/puzzle4.txt
fi

# test 5
printf "   %-5s ... " "Sample 5, 1 point"
exe/./PC05 ref/puzzle5.txt wrk/puzzle5.out > /dev/null
diff ref/puzzle5.out wrk/puzzle5.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle5.out wrk/puzzle5.out ref/puzzle5.txt
fi

# test 6
printf "   %-5s ... " "Sample 6, 1 point"
exe/./PC05 ref/puzzle6.txt wrk/puzzle6.out > /dev/null
diff ref/puzzle6.out wrk/puzzle6.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle6.out wrk/puzzle6.out ref/puzzle6.txt
fi

# test 7
printf "   %-5s ... " "Sample 7, 1 point"
exe/./PC05 ref/puzzle7.txt wrk/puzzle7.out > /dev/null
diff ref/puzzle7.out wrk/puzzle7.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle7.out wrk/puzzle7.out ref/puzzle7.txt
fi

# test 8
printf "   %-5s ... " "Sample 8, 1 point"
exe/./PC05 ref/puzzle8.txt wrk/puzzle8.out > /dev/null
diff ref/puzzle8.out wrk/puzzle8.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle8.out wrk/puzzle8.out ref/puzzle8.txt
fi

# test bad
printf "   %-s ... " "Sample 9, 1 point"
exe/./PC05 ref/puzzle_bad.txt wrk/puzzle_bad.out > /dev/null
diff ref/puzzle_bad.out wrk/puzzle_bad.out
if [ $? -ne 0 ]; then
	echo "Failure"
else
	echo "Success"
	let POINTS=$POINTS+1
	rm -rf ref/puzzle_bad.out wrk/puzzle_bad.out ref/puzzle_bad.txt
fi

# Print time it took to complete
echo "Time: $SECONDS seconds"

# Print the score of PC05 out of total tests
echo "Score: $POINTS / $WORTH"

# delete folders if empty
if [ ! "$(ls -A wrk)" ]; then
	rm -r wrk
fi

if [ ! "$(ls -A ref)" ]; then
	rm -r ref
fi
