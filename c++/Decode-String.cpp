class Solution {
public:
    string multiplyString(string s, int n) {
        string res = "";
        for(int i=0; i<n; i++) {
            res += s;
        }
        return res;
    }

    string decodeString(string s) {
        string result = "";
        stack<int> intStack;
        stack<char> stringStack;

        for(int i=0; i<s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int pow = 1, number = 0;
                while(i<s.size() && s[i] >= '0' && s[i] <= '9') {
                    number = number*pow + (s[i]-'0');
                    pow = 10;
                    i++;
                }
                intStack.push(number);
            }
            if((s[i] == '[') || (s[i] >= 'a' && s[i] <= 'z')) {
                stringStack.push(s[i]);
            }
            if(s[i] == ']') {
                while(stringStack.top() != '[') {
                    result = stringStack.top() + result;
                    stringStack.pop();
                }
                stringStack.pop();
                result = multiplyString(result, intStack.top());
                intStack.pop();

                for(int j=0; j<result.size(); j++) {
                    stringStack.push(result[j]);
                }
                result = "";
            }
        }

        while(!stringStack.empty()) {
            result = stringStack.top() + result;
            stringStack.pop();
        }

        return result;
    }
}; 