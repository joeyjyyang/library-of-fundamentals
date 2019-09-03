#include <iostream>
#include <vector>

class Node
{
public:
	Node(const int value) : value_(value), right_child_(nullptr), left_child_(nullptr)
	{
	}

	void addRight(Node *child)
	{
		right_child_ = child;
	}

	void addLeft(Node *child)
	{		
		left_child_ = child;
	}
	
	int getValue()
	{
		return value_;
	}

	void printNodes()
	{
		std::cout << right_child_->getValue() << std::endl;
		std::cout << this->getValue() << std::endl;
		std::cout << left_child_->getValue() << std::endl;
	}

	~Node()
	{
		delete right_child_, left_child_;
	}
	
private:
	int value_;
	Node *right_child_;
	Node *left_child_;
};

int main(int argc, char *argv[])
{
	Node *n1 = new Node(2);
	Node *n2 = new Node(5);
	Node *n3 = new Node(7);
	n1->addRight(n2);	 
	n1->addLeft(n3);
	n1->printNodes();	
	
	return 0;
}

 

