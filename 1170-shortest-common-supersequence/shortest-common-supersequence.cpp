class Solution {
public:

    string lcsP(string s1, string s2, int m, int n){
        // int t[m+1][n+1];

        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         if(m==0||n==0) t[i][j] = 0;
        //     }
        // }

        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        int i=m, j=n;

        string s = "";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]) {
                s+=s1[i-1];
                i--;
                j--;
            }
            else if(t[i-1][j]>t[i][j-1]) 
            {s+=s1[i-1];
            i--;}
            else 
            {s+=s2[j-1];
            j--;}
        }

        while(i>0){
            s+=s1[i-1];
            i--;
        }
        while(j>0){
            s+=s2[j-1];
            j--;
        }

        reverse(s.begin(), s.end());
        return s;


    }

    string shortestCommonSupersequence(string str1, string str2) {
        
        return lcsP(str1, str2, str1.size(), str2.size());
    }
};