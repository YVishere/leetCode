#include "bits/stdc++.h"
#include <cmath>
using namespace std;
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        unordered_map <int, pair<int,int>> um;
        if (grid[0][0] !=0 ){ return false;}
        int n = grid[0].size();

        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                um[grid[i][j]] = pair<int,int>{i,j};
            }
        }

        for (int i = 1; i < n*n; i++){
            int x = abs(um[i].first - um[i-1].first);
            int y = abs(um[i].second - um[i-1].second);

            if (!((x==1 && y==2) || (x==2 && y==1) )){
                return false;
            }
        }
        
        return true;
    }
};