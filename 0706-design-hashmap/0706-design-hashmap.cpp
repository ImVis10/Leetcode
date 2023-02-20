class MyHashMap {
    vector<list<pair<int, int>>> map;
    int SIZE = 999;
public:
    MyHashMap() {
        map.resize(SIZE);
    }
    
    int hash(int key) {
        return key % map.size();
    }
    
    void put(int key, int value) {
        int pos = hash(key);
        auto& list = map[pos];
        
        for(auto &record : list) {
            if (record.first == key) {
                record.second = value;
                return;
            }
        }
        list.push_back({key, value});
    }
    
    int get(int key) {
        int pos = hash(key);
        auto& list = map[pos];
        for(auto record : list) {
            if (record.first == key) {
                return record.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int pos = hash(key);
        auto& list = map[pos];
        
        for(auto record : list) {
            if (record.first == key) {
                list.remove(record);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */