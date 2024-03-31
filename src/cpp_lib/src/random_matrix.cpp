
#include "cpp_lib/random_matrix.hpp"

namespace ros_selfcheck
{

Eigen::MatrixXd 
RandomMatrixGenerator::generate_random_matrix(const int rows, const int cols) const
{
    return Eigen::MatrixXd::Random(rows, cols);
}

}
