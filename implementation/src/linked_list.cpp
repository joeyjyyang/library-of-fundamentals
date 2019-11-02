/*
 *	Author: Joey Yang
 *	Email: joeyyang.ai@gmail.com
 *	Description: linked list source file; contains function definitions. 
 */

#include <string>
#include <algorithm>

#include "linked_list.h"

template <class T>
data_structure::LinkedList<T>::LinkedList() :
	head_{nullptr}
{
	std::cout << "Linked List object instantiated." << std::endl;
}

/*rule of 3*/
//copy ctor
template <class T>
data_structure::LinkedList<T>::LinkedList(const data_structure::LinkedList<T>& other) :
	head_{nullptr}
{
	Node* current{other.head_};
	while (current != nullptr)
	{
		appendNode(current->id_);
		current = current->next_;
	}
	std::cout << "Linked List object copy constructor called." << std::endl; 
}

//copy assignment operator
//implicitly calls the copy ctor (pass by value) and uses the copy-and-swap idiom
template <class T>
data_structure::LinkedList<T>& data_structure::LinkedList<T>::operator=(data_structure::LinkedList<T> other) 
{
	std::cout << "Linked List object copy assignment operator called." << std::endl;
	swapContents(*this, other); 
	return *this;
}	

//dtor
template <class T>
data_structure::LinkedList<T>::~LinkedList() 
{
	Node* current{head_};
	while (current != nullptr) 
	{
		head_ = head_->next_;
		delete current;
		current = head_;
	}
	std::cout << "Linked List object destructor called." << std::endl;
}

//friend swap function
template <class U>
void swapContents(data_structure::LinkedList<U>& linked_list1, data_structure::LinkedList<U>& linked_list2)
{
	std::swap(linked_list1.head_, linked_list2.head_);
}

/*class methods*/
template <class T>
bool data_structure::LinkedList<T>::isEmpty() const 
{
	return head_ == nullptr;
}

template <class T>
bool data_structure::LinkedList<T>::findNode(const T& id) const 
{
	Node* current{head_};
	while (current != nullptr)
	{
		if (current->id_ == id) return true;
		else current = current->next_;
	}
	return false;
}

template <class T>
void data_structure::LinkedList<T>::appendNode(const T& id) 
{
	if (findNode(id)) std::cout << "Error: new node must have unique id. Could not add new node as this id already exists." << std::endl;
	else
	{
		Node* temp = new Node{id};
		if (isEmpty()) head_ = temp;
		else 
		{
			Node* current{head_};
			while (current->next_ != nullptr)
			{
				current = current->next_;
			}
			current->next_ = temp;
		}
		std::cout << "Appending new node {id: " << temp->id_ << "} to end of Linked List." << std::endl;
	}
}

template <class T>
void data_structure::LinkedList<T>::prependNode(const T& id) 
{
	if (findNode(id)) std::cout << "Error: new node must have unique id. Could not add new node as this id already exists." << std::endl;
	else
	{
		Node* temp = new Node{id};
		if (!isEmpty()) 
		{
			temp->next_ = head_;
		}
		head_ = temp;
		std::cout << "Prepending new node {id: " << temp->id_ << "} to beginning of Linked List." << std::endl;
	}
}

template <class T>
void data_structure::LinkedList<T>::removeNode(const T& id) 
{
	if (isEmpty()) std::cout << "Error: the Linked List is empty." << std::endl;
	else if (!findNode(id)) std::cout << "Error: the specified does not exist in the Linked List." << std::endl;
	else 
	{
		Node* current{head_};
		Node* trail{nullptr};
		while (current != nullptr)
		{
			if (current->id_ == id)
			{
				std::cout << "Removing node {id: " << current->id_ << "}." << std::endl;
				if (trail == nullptr)
				{
					head_ = head_->next_;
					delete current;
					current = head_;
				}
				else
				{
					current = current->next_;
					delete trail->next_;
					trail->next_ = current;
				}
			}
			else
			{
				trail = current;
				current = current->next_;
			}
		}
	}
}

