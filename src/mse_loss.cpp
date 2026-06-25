#include "../include/mse_loss.h"

#include <stdexcept>

float MSELoss::forward(
    const Tensor& prediction,
    const Tensor& target
) const
{
    if (!prediction.sameShape(target))
    {
        throw std::invalid_argument(
            "Prediction and target shapes must match");
    }

    float loss = 0.0f;

    for (int i = 0; i < prediction.size(); i++)
    {
        float diff =
            prediction[i] - target[i];

        loss += diff * diff;
    }

    return loss / prediction.size();
}