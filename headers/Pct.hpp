#pragma once

#include <cmath>
#include <vector>
#include <numeric>

#include "statistics.hpp"
#include <vector>
#include <algorithm>
#include <sstream>

class Pct : public IStatistics
{
public:
    Pct() : vect{}, num{}, number{}
    {
    }

    Pct(double procent) : procent{procent}
    {
    }

    void update(double next) override
    {
        vect.push_back(next);
    }

    double eval() override
    {
        num = round((procent / 100) * vect.size() + 0.5);

        // O (N+)
        std ::nth_element(vect.begin(), vect.begin() + num, vect.end(),
                          [](const double a, const double b)
                          {
                              return a < b;
                          });

        return vect[num - 1];
        ;
    }

    const char *name() const override
    {
        std ::stringstream ss;
        ss << "pct";
        ss << procent;
        const char *str = ss.str().c_str();
        return str;
    }

    ~Pct() = default;

private:
    double procent;
    size_t num;
    double number;
    std ::vector<double> vect;
};