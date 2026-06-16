#ifndef TENSOR_H
#define TENSOR_H

#include <vector>

class Tensor
{
private:
    std::vector<int> shape;
    std::vector<float> data;

    int getTotalSize(const std::vector<int>& shape) const;

public:
    Tensor(const std::vector<int>& shape);

    const std::vector<int>& getShape() const;

    int size() const;

    void reshape(const std::vector<int>& newShape);

    bool sameShape(const Tensor& other) const;

    Tensor operator+(const Tensor& other) const;


    Tensor operator-(const Tensor& other) const;

    Tensor operator*(float scalar) const;


    float& operator[](int index);

    float operator[](int index) const;


    void printShape() const;
};

#endif