#include <iostream>
#include <vector>

class Node
{
public:
	Node(const int value);
	~Node();

	void insertNode(const int value);
	void print() const;

private:
	int value_;
	Node *right_child_;
	Node *left_child_;
};

Node::Node(const int value) :
	value_(value), right_child_(nullptr), left_child_(nullptr)
{
}

Node::~Node()
{
	delete right_child_;
	delete left_child_;
}

void Node::insertNode(const int value)
{
	Node *node = new Node(value);
	if (right_child_ == nullptr && left_child_ == nullptr)
	{
		;
	}
	/*Node *node = new Node(value);
	if (node->value_ <= value_) left_child_ = node;
	else right_child_ = node;*/
}

void Node::print() const 
{
	std::cout << left_child_->value_ << std::endl;
	std::cout << value_ << std::endl;
	std::cout << right_child_->value_ << std::endl;
}


int main(int argc, char *argv[])
{
	Node *root = new Node(10);
	root->insertNode(15);
	root->insertNode(7);
	root->print();


	return 0;
}

 

