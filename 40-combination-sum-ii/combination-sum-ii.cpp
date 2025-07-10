class Solution {
public:

    
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int target, int i, vector<vector<int>> &ans, vector<int> &v){

        if(target==0){
            ans.push_back(v);
            return;
        }

        if(i>=nums.size() || target<0) return;

        for(int j=i;j<nums.size(); j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            v.push_back(nums[j]);
            helper(nums, target-nums[j], j+1, ans, v);
            v.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        helper(candidates, target, 0, ans, v);
      

        return ans;
        
    }
};