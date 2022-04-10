/*
    429. N-ary Tree Level Order Traversal
*/
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {

public:
    vector<vector<int>> levelOreder(Node* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ans;

        //创建队列
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            // count记录了当前层哪里截止
            int count = q.size();
            vector<int> level;

            // 将队列头节点的值压入 vector<int> level 中
            for(int i = 0; i < count; i++) {
                Node* cur = q.front();
                // 当前队头出队
                q.pop();
                level.push_back(cur->val);
                // 将队列头节点的 children 入队 q
                for(Node* child : cur->children) {
                    q.push(child);
                }
            }

            ans.push_back(move(level));
        }
        return ans;
    }
};