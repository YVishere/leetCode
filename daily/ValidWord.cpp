#include <cctype>
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3){
            return false;
        }

        bool hasVowel = false;
        bool hasConst = false;

        unordered_set <char> um = {'a','e','i','o','u'};

        for (int i =0; i<word.size(); i++){
            char g = tolower(word[i]);
            if (isdigit(g)){
                
            }
            else if (isalpha(g)){
                if(um.count(g) != 0){
                    hasVowel = true;
                }
                else{
                    hasConst = true;
                }
            }
            else{
                return false;
            }
        }

        return (hasVowel && hasConst);
    }
};