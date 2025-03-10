#include "../utils/common.hpp"

struct DoublyListNode {
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(int val):val(val), prev(nullptr), next(nullptr) {}
};

class LinkedListDeque{
private:
    DoublyListNode *front, *rear;
    int queSize = 0;
public:
    LinkedListDeque() {
        front = nullptr;
        rear = nullptr;
    }
    ~LinkedListDeque() {
        // 遍历链表节点，释放内存
        DoublyListNode *pre, *cur = front;
        while (cur != nullptr)
        {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
    }

    /* 获取双向队列的长度 */
    auto size() {
        return queSize;
    }
    /* 判断双向队列是否为空 */
    bool isEmpty() {
        return queSize == 0;
    }
    /* 入队操作 */
    void push(int num, bool isFront) {
        DoublyListNode *node = new DoublyListNode(num);
        // 若链表为空，则令 front 和 rear 都指向 node
        if (isEmpty()){
            front = node;
            rear = node;
        }
        // 队首入队操作
        else if (isFront){
            front->prev = node;
            node->next = front;
            front = node;
        }
        // 队尾入队操作
        else{
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
        queSize++;
    }
    /* 队首入队 */
    void pushFirst(int num){
        push(num, true);
    }
    /* 队尾入队 */
    void pushLast(int num){
        push(num, false);
    }
    /* 出队操作 */
    int pop(bool isFront){
        if (isEmpty())
            throw out_of_range("队列为空");
        int val;
        // 队首出队操作
        if(isFront){
            val = front->val;
            DoublyListNode *fNext = front->next;
            if(fNext != nullptr){
                fNext->prev = nullptr;
                front->next = nullptr;
            }
            delete front;
            front = fNext;  // 更新头结点
        }
        // 队尾出队操作
        else{
            val = rear->val;
            DoublyListNode *rPrev = rear->prev;
            if(rear->prev != nullptr){
                rPrev->next = nullptr;
                rear->prev = nullptr;
            }
            delete rear;
            rear = rPrev;
        }
        queSize--;
        return val;
    }
    /* 队首出队 */
    int popFirst(){
        return pop(true);
    }
    /* 队尾出队 */
    int popLast(){
        return pop(false);
    }
    /* 访问队首元素 */
    int peekFirst(){
        if(isEmpty())
            throw out_of_range("双向队列为空");
        return front->val;
    }
    /* 访问队尾元素 */
    int peekLast(){
        if(isEmpty())
            throw out_of_range("双向队列为空");
        return rear->val;
    }
    /* 返回数组用于打印 */
    std::vector<int> toVector(){
        DoublyListNode *node = front;
        std::vector<int> res(size());
        for(int i = 0; i < res.size(); i++){
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

/* Driver Code */
int main() {
    /* 初始化双向队列 */
    LinkedListDeque *deque = new LinkedListDeque();
    deque->pushLast(3);
    deque->pushLast(2);
    deque->pushLast(5);
    cout << "双向队列 deque = ";
    printVector(deque->toVector());

    /* 访问元素 */
    int peekFirst = deque->peekFirst();
    cout << "队首元素 peekFirst = " << peekFirst << endl;
    int peekLast = deque->peekLast();
    cout << "队尾元素 peekLast = " << peekLast << endl;

    /* 元素入队 */
    deque->pushLast(4);
    cout << "元素 4 队尾入队后 deque =";
    printVector(deque->toVector());
    deque->pushFirst(1);
    cout << "元素 1 队首入队后 deque = ";
    printVector(deque->toVector());

    /* 元素出队 */
    int popLast = deque->popLast();
    cout << "队尾出队元素 = " << popLast << "，队尾出队后 deque = ";
    printVector(deque->toVector());
    int popFirst = deque->popFirst();
    cout << "队首出队元素 = " << popFirst << "，队首出队后 deque = ";
    printVector(deque->toVector());

    /* 获取双向队列的长度 */
    int size = deque->size();
    cout << "双向队列长度 size = " << size << endl;

    /* 判断双向队列是否为空 */
    bool isEmpty = deque->isEmpty();
    cout << "双向队列是否为空 = " << boolalpha << isEmpty << endl;

    // 释放内存
    delete deque;

    return 0;
}