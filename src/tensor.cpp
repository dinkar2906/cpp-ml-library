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
        totalSize *= dim;
    }

    return totalSize;
}

const std::vector<int>& Tensor::getShape() const
{
    return shape;
}

int Tensor::size() const
{
    return data.size();
}

float& Tensor::operator[](int index)
{
    if (index < 0 || index >= size())
    {
        throw std::out_of_range("Tensor index out of range");
    }

    return data[index];
}

float Tensor::operator[](int index) const
{
    if (index < 0 || index >= size())
    {
        throw std::out_of_range("Tensor index out of range");
    }

    return data[index];
}

void Tensor::printShape() const
{
    std::cout << "Shape";

    for (size_t i = 0; i < shape.size(); i++)
    {
        std::cout << shape[i];

        if (i + 1 != shape.size())
        {
            std::cout << ", ";
        }
    }

    std::cout << ")\n";
}