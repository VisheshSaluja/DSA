class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            auto it = find(v.begin(), v.end(), nums[i]);
            if(it != v.end())
                {int a = distance(v.begin(), it);
                ans.push_back(a);}

        }
        return ans;
    }
};