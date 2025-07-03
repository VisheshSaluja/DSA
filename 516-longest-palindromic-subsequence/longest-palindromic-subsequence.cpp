class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int m = s.length();
        

        vector<vector<int>> t(m+1, vector<int>(m+1, 0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        return t[m][m];
        
    }
};