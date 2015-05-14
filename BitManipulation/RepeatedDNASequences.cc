//
// Created by WeiZhang on 5/10/15.
//

#ifndef LEETCODE_REPEATEDDNASEQUENCES_H
#define LEETCODE_REPEATEDDNASEQUENCES_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hmap;
        vector<string> result;
        string str;
        int intForStr = 0;
        int tmp = 0;
        if(s.size() < 10)
            return result;
        for(int i = 0; i < s.size() - 9; i++){
            str = s.substr(i, 10);
            intForStr = 0;
            for(int j = 0; j < str.size(); j++){
                switch(str[j]){
                    case 'A':
                        intForStr |= (0 << 2 * j);
                        break;
                    case 'C':
                        intForStr |= (1 << 2 * j);
                        break;
                    case 'G':
                        intForStr |= (2 << 2 * j);
                        break;
                    case 'T':
                        intForStr |= (3 << 2 * j);
                        break;
                }
            }
            if(hmap.find(intForStr) != hmap.end())
                hmap[intForStr]++;
            else{
                hmap.insert(pair<int, int>(intForStr, 1));
            }
        }
        for(unordered_map<int, int>::iterator it = hmap.begin(); it != hmap.end(); it++){
            if(it->second > 1) {
                str.clear();
                intForStr = 0;
                tmp = it->first;
                for (int i = 0; i < 10; i++) {
                    intForStr = tmp & 3;
                    tmp >>= 2;
                    switch(intForStr){
                        case 0:
                            str += 'A';
                            break;
                        case 1:
                            str += 'C';
                            break;
                        case 2:
                            str += 'G';
                            break;
                        case 3:
                            str += 'T';
                            break;
                    }
                }
                result.push_back(str);
            }
        }
        return result;
    }
};
#endif //LEETCODE_REPEATEDDNASEQUENCES_H
