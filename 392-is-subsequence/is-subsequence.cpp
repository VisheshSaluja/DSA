class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0;
        if(s.size()>t.size()) return false;

        for(int j=0;j<=t.size() && count<s.size();j++){
            if(s[count]==t[j]) count++;
        }

        return count==s.size();
        
    }
};