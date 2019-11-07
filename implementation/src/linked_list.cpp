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
LinkedList<T>::LinkedList() : head_{nullptr}, tail_{nullptr}, size_{0}
{
	std::cout << "Linked List object instantiated." << std::endl;
}

/*rule of 3*/
//copy ctor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head_{nullptr}, tail_{nullptr}, size_{0}
{
	std::cout << "Linked List object copy constructor called." << std::endl; 
	Node* current{other.head_};
	while (current != nullptr)
	{
		addEndNode(current->id_);
		current = current->next_;
	}	
}

//copy assignment operator
//implicitly calls the copy ctor (pass by value) and uses the copy-and-swap idiom
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> other) 
{
	std::cout << "Linked List object copy assignment operator called." << std::endl;
	swapContents(*this, other); 
	return *this;
}	

//dtor
template <class T>
LinkedList<T>::~LinkedList() 
{
	std::cout << "Linked List object destructor called." << std::endl;
	Node* current{head_};
	while (current != nullptr) 
	{
		head_ = head_->next_;
		delete current;
		current = head_;
	}
}

//friend swap function
template <class U>
void swapContents(LinkedList<U>& linked_list1, LinkedList<U>& linked_list2)
{
	std::swap(linked_list1.head_, linked_list2.head_);
	std::swap(linked_list1.tail_, linked_list2.tail_);
}

/*class methods*/
template <class T>
bool LinkedList<T>::isEmpty() const 
{
	return (head_ == nullptr && tail_ == nullptr && size_ == 0);
}

template <class T>
bool LinkedList<T>::isUnique(NodeId id) const 
{
	return (getNodePosition(id) < 0);
}

template <class T>
int LinkedList<T>::getSize() const 
{
	return size_;
}

template <typename T>
typename LinkedList<T>::NodeId LinkedList<T>::getNodeId(Position position) const
{
	if (position < 0 || position > getSize()) 
	{
		std::cout << "Error: position invalid." << std::endl;
		return -1;
	}
	else
	{
		if (position == 0) 
		{
				return head_->id_;
		}
		else if (position == getSize() - 1)
		{
	 		return tail_->id_;
		}
		else
		{
			Node* temp{head_};
			for (int index{0}; index <= position; ++index)
			{
				temp = temp->next_;
			}
			return temp->id_;
		}
	}
}

template <class T>
typename LinkedList<T>::Position LinkedList<T>::getNodePosition(NodeId id) const 
{
	if (isEmpty()) 
	{
		return -1;
	}
	else 
	{
		if (head_->id_ == id) 
		{
			return 0;
		}
		else if (tail_->id_ == id) 
		{
			return (getSize() - 1);
		}
		else 
		{
			int position{0};
			Node* current{head_};
			while (current != nullptr)
			{
				if (current->id_ == id) 
				{
					return position;
				}
				else 
				{
					current = current->next_;
				}
				position++;
			}
			return -1;
		}
	}
}

template <class T>
void LinkedList<T>::addEndNode(NodeId id) 
{
	if (!isUnique(id)) std::cout << "Error: new node must have unique id. Could not add new node as this id already exists." << std::endl;
	else
	{
		std::cout << "Appending new node {id: " << id << "} to end of Linked List." << std::endl;
		Node* temp = new Node{id};
		if (isEmpty()) 
		{
			head_ = tail_ = temp;
		}
		else 
		{
			tail_->next_ = temp;
			tail_ = temp;
		}
		size_++;
	}
}

template <class T>
void LinkedList<T>::addFrontNode(NodeId id) 
{
	if (!isUnique(id)) 
	{
		std::cout << "Error: new node must have unique id. Could not add new node as this id already exists." << std::endl;
	}
	else
	{
		std::cout << "Prepending new node {id: " << id << "} to beginning of Linked List." << std::endl;
		Node* temp = new Node{id};
		if (isEmpty()) 
		{
			head_ = tail_ = temp;
		}
		else
		{
			temp->next_ = head_;
			head_ = temp;
		}
		size_++;
	}
}

