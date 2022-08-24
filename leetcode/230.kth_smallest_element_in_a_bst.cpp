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
    void inorderTraverse(TreeNode* node, size_t& pos, int& val, const int k){
        if(node==nullptr){
            return;
        }
        inorderTraverse(node->left,pos, val, k);
        pos++;
        if(pos==k){
            val = node->val;
        }
        if(pos>=k){
            return;
        }
        inorderTraverse(node->right, pos, val, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        size_t pos = 0;
        int res=0;
        inorderTraverse(root, pos, res, k);
        return res;
    }
};
