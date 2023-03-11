#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <math.h>

namespace sort_vectors
{

    void example()
    {

        std ::vector<double> vect;

        vect.push_back(10);
        vect.push_back(9);
        vect.push_back(8);
        vect.push_back(7);
        vect.push_back(6);
        vect.push_back(5);
        vect.push_back(4);
        vect.push_back(3);
        vect.push_back(2);
        vect.push_back(1);

        for (int i = 0; i < vect.size(); ++i)
        {
            std ::cout << vect[i] << "  ";
        }

        std ::cout << std ::endl;

        /*std::sort(vect.begin(), vect.end(),
                  [](const double a, const double b)
                  {
                      return a < b;
                  });*/

        size_t num = 3;

        std ::cout << "num = " << num << std ::endl;
        std ::nth_element(vect.begin(), vect.begin() + num, vect.end(),
                          [](const double a, const double b)
                          {
                              return a < b;
                          });

        for (int i = 0; i < vect.size(); ++i)
        {
            std ::cout << vect[i] << "  ";
        }

        std ::cout << std ::endl;
    }
}
namespace vectors
{

    void example()
    {

        std ::vector<std ::string> ivector = {"hi", ", i'm ", "Ruslan"};

        std ::vector<std ::string> ivector2 = {"hi", ", i'm ", "Ruslan"};

        std ::cout << "razmer = " << ivector.size() << std ::endl;
        ivector.resize(3);
        ivector.push_back(" Albertovich");

        ivector.push_back(ivector.back());
        std ::cout << "razmer = " << ivector.size() << std ::endl;
        std ::vector<std ::vector<int>> vec;
        // vec.resize(10);  // десять векторов
        vec.push_back(std ::vector<int>());

        // ivector.push_back(ivector2);

        for (int i = 0; i < ivector.size(); ++i)
        {
            std ::cout << ivector[i];
        }

        // ivector.pop_back();

        ivector2.insert(ivector2.end(), " Albertovich");
        ivector2.push_back(" Albertovich");
        if (ivector2 == ivector)
        {
            std ::cout << ivector.at(1);
        }

        std ::cout << std ::endl;

        double a = 5.66556456;

        float b;
        b = static_cast<float>(a);
        std ::cout << b << std ::endl;
    }

}

namespace ssylka
{
    void Foo1(int a)
    {
        a = 1;
    }

    void Foo2(int &a)
    {
        a = 2;
    }

    void Foo3(int *a)
    {
        *a = 3;
    }

    void example()
    {
        /**/ int p = 5;
        int &r = p;
        r++;
        std ::cout << "p = " << p << std ::endl;

        Foo1(p);
        std ::cout << "value1 = " << p << std ::endl;

        Foo2(p);
        std ::cout << "value1 = " << p << std ::endl;

        Foo3(&p);
        std ::cout << "value1 = " << p << std ::endl;
    }
}

namespace chrono_
{

    void example()
    {
        auto startTime = std::chrono::system_clock::now(); // текущее время
        for (int i = 0; i < 100; ++i)
        {
            vectors::example();
        }                                                // запуск алгоритма
        auto endTime = std::chrono::system_clock::now(); // текущее время
        auto milliseconds = std::chrono::duration_cast<
            std::chrono::milliseconds>(
            endTime - startTime); // получаем значение разницы в миллисекундах

        std ::cout << "Vremya =  " << milliseconds.count() << std ::endl;
    }
}
int main()
{

    // std ::string s = "hello";
    // vectors::example();

    //  chrono_::example();

    // int k = std ::string::npos;
    // ssylka::example();
    // std::cout << std::numeric_limits<double>::max();

    sort_vectors ::example();

    return 0;
}