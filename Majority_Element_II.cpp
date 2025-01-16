class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0, el1 = -1, el2 = -1;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && arr[i] != el2) {
                el1 = arr[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0 && arr[i] != el1) {
                el2 = arr[i];
                cnt2 = 1;
            } 
            else if (arr[i] == el1) cnt1++;
            else if (arr[i] == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == el1) cnt1++;
            else if (arr[i] == el2) cnt2++;
        }

        if (cnt1 > n / 3) ans.push_back(el1);
        if (cnt2 > n / 3) ans.push_back(el2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
