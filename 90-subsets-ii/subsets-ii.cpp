class Solution {
public:

    vector<vector<int>> ans;

    void helper(vector<int> &nums, vector<vector<int>> &ans, int i, vector<int> v){

            ans.push_back(v);

        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;

            v.push_back(nums[j]);
            helper(nums, ans, j+1, v);
            v.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        helper(nums, ans, 0, v);

        return ans;
        
    }
};