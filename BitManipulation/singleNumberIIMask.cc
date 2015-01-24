#include <iostream>

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int one, two, three;
        for( int i = 0; i != n; i++ )
        {
            two |= A[i] & one;
            one ^= A[i];
            three = two & one;
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};