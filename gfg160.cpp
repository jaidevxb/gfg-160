#include<bits/stdc++.h>
using namespace std;

// Arrays day 1 to 13
// Second Largest
int getSecondLargest(vector<int> &arr) {
    int largest = arr[0];
    int slargest = -1;
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest)
            slargest = arr[i];
    }
    return slargest;
}

// Move All Zeroes to End
void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    int j = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return;
        
    for(int i = j+1; i<n; i++){
        if(arr[i] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

// Reverse an Array
void reverseArray(vector<int> &arr) {
    int n = arr.size();
    int left = 0, right = n-1;
    while(left < right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Rotate Array
void rotateArr(vector<int>& arr, int d) {
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

// Next Permutation
void nextPermutation(vector<int>& arr) {
    next_permutation(arr.begin(), arr.end());
}

// Majority Element II
vector<int> findMajority(vector<int>& arr) {
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

// Stock Buy and Sell – Multiple Transaction Allowed
int maximumProfit(vector<int> &prices) {
    int maxProfit = 0;
    for(int i = 0; i < prices.size()-1; i++){ // -1 because last index need to be accessed by i+1
        if(prices[i] < prices[i+1])
            maxProfit += prices[i+1] - prices[i];
    }
    return maxProfit;
}

// Stock Buy and Sell – Max one Transaction Allowed
int maximumProfit(vector<int> &prices) {
    int buyPrice = INT_MAX;
    int profit = 0;
    for(int i = 0; i<prices.size(); i++){
        if(prices[i] < buyPrice) buyPrice = prices[i];
        else profit = max(profit, prices[i] - buyPrice);
    }
    return profit;
}

// Minimize the Heights II
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

// Kadane's Algorithm   
int maxSubarraySum(vector<int> &arr) {
    int sum = 0, maxi = INT_MIN;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        sum+=arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return maxi;
}

// Maximum Product Subarray
int maxProduct(vector<int> &arr) {
    int pref = 1, suff = 1, ans = INT_MIN;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
           
        pref *= arr[i];
        suff *= arr[n-i-1];
        ans = max(ans, max(pref, suff));
    }
    return ans;
}

// Max Circular Subarray Sum
int circularSubarraySum(vector<int> &arr) {
    int maxSoFar = 0;
    int minSoFar = 0;
    int totalSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        totalSum += arr[i];

        maxSoFar += arr[i];
        maxSum = max(maxSum, maxSoFar);
        if(maxSoFar < 0) maxSoFar = 0;

        minSoFar += arr[i];
        minSum = min(minSum, minSoFar);
        if(minSoFar > 0) minSoFar = 0;
    }
    if (maxSum < 0) return maxSum; // if all the array elements are negative
    return max(totalSum - minSum, maxSum);
}

// Smallest Positive Missing Number
int missingNumber(vector<int> &arr) {
    int n = arr.size();

    // arrange numbers in its correct position
    for (int i = 0; i < n; i++) {
        // arr[arr[i] - 1] != arr[i] this to skip unwanted swaps
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) { 
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // return smallest positive
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) return i + 1;
    }

    // if all the nos. are in correct place return next no.
    return n + 1;
}


// Strings day 14 to 20
// Implement Atoi (ASCII to INTEGER)
int myAtoi(char *s) {
    int i = 0;
        
    // skipping leading whitespaces
    while(s[i] == ' '){
        i++;
    }
        
    // determine the sign
    int sign = 1;
    if(s[i] == '+' || s[i] == '-'){
        if(s[i] == '-') sign = -1;
        i++;
    }
        
    // to handle overflow
    long result = 0;
    while(isdigit(s[i])){
        result = result * 10 + (s[i] - '0');
            
        if(result * sign > INT_MAX) return INT_MAX;
        if(result * sign < INT_MIN) return INT_MIN;
        i++;
    }
    return (int)(result * sign);
}

// Add Binary Strings
string addBinary(string& s1, string& s2) {
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;

    string result;
    while (i >= 0 || j >= 0 || carry == 1) {
        int bit1 = i >= 0 ? s1[i] - '0' : 0;
        int bit2 = j >= 0 ? s2[j] - '0' : 0;

        int sum = bit1 + bit2 + carry;
        result += (sum % 2) + '0';
        carry = sum / 2;

        i--;
        j--;
    }
    reverse(result.begin(), result.end());
    
    size_t startPos = result.find_first_not_of('0');
    if (startPos != string::npos) result = result.substr(startPos);
    else result = "0";

    return result;
}

// Anagram
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

// Non Repeating Character
char nonRepeatingChar(string &s) {
    vector <int> arr(26,0);
    for(int i = 0; i<s.length(); i++){
        arr[s[i] - 'a']++;
    }
    for(int i =0; i<s.length(); i++){
        if (arr[s[i] - 'a'] == 1) return s[i];
    }
    return '$';
}

// KMP Algorithm
void computeLPS(string& pat, int m, vector<int>& lps){
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < m){
        if(pat[i] == pat[len]){
            lps[i] = len + 1;
            len++;
            i++;
        }
        else{ 
            if(len != 0) len = lps[len - 1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> search(string& pat, string& txt) {
    int n = txt.length();
    int m = pat.length();
    vector<int> lps(m,0);
    vector<int> res;
    computeLPS(pat, m, lps);
    int i = 0, j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j != 0) j = lps[j-1];
            else i++;
        }
        if(j == m){
            res.push_back(i-j);
            j = lps[j - 1];
        }
    }
    return res;
}

// Min Chars to Add for Palindrome
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

// Strings Rotations of Each Other
bool areRotations(string &s1, string &s2) {
    if(s1.length() != s2.length()) return false;
    string concat = s1 + s1;
    return concat.find(s2) != string::npos;
}

// Sort 0s, 1s and 2s
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

// Find H-Index
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

// 