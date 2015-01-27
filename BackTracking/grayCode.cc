#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    vector<int> grayCode(int n)
    {
        int mask;
        vector<int> result;
        result.push_back(0);
        for( int i = 0; i < n; i++ ) 
        {
            mask = 1 << i;
            for(int j = result.size() - 1; j >= 0; j--)
            {
                result.push_back( result[j] + mask );
            }
        }
        return result;
    }
};

int main()
{
    solution sl;
    std::vector<int> v;
    v = sl.grayCode(3);
    for( int i = 0; i != v.size(); i++)
        cout << v[i] << endl;
    return 0;
}