wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec17_InClass/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec17_InClass/include/Edge.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec17_InClass/include/Graph.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec17_InClass/include/Graph_sol.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec17_InClass/include/Vertex.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec17_InClass/src/DFS2.cpp  
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec17_InClass/src/DFS.cpp
cd ..
rm setup.sh