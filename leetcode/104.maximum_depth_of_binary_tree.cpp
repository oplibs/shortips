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

#include <algorithm>

class Solution {
public:
    void traverse(TreeNode* node, int &cur, int& depth){
      if(node==nullptr) {
        depth = std::max(cur-1, depth);
        return;
      }
      cur++;
      traverse(node->left, cur, depth);
      traverse(node->right, cur, depth);
      cur--;
    }
    int maxDepth(TreeNode* root) {
      if(root == nullptr) {
        return 0;
      }
      int cur=1;
      int depth=1;
      traverse(root, cur, depth);
      return depth;
    }
};
