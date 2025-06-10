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
            
            if (toRet.size() < k){
                
                if (um[num]!=1){
                    int inde =findElement(toRet, num);
                    if (inde!=-1){
                        toRet.erase(inde + toRet.begin());
                    }
                    else{
                        toRet.erase(toRet.begin());
                    }
                    toRet.push_back(num);
                }
                else{ 
                 toRet.push_back(num);
                }
            }
            else{
                int inde = findElement(toRet, num);
                if (inde != -1){
                    for (int i = inde; i < toRet.size()-1;i++){
                        if (um[toRet[i]] <= um[toRet[i+1]]){
                            break;
                        }
                        int t = toRet[i];
                        toRet[i] = toRet[i+1];
                        toRet[i+1] = t;
                    }
                    continue;
                }
                if (um[num] > um[toRet[0]]){
                    toRet.erase(toRet.begin());
                    toRet.push_back(num);
                }
            }
        }
        return toRet;
    }
private:
    int findElement(vector<int>& nums, int n){
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == n){
                return i;
            }
        }
        return -1;
    }
};
