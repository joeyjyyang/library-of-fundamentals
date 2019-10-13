#include "linked_list.h"

/*	
 * Compile Command: g++ -std=c++11 -I ../include -o main main.cpp linked_list.cpp
 */
 
int main(int argc, char *argv[])
{
	std::cout << "------Test Case #1------" << std::endl;
	{
		data_structure::LinkedList<int> dummy_list1;
	
		dummy_list1.appendNode(3);
		dummy_list1.prependNode(1);
		dummy_list1.insertNode(2, 1);
		dummy_list1.printLinkedList();
		std::cout << "--------------" << std::endl;

		dummy_list1.insertNode(6, 2);
		dummy_list1.appendNode(6);
		dummy_list1.prependNode(6);
		dummy_list1.printLinkedList();

		dummy_list1.removeNode(6);
		dummy_list1.printLinkedList();
		std::cout << "--------------" << std::endl;
		
		dummy_list1.reverseLinkedListRecursive();
		std::cout << "Reversing Linked List." << std::endl;
		dummy_list1.printLinkedList();
		std::cout << "--------------" << std::endl;
		
		dummy_list1.appendNode(2);
		dummy_list1.prependNode(1);
		dummy_list1.insertNode(3, 0);
		std::cout << "--------------" << std::endl;

		dummy_list1.getNodeID(0);
		dummy_list1.getNodeID(1);
		dummy_list1.getNodeID(2);
		dummy_list1.getNodeID(3);
		std::cout << "--------------" << std::endl;
	}
	std::cout << "------Test Case #2------" << std::endl;
	{
		data_structure::LinkedList<char> dummy_list1;
		
		dummy_list1.appendNode('c');
		dummy_list1.appendNode('d');
		dummy_list1.prependNode('a');
		dummy_list1.insertNode('b', 1);
		dummy_list1.reverseLinkedListRecursive();
		std::cout << "Reversing Linked List." << std::endl;
		dummy_list1.printLinkedList();
		std::cout << "--------------" << std::endl;

		data_structure::LinkedList<char> dummy_list3{dummy_list1}; //copy constructor
		dummy_list3.removeNode('c');
		dummy_list3.printLinkedList();
		std::cout << "--------------" << std::endl;

		data_structure::LinkedList<char> dummy_list2;
		dummy_list2 = dummy_list3; //copy assignment operator
		dummy_list2.reverseLinkedListRecursive();
		std::cout << "Reversing Linked List." << std::endl;
		dummy_list2.printLinkedList();
		std::cout << "--------------" << std::endl;
	}

	return 0;
}
