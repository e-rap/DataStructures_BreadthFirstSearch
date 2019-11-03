#include "Search.h"
#include <deque>
#include <unordered_map>
#include <iostream>

namespace DepthFirstSearch
{
  const int SOURCE = 1;
  const int DESTINATION = 2;
  const int BLANK = 3;
  const int WALL = 0;

  using NodePtr = const Graph::Node*;
  using Position = Graph::Position;

  // function declarations
  std::pair<NodePtr, NodePtr> find_source_dest(const Graph& graph);
  int depth_first_search(const Graph& graph);

  void RunDFS(const Graph& graph)
  {
    int distance = depth_first_search(graph);
    if (distance != -1)
    {
      std::cout << "1:" << distance << "\n";
    }
    else
    {
      std::cout << "0" << "\n";
    }
  }

  /// depth first search algorithm. returns the shortest distance from
  /// source node to destination node. if no path exists returns -1.
  int depth_first_search(const Graph& graph)
  {
    // get pointers to the source and destination nodes
    std::pair<NodePtr, NodePtr> source_dest{ find_source_dest(graph) };
    NodePtr source = source_dest.first;
    NodePtr destination = source_dest.second;

    // maps visited nodes to parent node
    std::unordered_map<NodePtr, NodePtr> visited_nodes;

    // stores nodes to be searched
    std::deque<NodePtr> node_stack{};

    visited_nodes[source] = nullptr; // mark source as visited 
    node_stack.push_back(source); // push the source node

    bool destination_found{ false };
    while (!node_stack.empty())
    {
      // pop the first node from the stack
      NodePtr cur_node{ node_stack.back() };
      node_stack.pop_back();

      // check if the node is the destination
      if (cur_node == destination)
      {
        destination_found = true;
        break;
      }

      // look at all neighbouring nodes
      for (NodePtr neighbour : cur_node->get_neighbours())
      {
        if (neighbour->get_value() != WALL) // ignore walls
        {
          // if not visited
          if (visited_nodes.find(neighbour) == visited_nodes.end())
          {
            // mark as visited
            visited_nodes[neighbour] = cur_node;
            node_stack.push_back(neighbour); //push on to stack
          }
        }
      }
    }

    // Calculate the distance by traversing the shortest path from 
    // the destination to the source.
    int distance{ -1 };
    if (destination_found)
    {
      distance = 0;
      NodePtr node = visited_nodes[destination];
      while (node != nullptr)
      {
        distance += 1;
        node = visited_nodes[node];
      }
    }
    return distance;
  }

  std::pair<NodePtr, NodePtr> find_source_dest(const Graph& graph)
  {
    std::pair<NodePtr, NodePtr> output{};

    auto dim{ graph.get_dim() };

    /// find source and destination
    for (size_t m{ 0 }; m < dim.first; ++m)
    {
      for (size_t n{ 0 }; n < dim.second; ++n)
      {
        NodePtr cur_node{ graph.get_node(std::make_pair(m,n)) };
        if (cur_node->get_value() == SOURCE)
        {
          output.first = cur_node;
        }
        else if (cur_node->get_value() == DESTINATION)
        {
          output.second = cur_node;
        }
        else
        {
          // Do nothing
        }
      }
    }
    return output;

  }

}