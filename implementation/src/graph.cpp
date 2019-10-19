#include <iostream>

class Graph 
{
public:
	Graph()
	{
		std::cout << "created." << std::endl;
	}

	~Graph()
	{
		std::cout << "destroyed." << std::endl;
	}

private:

};

int main(int argc, char* argv[])
{
	Graph *graph = new Graph();

	delete graph;
	return 0;
}
