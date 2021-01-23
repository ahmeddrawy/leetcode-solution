//
// Created by ahmeddrawy on 1/22/21.
//

class Solution {
public:
    int myAtoi(string s) {
        return getString(s);
    }
    int getString(string s){
//        remove(s.begin(),s.end(), ' ');
        string ret ="";
        bool fst = false;
        bool pst = true;
        bool sign = false;
        bool fstp = false;
        for (int i = 0; i <s.size() ; ++i) {
            if(s[i] =='0' && !fstp){
                fst = 1;
                continue;

            }
            if (isdigit(s[i]) ){
                fstp = true;
                fst = true;
                ret+=s[i];
            }
            else if(!fst){
                if(!sign &&s[i] == '-'){
                    sign = true;
                    pst = false;
                    fst = 1;
                }
                else if(!sign&&s[i] =='+' )
                    sign = true, fst= 1;
                else if(s[i]==' ')continue;
                else return 0;
            }
            else if(fst){// we reached end of number
                break;
            }
        }
        reverse(ret.begin(), ret.end());
        long long ans = 0;
        for (int i = 0; i <ret.size() ; ++i){
            if(i>= 10){
                if(pst){
                    return (1ll<<31) - 1;
                }
                return (-1)*(1ll<<31);
            }
            ans += (ret[i]-'0')*(pow(10,i));
            if(ans >=(1ll<<31)){


                if(pst){
                    return (1ll<<31) - 1;
                }
                return (-1)*(1ll<<31);
            }

        }

        return (pst? 1 : -1) * ans;
    }
};