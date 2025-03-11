#include "../utils/common.hpp"
/* 键值对 */
struct Pair{
public:
    int key;
    std::string val;
    Pair(int key, std::string val):key(key), val(val){}
};

/* 基于数组实现的哈希表 */

class ArrayHashMap{
private:
    std::vector<Pair *> buckets;
public:
    ArrayHashMap(){
        // 初始化数组，包含100个桶
        buckets = std::vector<Pair *>(100);
    }
    ~ArrayHashMap(){
        for(const auto bucket : buckets){
            delete bucket;
        }
        buckets.clear();
    }

    /* 哈希函数 */
    int hashFunc(int key){
        return key % 100;
    }
    /* 查询操作 */
    std::string get(int key){
        int index = hashFunc(key);
        Pair *pair = buckets[index];
        if(pair == nullptr){
            return "";
        }
        return pair->val;
    }
    /* 添加操作 */
    void put(int key, std::string val){
        int index = hashFunc(key);
        Pair *pair = new Pair(key, val);
        buckets[index] = pair;
    }
    /* 删除操作 */
    void remove(int key){
        int index = hashFunc(key);
        delete buckets[index];
        buckets[index] = nullptr;
    }
    /* 获取所有键值对 */
    std::vector<Pair *> pairSet(){
        std::vector<Pair *> pairSet;
        for (Pair *pair : buckets){
            if(pair != nullptr){    // 因为哈希表不是连续存储
                pairSet.push_back(pair);
            }
            
        }
        return pairSet;
    }
    /* 获取所有键 */
    std::vector<int> keySet(){
        std::vector<int> keySet;
        for(Pair *pair : buckets){
            if(pair != nullptr){
                keySet.push_back(pair->key);
            }
            
        }
        return keySet;
    }
    /* 获取所有值 */
    std::vector<string> valueSet(){
        std::vector<string> valueSet;
        for(Pair *pair : buckets){
            if(pair != nullptr){
                valueSet.push_back(pair->val);
            }
            
        }
        return valueSet;
    }
    /* 打印哈希表 */
    void  print(){
        for(Pair *kv : pairSet()){
            std::cout << kv->key << "->" << kv->val << endl;
        }
    }
};