#include "linked_list.h"

/*	
	Compile Command: g++ -std=c++11 -I ../include -o main main.cpp linked_list.cpp
*/
 
int main(int argc, char* argv[])
{
	LinkedList linked_list;

	linked_list.appendNode(3);
	linked_list.appendNode(4);
	linked_list.printLinkedList();

	linked_list.prependNode(1);
	linked_list.printLinkedList();

	linked_list.insertNode(2, 1);
	linked_list.printLinkedList();

	linked_list.insertNode(6, 2);
	linked_list.printLinkedList();

	linked_list.removeNode(6);
	linked_list.printLinkedList();

	linked_list.reverseLinkedList();
	std::cout << "Reversing Linked List." << std::endl;
	linked_list.printLinkedList();

	return 0;
}
