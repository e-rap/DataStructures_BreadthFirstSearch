#pragma once
#include <list>

/// Node structure for constructing graph datastructures.
template<typename data_type>
class Node
{
public:
  /// Constructs a node with given value.
  Node(const data_type& value);
  ~Node() {};

  /// returns the value of the node.
  data_type get_value() const;

  /// adds a neighbour to the node.
  void add_neighbour(Node* node);

  /// returns all neighours of the node.
  const std::list<Node<data_type>*> get_neighbours() const;

private:
  data_type value; ///< value of the node
  std::list<Node*> neighbours; ///< neighbours of the node
};

template <typename data_type>
inline Node<data_type>::Node(const data_type& value)
  : value{ value }, neighbours{}
{
}

template<typename data_type>
inline data_type Node<data_type>::get_value() const
{
  return value;
}

template<typename data_type>
inline void Node<data_type>::add_neighbour(Node* node)
{
  neighbours.push_back(node);
}

template<typename data_type>
inline const std::list<Node<data_type>*> Node<data_type>::get_neighbours() const
{
  return neighbours;
}
