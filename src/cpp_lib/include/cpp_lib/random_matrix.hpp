
#ifndef __CPP_LIB_RANDOM_MATRIX_HPP__
#define __CPP_LIB_RANDOM_MATRIX_HPP__

#include <Eigen/Dense>

namespace ros_selfcheck
{

class RandomMatrixGenerator
{

public:
    RandomMatrixGenerator() {};
    ~RandomMatrixGenerator() {};

    Eigen::MatrixXd generate_random_matrix(const int rows, const int cols) const;
};

}

#endif // __CPP_LIB_RANDOM_MATRIX_HPP__
