wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/Makefile
make initialize
mkdir include src 
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/include/Shape.h 
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/include/Rectangle.h   
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/include/Triangle.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/src/Shape.cpp 
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/src/Rectangle.cpp   
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/src/Triangle.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab11/src/Lab11.cpp
cd ..
rm setup.sh