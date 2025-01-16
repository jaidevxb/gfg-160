class Solution {
  public:
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
};
