wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec19_InClass/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec19_InClass/include/3Sums.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/Edge.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/Graph.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/Vertex.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/MSTElem.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec19_InClass/src/3Sum.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec19_InClass/src/containsDup.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec19_InClass/src/TwoSums.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/src/Dijkstra.cpp
cd ..
rm setup.sh