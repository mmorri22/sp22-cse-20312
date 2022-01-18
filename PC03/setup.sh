wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC04/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC04/include/bst.h
cd ..
cd src
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC04/src/PC04.c
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC04/src/bst.c
cd ..
rm setup.sh