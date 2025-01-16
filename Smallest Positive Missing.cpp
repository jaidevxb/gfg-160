
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // arrange numbers in its correct position
        for (int i = 0; i < n; i++) {
            // arr[arr[i] - 1] != arr[i] this to skip unwanted swaps
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) { 
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // return smallest positive
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) return i + 1;
        }

        // if all the nos. are in correct place return next no.
        return n + 1;
    }
};
