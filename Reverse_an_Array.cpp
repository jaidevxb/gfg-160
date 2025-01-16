class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left = 0, right = n-1;
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};
