#pragma once

#include "Graph.h"

namespace BreadthFirstSearch
{
  // constants
  extern const int SOURCE;      ///< source value
  extern const int DESTINATION; ///< destination value
  extern const int BLANK;       ///< blank cell value
  extern const int WALL;        ///< wall cell value

  /// assignment API for running breadth first search algorithm
  void RunBFS(const Graph& graph);
}