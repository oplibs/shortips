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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> queue[2];
        if(root==nullptr){
            return result;
        }
        size_t qidx=0;
        queue[qidx].push_back(root);
        while(queue[qidx].size()>0){
            for(auto item:queue[qidx]){
                if(item->left!=nullptr){
                    queue[1-qidx].push_back(item->left);
                }
                if(item->right!=nullptr){
                    queue[1-qidx].push_back(item->right);
                }
            }
            if(queue[qidx].size()>0){
                result.push_back(queue[qidx][queue[qidx].size()-1]->val);
            }
            queue[qidx].clear();
            qidx=1-qidx;
        }
        return result;
    }
};
