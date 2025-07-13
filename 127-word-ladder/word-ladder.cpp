class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        s.erase(beginWord);

        q.push({beginWord, 1});

        while(!q.empty()){
            string word = q.front().first;
            int changes = q.front().second;
            q.pop();
            if(word==endWord) return changes;

            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word, changes+1});
                    }
                }
                word[i] = original;
            }

        }


        

        return 0;
    }
};