template <class T>
void data_structure::LinkedList<T>::printLinkedList() const 
{
	if (isEmpty()) std::cout << "Error: the Linked List is empty." << std::endl;
	else 
	{
		Node* current{head_};
		std::cout << "Printing nodes of Linked List." << std::endl;
		int position{}; //zero initialization
		while (current != nullptr) 
		{
			std::cout << "Node {id: " << current->id_ <<  "} at position: " << position << std::endl;
			current = current->next_;
			position++;
		}
	}
}

template <class T>
void data_structure::LinkedList<T>::reverseLinkedListRecursive() 
{	
	if (head_->next_ == nullptr) return;
	Node* current{head_};
	head_ = current->next_;
	reverseLinkedListRecursive();
	current->next_->next_ = current;
	current->next_ = nullptr;
}

template <class T>
void data_structure::LinkedList<T>::reverseLinkedListIterative() 
{
	Node* current{head_};
	Node* trail{nullptr};
	while (current != nullptr)
	{
		current = head_->next_;
		head_->next_ = trail;
		trail = head_;
		head_ = current;
	}
	head_ = trail;
}

/*
template <class T>
void data_structure::LinkedList<T>::mergeSortLinkedList()
{
}
*/

//explicit instantiation of template into current compilation unit
template class data_structure::LinkedList<char>;
template class data_structure::LinkedList<int>;
template class data_structure::LinkedList<double>;
template class data_structure::LinkedList<std::string>;

template void swapContents(data_structure::LinkedList<char>& linked_list1, data_structure::LinkedList<char>& linked_list2);
template void swapContents(data_structure::LinkedList<int>& linked_list1, data_structure::LinkedList<int>& linked_list2);
template void swapContents(data_structure::LinkedList<double>& linked_list1, data_structure::LinkedList<double>& linked_list2);
template void swapContents(data_structure::LinkedList<std::string>& linked_list1, data_structure::LinkedList<std::string>& linked_list2);

int main(int argc, char* argv[])
{
	std::cout << "---- Test Case #1: Printing, Adding, and Removing ----" << std::endl;
	{
		data_structure::LinkedList<int>* dummy_list1 = new data_structure::LinkedList<int>();
		dummy_list1->appendNode(3);
		dummy_list1->prependNode(2);
		dummy_list1->appendNode(4);
		dummy_list1->prependNode(4);
		dummy_list1->prependNode(1);
		dummy_list1->appendNode(1);
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		dummy_list1->removeNode(2);
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		delete dummy_list1;
	}
	std::cout << "---- Test Case #2: Reversing (Recursively and Iteratively) ----" << std::endl;
	{
		data_structure::LinkedList<int>* dummy_list1 = new data_structure::LinkedList<int>();
		dummy_list1->appendNode(4);
		dummy_list1->appendNode(3);
		dummy_list1->appendNode(2);
		dummy_list1->appendNode(1);
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		dummy_list1->reverseLinkedListIterative();
		std::cout << "Reversing Linked List iteratively." << std::endl;
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;
		
		dummy_list1->reverseLinkedListRecursive();
		std::cout << "Reversing Linked List recursively." << std::endl;
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		delete dummy_list1;
	}
	std::cout << "---- Test Case #3: Rule of 3 ----" << std::endl;
	{
		data_structure::LinkedList<char>* dummy_list1 = new data_structure::LinkedList<char>();
		dummy_list1->appendNode('a');
		dummy_list1->appendNode('b');
		dummy_list1->appendNode('c');
		dummy_list1->appendNode('d');
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		data_structure::LinkedList<char>* dummy_list3 = new data_structure::LinkedList<char>(*dummy_list1); //copy constructor
		dummy_list3->printLinkedList();
		std::cout << "--------------" << std::endl;

		data_structure::LinkedList<char>* dummy_list2 = new data_structure::LinkedList<char>();
		dummy_list2 = dummy_list3; //copy assignment operator
		dummy_list2->printLinkedList();
		std::cout << "--------------" << std::endl;

		delete dummy_list1;
		delete dummy_list2;
		delete dummy_list3;
	}
	return 0;
}
