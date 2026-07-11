class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;

        for (int i = 0; i< prices.size() - 1; i++)
        {
            if (prices[i] < prices[i+1]) //skip, 4,0, 3
            {
                int profit = prices[i+1] - prices[i]; //0, 4, 0, 3,  
                maxProfit = maxProfit + profit; //0 , 4,7
            }
        }
        return maxProfit; 
    }
};