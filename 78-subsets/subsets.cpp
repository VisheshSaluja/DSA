class Solution {
public:

    void helper(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int> &v){

        

        if(i>=nums.size()){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        helper(nums, i+1, ans, v);

        v.pop_back();
        helper(nums, i+1, ans, v);

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> v;

        helper(nums, 0, ans, v);

        return ans;
        
    }
};