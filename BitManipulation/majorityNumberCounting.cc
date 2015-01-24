#include <iostream>
#include <vector>
using namespace std;

//Algorithm from https://github.com/roederw/interview_questions/blob/master/majorityElement/majorityElement.cpp
//remove the edge test.
//still not the best!
//Must be tested by C++11

class solution
{
public:
    int majorityNumber(vector<int> &num)
    {
        int lastNum = num[0];
        int count = 1;

        for( int i = 1; i != num.size(); i++ )
        {
            lastNum == num[i] ? count++ : count --;
            if(count == 0)
            {
                lastNum = num[i];
                count++;
            }
        }
        return lastNum;
    }
};

int main()
{
    vector<int> list{1,2,3,4,4,4,4};    
    solution sl;
    cout << sl.majorityNumber(list)<<endl;
    return 0;
}