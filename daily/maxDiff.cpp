#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxDifference(string s) {

        int lowestEven = s.length() + 1;
        int highestOdd = 0;

        unordered_map <char,int> um;
        for (int i = 0; i < s.length(); i++){
            if (um.count(s[i]) == 0){
                um[s[i]] = 1;
            }
            else{
                um[s[i]] = um[s[i]] + 1;
            }
        }
        for (auto i = um.begin(); i!=um.end();i++){
            if (i->second % 2 == 0){
                if (i->second < lowestEven){
                    lowestEven = i->second;
                }
            }
            else{
                if (i->second > highestOdd){
                    highestOdd = i->second;
                }
            }
        }
        int diff = highestOdd - lowestEven;
        if (lowestEven == s.length() + 1 || highestOdd == 0){
            return -1;
        }
        return diff;
    }
};