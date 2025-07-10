class Solution {
public:

    void helper(vector<int>& candidates, int target, int i, vector<vector<int>> &ans, vector<int> &v, int sum){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(v);
            return;
        }
        // if(i>=candidates.size() || target<0) return;

            for(int j=i;j<candidates.size();j++){
                
                v.push_back(candidates[j]);
                helper(candidates, target, j, ans, v, sum+candidates[j]);
                v.pop_back();
            }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        helper(candidates, target, 0, ans, v, 0);

        return ans;
        
    }
};