class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int buyPrice = INT_MAX;
        int profit = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i] < buyPrice) buyPrice = prices[i];
            else profit = max(profit, prices[i] - buyPrice);
        }
        return profit;
    }
};
