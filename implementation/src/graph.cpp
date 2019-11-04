#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <cassert>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>

using namespace std;

// Aliases for consistency
using NodeId = unsigned int;
using EdgeWeight = double;


//----------------------------------------------------------
// Provided Code
//----------------------------------------------------------
// Edge payload
struct EdgeData {
  EdgeData(NodeId _to_node, EdgeWeight _weight)
  : to_node(_to_node), weight(_weight) {}

  // Node ID 0 is considered invalid. We need a default
  // constructor to satisfy std::unordered_map
  EdgeData() : to_node(0), weight(0) {}

  NodeId to_node;
  EdgeWeight weight;
};

// Graph
class Graph {
 public:
  Graph() {}
  using EdgeList = unordered_map<NodeId, EdgeData>;
  EdgeList edgesFor(NodeId id) const;
  EdgeData* findEdge(NodeId from, NodeId to);
  void addBidirectionalEdge(NodeId from, NodeId to, EdgeWeight weight = 1.0);
  void addEdge(NodeId from, NodeId to, EdgeWeight weight = 1.0);

 private:
  unordered_map<NodeId, EdgeList> graph_;
};

// Your solution here

//----------------------------------------------------------
// Test Code
//----------------------------------------------------------
int main() {

  // Build the graph
  Graph graph;
  graph.addBidirectionalEdge(1, 2);
  graph.addBidirectionalEdge(1, 3);
  graph.addBidirectionalEdge(2, 3);

  graph.addBidirectionalEdge(4, 5);
  graph.addBidirectionalEdge(4, 6);
  graph.addBidirectionalEdge(5, 6);

  graph.addEdge(7, 7);

  // Test whether the nodes are pathable
  NodeId start;
  while (cin >> start) {
    NodeId end;
    cin >> end;
    cout << "";
  }

  return 0;
}

Graph::EdgeList Graph::edgesFor(NodeId id) const {
  auto edge_list_iter = graph_.find(id);
  if (edge_list_iter == graph_.end()) {
    return {};
  }

  return graph_.at(id);
}

EdgeData* Graph::findEdge(NodeId from, NodeId to) {
  auto edge_list_iter = graph_.find(from);
  if (edge_list_iter == graph_.end()) {
    return nullptr;
  }

  auto& edge_list = edge_list_iter->second;
  auto edge_iter = edge_list.find(to);

  return (edge_iter == edge_list.end()) ?
      nullptr:
      &edge_iter->second;
}

void Graph::addBidirectionalEdge(NodeId from, NodeId to, EdgeWeight weight) {
  addEdge(from, to, weight);
  addEdge(to, from, weight);
}

void Graph::addEdge(NodeId from, NodeId to, EdgeWeight weight) {
  if (graph_.find(from) == graph_.end()) {
    // Build the edge list if it doesn't already exist
    graph_[from] = EdgeList();
  } else {

    // If 'from' is already in the graph, ensure this
    // edge does not exist already
    if (graph_[from].find(to) != graph_[from].end()) {
      cerr << "Cannot creat edge from " << from << " to " << to << ". Already exists." << endl;
      return;
    }
  }

  // Place the edge in the edge list
  graph_[from][to] = EdgeData(to, weight);
}
