wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec27_InClass/Makefile
make initialize
mkdir include src
cd src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec27_InClass/src/pthread_1.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec27_InClass/src/pthread_2.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec27_InClass/src/pthread_3.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec27_InClass/src/pthread_in_class.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec27_InClass/src/pthread_in_class_sol.c
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec27_InClass/src/pthread_in_class_rc.c
cd ..
rm setup.sh