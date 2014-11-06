/*************************************************************************
	> File Name: Word_Search.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月06日 星期四 15时56分05秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
protected:
    bool isExist(vector<vector<char> > &board, int row, int col, string &word, int pos, vector<vector<bool> > &vvb){
        if(word[pos] == '\0') return true;
        else if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
        else if(board[row][col] != word[pos] || vvb[row][col]) return false;
        vvb[row][col] = true;
        bool ret = isExist(board, row + 1, col, word, pos + 1, vvb) || isExist(board, row - 1, col, word, pos + 1, vvb) \
                    || isExist(board, row, col + 1, word, pos + 1, vvb) || isExist(board, row, col - 1, word, pos + 1, vvb);
        vvb[row][col] = false;
        return ret;
    }

public:
    bool exist(vector<vector<char> > &board, string word){
        vector<vector<bool> > vvb(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j)
                if(isExist(board, i, j, word, 0, vvb))
                    return true;
        return false;
    }
};
