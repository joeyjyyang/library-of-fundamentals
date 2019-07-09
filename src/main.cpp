#include "linked_list.h"

/*	
 * Compile Command: g++ -std=c++11 -I ../include -o main main.cpp linked_list.cpp
 */
 
int main(int argc, char *argv[])
{
	std::cout << "------Test Case #1------" << std::endl;
	{
		data_structure::LinkedList<int> linked_list;
	
		linked_list.appendNode(3);
		linked_list.appendNode(4);
		linked_list.printLinkedList();
		std::cout << "--------------" << std::endl;

		linked_list.prependNode(1);
		linked_list.printLinkedList();
		std::cout << "--------------" << std::endl;

		linked_list.insertNode(2, 1);
		linked_list.printLinkedList();
		std::cout << "--------------" << std::endl;

		linked_list.insertNode(6, 2);
		linked_list.printLinkedList();

		linked_list.removeNode(6);
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
	}
	std::cout << "------Test Case #2------" << std::endl;
	{
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

		data_structure::LinkedList<char> dummy_list1(linked_list);
		dummy_list1.removeNode('c');
		dummy_list1.printLinkedList();
		std::cout << "--------------" << std::endl;

		data_structure::LinkedList<char> dummy_list2;
		dummy_list2 = dummy_list2;
		dummy_list2.reverseLinkedList();
		std::cout << "Reversing Linked List." << std::endl;
		dummy_list2.printLinkedList();
		std::cout << "--------------" << std::endl;
	}

	return 0;
}
