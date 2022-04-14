wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/include/Treap.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/include/TreapNode.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/include/Treap_sol.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/src/InsertRandom2.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/src/InsertRandom.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/src/TreapInsert.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec26_InClass/src/TreapTest.cpp
cd ..
rm setup.sh