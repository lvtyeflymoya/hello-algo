#include "../utils/common.hpp"
/* 基于环形数组实现的队列 */
class ArrayQueue {
private:
    int *nums;      // 用于存储队列元素的数组
    int front;      // 队首指针，指向队首元素
    int queSize;    // 队列长度
    int queCapacity;// 队列容量
public:
    ArrayQueue(int capacity) {
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    }

    ~ArrayQueue() {
        delete[] nums;
    }


    /* 获取队列的容量 */
    int capacity() {
        return queCapacity;
    }
    /* 获取队列的长度 */
    int size() {
        return queSize;
    }
    /* 判断队列是否为空 */
    bool isEmpty() {
        return queSize == 0;
    }
    /* 入队 */
    void push(int num) {
        if (queSize == queCapacity) {
            cout << "队列已满" << endl;
            return;
        }
        // rear越过数组尾部后回到头部
        int rear = (front + queSize) % queCapacity;
        nums[rear] = num;
        queSize++;
    }
    /* 出队 */
    int pop() {
        int num = peek();
        front = (front + 1) % queCapacity;
        queSize--;
        return num;
    }
    /* 访问队首元素 */
    int peek() {
        if (isEmpty())
            throw out_of_range("队列为空");
        return nums[front];
    }
    /* 将数组转化为 Vector 并返回 */
    std::vector<int> toVector() {
        vector<int> res(queSize);
        for(int i = 0, j = front; i < queSize; i++, j++) {
            res[i] = nums[j % queCapacity];
        }
        return res;
    }
};

/* Driver Code */
int main() {
    /* 初始化队列 */
    int capacity = 10;
    ArrayQueue *queue = new ArrayQueue(capacity);

    /* 元素入队 */
    queue->push(1);
    queue->push(3);
    queue->push(2);
    queue->push(5);
    queue->push(4);
    cout << "队列 queue = ";
    printVector(queue->toVector());

    /* 访问队首元素 */
    int peek = queue->peek();
    cout << "队首元素 peek = " << peek << endl;

    /* 元素出队 */
    peek = queue->pop();
    cout << "出队元素 pop = " << peek << "，出队后 queue = ";
    printVector(queue->toVector());

    /* 获取队列的长度 */
    int size = queue->size();
    cout << "队列长度 size = " << size << endl;

    /* 判断队列是否为空 */
    bool empty = queue->isEmpty();
    cout << "队列是否为空 = " << empty << endl;

    /* 测试环形数组 */
    for (int i = 0; i < 10; i++) {
        queue->push(i);
        queue->pop();
        cout << "第 " << i << " 轮入队 + 出队后 queue = ";
        printVector(queue->toVector());
    }

    // 释放内存
    delete queue;

    return 0;
}
