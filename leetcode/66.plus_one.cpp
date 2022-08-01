class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int take=1;
      int from=digits.size()-1;
      while(from>=0){
        int val = digits[from] + take;
        if(val>=10){
          take = 1;
        }else{
          take = 0;
        }
        digits[from--] = val % 10;
      }
      if(take==1){
        auto it = digits.begin();
        digits.insert(it, 1);
      }
      return digits;
    }
};
