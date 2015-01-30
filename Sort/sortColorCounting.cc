#include <iostream>

class Solution
{
public:
    void sortColor(int A[], int n)
    {
        int Counting[3] = {0};
        for(int i = 0; i < n; i++)
        {
            Counting[A[i]]++;
        }
        int insert = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < Counting[i]; j++)
            {
                A[insert] = i;
                insert++;
            }
        }
    }
};

int main()
{
    int A[] = {2,0};
    Solution sl;
    sl.sortColor(A, sizeof(A)/sizeof(A[0]));
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        std::cout << A[i] << std::endl;
    return 0;
}