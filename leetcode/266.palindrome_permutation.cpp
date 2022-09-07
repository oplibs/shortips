/**
 * Copyright (C) The software Authors. All rights reserved.
 * File Name: 266.palindrome_permutation.cpp
 * Author:
 * mail:
 * Created Time: Wed Sep  7 14:03:55 2022
 * Brief:
 */

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> dict;
        for(int i=0; i<s.length(); i++){
            if(dict.count(s[i])){
                dict[s[i]]=dict[s[i]]+1;
            }else{
                dict[s[i]]=1;
            }
        }
        map<char,int>::iterator itr;
        int count=0;
        for(itr=dict.begin();itr!=dict.end();itr++){
            if(itr->second % 2==1){
                count++;
            }
        }
        return !(count>1);
    }
};
