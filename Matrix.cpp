#include "Matrix.h"

namespace BreadthFirstSearch
{
  Matrix generate_matrix()
  {
    return Matrix{ {3,0,3,3,3},
                   {0,3,3,0,3},
                   {0,1,3,0,3},
                   {0,0,3,3,2},
                   {0,0,0,0,0} };
  }

} // BreadthFirstSearch


