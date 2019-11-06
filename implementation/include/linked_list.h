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
	using Position = const int;

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
	bool isUnique(NodeId Id) const;
	int getSize() const;
	NodeId getNodeId(Position position) const;
	Position getNodePosition(NodeId id) const;
	void addFrontNode(NodeId id);
	void addEndNode(NodeId id);
	void insertNode(NodeId id, Position position);
	void removeFrontNode();
	void removeEndNode();
	void removeNodeById(NodeId id);
	void removeNodeByPosition(Position position);
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
	Node* tail_;
	int size_;
};

#endif // LINKED_LIST_H
