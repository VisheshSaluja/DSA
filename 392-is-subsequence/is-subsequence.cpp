class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0;

        for(int j=0;j<t.size();j++){
            if(s[count]==t[j]) count++;
        }

        return count==s.size();
        
    }
};