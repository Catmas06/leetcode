#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int TreeHigh(struct TreeNode *root) {
    if(!root) {
        return 0;
    }
    int high1 = TreeHigh(root->left);
    int high2 = TreeHigh(root->right);
    if(high1 == -1 || high2 == -1){
        return -1;
    }
    if((high1 - high2 <= 1) && (high1 - high2) >= -1) {
        return high1 > high2 ? high1 + 1 : high2 + 1;
    }
    else return -1;
}

bool isAVL(struct TreeNode *root){
    if(!root){
        return true; 
    }
    int high1 = TreeHigh(root->left);
    int high2 = TreeHigh(root->right);
    if(high1 == -1 || high2 == -1){
        return false;
    }
    else if((high1 - high2 <= 1) && (high1 - high2) >= -1) return true;
    else return false;
}