class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        int low = 0, high = mp[key].size() - 1;
        string val = "";
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mp[key][mid].second > timestamp) high = mid - 1;
            else {
                low = mid + 1;
                val = mp[key][mid].first;
            }
        }
        return val;
    }
private:
    unordered_map<string, vector<pair<string, int>>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */