#include "../utils/common.hpp"

int main(){
    //初始化栈
    std::stack<int> stack;
    //元素入栈
    stack.push(1);
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(4);
    //访问栈顶元素
    int top = stack.top();
    //元素出栈
    stack.pop();
    //获取栈的长度
    int size = stack.size();
    //判断是否为空
    bool empty = stack.empty();
    
    std::cout<< top << std::endl;
    std::cout<< size << std::endl;
    std::cout<< empty << std::endl;
}