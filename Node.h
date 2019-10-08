#pragma once
#include <list>

template<typename data_type>
class Node
{
public:
  Node(const data_type& value);
  ~Node();
  data_type get_value();
  void add_neighbour(Node* node);
  const std::list<Node<data_type>*> get_neighbours() const;


private:
  data_type value;
  std::list<Node*> neighbours;

};

template <typename data_type>
inline Node<data_type>::Node(const data_type& value)
  : value{ value }, neighbours{}
{
}

template<typename data_type>
inline Node<data_type>::~Node()
{
}

template<typename data_type>
inline data_type Node<data_type>::get_value()
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
