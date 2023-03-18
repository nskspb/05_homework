#pragma once

#include "statistics.hpp"

class Mean : public IStatistics
{
public:
    Mean() : sum{}, count{}
    {
    }

    void update(double next) override
    {
        sum += next;
        count++;
    }

    double eval() override
    {
        return (sum / count);
    }

    const char *name() const override
    {
        return "mean";
    }

    ~Mean() = default;

private:
    double sum;
    double count;
};
