class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

private:
    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int i = c - 'a';
                if (!node->children[i])
                    node->children[i] = new TrieNode();
                node = node->children[i];
            }
            node->word = word;
        }

        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];

        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& dir : dirs) {
            int newi = i + dir[0], newj = j + dir[1];
            if (newi >= 0 && newj >= 0 && newi < board.size() && newj < board[0].size()) {
                dfs(board, newi, newj, node, result);
            }
        }

        board[i][j] = c; // backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        TrieNode* root = buildTrie(words);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};
