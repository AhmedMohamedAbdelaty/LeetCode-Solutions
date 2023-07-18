class LRUCache {
    int cap;
    list<int> l;
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> pos;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end()) {
            l.erase(pos[key]);
            l.push_front(key);
            pos[key] = l.begin();
            return mp[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end()) {
            l.erase(pos[key]);
            l.push_front(key);
            pos[key] = l.begin();
            mp[key] = value;
        } else {
            if (l.size() == cap) {
                int last = l.back();
                l.pop_back();
                mp.erase(last);
                pos.erase(last);
            }
            l.push_front(key);
            pos[key] = l.begin();
            mp[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */