class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        int len=s.length();
        vector<vector<bool>> res(len, vector<bool>(len, false));
        for(int i=0; i<len; i++){
            res[i][i]=true;
            if(i<len-1 && s[i]==s[i+1]){
                //printf("here");
                res[i][i+1]=true;
            }
        }
        /*
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                if(res[i][j]){
                    printf("%d %d t\n",i,j);
                }else{
                    printf("%d %d f\n",i,j);
                }
            }
        }
        */
        //上面已经处理了长度为2的，那应该从长度为3的开始，而且是<=len
        for(int L=3;L<=len;L++){
            for(int i=0;i<len;i++){
                //注意这里是按照长度跳变的。
                int j = L+i-1;
                //printf("%d %d\n", i, j);
                //注意越界指标
                if(j>=len){
                    continue;
                }
                //printf("hit %d %d\n", i, j);
                if(s[i]==s[j]){
                    res[i][j]=res[i+1][j-1];
                }
            }
        }
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                if(res[i][j]){
                    //printf("%d %d t\n",i,j);
                    ret++;
                }
                /*else{
                    printf("%d %d f\n",i,j);
                }
                */
            }
        }
        return ret;
    }
};
