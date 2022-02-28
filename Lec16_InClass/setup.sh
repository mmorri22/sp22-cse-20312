wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec16_InClass/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec16_InClass/include/max_heap.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec16_InClass/include/min_heap.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec16_InClass/src/FindKthLargest.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec16_InClass/src/FindKthLargest_sol.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec16_InClass/src/FindMedian.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec16_InClass/src/FindMedian_sol.cpp
cd ..
rm setup.sh