/**
 * Copyright (C) The software Authors. All rights reserved.
 * File Name: 298.binary_tree_longest_consecutive_sequence.cpp
 * Author:
 * mail:
 * Created Time: Wed Aug 24 14:50:29 2022
 * Brief:
 */
class Solution {
public:
    void preorderTraverse(TreeNode* node, int& lastval, int& maxpath, int &curpath){
        if(node==nullptr){
            return;
        }
        //****注意cache
        int cacheval = lastval;
        int cachepath = curpath;
        //****注意cache
        if(lastval+1 == node->val){
            curpath+=1;
        }else{
            curpath=1;
        }
        maxpath = std::max(maxpath, curpath);
        lastval = node->val;
        preorderTraverse(node->left,lastval,maxpath,curpath);
        preorderTraverse(node->right,lastval,maxpath,curpath);
        lastval = cacheval;
        curpath = cachepath;
    }
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int lastval=root->val-1;
        int maxpath=0;
        int curpath=0;
        preorderTraverse(root, lastval, maxpath, curpath);
        return maxpath;
    }
};
