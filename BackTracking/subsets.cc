//
// Created by zwPapEr on 5/9/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sets;
        result.push_back(sets);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            generater(result, nums, sets, i);
        return result;
    }
    void generater(vector<vector<int>> &output, vector<int> &resource, vector<int> sub, int index){
        if(index >= resource.size())
            return;
        sub.push_back(resource[index]);
        output.push_back(sub);
        for(int i = index + 1; i < resource.size(); i++){
            generater(output, resource, sub, i);
        }


    }
};