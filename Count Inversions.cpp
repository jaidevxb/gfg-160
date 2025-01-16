class Solution {
  public:
    // Function to count inversions in the array.
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;     // Starting index for the left subarray
        int j = mid + 1;  // Starting index for the right subarray
        int k = left;     // Starting index for the merged subarray
        int invCount = 0;

        // Merge the two subarrays into temp
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } 
            else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1); // Count inversions
            }
        }

        // Copy remaining elements of left subarray
        while (i <= mid)
            temp[k++] = arr[i++];

        // Copy remaining elements of right subarray
        while (j <= right)
            temp[k++] = arr[j++];

        // Copy the merged elements back to the original array
        for (i = left; i <= right; i++)
            arr[i] = temp[i];

        return invCount;
    }

        
    
    int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            invCount += mergeSortAndCount(arr, temp, left, mid);
            invCount += mergeSortAndCount(arr, temp, mid + 1, right);
            invCount += mergeAndCount(arr, temp, left, mid, right);
        }
        return invCount;
    }
    
    int inversionCount(vector<int> &arr) {
        vector<int> temp(arr.size());
        return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    }
};
