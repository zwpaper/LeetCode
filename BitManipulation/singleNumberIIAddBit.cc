#include <iostream>

class Solution {
public:
    int singleNumber(int A[], int n) {
        int count = 0;
        int length = sizeof(A[0]) * 8;
        int mask = 0;
        int result = 0;
        for( int i = 0; i != length; i++)
        {
            count = 0;
            mask = 1 << i;
            for( int j = 0; j != n; j++)
                if( mask & A[j] )
                    count++;
            result |= (count % 3) << i;
        }
        return result;
    }
};

int main()
{
    int list[] = {1,1,1,2};
    Solution sn;
    int result = sn.singleNumber(list, 4);
    std::cout << result << std::endl;
    return 0;

}