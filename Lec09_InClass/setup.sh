wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec09_InClass/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec09_InClass/include/bst.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec09_InClass/include/bst_sol.h
cd ..
cd src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec09_InClass/src/Lec09.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec09_InClass/src/Lec09_sol.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec09_InClass/src/bst.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec09_InClass/src/bst_sol.c
cd ..
rm setup.sh