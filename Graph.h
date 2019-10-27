#pragma once

#include "Matrix.h"
#include "Node.h"
#include <list>
#include <vector>
#include <memory>

namespace BreadthFirstSearch
{
  /// stores a matrix within a graph datastructure
  class Graph
  {
  public:
    using Node = Node<int>;
    using Position = std::pair<int, int>;

    /// Constructs a graph from given Matrix mat
    Graph(const Matrix& mat);
    virtual ~Graph() {}
    
    /// returns a pointer to the node at the given position within the graph
    const Node* get_node(Position pos) const;
    Position get_dim() const;

  private:
    /// returns all valid neighbours from position on matrix
    virtual std::vector<Position> get_neighbours(Position pos);

    /// converts 2D position to 1D index
    size_t position_to_index(Position pos) const;

    std::vector<std::unique_ptr<Node>> Nodes; ///< all nodes in the graph
    std::pair<size_t, size_t> dim; ///< dimention of the input matrix
  };
}



