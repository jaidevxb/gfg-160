class Solution {
  public:
    vector<int> computeLPS(string& s){
        int n = s.length();
        vector<int> lps(n,0);
        int i = 1, j = 0;
        while(i < n){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                i++;
                j++;
            }
            else{
                if(j != 0) j = lps[j - 1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string newStr = s + "$" + rev;
        vector<int> lps = computeLPS(newStr);
        int n = newStr.length();
        return s.length() - lps[n - 1];
    }
};
