class Solution {
public:

    int lcs(string s1, string s2){

        int m = s1.size();

        vector<vector<int>> t(m+1, vector<int>(m+1, 0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) t[i][j] = 1+t[i-1][j-1];
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][m];
    }

    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int l = lcs(s, s2);
        int m = s.size();
        return (m-l);
        
    }
};