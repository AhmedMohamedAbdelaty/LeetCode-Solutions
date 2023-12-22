class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp; // key -> {{value, timestamp}, {value, timestamp}, ...

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({ timestamp, value });
    }

    string get(string key, int timestamp)
    {
        auto it = upper_bound(mp[key].begin(), mp[key].end(), timestamp, [](int val, pair<int, string> p) {
            return val < p.first;
        }); // returns the first element in the vector that is greater than value, or last if no such element is found.

        // To handle the edge case where the given timestamp is earlier than the earliest timestamp stored for the key.
        if (it == mp[key].begin())
            return "";
        pair<int, string> p = *(it - 1);
        return p.second;
    }
    void print()
    {
        for (auto& x : mp) {
            cout << x.first << " -> ";
            for (auto& y : x.second)
                cout << "{" << y.first << ", " << y.second << "}, ";
            cout << "\n";
        }
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */