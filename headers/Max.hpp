#pragma once

#include <limits>
#include "statistics.hpp"

class Max : public IStatistics
{
public:
    Max() : m_max{std::numeric_limits<double>::lowest()}
    {
    }

    void update(double next) override
    {
        if (next > m_max)
        {
            m_max = next;
        }
    }

    double eval() override
    {
        return m_max;
    }

    const char *name() const override
    {
        return "max";
    }

    ~Max() = default;

private:
    double m_max;
};