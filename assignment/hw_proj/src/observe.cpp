#include "../include/config.h"
#include "../include/observe.h"
#include <random>

int observeOpponent()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1,100);
    return distrib(gen);
}