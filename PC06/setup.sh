wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/Makefile
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/PC06_sample_run_1.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/PC06_sample_run_2.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/PC06_sample_run_3.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/test_PC06.sh
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/include/dllist.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/include/lru_cache.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/src/PC06.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC06/src/lru_cache.cpp
cd ..
rm setup.sh
