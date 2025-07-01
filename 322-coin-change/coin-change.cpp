class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(), coins.end());
        // int t[coins.size()+1][amount+1];
        vector<vector<int>> t(coins.size() + 1, vector<int>(amount + 1, 0));


        if(amount==0) return 0;

        for(int i=0; i<=coins.size(); i++){
    for(int j=0; j<=amount; j++){
        if (j == 0)
            t[i][j] = 0;  // 0 coins to make amount 0
        else if (i == 0)
            t[i][j] = INT_MAX - 1;  // Impossible to make positive amount with 0 coins
    }
}

        for(int i=1;i<coins.size()+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j)
                    t[i][j] = min(t[i-1][j], 1+t[i][j-coins[i-1]]);
                else t[i][j] = t[i-1][j];
            }
        }
    
        if(t[coins.size()][amount]>=INT_MAX-1) return -1;

        return (t[coins.size()][amount]);

        
    }
};