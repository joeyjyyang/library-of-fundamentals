#include "linked_list.h"

/*	
	Compile Command: g++ -std=c++11 -I ../include -o main main.cpp linked_list.cpp
*/
 
int main(int argc, char* argv[])
{
	LinkedList linked_list;
	linked_list.appendNode(1);
	std::cout << "Program end" << std::endl;	

	return 0;
}
