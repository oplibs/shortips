class Solution {
public:
    int fib(int n) {
      int res[2]={0,1};
      if(n<2){
        return res[n];
      }
      for(int i=2; i<=n; i++){
        int temp=res[1]+res[0];
        res[0] = res[1];
        res[1] = temp;
      }
      return res[1];
    }
};
