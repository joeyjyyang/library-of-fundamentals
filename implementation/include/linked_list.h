/*
 *	Author: Joey Yang
 *	Email: joeyyang.ai@gmail.com
 *	Description: linked list header file; contains function declarations.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

//forward declaration 
template <class T>
class LinkedList;

template <class U>
void swapContents(LinkedList<U>& linked_list1, LinkedList<U>& linked_list2);

template <class T>
class LinkedList 
{
public:
	//type alias for consistency
	using NodeId = const T;

	//ctor
	LinkedList();

	/*rule of 3*/
	//copy ctor
	LinkedList(const LinkedList<T>& other);
	//copy assignment operator
	LinkedList<T>& operator=(LinkedList<T> other);
	//dtor
	~LinkedList();

	//friend swap function
	template <class U>
	friend void ::swapContents(LinkedList<U>& linked_list1, LinkedList<U>& linked_list2);

	/*class methods*/
	bool isEmpty() const;
	bool findNode(NodeId id) const;
	void appendNode(NodeId id);
	void prependNode(NodeId id);
	void removeNode(NodeId id);
	void printLinkedList() const;
	void reverseLinkedListRecursive();
	void reverseLinkedListIterative();
	//void mergeSortLinkedList();

private:
	struct Node
	{
		NodeId id_;
		Node* next_;
		Node(NodeId id) : id_{id}, next_{nullptr} {}
	};
	Node* head_;
};

#endif // LINKED_LIST_H
