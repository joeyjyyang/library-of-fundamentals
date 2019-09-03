#include <iostream>
#include <vector>

class Node
{
public:
	Node(int value) : value_(value)
	{
	}
	
	void addLeft(Node child)
	{
		child_nodes_[0];	
	}
/*
	void addRight(Node child)
	{
		child_nodes_[1] = child;
	}
*/
	int getValue()
	{
		return value_;
	}
/*
	int getLeft()
	{
		return child_nodes_[0].getValue();
	}

	int getRight()
	{
		return child_nodes_[1].getValue();
	}
*/
	~Node()
	{
	}
private:
	int value_;
	std::vector<Node> child_nodes_[2];
};

int main(int argc, char *argv[])
{
	Node n1(2), n2(5), n3(7);

	n1.addLeft(n2);	
	return 0;
}

 

