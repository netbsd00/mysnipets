#include <iostream>
#include <random>

float getRandF(float min, float max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<float> uni(min, max);

    return uni(rng);
}

int getRand(int min, int max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);

    return uni(rng);
}