#include <vector>
using namespace std;
std::vector<int> solution(std::vector<int> a)
{
    for(bool NotSorted = 1;NotSorted;)
        {
            NotSorted = 0;
            for(int i = 0; i < a.size()-1; i++)
            {
                if(a[i]>a[i+1])
                {
                    NotSorted = 1;
                    int temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
        }
    return a;
}