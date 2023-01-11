class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (map.count(key) == 0) { // if key is not present in the map
            return "";
        }
        
        int low = 0, high = map[key].size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (timestamp < map[key][mid].second) {
                high = mid - 1;
            } else if (timestamp > map[key][mid].second) {
                low = mid + 1;
            } else {
                return map[key][mid].first;
            }
        }
        
        if (high >= 0 && low > high) {
            return map[key][high].first;
        }
        
        return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */