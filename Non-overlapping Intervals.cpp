class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // Step 1: Sort intervals by their end time in ascending order
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { 
            return a[1] < b[1];
        });

        int end = intervals[0][1];  // The end time of the first interval
        int count = 0;  // This will count how many intervals need to be removed

        // Step 2: Iterate through the intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Step 2.1: If the start of the current interval is less than the end of the previous interval, they overlap
            if (intervals[i][0] < end)
                count++;  
            else
                end = intervals[i][1];  // Otherwise, update the `end` to the end time of the current interval
        }
        return count;
    }
};
