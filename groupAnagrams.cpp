#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, int>um;
        int index = 0;
        vector<vector<string>> toret;
        for (int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if (um.find(s) == um.end()){
                um[s] = index;
                vector<string> toapp = {strs[i]};
                toret.push_back(toapp);
                index++;
            }
            else{
                toret[um[s]].push_back(strs[i]);
            }
        }
        return toret;
    }
};
