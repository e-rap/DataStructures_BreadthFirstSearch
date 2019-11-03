#pragma once

#include <vector>
#include <string>

namespace DepthFirstSearch
{
  template <typename data_type>
  using container = std::vector<data_type>;
  using row = container<int>;
  using Matrix = container<row>;

  /// loads test input file and creates vector of matricies
  std::vector<Matrix> load_test_data(std::string file_name);

  /// generates a matrix from vector of data
  Matrix generate_matrix(size_t N, std::vector<int> data);

} // DepthFirstSearch



