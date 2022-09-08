class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = INT_MAX;
        //从1开始，这样比较安全
        for(size_t r=1; r < triangle.size(); r++){
            for(size_t i = 0; i < triangle[r].size(); i++){
                if(i==0){
                    triangle[r][i]+=triangle[r-1][0];
                }else if( i == triangle[r].size()-1){
                    triangle[r][i]+=triangle[r-1][i-1];
                }else{
                    triangle[r][i]+=std::min(triangle[r-1][i-1],triangle[r-1][i]);
                }
            }
        }
        for(size_t i = 0; i < triangle[triangle.size()-1].size(); i++){
            res = std::min(res, triangle[triangle.size()-1][i]);
        }
        return res;
    }
};
