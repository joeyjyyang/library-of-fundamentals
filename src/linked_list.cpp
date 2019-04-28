/*
	File: linked_list.cpp

	Author: Joey Yang

	Description: linked list class file; contains function definitions.
	Implementation of a linked list.
*/

#include "linked_list.h"

#include <cstdlib>
#include <string>

//constructor
LinkedList::LinkedList() 
{
	head_ = nullptr;
	tail_ = nullptr;
	std::cout << "Linked List object instantiated." << std::endl;
}

/* rule of 3 */

/*
LinkedList::LinkedList(const LinkedList& other) 
{
}
*/

/*
LinkedList& LinkedList::operator=(const LinkedList& other) 
{
}	
*/

LinkedList::~LinkedList() 
{
	Node* current = head_;
	while (current != nullptr) {
		head_ = head_->next_;
		delete current;
		current = head_;
	}
}

/* class methods */
bool LinkedList::isEmpty() const 
{
	return head_ == nullptr;
}

int LinkedList::getSize() const 
{
	if (isEmpty()) 
	{
		return 0;
	}
	else 
	{
		Node* current = head_;
		int queue_size = 0;
		while (current != nullptr) 
		{
			current = current->next_;
			queue_size++;
		}
		return queue_size;
	}
}

void LinkedList::appendNode(const int id) 
{
	Node* current = new Node(id);
	if (isEmpty()) 
	{
		std::cout << "Adding first node to empty Linked List: " << "id: " << current->id_ << std::endl;
		head_ = current;
		tail_ = current;
	}
	else 
	{
		std::cout << "Adding new node to end of Linked List: " << "id: " << current->id_ << std::endl;
		tail_->next_ = current;
		tail_ = tail_->next_;
	}
}

void LinkedList::prependNode(const int id) 
{
	Node* current = new Node(id);
	if (isEmpty()) 
	{
		std::cout << "Adding first node to empty Linked List: " << "id: " << current->id_ << std::endl;
		head_ = current;
		tail_ = current;
	}
	else 
	{
		std::cout << "Adding new node to beginning of Linked List: " << "id: " << current->id_ << std::endl;
		current->next_ = head_;
		head_ = current;
	}
}

void LinkedList::insertNode(const int id, int position) 
{
	if (position == 1) 
	{
		prependNode(id);
	}
	else if (position == getSize() + 1) 
	{
		appendNode(id);
	}
	else if (position > getSize() + 1) 
	{
		std::cout << "Error: the position to insert the new node is invalid." << std::endl;
	}
	else 
	{
		Node* current = new Node(id);
		Node* trail = head_;
		for (int current_position = 1; current_position < position - 1; current_position++) {
			trail = trail->next_;
		}
		std::cout << "Inserting new node to Linked List: " << "id: " << current->id_ << "at position: " << position << std::endl;
		current->next_ = trail->next_;
		trail->next_ = current;
	}
}

void LinkedList::removeNode(const int id) 
{
	if (isEmpty()) 
	{
		std::cout << "Error: the Linked List is empty; there are no node to remove." << std::endl;
	}
	else 
	{
		if (head_->id_ == id) 
		{
			std::cout << "Removing node from beginning of Linked List: " << "ID: " << head_->id_ << std::endl;
			Node* current = head_;
			head_ = head_->next_;
			delete current;
		}
		else if (tail_->id_ == id) 
		{
			std::cout << "Removing node from end of Linked List: " << "ID: " << tail_->id_ << std::endl;
			Node* current = head_;
			while (current->next_ != tail_) 
			{
				current = current->next_;
			}
			tail_ = current;
			tail_->next_ = nullptr;
			current = current->next_;
			delete current;
		}
		else 
		{
			Node* current = head_->next_;
			Node* trail = head_;
			while (current != nullptr) 
			{
				if (current->id_ == id) 
				{
					std::cout << "Removing node from Linked List: " << "ID: " << current->id_ << std::endl;
					trail->next_ = current->next_;
					current->next_ = nullptr;
					delete current;
					return;
				}
				else 
				{
					trail = current;
					current = current->next_;
				}
			}
			std::cout << "Error: could not find node in Linked List." << std::endl;
		}
	}
}

void LinkedList::printLinkedList() const 
{
	if (isEmpty()) 
	{
		std::cout << "The Linked List is empty." << std::endl;
	}
	else 
	{
		Node* current = head_;
		std::cout << "Printing nodes of Linked List: " << std::endl;
		while (current != nullptr) 
		{
			std::cout << "ID: " << current->id_ << std::endl;
			current = current->next_;
		}
	}
}

void LinkedList::loadNodes(std::ifstream& infile) 
{
	if (!infile.is_open()) 
	{
		std::cout << "Error: failed to open csv file containing nodes to load." << std::endl;
	}
	else 
	{
		std::string line;
		std::string field_id;
		while (std::getline(infile, field_id, ',')) 
		{
			try 
			{
				appendNode(atoi(field_id.c_str()));
			}
			catch (const std::invalid_argument& ex) 
			{
				std::cout << "Error: the ID is invalid and could not be converted into a number." << std::endl;
			}
			catch (const std::out_of_range& ex) 
			{
				std::cout << "Error: the ID is out of range." << std::endl;
			}
		}
	}
}

//recursively reverse the Linked List
void LinkedList::reverseLinkedList() 
{
	if (head_ == tail_) 
	{
		return;
	}
	Node* current = head_;
	head_ = current->next_;
	reverseLinkedList();
	tail_->next_ = current;
	current->next_ = nullptr;
	tail_ = current;
}

/*
void mergeSortLinkedList()
{
}
*/
