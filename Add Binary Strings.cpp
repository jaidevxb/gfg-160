
// User function template for C++
class Solution {
  public:
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
};
