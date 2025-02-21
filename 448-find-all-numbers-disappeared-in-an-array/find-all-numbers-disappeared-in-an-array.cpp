class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ans;
        set<int> s(nums.begin(), nums.end());



        for(int i=1;i<nums.size()+1;i++){
            // cout<<s[i];
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};