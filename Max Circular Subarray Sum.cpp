class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int maxSoFar = 0;
        int minSoFar = 0;
        int totalSum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];

            maxSoFar += arr[i];
            maxSum = max(maxSum, maxSoFar);
            if(maxSoFar < 0) maxSoFar = 0;

            minSoFar += arr[i];
            minSum = min(minSum, minSoFar);
            if(minSoFar > 0) minSoFar = 0;
        }
        if (maxSum < 0) return maxSum; // if all the array elements are negative
        return max(totalSum - minSum, maxSum);
    }
};
