class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;

        vector<int> mismatch;

        // Collect indices where characters differ
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                mismatch.push_back(i);
                if (mismatch.size() > 2) return false; // too many mismatches
            }
        }

        // Check that the mismatches can be fixed with one swap
        if (mismatch.size() == 2) {
            int i = mismatch[0], j = mismatch[1];
            return s1[i] == s2[j] && s1[j] == s2[i];
        }

        return false; // can't be fixed with one swap
    }
};
