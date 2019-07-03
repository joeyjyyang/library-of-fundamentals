#include "linked_list.h"

/*	
 * Compile Command: g++ -std=c++11 -I ../include -o main main.cpp linked_list.cpp
 */
 
int main(int argc, char* argv[])
{
/*
	data_structure::LinkedList<char> linked_list;
	
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
*/
	data_structure::LinkedList<char> linked_list;
	
	linked_list.appendNode('c');
	linked_list.appendNode('d');
	linked_list.printLinkedList();
	std::cout << "--------------" << std::endl;

	linked_list.prependNode('a');
	linked_list.printLinkedList();
	std::cout << "--------------" << std::endl;

	linked_list.insertNode('b', 1);
	linked_list.printLinkedList();
	std::cout << "--------------" << std::endl;

	linked_list.insertNode('f', 2);
	linked_list.printLinkedList();
	std::cout << "--------------" << std::endl;

	linked_list.removeNode('f');
	linked_list.printLinkedList();
	std::cout << "--------------" << std::endl;

	linked_list.reverseLinkedList();
	std::cout << "Reversing Linked List." << std::endl;
	linked_list.printLinkedList();
	std::cout << "--------------" << std::endl;

	linked_list.getNodeID(0);
	linked_list.getNodeID(1);
	linked_list.getNodeID(2);
	linked_list.getNodeID(3);
	linked_list.getNodeID(4);
	std::cout << "--------------" << std::endl;

	data_structure::LinkedList<char> test(linked_list);
	test.printLinkedList();
		
	test = linked_list;
	test.printLinkedList();

	return 0;
}
