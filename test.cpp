#include <iostream>
#include <vector>

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

int main()
{

    // std ::string s = "hello";
    vectors::example();

    // int k = std ::string::npos;
    // ssylka::example();

    return 0;
}