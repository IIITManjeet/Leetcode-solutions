class MyHashSet {
    vector<bool>s;
public:
    MyHashSet() {
        s=vector<bool>(1000001,false);
    }
    
    void add(int key) {
        s[key]=true;
    }
    
    void remove(int key) {
        s[key]=false;
    }
    
    bool contains(int key) {
        return s[key]==true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */