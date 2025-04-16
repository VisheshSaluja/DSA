class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int j=0;
        int mx = 0;


        while(j<prices.size()){
            if(prices[i]<prices[j])
            {
                
                int profit = prices[j]-prices[i];
                mx = max(mx, profit);
                
            }
            else i=j;
            j++;
        }
        return mx;
    }
};