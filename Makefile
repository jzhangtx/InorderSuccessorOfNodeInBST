SuccessorOfNodeInBST: SuccessorOfNodeInBST.o
	g++ -g -o SuccessorOfNodeInBST.exe SuccessorOfNodeInBST.o -pthread    

SuccessorOfNodeInBST.o: SuccessorOfNodeInBST/SuccessorOfNodeInBST.cpp
	g++ -g  -c -pthread SuccessorOfNodeInBST/SuccessorOfNodeInBST.cpp
