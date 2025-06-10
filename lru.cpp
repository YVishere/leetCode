#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    int max_size;
    unordered_map <int, list<pair<int,int>>::iterator> cache;
    list <pair<int, int>> lru;
    int count;
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        if (cache.count(key) == 0){
            return -1;
        }
        else{
            lru.splice(lru.begin(), lru, cache[key]);
            
            return cache[key]->second;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key) == 1){
            cache[key]->second = value;
            lru.splice(lru.begin(), lru, cache[key]);
        }
        else{
            if (lru.size() < max_size){
                lru.push_front(pair<int, int>{key,value});
                cache[key] = lru.begin();
            }
            else{
                int old_key = lru.back().first;
                lru.pop_back();
                cache.erase(old_key);
                lru.push_front(pair<int,int> {key, value});
                cache[key] = lru.begin();
            }
        }
    }
};
