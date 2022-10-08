#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//     vector<string> letterCombinations(string digits) {
        
//     }
    

vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


    vector<string> letterCombinations(string digits, int index) {
        vector<string> res;
        int n = digits.size();
        
        if(n==0 || index >= n)
            return res;

        if(index == (n-1)){
            int currIndex = digits[index] - '0';
            for(int i=0;i<letters[currIndex].size();i++){
                // string newString = "" + letters[currIndex][i];
                string newString(1,letters[currIndex][i]);
                // cout<<"index "<<index<<" i "<<i<<" char "<<letters[currIndex][i]<<endl;
                res.push_back(newString);
                // cout<<"newString "<<newString<<endl;
            }
            // printString(res);
            return res;
        }

        vector<string> temp;
        temp = letterCombinations(digits, index + 1);
        int temp_len = temp.size();

        int currIndex = digits[index] - '0';
        
        for(int i=0;i<letters[currIndex].size();i++){
            char newChar = letters[currIndex][i];

            for(int j=0;j<temp_len;j++){
                string newString=newChar+temp[j];
                res.push_back(newString);    
            }

        }
        
        return res;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        res = letterCombinations(digits, 0);
        return res;
    }

};