#include <vector>
#include <string>
#include <cmath>

using namespace std;


class PrimeDecomp
{
private:
    static vector<int> primes(int size)
    {
        vector<int> a;
        a.resize(size+1);
        for (int i = 2; i * i <= size; i++)
            if (a[i] == 0)
                for (int k = i * i; k <= size; k += i)
                    a[k] = 1;
        return a;
    }


    static string createForm(int x, int power)
    {
        if (power == 1) return "(" + to_string(x) + ")";
        return "(" + to_string(x) + "**" + to_string(power) + ")";
    }


public:
    static std::string factors(const int x)
    {
        string result = "";
        int last = x;
        vector<int> pr = primes(sqrt(x));
        for (int i = 2; i < pr.size(); i++)
        {
            if (pr[i] == 0)
            {
                int temp = x;
                int j = 0;
                for (; temp % i == 0; temp/=i, j++);
                if (j == 0) continue;
                result += createForm(i, j);
                for (int n = 0; n < j; n++) last /= i;
            }
        }
        if(last!=1)
        result += createForm(last, 1);
        return result;
    }
};