template <class T>
void LinkedList<T>::insertNode(NodeId id, Position position) 
{
	if (!isUnique(id)) 
	{
		std::cout << "Error: new node must have unique id. Could not add new node as this id already exists." << std::endl;
	}
	else if (position < 0 || position > getSize()) 
	{
		std::cout << "Error: position invalid." << std::endl;
	}
	else if (position == 0) 
	{
		addFrontNode(id);
	}
	else if (position == getSize()) 
	{
		addEndNode(id);
	}
	else
	{
		Node* temp = new Node{id};
		Node* current{head_};
		for (int index{0}; index < position - 1; ++index)
		{
			current = current->next_;
		}
		temp->next_ = current->next_;
		current->next_ = temp;
		std::cout << "Inserting new node {id: " << id << "} at position: " << position << std::endl;
		size_++;
	}
}

template <class T>
void LinkedList<T>::removeFrontNode() 
{
	if (isEmpty()) 
	{
		std::cout << "Error: the Linked List is empty." << std::endl;
	}
	else
	{
		std::cout << "Removing node {id: " << head_->id_ << "} at front of Linked List." << std::endl;
		Node* temp{head_};
		head_ = head_->next_;
		delete temp;
		size_--;
	}
}

template <class T>
void LinkedList<T>::removeEndNode() 
{
	if (isEmpty()) 
	{
		std::cout << "Error: the Linked List is empty." << std::endl;
	}
	else
	{
		std::cout << "Removing node {id: " << tail_->id_ << "} at end of Linked List." << std::endl;
		Node* temp{head_};
		while (temp->next_ != tail_)
		{
			temp = temp->next_;
		}
		temp->next_ = tail_->next_;
		delete tail_;
		tail_ = temp;
		size_--;
	}
}

template <class T>
void LinkedList<T>::removeNodeById(NodeId id) 
{
	if (isEmpty()) 
	{
		std::cout << "Error: the Linked List is empty." << std::endl;
	}
	else if (getNodePosition(id) < 0) 
	{
		std::cout << "Error: the specified node {id: " << id << "} does not exist in the Linked List." << std::endl;
	}
	else 
	{
		if (head_->id_ == id) 
		{
			removeFrontNode();
		}
		else if (tail_->id_ == id) 
		{
			removeEndNode();
		}
		else
		{
			std::cout << "Removing node {id: " << id << "} from Linked List." << std::endl;
			Node* current{head_};
			Node* trail{nullptr};
			while (current != nullptr)
			{
				if (current->id_ == id)
				{
					current = current->next_;
					delete trail->next_;
					trail->next_ = current;	
				}
				else
				{
					trail = current;
					current = current->next_;
				}
			}
			size_--;
		}
	}
}

template <class T>
void LinkedList<T>::removeNodeByPosition(Position position) 
{
	if (position < 0 || position >= getSize()) 
	{
		std::cout << "Error: position invalid." << std::endl;
	}
	else
	{
		if (position == 0) 
		{
			removeFrontNode();
		}
		else if (position == getSize() - 1) 
		{
			removeEndNode();
		}
		else
		{
			std::cout << "Removing node at position: " << position << " from Linked List." << std::endl;
			Node* current{head_};
			Node* trail{nullptr};
			for (int index{0}; index < position; ++index)
			{
				trail = current;
				current = current->next_;
			}
			trail->next_ = current->next_;
			delete current;
			size_--;
		}
	}
}

template <class T>
void LinkedList<T>::printLinkedList() const 
{
	if (isEmpty()) 
	{
		std::cout << "Error: the Linked List is empty." << std::endl;
	}
	else 
	{
		Node* current{head_};
		std::cout << "Printing nodes of Linked List with total of " << getSize() << " nodes." << std::endl;
		int position{0};
		while (current != nullptr) 
		{
			std::cout << "Node {id: " << current->id_ <<  "} at position: " << position << std::endl;
			current = current->next_;
			position++;
		}
	}
}

