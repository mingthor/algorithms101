
#include "../../util/common.h"

template <class K, class V>
struct DataEntry {
    K key;
    V value;
    time_t ttl;
    time_t expiration;

    DataEntry(K k, V v, time_t live)
    : key(k), value(v), ttl(live) {
        expiration = time(0) + live;
    }
    DataEntry(const DataEntry& other)
    : key(other.key), value(other.value), ttl(other.ttl) {
        expiration = time(0) + ttl;
    }
};

template <class K, class V>
class Cache {
public:
    virtual V get(K key) = 0;
    virtual void set(K key, V value, time_t ttl) = 0;
};

template <class K, class V>
class LRUCache : public Cache<K, V> {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    V get(K key) {
        if (!index.count(key)) return -1;
        
        auto item = *index[key];
        data.erase(index[key]);
        // passive eviction of expired items
        if (item.expiration <= time(0)) {
            index.erase(key);
            return -1;
        }
        index[key] = data.insert(data.end(), DataEntry<K, V>(item));
        return item.value;
    }
    
    void set(K key, V value, time_t ttl) {
        if (index.count(key)) {
            data.erase(index[key]);
            index[key] = data.insert(data.end(), DataEntry<K, V>(key, value, ttl));
        } else {
            // handle eviction first
            if (data.size() == cap) {
                auto item = data.front();
                data.pop_front();
                index.erase(item.key);
            }
            index[key] = data.insert(data.end(), DataEntry<K, V>(key, value, ttl));
        }
    }
private:
    typedef list<DataEntry<K, V> > DataList;
    DataList data;
    unordered_map<K, typename DataList::iterator> index;
    int cap;
};

template <typename K, typename V>
class Memcache {
public:
    Memcache(int sz) {
        // do intialization if necessary
        _dataCache = new LRUCache<K, V>(sz);
    }
    ~Memcache() {
        if (_dataCache) delete _dataCache;
    }

    V get(K key) {
        // write your code here
        return _dataCache->get(key);
    }

    void set(K key, V value, time_t ttl) {
        // write your code here
        _dataCache->set(key, value, ttl);
    }

    void remove(K key) {
        // write your code here
    }
private:
    Cache<K, V>* _dataCache;
};

int main()
{
    Memcache<int, int> memcache(2);
    memcache.set(1, 1, 1);
    memcache.set(2, 2, 1);
    cout<<memcache.get(1)<<endl;

    return 0;
}