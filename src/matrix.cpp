#include "../include/matrix.h"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int rows, int cols)
    : rows(rows), cols(cols), data(rows * cols, 0.0f)
{
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getCols() const
{
    return cols;
}

float& Matrix::operator()(int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        throw std::out_of_range("Matrix index out of range");
    }

    return data[row * cols + col];
}

float Matrix::operator()(int row, int col) const
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        throw std::out_of_range("Matrix index out of range");
    }

    return data[row * cols + col];
}

void Matrix::print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << (*this)(i, j) << " ";
        }

        std::cout << '\n';
    }
}