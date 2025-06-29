class Solution {
public:

    int countSubset(vector<int> nums, int target){
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));

        // Initialize base cases
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1; // One way to get sum 0
        }


        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=target;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if((sum+target)%2!=0 || (sum+target)<0) return 0;

        int newT = (sum+target)/2;

        return countSubset(nums, newT);

    }
};