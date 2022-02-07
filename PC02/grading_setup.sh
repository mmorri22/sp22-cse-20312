# Variables for the script
SCRIPT_OUT="test_points.out"
REDIRECT="redirect.out"

# Point Breakdown Variables
STUDENT_GRADE=0
TOTAL=300

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
