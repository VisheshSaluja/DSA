class Solution {
public:
    int missingNumber(vector<int>& nums) {
       

        int n = nums.size();
        int tsum = (n*(n+1))/2;
        int asum = 0;

        for(int i=0;i<nums.size();i++){
            asum += nums[i];
        }

        int answer = tsum - asum;
        return answer;

    }
};