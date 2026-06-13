#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
private:
    int rows;
    int cols;
    std::vector<float> data;

public:
    Matrix(int rows, int cols);

    int getRows() const;
    int getCols() const;

    float& operator()(int row, int col);
    float operator()(int row, int col) const;

    void print() const;
    void randomize(float min, float max);
    Matrix operator+(const Matrix& other) const;

    Matrix operator-(const Matrix& other) const;

    Matrix matmul(const Matrix& other) const;

    Matrix operator*(float scalar) const;
};

#endif