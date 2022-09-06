/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxpath(TreeNode* node,int& ret){
        if(node==nullptr){
            return 0;
        }
        int maxleft=maxpath(node->left,ret);
        int maxright=maxpath(node->right,ret);
        // 路径的定义，这里不能+1
        ret=std::max(maxleft+maxright, ret);
        return 1+std::max(maxleft,maxright);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ret=INT_MIN;
        maxpath(root, ret);
        return ret;
    }
};
