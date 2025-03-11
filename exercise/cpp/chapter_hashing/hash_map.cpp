#include "../utils/common.hpp"

int main(){
    unordered_map<int, string> map;

    map[12836] = "小哈";
    map[15937] = "小啰";
    map[16750] = "小算";
    map[13276] = "小法";
    map[10583] = "小鸭";

    string name = map[15937];
    cout << name << endl;

    map.erase(10583);

    // 遍历键值对 Key->Value
    for (auto kv : map){
        cout << kv.first << "->" << kv.second << endl;
    }

    // 使用迭代器遍历
    for (auto iter = map.begin(); iter != map.end(); iter++){
        cout << iter->first << "->" << iter->second << endl;
    }
}