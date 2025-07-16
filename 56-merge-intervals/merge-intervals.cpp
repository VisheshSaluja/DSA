class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()<=1) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        vector<int> curr = intervals[0];

        ans.push_back(curr);

        for(int i=0;i<intervals.size();i++){
            int currStart = curr[0];
            int currEnd = curr[1];

            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if(nextStart<=currEnd){
                curr[1] = max(currEnd, nextEnd);
                ans.back()[1] = curr[1];
            }
            else{
                curr = intervals[i];
                ans.push_back(curr);
            }
        }
        return ans;

    }
};