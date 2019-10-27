#include "Graph.h"

namespace BreadthFirstSearch
{
  Graph::Graph(const Matrix& mat)
    : Nodes{}, dim{ mat.size(),mat[0].size() }
  {
    // add all nodes to the matrix
    for (size_t m{ 0 }; m < dim.first; ++m)
    {
      // loop per col in matrix
      for (size_t n{ 0 }; n < dim.second; ++n)
      {
        Nodes.push_back(std::make_unique<Node>(mat[m][n]));
      }
    }

    // add all neighbours to each node
    for (size_t m{ 0 }; m < dim.first; ++m)
    {
      for (size_t n{ 0 }; n < dim.second; ++n)
      {
        Position current_pos{ m,n };
        Node* current_node{ Nodes[position_to_index(current_pos)].get() };
        std::vector<Position> neighbours{ get_neighbours(current_pos) };
        for (const auto& pos : neighbours)
        {
          current_node->add_neighbour(Nodes[position_to_index(pos)].get());
        }
      }
    }
  }

  const Graph::Node* Graph::get_node(Position pos) const
  {
    return Nodes[position_to_index(pos)].get();
  }

  Graph::Position Graph::get_dim() const
  {
    return dim;
  }

  std::vector<Graph::Position> Graph::get_neighbours(Position pos)
  {
    std::vector<Position> output;

    // up    = row - 1, col (if >= 0)
    if ((pos.first - 1) >= 0)
    {
      output.emplace_back(std::make_pair(pos.first - 1, pos.second));
    }
    // down  = row + 1, col (if <= row size) 
    if ((pos.first + 1) < dim.first)
    {
      output.emplace_back(std::make_pair(pos.first + 1, pos.second));
    }
    // right = row, col - 1 (if >= 0)
    if ((pos.second - 1) >= 0)
    {
      output.emplace_back(std::make_pair(pos.first, pos.second - 1));
    }
    // left  = row, col + 1 (if <= col size)
    if ((pos.second + 1) < dim.second)
    {
      output.emplace_back(std::make_pair(pos.first, pos.second + 1));
    }

    return output;
  }

  size_t Graph::position_to_index(Position pos) const
  {
    return size_t(pos.first * dim.first + pos.second);
  }

}
