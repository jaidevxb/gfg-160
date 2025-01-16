class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        
        if (s1.length() != s2.length())
            return false;
        
        vector <int> arr(26,0);
        for(int i = 0; i<s1.length(); i++){
            arr[s1[i] - 'a']++;
        }
        
        for(int i = 0; i<s2.length(); i++){
            arr[s2[i] - 'a']--;
        }
        
        for(int i =0; i<26; i++){
            if(arr[i] != 0) return false;
        }
        return true;
    }
};
