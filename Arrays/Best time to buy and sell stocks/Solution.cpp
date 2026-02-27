class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;   // buy day
        int maxProfit = 0;

        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] < prices[left]) {
                left = right;   // found cheaper buy price
            } else {
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            }
        }

        return maxProfit;
    }
};
