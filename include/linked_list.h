/*
 *	File: linked_list.h
 *
 *	Description: linked list header file; contains function declarations.
 *
 *	Author: Joey Yang
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

//forward declaration 
namespace data_structure
{
	template <class T>
	class LinkedList;
}

template <class U>
void swapContents(data_structure::LinkedList<U> &linked_list1, data_structure::LinkedList<U> &linked_list2);

namespace data_structure
{
template <class T>
class LinkedList 
{
public:
	//ctor
	LinkedList();

	//rule of 3
	
	//copy ctor
	LinkedList(const LinkedList<T> &other);
	//copy assignment operator
	LinkedList<T>& operator=(LinkedList<T> other);
	//dtor
	~LinkedList();
	
	//friend swap function
	template <class U>
	friend void ::swapContents(LinkedList<U> &linked_list1, LinkedList<U> &linked_list2);
	
	//class methods
	
	bool isEmpty() const;
	int getSize() const;
	T getNodeID(const int position) const;
	void appendNode(const T &id);
	void prependNode(const T &id);
	void insertNode(const T &id, const int position);
	void removeNode(const T &id);
	void printLinkedList() const;
	//void loadNodes(std::ifstream &nodes_infile);
	//recursively reverse the Linked List
	void reverseLinkedList();
	//void mergeSortLinkedList();

private:
	struct Node
	{
		const T id_;
		Node *next_;
		
		Node() : 
			id_(0),
			next_(nullptr) 
		{
		}

		Node(const T id) : 
			id_(id), 
			next_(nullptr) 
		{
		}
	};

	Node *head_;
	Node *tail_;
};
}

#endif // LINKED_LIST_H
