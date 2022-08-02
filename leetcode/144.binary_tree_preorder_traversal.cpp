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
    void preorder(TreeNode* node, vector<int>& results) {
      if(node!=nullptr){
        results.push_back(node->val);
      }else{
        return;
      }
      if(node->left){
        preorder(node->left, results);
      }
      if(node->right){
        preorder(node->right, results);
      }
    }
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> results;
      preorder(root, results);
      return results;
    }
};
