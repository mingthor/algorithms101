#include "../../util/common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        string res(num1.length()+num2.length(), '0');
        for (int i=(int)num1.length()-1; i>=0; i--) {
            int carry = 0;
            for (int j=(int)num2.length()-1; j>=0; j--) {
                int r = res[i+j+1]-'0'+(num1[i]-'0') * (num2[j]-'0') + carry;
                res[i+j+1] = r % 10 + '0';
                carry = r / 10;
            }
            res[i] += carry;
        }
        auto start = res.find_first_not_of('0');
        if (start == string::npos) return "0";
        return res.substr(start);
    }

    string naive_multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        string res;
        for (int i=num1.size()-1; i>=0; i--) {
            string r = multiply(num2, num1[i]);
            r.insert(r.end(), num1.size()-i-1, '0');
            res = add(res, r);
        }
        auto start = res.find_first_not_of('0');
        if (start == string::npos) return "0";
        return res.substr(start);
    }
    string multiply(string num, char digit) {
        int carry = 0;
        int d = digit-'0';
        for (auto it=num.rbegin(); it!=num.rend(); ++it) {
            int r = (*it-'0') * d + carry;
            *it = r % 10 + '0';
            carry = r / 10;
        }
        char c = '0'+carry;
        return c+num; 
    }
    string add(string num1, string num2) {
        int carry = 0;
        int i=(int)num1.size()-1;
        int j=(int)num2.size()-1;
        string res;
        for (; i>=0 || j>=0; i--,j--) {
            int di = i>=0 ? (num1[i]-'0') : 0;
            int dj = j>=0 ? (num2[j]-'0') : 0;
            res.push_back('0'+(di+dj+carry) % 10);
            carry = (di+dj+carry) / 10;
        }
        if (carry) res.push_back('0'+carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

TEST(Solution, multiply)
{
    string num1 = "123";
    string num2 = "2321";
    string res1 = multiply(num1, num2);
    ASSERT_EQ(res1, "285483");

    num1 = "0";
    num2 = "12";
    string res = multiply(num1, num2);
    ASSERT_EQ(res, "0");

    num1 = "9133";
    num2 = "0";
    res = multiply(num1, num2);
    ASSERT_EQ(res, "0");

    num1 = "";
    num2 = "";
    res = multiply(num1, num2);
    ASSERT_EQ(res, "");

    num1 = "123";
    num2 = "456";
    res = multiply(num1, num2);
    ASSERT_EQ(res, "56088");
}

int main()
{
    RunAllTests();
    return 0;
}