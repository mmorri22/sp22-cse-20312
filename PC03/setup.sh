wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC03/Makefile
make initialize
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC03/PC03_sample_run.txt
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC03/test_PC03.sh
chmod a+rx test_PC03.sh
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC03/include/fenwick.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC03/src/PC03.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/PC03/src/fenwick.c
cd ..
rm setup.sh