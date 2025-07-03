class Solution {
public:

    int lcs(string s1, string s2){
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[m][n];
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int l = lcs(word1, word2);

        return (m-l + n-l);
    }
};