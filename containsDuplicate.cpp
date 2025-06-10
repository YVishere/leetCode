#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for (int i = 0; i < nums.size(); i++){
            if (um.find(nums[i])==um.end()){
                um[nums[i]] = 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
