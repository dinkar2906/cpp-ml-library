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

Matrix Matrix::operator+(const Matrix& other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument(
            "Matrix dimensions must match for addition");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument(
            "Matrix dimensions must match for subtraction");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result(i, j) = (*this)(i, j) - other(i, j);
        }
    }

    return result;
}

Matrix Matrix::operator*(float scalar) const
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result(i, j) = (*this)(i, j) * scalar;
        }
    }

    return result;
}

Matrix Matrix::matmul(const Matrix& other) const
{
    if (cols != other.rows)
    {
        throw std::invalid_argument(
            "Invalid dimensions for matrix multiplication");
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            float sum = 0.0f;

            for (int k = 0; k < cols; k++)
            {
                sum += (*this)(i, k) * other(k, j);
            }

            result(i, j) = sum;
        }
    }

    return result;
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