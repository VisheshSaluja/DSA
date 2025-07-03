class Solution {
public:

    int lcs(string s1, string s2){
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0) t[i][j] = j;
                if(j==0) t[i][j] = i;
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }
                else t[i][j] = 1+min(t[i-1][j], min(t[i][j-1], t[i-1][j-1]));
            }
        }
        return t[m][n];
    }

    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();
        int l = lcs(word1, word2);


        return l;
        
    }
};