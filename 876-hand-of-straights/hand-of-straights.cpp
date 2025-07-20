class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int n = hand.size();

    // If total cards aren't divisible by groupSize, it's impossible
    if (n % groupSize != 0) return false;

    // Count frequency of each card
    map<int, int> count;
    for (int card : hand) {
        count[card]++;
    }

    // Process the map greedily
    for (auto it = count.begin(); it != count.end(); ++it) {
        int card = it->first;
        int freq = it->second;

        // Skip if no more of this card
        if (freq == 0) continue;

        // Try to build group starting from this card
        for (int i = 0; i < groupSize; ++i) {
            int nextCard = card + i;

            // If next card is missing or has fewer cards, return false
            if (count[nextCard] < freq) return false;

            // Deduct 'freq' from each card in the group
            count[nextCard] -= freq;
        }
    }

    return true;
    }
};