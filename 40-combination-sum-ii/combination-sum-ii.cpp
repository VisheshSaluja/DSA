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
            // if(nums[j]>target) break;
            v.push_back(nums[j]);
            helper(nums, target-nums[j], j+1, ans, v);
            v.pop_back();
        }

        // v.push_back(nums[i]);
        // helper(nums, target-nums[i], i+1, ans, v);
        // v.pop_back();
        // helper(nums, target, i+1, ans, v);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        helper(candidates, target, 0, ans, v);
        vector<vector<int>> result;
        

        for(auto it: ans){
            result.push_back(it);
        }

        return result;
        
    }
};