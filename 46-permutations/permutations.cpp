class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int i){

        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){
            // if(j>i && nums[j]==v[0]) j++;

            swap(nums[i], nums[j]);
            

            helper(nums, i+1);
            swap(nums[i], nums[j]);
            // v.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {


        helper(nums, 0);
        return ans;
        
    }
};