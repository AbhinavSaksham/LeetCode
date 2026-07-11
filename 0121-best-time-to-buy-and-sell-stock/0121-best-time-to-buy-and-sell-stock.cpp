class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0]; //store 1st index of arr
        int profit = 0;

        for (int i=1; i< prices.size(); i++) //traverse the arr
        {   
            profit = max(profit, prices[i]-mini); //find max diff
            mini = min(mini, prices[i]);    //store min val from arr

        }
        return profit;
    }
};