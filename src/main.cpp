#include "linked_list.h"

/*	
	Compile Instructions: g++ -std=c++11 -o main ../include/ main.cpp
*/
 
int main(int argc, char* argv[])
{
	LinkedList linked_list;
	linked_list.appendNode(1);
	std::cout << "Program end." << std::endl;	

	return 0;
}
