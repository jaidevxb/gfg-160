// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
    
        int hIndex = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                hIndex = i + 1;
            } 
            else break;
        }
        return hIndex;
    }
};
