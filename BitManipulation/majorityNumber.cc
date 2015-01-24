#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &num)
    {
        std::vector<int> result, zero, one;
        result = num;
        n2 = num.size() / 2;
        for(int i = 0; i != sizeof(int) * 8; i++)
        {
            int mask = 1 << i;
            one.clear();
            zero.clear();
            for(vector<int>::const_iterator iter = result.begin();
                iter != result.end(); iter++)
            {
                if( *iter & mask )
                    one.push_back(*iter);
                else
                    zero.push_back(*iter);
            }
            //result.clear();
            result = one.size() > zero.size() ? one : zero;
        }
        return one.size() > zero.size() ? one[0] : zero[0];
    }
};

int main()
{
    int l[] = {1,2,3,4,4,4,4};
    vector<int> list(l, l + sizeof(l) / sizeof(l[0]));
    Solution sl;
    std::cout << sl.majorityElement(list) << std::endl;
    return 0;
}