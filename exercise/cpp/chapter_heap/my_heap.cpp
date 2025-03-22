#include "../utils/common.hpp"
#include <algorithm>

class MaxHeap{
private:
    vector<int> maxHeap;

    int left(int index){
        return 2 * index + 1;
    }

    int right(int index){
        return 2 * index + 2;
    }

    int parent(int index){
        return (index - 1) / 2;
    }

    
    /* 从节点 i 开始，从底至顶堆化 */
    void siftUp(int idx){
        while(true){
            int p = parent(idx);
            if(p < 0 || maxHeap[idx] <= maxHeap[p])
                break;
            swap(maxHeap[idx], maxHeap[p]);
            idx = p;
        }
    }

    /* 从节点 i 开始，从顶至底堆化 */
    void siftDown(int i){
        while (true)
        {
            int l = left(i), r = right(i), ma = i;
            if (l < size() && maxHeap[l] > maxHeap[ma])
                ma = l;
            if (r < size() && maxHeap[r] > maxHeap[ma])
                ma = r;
            if (ma = i)
                break;
            swap(maxHeap[i], maxHeap[ma]);
            i = ma;
        }
        
    }

    
public:
    /* 构造方法，根据输入列表建堆 */
    MaxHeap(vector<int> nums) {
        // 将列表元素原封不动添加进堆
        maxHeap = nums;
        // 堆化除叶节点以外的其他所有节点
        for (int i = parent(size() - 1); i >= 0; i--) {
            siftDown(i);
        }
    }

    // 修改返回类型为 size_t
    int size(){
        return maxHeap.size();
    }

    /* 判断堆是否为空 */
    bool isEmpty() {
        return size() == 0;
    }

    int peek(){
        return maxHeap[0];
    }

    void push(int num){
        maxHeap.push_back(num);
        siftUp(size() - 1);
    }

   

    /* 元素出堆 */
    int pop(){
        // 判空处理
        if (maxHeap.empty()){
            throw out_of_range("堆为空");
        }
        swap(maxHeap[0], maxHeap[size() - 1]);
        maxHeap.pop_back();
        siftDown(0);
    }


    /* 打印堆（二叉树）*/
    void print() {
        cout << "堆的数组表示：";
        printVector(maxHeap);
        cout << "堆的树状表示：" << endl;
        TreeNode *root = vectorToTree(maxHeap);
        printTree(root);
        freeMemoryTree(root);
    }
};
/* Driver Code */
int main() {
    /* 初始化大顶堆 */
    vector<int> vec{9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2};
    MaxHeap maxHeap(vec);
    cout << "\n输入列表并建堆后" << endl;
    maxHeap.print();

    /* 获取堆顶元素 */
    int peek = maxHeap.peek();
    cout << "\n堆顶元素为 " << peek << endl;

    /* 元素入堆 */
    int val = 7;
    maxHeap.push(val);
    cout << "\n元素 " << val << " 入堆后" << endl;
    maxHeap.print();

    /* 堆顶元素出堆 */
    peek = maxHeap.peek();
    maxHeap.pop();
    cout << "\n堆顶元素 " << peek << " 出堆后" << endl;
    maxHeap.print();

    /* 获取堆大小 */
    int size = maxHeap.size();
    cout << "\n堆元素数量为 " << size << endl;

    /* 判断堆是否为空 */
    bool isEmpty = maxHeap.isEmpty();
    cout << "\n堆是否为空 " << isEmpty << endl;

    return 0;
}

