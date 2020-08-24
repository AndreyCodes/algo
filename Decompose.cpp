#include <iostream>
#include <vector>
#include <string>

using namespace std;


class PrimeDecomp
{
private:
    static vector<int> primes(int size)   //Решето Эратосфена// 0 означает, что число с данным индексом простое//
    {
        vector<int> a;
        a.resize(size+1);
        for (int i = 2; i * i <= size; i++)
            if (a[i] == 0)
                for (int k = i * i; k <= size; k += i)
                    a[k] = 1;
        return a;
    }


    static string createForm(int x, int power) //Создание формы для печати
    {
        if (power == 1) return "(" + to_string(x) + ")";
        return "(" + to_string(x) + "**" + to_string(power) + ")";
    }


public:
    static std::string factors(const int x) //Алгоритм разложение на множители
    {
        string result = "";
        vector<int> pr = primes(x);         //Решето чисел [2,x]
        for (int i = 2; i < pr.size(); i++)
        {
            if (pr[i] == 0) // пробуем каждое простое число
            {
                int temp = x;
                int j = 0; //степень простого числа
                for (; temp % i == 0; temp/=i, j++);  
                if (j == 0) continue;
                result += createForm(i, j);
            }
        }
        return result;
    }
};