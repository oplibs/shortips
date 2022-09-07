class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(auto item: wordDict){
            dict.insert(item);
        }
        vector<bool> dp(s.length()+1, false);
        dp[0]=true;
        for(int i=1; i<=s.length(); i++){
            for(int j=0; j<i; j++){
                int len=i-j;
                string data=s.substr(j, len);
                if(dict.count(data)){
                    dp[i]=dp[j];
                    //一定要break，不然会被重复改写
                    if(dp[i]){
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
