#include "../utils/common.hpp"

vector<int> levelOrder(TreeNode *root){
    // 创建一个队列，存放节点,加入根节点
    queue<TreeNode *> queue;
    queue.push(root);
    // 初始化列表保存遍历序列
    vector<int> vec;
    while(!queue.empty()){
        TreeNode *node = queue.front();
        queue.pop();
        vec.push_back(node->val);
        if(node->left != nullptr){
            queue.push(node->left);
        }
        if (node->right != nullptr){
            queue.push(node->right);
        }
    }
    return vec;
}
/* Driver Code */
int main() {
    /* 初始化二叉树 */
    // 这里借助了一个从数组直接生成二叉树的函数
    TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout << endl << "初始化二叉树\n" << endl;
    printTree(root);

    /* 层序遍历 */
    vector<int> vec = levelOrder(root);
    cout << endl << "层序遍历的节点打印序列 = ";
    printVector(vec);

    return 0;
}
