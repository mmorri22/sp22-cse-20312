wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab08/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab08/include/Edge.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab08/include/Graph.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab08/include/Vertex.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab08/src/BFS2.cpp  
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lab08/src/BFS.cpp
cd ..
rm setup.sh