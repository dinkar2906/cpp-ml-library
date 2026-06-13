#pragma once

#include <vector>

class Tensor
{
private:
    std::vector<int> shape;
    std::vector<float> data;

public:
    Tensor(const std::vector<int>& shape);

    int size() const;

    const std::vector<int>& getShape() const;
};