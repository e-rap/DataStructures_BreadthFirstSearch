#pragma once

#include <vector>

namespace BreadthFirstSearch
{
  template <typename data_type>
  using container = std::vector<data_type>;
  using row = container<int>;
  using Matrix = container<row>;

  Matrix generate_matrix(size_t N, size_t M);

} // BreadthFirstSearch



