//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
//complexity o(m*n)
#include <bits/stdc++.h>
using namespace std;


 string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        vector<int> res(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                res[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]%=10;
            }
        }
        int i=0;
        string result ="";
        while(res[i]==0) i++;
        while(i<res.size()) result+=to_string(res[i++]);
        return result;
        
    }

int main(){
    string num1="123", num2="456";
    cout << multiply(num1, num2) << endl; // Output: 56088
    return 0;
}
