class Solution {
  public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while(low < high){
            if(arr[low] < arr[high]) // sorted
                return arr[low];
            int mid = (low + high) / 2;
            if (arr[mid] > arr[high]) // search to right
                low = mid + 1;
            else // search to left
                high = mid;
        }
        return arr[low]; // low == high
    }
};
