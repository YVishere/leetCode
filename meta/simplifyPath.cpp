#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        list <string> name;
        int count = -1;
        string toBuild = "";
        for (int i = 0; i <= path.length(); i++){
            if (path[i] == '/' || i == path.length()){
                if (toBuild == ".."){
                    if (name.size() == 0){
                        toBuild="";
                        continue;
                    }
                    name.pop_back();
                    count--;
                    count--;
                    toBuild = "";
                    continue;
                }
                if (toBuild == "."){
                    count--;
                    toBuild = "";
                    continue;
                }
                if (toBuild == ""){
                    count++;
                    continue;
                }
                name.push_back(toBuild);
                toBuild = "";
                count++;
                continue;
            }
            toBuild.push_back(path[i]);
        }
        string toRet = "";
        if (name.size() == 0){
            return "/";
        }
        
        for (auto i = name.begin(); i != name.end(); ++i){
            toRet += "/";
            toRet += *i;
        }
        return toRet;
    }
};