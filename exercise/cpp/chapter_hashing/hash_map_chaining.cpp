#include "array_hash_map.cpp"
/* 链式地址哈希表 */
class HashMapChaining{
private:
    int size;   //键值对数量
    int capacity;   // 哈希表容量
    double loadThres;   // 负载因子阈值
    int extendRatio;    // 扩容倍数
    vector<vector<Pair *>> buckets;
public:
    HashMapChaining() : size(0), capacity(4), loadThres(2.0/3.0), extendRatio(2){
        buckets.resize(capacity);
    }

    ~HashMapChaining(){
        for(auto &bucket : buckets){
            for(Pair *pair : bucket){
                delete pair;
            }
        }
    }

    /* 哈希函数 */
    int hashFunc(int key){
        return key % capacity;
    }
    /* 负载因子 */
    double loadFactor(){
        return (double)size / (double)capacity;
    }
    /* 查询操作 */
    string get(int key){
        int index = hashFunc(key);
        for(Pair *pair : buckets[index]){
            if(pair->key == key){
                return pair->val;
            }
        }
        // 若未找到key，返回空字符串
        return "";
    }
    /* 添加操作 */
    void put(int key, string val){
        // 考虑扩容
        if (loadFactor() > loadThres){
            extend();
        }
        int index = hashFunc(key);
        for(Pair *pair : buckets[index]){
            if(pair->key == key){
                pair->val = val;
                return;
            }
        }
        buckets[index].push_back(new Pair(key, val));
        size++;
    }
    /* 删除操作 */
    void remove(int key){
        int index = hashFunc(key);
        auto &bucket = buckets[index];
        for(auto i = 0; i < bucket.size(); i++){
            if(bucket[i]->key == key){
                Pair *tmp = bucket[i];
                bucket.erase(bucket.begin() + i);
                delete tmp;
                size--;
                return;
            }
        }
    }
    /* 扩容哈希表 */
    void extend(){
        vector<vector<Pair *>> bucketstmp = buckets;
        capacity *= extendRatio;
        buckets.clear();
        buckets.resize(capacity);
        size = 0;
        for(auto i = 0; i < bucketstmp.size(); i++){
            for(Pair *pair : bucketstmp[i]){
                put(pair->key, pair->val);
                delete pair;
            }
        }
    }
    /* 打印哈希表 */
    void print(){
        for (auto &bucket : buckets){
            cout << "[";
            for (Pair *pair : bucket){
                cout << pair->key << "->" << pair->val << ",";
            }
            cout<< "]\n";
        }
    }
};
/* Driver Code */
int main() {
    /* 初始化哈希表 */
    HashMapChaining map = HashMapChaining();

    /* 添加操作 */
    // 在哈希表中添加键值对 (key, value)
    map.put(12836, "小哈");
    map.put(15937, "小啰");
    map.put(16750, "小算");
    map.put(13276, "小法");
    map.put(10583, "小鸭");
    cout << "\n添加完成后，哈希表为\nKey -> Value" << endl;
    map.print();

    /* 查询操作 */
    // 向哈希表中输入键 key ，得到值 value
    string name = map.get(13276);
    cout << "\n输入学号 13276 ，查询到姓名 " << name << endl;

    /* 删除操作 */
    // 在哈希表中删除键值对 (key, value)
    map.remove(12836);
    cout << "\n删除 12836 后，哈希表为\nKey -> Value" << endl;
    map.print();

    return 0;
}
