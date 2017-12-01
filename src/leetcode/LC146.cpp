#include "../../util/common.h"

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!index.count(key)) return -1;
        
        auto item = *index[key];
        data.erase(index[key]);
        index[key] = data.insert(data.end(), item);
        return item.second;
    }
    
    void put(int key, int value) {
        if (index.count(key)) {
            data.erase(index[key]);
            index[key] = data.insert(data.end(), make_pair(key, value));
        } else {
            // handle eviction first
            if (data.size() == cap) {
                auto item = data.front();
                data.pop_front();
                index.erase(item.first);
            }
            index[key] = data.insert(data.end(), make_pair(key, value));
        }
    }
private:
    typedef list<pair<int, int>> DataList;
    DataList data;
    unordered_map<int, DataList::iterator> index;
    int cap;
};