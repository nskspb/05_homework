#pragma once

#include <cmath>
#include <vector>
#include <numeric>

#include "statistics.hpp"
#include <vector>
#include <algorithm>

class Pct95 : public IStatistics
{
public:
    Pct95() : pct95{}, vect{}
    {
    }

    void update(double next) override
    {
        vect.push_back(next);
        num = round(0.95 * vect.size() + 0.5);

        /*std::sort(vect.begin(), vect.end(),
                  [](const double a, const double b)
                  {
                      return a < b;
                  });*/

        std ::nth_element(vect.begin(), vect.begin() + num, vect.end(),
                          [](const double a, const double b)
                          {
                              return a < b;
                          });

        pct95 = vect[num - 1];
    }

    double eval() const override
    {
        return pct95;
    }

    const char *name() const override
    {
        return "pct95";
    }

    ~Pct95() = default;

private:
    size_t num;
    double pct95;
    std ::vector<double> vect;
};