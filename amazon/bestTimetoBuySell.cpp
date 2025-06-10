#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int minPrice = -1;
        for (int i = 0; i < prices.size(); i++){
            if (minPrice == -1 || prices[i] < minPrice){
                minPrice = prices[i];
                continue;
            }
            int diff = prices[i] - minPrice;
            if (diff > max){
                max = diff;
            }
        }
        return max;
    }
};