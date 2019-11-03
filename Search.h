#pragma once

#include "Graph.h"

namespace DepthFirstSearch
{
  // constants
  extern const int SOURCE;      ///< source value
  extern const int DESTINATION; ///< destination value
  extern const int BLANK;       ///< blank cell value
  extern const int WALL;        ///< wall cell value

  /// assignment API for running depth first search algorithm
  void RunDFS(const Graph& graph);
}