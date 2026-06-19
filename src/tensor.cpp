#include "../include/tensor.h"

#include <iostream>
#include <stdexcept>

Tensor::Tensor(const std::vector<int>& shape)
    : shape(shape)
{
    int totalSize = getTotalSize(shape);

    data.resize(totalSize, 0.0f);
}

int Tensor::getTotalSize(const std::vector<int>& shape) const
{
    int totalSize = 1;

    for (int dim : shape)
    {
        if (dim <= 0)
        {
            throw std::invalid_argument(
                "Tensor dimensions must be positive");
        }

        totalSize *= dim;
    }

    return totalSize;
}

int Tensor::getFlatIndex(
    const std::vector<int>& indices
) const
{
    if (indices.size() != shape.size())
    {
        throw std::invalid_argument(
            "Incorrect number of indices");
    }

    int flatIndex = 0;
    int stride = 1;

    for (int i = static_cast<int>(shape.size()) - 1;
         i >= 0;
         i--)
    {
        if (indices[i] < 0 ||
            indices[i] >= shape[i])
        {
            throw std::out_of_range(
                "Tensor index out of range");
        }

        flatIndex += indices[i] * stride;
        stride *= shape[i];
    }

    return flatIndex;
}

const std::vector<int>& Tensor::getShape() const
{
    return shape;
}

int Tensor::size() const
{
    return static_cast<int>(data.size());
}

void Tensor::reshape(
    const std::vector<int>& newShape)
{
    int newSize = getTotalSize(newShape);

    if (newSize != size())
    {
        throw std::invalid_argument(
            "Cannot reshape tensor: total number of elements must remain the same");
    }

    shape = newShape;
}

bool Tensor::sameShape(
    const Tensor& other) const
{
    return shape == other.shape;
}

Tensor Tensor::operator+(
    const Tensor& other) const
{
    if (!sameShape(other))
    {
        throw std::invalid_argument(
            "Tensor shapes must match for addition");
    }

    Tensor result(shape);

    for (int i = 0; i < size(); i++)
    {
        result[i] = data[i] + other[i];
    }

    return result;
}

Tensor Tensor::operator-(
    const Tensor& other) const
{
    if (!sameShape(other))
    {
        throw std::invalid_argument(
            "Tensor shapes must match for subtraction");
    }

    Tensor result(shape);

    for (int i = 0; i < size(); i++)
    {
        result[i] = data[i] - other[i];
    }

    return result;
}

Tensor Tensor::operator*(
    float scalar) const
{
    Tensor result(shape);

    for (int i = 0; i < size(); i++)
    {
        result[i] = data[i] * scalar;
    }

    return result;
}

float& Tensor::operator[](int index)
{
    if (index < 0 ||
        index >= size())
    {
        throw std::out_of_range(
            "Tensor index out of range");
    }

    return data[index];
}

float Tensor::operator[](int index) const
{
    if (index < 0 ||
        index >= size())
    {
        throw std::out_of_range(
            "Tensor index out of range");
    }

    return data[index];
}

float& Tensor::at(
    const std::vector<int>& indices)
{
    return data[getFlatIndex(indices)];
}

float Tensor::at(
    const std::vector<int>& indices) const
{
    return data[getFlatIndex(indices)];
}


Tensor Tensor::matmul(const Tensor& other) const
{
    if (shape.size() != 2 || other.shape.size() != 2)
    {
        throw std::invalid_argument(
            "Tensor matmul currently supports only 2D tensors");
    }

    int rowsA = shape[0];
    int colsA = shape[1];

    int rowsB = other.shape[0];
    int colsB = other.shape[1];

    if (colsA != rowsB)
    {
        throw std::invalid_argument(
            "Invalid dimensions for tensor matrix multiplication");
    }

    Tensor result({rowsA, colsB});

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            float sum = 0.0f;

            for (int k = 0; k < colsA; k++)
            {
                sum += at({i, k}) * other.at({k, j});
            }

            result.at({i, j}) = sum;
        }
    }

    return result;
}


void Tensor::printShape() const
{
    std::cout << "Shape: (";

    for (size_t i = 0;
         i < shape.size();
         i++)
    {
        std::cout << shape[i];

        if (i + 1 != shape.size())
        {
            std::cout << ", ";
        }
    }

    std::cout << ")\n";
}