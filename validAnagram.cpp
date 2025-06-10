#include <bits/stdc++.h>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        unordered_map <char,int> um1;
        unordered_map <char,int> um2;

        for (int i = 0; i != s.length(); i++){
            if (t.find(s[i]) == t.npos){
                return false;
            }
            if (um1.find(s[i]) == um1.end()){
                um1[s[i]] = 1;
            }
            else{
                um1[s[i]] = 1+ um1[s[i]];
            }
            if (um2.find(t[i]) == um2.end()){
                um2[t[i]] = 1;
            }
            else{
                um2[t[i]] = 1+ um2[t[i]];
            }
        }
        for (int i =0; i<s.length();i++){
            if (um1[s[i]] != um2[s[i]]){
                return false;
            }
        }
        return true;
    }
};
