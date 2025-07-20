class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
    vector<pair<int, double>> cars;

    // Compute time for each car to reach target
    for (int i = 0; i < n; ++i) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    // Sort cars by starting position in descending order
    sort(cars.rbegin(), cars.rend());

    int fleets = 0;
    double lastTime = 0;

    for (const auto& [pos, time] : cars) {
        if (time > lastTime) {
            fleets++;         // new fleet
            lastTime = time;  // update fleet time
        }
        // else joins existing fleet
    }

    return fleets;

    }
};