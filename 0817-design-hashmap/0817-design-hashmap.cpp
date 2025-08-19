class MyHashMap {
public:
    int M;
    vector<list<pair<int,int>>>arr;
    MyHashMap() {
        M = 12000;
        arr.resize(M,list<pair<int,int>>{});
    }
    
    int getIndex(int key){
        return key%M;
    }

    void put(int key, int val) {
        int index = getIndex(key);
        auto &bucket = arr[index];

        auto it = arr[index].end();
        for(auto iter = bucket.begin();iter!=bucket.end();iter++){
            if(iter->first == key){
                it = iter;
                break;
            }
        }
        if(it == bucket.end()){
            bucket.push_back({key,val});
        }else{
            it->second = val;
        }
    }
    
    int get(int key) {
        int index = getIndex(key);
        auto &bucket = arr[index];

        auto it = arr[index].end();
        for(auto iter = bucket.begin();iter!=bucket.end();iter++){
            if(iter->first == key){
                it = iter;
                break;
            }
        }
        if(it == bucket.end()){
            return -1;
        }else{
            return it->second;
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto &bucket = arr[index];

        auto it = arr[index].end();
        for(auto iter = bucket.begin();iter!=bucket.end();iter++){
            if(iter->first == key){
                it = iter;
                break;
            }
        }
        if(it != bucket.end()){
            bucket.erase(it);
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