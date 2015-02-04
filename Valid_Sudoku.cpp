/*************************************************************************
	> File Name: Valid_Sudoku.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月21日 星期五 15时13分44秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<vector<char> > &board){
        //判断行
        for(int i = 0; i < 9 ; ++i){
            vector<bool> vb(9, false);
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    continue;
                }
                if(!vb[board[i][j] - '1']){
                    vb[board[i][j] - '1'] = true;
                }
                else{
                    return false;
                }
            }
        }

        //判断列
        for(int i = 0; i < 9; ++i){
            vector<bool> vb(9, false);
            for(int j = 0; j < 9; ++j){
                if(board[j][i] == '.'){
                    continue;
                }
                if(!vb[board[j][i] - '1']){
                    vb[board[j][i] - '1'] = true;
                }
                else{
                    return false;
                }
            }
        }

        //判断子正方形
        for(int i = 0; i <= 6; i += 3){
            for(int j = 0; j <= 6; j += 3){
                vector<bool> vb(9, false);
                for(int m = 0; m < 3; ++m){
                    for(int n = 0; n < 3; ++n){
                        if(board[i + m][j + n] == '.'){
                            continue;
                        }
                        if(!vb[board[i + m][j + n] - '1']){
                            vb[board[i + m][j + n] - '1'] = true;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
