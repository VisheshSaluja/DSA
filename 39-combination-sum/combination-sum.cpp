class Solution {
public:

    void helper(vector<int>& candidates, int target, int i, vector<vector<int>> &ans, vector<int> &v){

        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i>=candidates.size() || target<0) return;

            v.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i, ans, v);

            v.pop_back();
            helper(candidates, target, i+1, ans, v);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        helper(candidates, target, 0, ans, v);

        return ans;
        
    }
};