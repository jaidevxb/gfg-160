class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int maxProfit = 0;
        for(int i = 0; i < prices.size()-1; i++){ // -1 because last index need to be accessed by i+1
            if(prices[i] < prices[i+1])
                maxProfit += prices[i+1] - prices[i];
        }
        return maxProfit;
    }
};
