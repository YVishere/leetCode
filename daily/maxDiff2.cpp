//This solution exceeded time limit
//Need to do some prefix partiy type shi

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxDifference(string s, int k) {
        int max_diff = INT_MIN;
        int diff = 0;

        for (int w = k; w <= s.length(); w++){
            int um[5] = {0};
            
            for (int i = 0; i < w; i++){
                int ind = s[i] - '0';
                um[ind]++;
            }
            
            int highestOdd = 0;
            int lowestEven = s.length()+1;
            for (int i = 0; i < 5; i++){
                
                if (um[i] != 0 && um[i]%2==0 && um[i]<lowestEven){
                    lowestEven = um[i];
                }
                if(um[i]%2!=0 && um[i]>highestOdd){
                    highestOdd = um[i];
                }
            }
            if (highestOdd!=0 && lowestEven!=s.length()+1 && lowestEven != 0){
                diff = highestOdd - lowestEven;
                if (diff > max_diff){
                    max_diff = diff;
                }
            }
            int j = w;
            while(j < s.length()){
                int ind = s[j-w] - '0';
                int ind2 = s[j] - '0';
                um[ind]--;
                um[ind2] += 1;
                j++;
                
                int highestOdd = 0;
                int lowestEven = s.length()+1;
                for (int i = 0; i <5; i++){
                    if (um[i] != 0 && um[i]%2==0 && um[i]<lowestEven){
                        lowestEven = um[i];
                    }
                    if(um[i]%2!=0 && um[i]>highestOdd){
                        highestOdd = um[i];
                    }
                }
                if (highestOdd!=0 && lowestEven!=s.length()+1 && lowestEven != 0){
                    diff = highestOdd - lowestEven;
                    if (diff > max_diff){
                        max_diff = diff;
                    }
                }
            }
        }
        return max_diff;
    }
};