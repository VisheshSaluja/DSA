class Solution {
public:
priority_queue<int> maxHeap;
    int lastStoneWeight(vector<int>& stones) {
        for(int s: stones){
            maxHeap.push(s);
        }

        while(maxHeap.size()>1){
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if(second<first){
                maxHeap.push(first-second);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};