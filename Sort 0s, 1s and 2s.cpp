class Solution {
  public:
    void sort012(vector<int>& arr) {
        int i = 0, j = 0, k = arr.size()-1;
        while(j <= k){
            int ele = arr[j];
            if(ele == 0){ 
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else if(ele == 1) j++;
            else{
                swap(arr[j], arr[k]);
                k--;
            }
        }
    }
};
