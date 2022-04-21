class MyHashSet {
public:
    /** Initialize your data structure here. */
    int arr[1000001];
    MyHashSet(){
        memset(arr,false,sizeof(arr));
    }
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return arr[key];
    }
};