#ifndef TENSOR_H
#define TENSOR_H

#include <vector>

class Tensor
{
private:
    std::vector<int> shape;
    std::vector<float> data;

    int getTotalSize(const std::vector<int>& shape) const;

    int getFlatIndex(
        const std::vector<int>& indices
    ) const;

public:
    Tensor(const std::vector<int>& shape);

    const std::vector<int>& getShape() const;

    int size() const;

    float& at(
        const std::vector<int>& indices
    );

    float at(
        const std::vector<int>& indices
    ) const;


    void reshape(const std::vector<int>& newShape);

    void randomize(float min, float max);

    bool sameShape(const Tensor& other) const;

    Tensor operator+(const Tensor& other) const;

    
    Tensor operator-(const Tensor& other) const;
    
    Tensor operator*(float scalar) const;
    
    Tensor matmul(const Tensor& other) const;

    float& operator[](int index);

    float operator[](int index) const;


    void printShape() const;
};

#endif