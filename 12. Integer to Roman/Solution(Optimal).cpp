#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string intToRoman(int num) {
            array<int, 13> values   = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
            array<string, 13> romans = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
            string result = "";
            for (int i = 0; i < 13; ++i) {
                if(num==0){
                    break;
                }
                int n=num/values[i];
                while(n>0){
                    result+=romans[i];
                    n--;
                }
                num=num%values[i];
            }
            return result;
        }
    };
    