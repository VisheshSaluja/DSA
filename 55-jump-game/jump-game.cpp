class Solution {
public:

    bool helper(int index, vector<int>& nums){

        if(index>=nums.size()-1) return true;

        int maxJump = index + nums[index];

        for(int next = index+1; next<=maxJump; next++){
            if(helper(next, nums)) return true;
        }

        return false;
    }

    bool GreedyHelper(vector<int>& nums){
        int mxReach = 0;

        for(int i=0; i<nums.size();i++){
            if(i > mxReach) return false;

            mxReach = max(mxReach, i+nums[i]);
        }

        return true;
    }

    bool canJump(vector<int>& nums) {
        // return helper(0, nums);
        return GreedyHelper(nums);
    }
};