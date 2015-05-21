#include <iostream>

class Solution
{
public:
    void sortColor(int A[], int n)
    {
        int zero = -1, one = 0, two = n;
        while(one < two)
        {
            if(A[one] == 0)
                swap(A[one++], A[++zero]);
            else if(A[one] == 2)
                swap(A[one], A[--two]);
            else
                one++;
        }

    }
    void swap(int &a, int &b)
    {
            int temp = a;
            a = b;
            b = temp;
    }
};

int main()
{
    int A[] = {2};
    Solution sl;
    sl.sortColor(A, sizeof(A)/sizeof(A[0]));
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        std::cout << A[i] << std::endl;
    return 0;
}
