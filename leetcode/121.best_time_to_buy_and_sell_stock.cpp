#include <algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.size()<2){
        return 0;
      }
      int minbuy=prices[0];
      prices[0]=0;
      int maxearn=0;
      int i;
      for(i=1;i<prices.size();i++){
        if(prices[i]<minbuy){
          minbuy = prices[i];
        }
        prices[i]=std::max(prices[i-1], prices[i]-minbuy);
      }
      return prices[i-1];
    }
};
