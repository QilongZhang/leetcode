/*************************************************************************
	> File Name: Integer_to_Roman.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月27日 星期一 11时43分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    string intToRoman(int num){
        int K = num/1000, H = (num/100)%10, T = (num/10)%10, S = num%10;
        string str;
        int i;
        for(i = 0; i < K; ++i)  str.push_back('M');
        if(H < 4){
            for(i = 0; i < H; ++i)  str.push_back('C');
        }
        else if(H == 4){
            str += "CD";
        }
        else if(H < 9){
            str.push_back('D');
            for(i = 0; i < H - 5; ++i)  str.push_back('C');
        }
        else{
            str += "CM";
        }

        if(T < 4){
            for(i = 0; i < T; ++i)  str.push_back('X');
        }
        else if(T == 4){
            str += "XL";
        }
        else if(T < 9){
            str.push_back('L');
            for(i = 0; i < T - 5; ++i)  str.push_back('X');
        }
        else{
            str += "XC";
        }

        if(S < 4){
            for(i = 0; i < S; ++i)  str.push_back('I');
        }
        else if(S == 4){
            str += "IV";
        }
        else if(S < 9){
            str.push_back('V');
            for(i = 0; i < S - 5; ++i)  str.push_back('I');
        }
        else{
            str += "IX";
        }
        return str;
    }
};

int main(){
    Solution st;
    cout<<st.intToRoman(3000)<<endl;
    return 0;
}
