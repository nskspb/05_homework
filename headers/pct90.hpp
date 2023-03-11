#pragma once

#include <cmath>
#include <vector>
#include <numeric>

#include "statistics.hpp"
#include <vector>
#include <algorithm>

class Pct90 : public IStatistics
{
public:
    Pct90() : pct90{}, vect{}, num{}, number{}
    {
    }

    void update(double next) override
    {
        vect.push_back(next);
        num = round(0.9 * vect.size() + 0.5);

        // O(n*logn)

        /*std::sort(vect.begin(), vect.end(),
                  [](const double a, const double b)
                  {
                      return a < b;
                  });*/

        // O (N+)
        std ::nth_element(vect.begin(), vect.begin() + num, vect.end(),
                          [](const double a, const double b)
                          {
                              return a < b;
                          });

        pct90 = vect[num - 1];
    }

    double eval() const override
    {
        return pct90;
    }

    const char *name() const override
    {
        return "pct90";
    }

    ~Pct90() = default;

private:
    size_t num;
    double number;
    double pct90;
    std ::vector<double> vect;
};