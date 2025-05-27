#include <iostream>
#include <unordered_map>
#include <string>
#include <list>

class Storage{
    std::unordered_map<std::string, std::string> mpp;
    const std::size_t SIZE;

    public:

    Storage(std::size_t size) : SIZE(size) {}

    // add data
    bool addData(std::string key, std::string val) {
        if(mpp.size() < SIZE) {
            mpp[key] = val;
            return true;
        }
        
        std::cout<<"Cache overflow"<<std::endl; // need eviction
        return false;
        
    }

    // get cache
    std:: string getData(std::string key) {
        if(mpp.find(key) != mpp.end()) {
            return mpp[key];
        }else{
            std::cout<<"Key dosent exists or been evicted"<<std::endl;
        }

        return "";
    }

    bool removeData(std::string key) {
        if(mpp.find(key) != mpp.end()) {
            mpp.erase(key);
            return true;
        }

        return false;
    }
};

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next=nullptr, Node* prev=nullptr) : val(val), next(next), prev(prev) {}
};

class LinkedList {
    
};

class EvictionPolicy{
    std::list<std::string> dll;

    public:

    void add(std::string key) {
        dll.push_front(key);
    }

    void get(std::string key) {
        // pushing the key in front so it dosent get evicted
        dll.remove(key);  // TODO: Need to make it efficient form O(n) to Olog(n)/(1)
        dll.push_front(key);
    }

    std::string evict() {
        std::string evictedKey = dll.back();
        dll.pop_back();

        return evictedKey;
    }
};

class Cache final{
    Storage storage;
    EvictionPolicy evictionPolicy;

    public:

    Cache(const Storage& storage, const EvictionPolicy& evictionPolicy) : storage(storage), evictionPolicy(evictionPolicy) {}

    // set cache
    void set(std::string key, std::string value) {
        if(storage.addData(key, value)) {
            evictionPolicy.add(key);
            return;
        }

        // if need data eviction
        std::string evictedKey = evictionPolicy.evict();
        if(storage.removeData(evictedKey)) { // removal form map is successful
            storage.addData(key, value);
            evictionPolicy.add(key);
        }

    }

    // get cache
    std::string get(std::string key) {
        std:: string value = storage.getData(key);
        evictionPolicy.get(key);
        return value;
    }

};


int main() {
    Storage hdd = Storage(2);
    EvictionPolicy del = EvictionPolicy();
    Cache redis = Cache(hdd, del);

    redis.set("1", "Hello");
    std::cout<<redis.get("1")<<std::endl;
    redis.set("2", "hey");
    redis.set("3", "hola");
    std::cout<<redis.get("2")<<std::endl;
    std::cout<<redis.get("3")<<std::endl;
    std::cout<<redis.get("1")<<std::endl;
    return 0;
}