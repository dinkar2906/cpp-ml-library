#include "../include/linear.h"

Linear::Linear(
    int inFeatures,
    int outFeatures
)
    : weights({inFeatures, outFeatures}),
      bias({1, outFeatures}),
      inFeatures(inFeatures),
      outFeatures(outFeatures)
{
    weights.randomize(-0.1f, 0.1f);
    bias.randomize(-0.1f, 0.1f);
}

Tensor Linear::forward(
    const Tensor& input
) const
{
    Tensor output =
        input.matmul(weights);

    output = output + bias;

    return output;
}