template <class T>
void LinkedList<T>::reverseLinkedListRecursive() 
{	
	if (head_ == tail_) 
	{
		return;
	}
	Node* current{head_};
	head_ = current->next_;
	reverseLinkedListRecursive();
	tail_->next_ = current;
	current->next_ = nullptr;
	tail_ = current;
}

template <class T>
void LinkedList<T>::reverseLinkedListIterative() 
{
	Node* current{head_};
	Node* trail{nullptr};
	tail_ = head_;
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
void LinkedList<T>::mergeSortLinkedList()
{
}
*/

//explicit instantiation of template into current compilation unit
template class LinkedList<char>;
template class LinkedList<int>;

template void swapContents(LinkedList<char>& linked_list1, LinkedList<char>& linked_list2);
template void swapContents(LinkedList<int>& linked_list1, LinkedList<int>& linked_list2);

int main(int argc, char* argv[])
{
	std::cout << "---- Test Case #1: Printing, Adding, and Removing ----" << std::endl;
	{
		LinkedList<int>* dummy_list1 = new LinkedList<int>();
		dummy_list1->addFrontNode(3); //3
		dummy_list1->addEndNode(3); //error
		dummy_list1->addEndNode(4); //3 4
		dummy_list1->insertNode(1, 0); //1 3 4
		dummy_list1->insertNode(2, 1); //1 2 3 4
		dummy_list1->printLinkedList(); 
		dummy_list1->insertNode(5, 5); //error
		dummy_list1->insertNode(5, 4); //1 2 3 4 5
		dummy_list1->addFrontNode(0); //0 1 2 3 4 5 
		dummy_list1->addEndNode(6); //0 1 2 3 4 5 6
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		dummy_list1->removeNodeByPosition(12); //error
		dummy_list1->removeNodeById(-2); //error
		dummy_list1->removeFrontNode(); //1 2 3 4 5 6 
		dummy_list1->printLinkedList();
		dummy_list1->removeNodeByPosition(0);//2 3 4 5 6
		dummy_list1->printLinkedList();
		dummy_list1->removeNodeById(3); //2 4 5 6
		dummy_list1->printLinkedList();
		dummy_list1->removeNodeByPosition(2); //2 4 6
		dummy_list1->printLinkedList();
		dummy_list1->removeNodeByPosition(2); //2 4 
		dummy_list1->printLinkedList();
		dummy_list1->removeEndNode(); //2 
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		delete dummy_list1;
	}
	std::cout << "---- Test Case #2: Reversing (Recursively and Iteratively) ----" << std::endl;
	{
		LinkedList<int>* dummy_list1 = new LinkedList<int>();
		dummy_list1->addFrontNode(4);
		dummy_list1->addFrontNode(3);
		dummy_list1->addFrontNode(2);
		dummy_list1->addFrontNode(1);
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
		LinkedList<char>* dummy_list1 = new LinkedList<char>();
		dummy_list1->addFrontNode('a');
		dummy_list1->addFrontNode('b');
		dummy_list1->addFrontNode('c');
		dummy_list1->addFrontNode('d');
		dummy_list1->printLinkedList();
		std::cout << "--------------" << std::endl;

		LinkedList<char>* dummy_list3 = new LinkedList<char>(*dummy_list1); //copy constructor
		dummy_list3->printLinkedList();
		std::cout << "--------------" << std::endl;

		LinkedList<char>* dummy_list2 = new LinkedList<char>();
		dummy_list2 = dummy_list3; //copy assignment operator
		dummy_list2->printLinkedList();
		std::cout << "--------------" << std::endl;

		delete dummy_list1;
		delete dummy_list2;
		delete dummy_list3;
	}
	return 0;
}
