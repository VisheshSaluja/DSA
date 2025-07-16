class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for(auto s: strs){
            string sortedW = s;
            sort(sortedW.begin(), sortedW.end());
            anagrams[sortedW].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto it: anagrams){
            ans.push_back(it.second);
        }

        return ans;
        
        
    }
};