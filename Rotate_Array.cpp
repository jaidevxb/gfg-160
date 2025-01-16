class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d = d % n;
        int temp[d];
        for(int i = 0; i < d; i++)
            temp[i] = arr[i];
        for(int i = d; i < n; i++)
            arr[i-d] = arr[i];
        for(int i = n-d; i < n; i++)
            arr[i] = temp[i-(n-d)];
    }
};
