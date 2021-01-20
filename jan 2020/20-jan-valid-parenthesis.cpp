//
// Created by ahmeddrawy on 1/20/21.
//

class Solution {
public:
    bool isValid(string s) {
        stack<char> mstack ;
        mstack.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            char top = '0';
            if(!mstack.empty())
                top = mstack.top();
            if(s[i] == ')'){
                if(top == '(')
                    mstack.pop();
                else{
                    mstack.push(s[i]);
                }
            }else if(s[i]=='}'){
                if(top == '{')
                    mstack.pop();
                else{
                    mstack.push(s[i]);
                }
            }
            else if(s[i]==']'){
                if(top == '[')
                    mstack.pop();
                else{
                    mstack.push(s[i]);
                }
            }else{
                mstack.push(s[i]);
            }
        }
        return mstack.empty();
    }
};