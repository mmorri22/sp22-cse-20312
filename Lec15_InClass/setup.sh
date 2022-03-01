wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/include/3Sums.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/src/3Sum.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/src/containsDup.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/src/TwoSums.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/src/fibMemo.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/src/countSort.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec15_InClass/src/bucketSort.cpp
cd ..
rm setup.sh