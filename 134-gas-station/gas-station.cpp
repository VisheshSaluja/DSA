class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
         int totalGas = 0;    // total gas in all stations
    int totalCost = 0;   // total cost to travel all edges
    int tank = 0;        // current gas in tank
    int start = 0;       // candidate start index

    for (int i = 0; i < gas.size(); ++i) {
        totalGas += gas[i];       // add current station gas
        totalCost += cost[i];     // add travel cost to next station
        tank += gas[i] - cost[i]; // simulate current segment

        // If we run out of gas, reset start point
        if (tank < 0) {
            start = i + 1; // try next station as start
            tank = 0;      // reset tank
        }
    }

    // If total gas is less than total cost, it's impossible
    if(totalGas < totalCost) return -1;

    return start;

    }
};