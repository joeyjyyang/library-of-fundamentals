CXX = g++
CXXFLAGS = -std=c++11
HEADER_DIR = ../include/

all: linked_list binary_tree 

linked_list: linked_list.o 
	$(CXX) $(CXXFLAGS) -o linked_list linked_list.o

linked_list.o: linked_list.cpp $(HEADER_DIR)linked_list.h
	$(CXX) $(CXXFLAGS) -I $(HEADER_DIR) -c linked_list.cpp 

binary_tree: binary_tree.o
	$(CXX) $(CXXFLAGS) -o binary_tree binary_tree.o

binary_tree.o: binary_tree.cpp
	$(CXX) $(CXXFLAGS) -c binary_tree.cpp
