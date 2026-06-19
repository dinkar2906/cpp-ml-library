#ifndef LINEAR_H
#define LINEAR_H

#include "tensor.h"

class Linear
{
private:
    Tensor weights;
    Tensor bias;

    int inFeatures;
    int outFeatures;

public:
    Linear(
        int inFeatures,
        int outFeatures
    );

    Tensor forward(
        const Tensor& input
    ) const;
};

#endif