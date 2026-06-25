#ifndef MSE_LOSS_H
#define MSE_LOSS_H

#include "tensor.h"

class MSELoss
{
public:
    float forward(
        const Tensor& prediction,
        const Tensor& target
    ) const;
};

#endif