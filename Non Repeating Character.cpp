
class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector <int> arr(26,0);
        for(int i = 0; i<s.length(); i++){
            arr[s[i] - 'a']++;
        }
        for(int i =0; i<s.length(); i++){
            if (arr[s[i] - 'a'] == 1) return s[i];
        }
        return '$';
    }
};
