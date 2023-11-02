class MyHashMap {
public:
    struct in_record {
        bool if_exist;
        int value;
    };
    
    MyHashMap() {
    }
    
    void put(int key, int value) {
        record[key] = {true, value};
    }
    
    int get(int key) {
        if (record[key].if_exist) {
            return record[key].value;
        } else {
            return -1;
        }
    }
    
    void remove(int key) {
        record[key].if_exist = false;
    }
private:
    struct in_record record[1000001] = {{false, 0}};;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
