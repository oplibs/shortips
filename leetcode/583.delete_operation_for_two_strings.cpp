#include <algorithm>

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m=word1.size();
        size_t n=word2.size();
        vector<vector<int>> data(m+1, vector<int>(n+1, 0));
        for(size_t i = 0; i< n+1; i++){
            data[0][i]=i;
        }
        for(size_t i = 0; i< m+1; i++){
            data[i][0]=i;
        }
        for(size_t i = 1; i< m+1; i++){
            for(size_t j = 1; j< n+1; j++){
                if(word1[i-1] == word2[j-1]){
                    data[i][j]=std::min(std::min(data[i-1][j]+1, data[i][j-1]+1), data[i-1][j-1]);
                }else {
                    data[i][j]=std::min(data[i-1][j]+1, data[i][j-1]+1);
                }
            }
        }
        return data[m][n];
    }
};
