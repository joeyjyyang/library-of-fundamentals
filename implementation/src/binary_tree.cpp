#include <iostream>
#include <vector>

class Node
{
public:
	Node(const int value) : value_(value), right_child_(nullptr), left_child_(nullptr)
	{
	}

	void insertNode(const int value);
	
	/*
	void printNodes()
	{
		std::cout << right_child_->getValue() << std::endl;
		std::cout << this->getValue() << std::endl;
		std::cout << left_child_->getValue() << std::endl;
	}
	*/
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
	Node *root = new Node(10);
	root->insertNode(15);

	return 0;
}

 

