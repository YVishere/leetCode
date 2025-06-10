#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int>um;
        int smallest = -1;
        int smallest_index;
        vector<int> toRet;
        for (int i = 0; i<nums.size(); i++){
            int num = nums[i];

            if (um.find(num) == um.end()){
                um[num] = 1;
            }
            else{
                um[num] = um[num] + 1;
            }
        }
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        
        for (unordered_map<int,int>::iterator i = um.begin(); i!=um.end();i++){
            int num=i->first;
            int count=i->second;

            buckets[count].push_back(num);
        }

        for (int i = buckets.size()-1; i >= 0; i--){
            for (int j = buckets[i].size()-1; j >= 0; j--){
                toRet.push_back(buckets[i][j]);
                if (toRet.size() == k){
                    break;
                }
            }
            if (toRet.size() == k){
                break;
            }
        }
        return toRet;
    }
};
