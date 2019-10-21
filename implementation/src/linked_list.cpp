/*
 *	Author: Joey Yang
 *	Email: joeyyang.ai@gmail.com
 *	Description: linked list source file; contains function definitions. 
 */

#include <string>
#include <algorithm>

#include "linked_list.h"

//ctor
template <class T>
data_structure::LinkedList<T>::LinkedList() :
	head_{nullptr}
{
	std::cout << "Linked List object instantiated." << std::endl;
}

//rule of 3

//copy ctor
template <class T>
data_structure::LinkedList<T>::LinkedList(const data_structure::LinkedList<T> &other) :
	head_{nullptr}
{
	Node *current{other.head_};
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
	Node *current{head_};
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
void swapContents(data_structure::LinkedList<U> &linked_list1, data_structure::LinkedList<U> &linked_list2)
{
	std::swap(linked_list1.head_, linked_list2.head_);
}

//class methods 

template <class T>
bool data_structure::LinkedList<T>::isEmpty() const 
{
	return head_ == nullptr;
}

template <class T>
int data_structure::LinkedList<T>::getSize() const 
{
	if (isEmpty()) 
	{
		return 0;
	}
	else 
	{
		Node *current{head_};
		int queue_size{}; //zero initialization
		while (current != nullptr) 
		{
			current = current->next_;
			queue_size++;
		}
		
		return queue_size;
	}
}

template <class T>
T data_structure::LinkedList<T>::getNodeID(const int position) const
{
	if (position == 0) 
	{
		std::cout << "Node {id: " << head_->id_ << "} is located at position " << position << std::endl;
		
		return head_->id_;
	}
	else if (position > getSize() - 1 || position < 0) 
	{
		std::cout << "Error: the node position is invalid." << std::endl;
		
		return 0;
	}
	else 
	{
		Node* current{head_};
		for (int current_position = 0; current_position < position; ++current_position) 
		{
			current = current->next_;
		}
		std::cout << "Node {id: " << current->id_ << "} is located at position " << position << std::endl;
		
		return current->id_;
	}

}

template <class T>
void data_structure::LinkedList<T>::appendNode(const T &id) 
{
	Node *temp = new Node{id};
	if (isEmpty()) 
	{
		std::cout << "Adding first node {id: " << temp->id_ << "} to empty Linked List." << std::endl;
		head_ = temp;
	}
	else 
	{
		Node *current{head_};
		while (current->next_ != nullptr)
		{
			current = current->next_;
		}
		std::cout << "Adding new node {id: " << temp->id_ << "} to end of Linked List." << std::endl;
		current->next_ = temp;
	}
}

template <class T>
void data_structure::LinkedList<T>::prependNode(const T &id) 
{
	Node *temp = new Node{id};
	if (isEmpty()) 
	{	
		std::cout << "Adding first node to empty Linked List: " << "id: " << temp->id_ << std::endl;
	}
	else 
	{
		std::cout << "Adding new node {id: " << temp->id_ << "} to beginning of Linked List." << std::endl;
		temp->next_ = head_;
	}
	head_ = temp;
}

template <class T>
void data_structure::LinkedList<T>::insertNode(const T &id, const int position) 
{
	if (position == 0) 
	{
		prependNode(id);
	}
	else if (position == getSize()) 
	{
		appendNode(id);
	}
	else if (position > getSize() || position < 0) 
	{
		std::cout << "Error: the position to insert the new node is invalid." << std::endl;
	}
	else 
	{
		Node *temp = new Node{id};
		Node *trail{head_};
		for (int current_position = 0; current_position < position - 1; ++current_position) 
		{
			trail = trail->next_;
		}
		std::cout << "Inserting new node {id: " << temp->id_ << "} to Linked List at position " << position << std::endl;
		temp->next_ = trail->next_;
		trail->next_ = temp;
	}
}

template <class T>
void data_structure::LinkedList<T>::removeNode(const T &id) 
{
	if (isEmpty()) 
	{
		std::cout << "Error: the Linked List is empty; there are no node to remove." << std::endl;
	}
	else 
	{
		int position = 0;
		Node *current{head_};
		Node *trail{nullptr};
		while (current != nullptr)
		{
			if (current->id_ == id)
			{
				std::cout << "Removing node {id: " << current->id_ << "} at position: " << position << std::endl;
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
			position++;
		}
	}
}

template <class T>
void data_structure::LinkedList<T>::printLinkedList() const 
{
	if (isEmpty()) 
	{
		std::cout << "The Linked List is empty." << std::endl;
	}
	else 
	{
		Node *current{head_};
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
	if (head_->next_ == nullptr) 
	{
		return;
	}
	Node *current{head_};
	head_ = current->next_;
	reverseLinkedListRecursive();
	current->next_->next_ = current;
	current->next_ = nullptr;
}

template <class T>
void data_structure::LinkedList<T>::reverseLinkedListIterative() 
{
	Node *current{head_};
	Node *trail{nullptr};
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
void data_structure::LinkedList<T>::mergerSort()
{
}
*/

//explicit instantiation of template into current compilation unit
template class data_structure::LinkedList<char>;
template class data_structure::LinkedList<int>;
template class data_structure::LinkedList<double>;
template class data_structure::LinkedList<std::string>;

template void swapContents(data_structure::LinkedList<char> &linked_list1, data_structure::LinkedList<char> &linked_list2);
template void swapContents(data_structure::LinkedList<int> &linked_list1, data_structure::LinkedList<int> &linked_list2);
template void swapContents(data_structure::LinkedList<double> &linked_list1, data_structure::LinkedList<double> &linked_list2);
template void swapContents(data_structure::LinkedList<std::string> &linked_list1, data_structure::LinkedList<std::string> &linked_list2);

int main(int argc, char *argv[])
{
	std::cout << "------Test Case #0------" << std::endl;
	{
		data_structure::LinkedList<int> *dummy_list1 = new data_structure::LinkedList<int>();
		
		dummy_list1->appendNode(3);
		dummy_list1->prependNode(1);
		dummy_list1->insertNode(2, 1);
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

	std::cout << "------Test Case #1------" << std::endl;
	{
		data_structure::LinkedList<int> *dummy_list1 = new data_structure::LinkedList<int>();
	
		dummy_list1->appendNode(3);
		dummy_list1->prependNode(1);
		dummy_list1->insertNode(2, 1);
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		dummy_list1->insertNode(6, 2);
		dummy_list1->appendNode(6);
		dummy_list1->prependNode(6);
		dummy_list1->printLinkedList();

		dummy_list1->removeNode(6);
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;
		
		dummy_list1->reverseLinkedListRecursive();
		std::cout << "Reversing Linked List recursively." << std::endl;
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;
		
		dummy_list1->appendNode(2);
		dummy_list1->prependNode(1);
		dummy_list1->insertNode(3, 0);
		std::cout << "--------------" << std::endl;

		dummy_list1->getNodeID(0);
		dummy_list1->getNodeID(1);
		dummy_list1->getNodeID(2);
		dummy_list1->getNodeID(3);
		std::cout << "--------------" << std::endl;
		
		delete dummy_list1;
	}

	std::cout << "------Test Case #2------" << std::endl;
	{
		data_structure::LinkedList<char> *dummy_list1 = new data_structure::LinkedList<char>();
		
		dummy_list1->appendNode('c');
		dummy_list1->appendNode('d');
		dummy_list1->prependNode('a');
		dummy_list1->insertNode('b', 1);
		dummy_list1->reverseLinkedListRecursive();
		std::cout << "Reversing Linked List recursively." << std::endl;
		dummy_list1->printLinkedList();
		dummy_list1->reverseLinkedListIterative();
		std::cout << "Reversing Linked List iteratively." << std::endl;
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		data_structure::LinkedList<char> *dummy_list3 = new data_structure::LinkedList<char>(*dummy_list1); //copy constructor
		dummy_list3->removeNode('c');
		dummy_list3->printLinkedList();
		std::cout << "--------------" << std::endl;

		data_structure::LinkedList<char> *dummy_list2 = new data_structure::LinkedList<char>();
		dummy_list2 = dummy_list3; //copy assignment operator
		dummy_list2->reverseLinkedListRecursive();
		std::cout << "Reversing Linked List recursively." << std::endl;
		dummy_list2->printLinkedList();
		std::cout << "--------------" << std::endl;

		delete dummy_list1;
		delete dummy_list2;
		delete dummy_list3;
	}

	return 0;
}
