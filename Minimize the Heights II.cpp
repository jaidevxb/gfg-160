// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr,int k) {
        int n = arr.size();  
        sort(arr.begin(), arr.end());  
    
        int ans = arr[n-1] - arr[0];
        int largest = arr[n-1] - k;   
        int smallest = arr[0] + k;    
    
        for (int i = 0; i < n - 1; i++) {
            int mi = min(smallest, arr[i + 1] - k);  
            int ma = max(largest, arr[i] + k); 
            if(mi < 0) continue;
            ans = min(ans, ma - mi);
        }
    
        return ans;
    }
};
