CXX = g++
CXXFLAGS = -std=c++11
HEADER_DIR = ../include/

all: linked_list binary_search_tree graph sliding_window 

linked_list: linked_list.o 
	$(CXX) $(CXXFLAGS) -o linked_list linked_list.o

linked_list.o: linked_list.cpp $(HEADER_DIR)linked_list.h
	$(CXX) $(CXXFLAGS) -I $(HEADER_DIR) -c linked_list.cpp 

binary_search_tree: binary_search_tree.o
	$(CXX) $(CXXFLAGS) -o binary_search_tree binary_search_tree.o

binary_search_tree.o: binary_search_tree.cpp
	$(CXX) $(CXXFLAGS) -c binary_search_tree.cpp

graph: graph.o
	$(CXX) $(CXXFLAGS) -o graph graph.o

graph.o: graph.cpp
	$(CXX) $(CXXFLAGS) -c graph.cpp

sliding_window: sliding_window.o
	$(CXX) $(CXXFLAGS) -o sliding_window sliding_window.o

sliding_window.o: sliding_window.cpp
	$(CXX) $(CXXFLAGS) -c sliding_window.cpp
