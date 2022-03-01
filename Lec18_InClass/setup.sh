wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/Makefile
make initialize
mkdir include src
cd include
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/Edge.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/Graph.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/Graph_sol.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/Vertex.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/MSTElem.h
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/include/MSTElem_sol.h
cd ../src
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/src/MST3.cpp
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/src/MST2.cpp  
wget https://raw.githubusercontent.com/mmorri22/sp22-cse-20312/main/Lec_18InClass/src/MST.cpp
cd ..
rm setup.sh