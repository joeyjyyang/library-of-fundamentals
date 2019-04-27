/*
	File: linked_list.h

	Description: linked list header file; contains function declarations.

	Author: Joey Yang
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <sstream>

class LinkedList 
{
public:
	//constructor
	LinkedList();

	/* rule of 3 */
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();

	/* class methods */
	bool isEmpty() const;
	int getSize() const;
	void appendNode(const int id);
	void prependNode(const int id);
	void insertNode(const int id, int position);
	void removeNode(const int id);
	void printLinkedList() const;
	void loadNodes(std::ifstream& nodes_infile);
	//recursively reverse the Linked List
	void reverseLinkedList();
	void mergeSortLinkedList();

private:
	struct Node
	{
		const int id_;
		Node* next_;
		Node() : 
			id_(0), next_(nullptr) 
		{
		}
		Node(const int id) : 
			id_(id), next_(nullptr) 
		{
		}
	};

	Node* head_;
	Node* tail_;
};

#endif // LINKED_LIST_H
