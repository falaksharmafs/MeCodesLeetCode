class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        int n = plantTime.size();

        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({growTime[i], plantTime[i]});
        }

        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        int plantDays = 0;
        int ans = 0;

        for(auto &p : arr) {

            int grow = p.first;
            int plant = p.second;

            plantDays += plant;

            ans = max(ans, plantDays + grow);
        }

        return ans;
    }
};