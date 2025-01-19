#include <iostream>
#include <Eigen/Dense>

const size_t ROWS = 3000000;
const size_t FEATURES = 30;

using namespace Eigen;

void linear_regression(const MatrixXd& X, const VectorXd& y, VectorXd& w) {
    w = (X.transpose() * X).inverse() * X.transpose() * y;
}

int main() {
    MatrixXd X(ROWS, FEATURES);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < FEATURES; ++j) {
            X(i, j) = static_cast<double>(std::rand() * 100 / RAND_MAX;
        }
    }

    VectorXd y(ROWS);
    for (int i = 0; i < ROWS; ++i) {
        y(i) = 1 + 10 / (static_cast<double>(std::rand()) / RAND_MAX + 9);
    }

    VectorXd w(10);

    linear_regression(X, y, w);

    return 0;
}
