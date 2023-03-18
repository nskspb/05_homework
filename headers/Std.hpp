#pragma once

#include <cmath>
#include <vector>
#include <numeric>

#include "statistics.hpp"

class Std : public IStatistics
{
public:
    Std() : sko{}, mean{}, vect{}
    {
    }

    void update(double next) override
    {
        sko = 0;
        vect.push_back(next);
    }

    double eval() override
    {
        mean = std::accumulate(vect.begin(), vect.end(), 0) / vect.size();
        for (size_t i = 0; i < vect.size(); ++i)
        {
            sko += pow((vect[i] - mean), 2);
        }
        return sqrt(sko / vect.size());
    }

    const char *name() const override
    {
        return "std";
    }

    ~Std() = default;

private:
    double sko;
    double mean;
    std ::vector<double> vect;
};