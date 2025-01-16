class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> res;

        // Sort the intervals based on the start time
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // Merge intervals
        for (auto& interval : arr) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            }  
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }

        return res;
    }
};
