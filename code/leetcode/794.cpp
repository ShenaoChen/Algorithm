class Solution {
public:
    int check(char a, char b, char c){
        if(a == b && a == c){
            if(a == 'X')
                return 1;
            else if(a == 'O')
                return 2;
        }
        return 0;
    }
    bool validTicTacToe(vector<string>& board) {
        bool flag[3] = {false};
        int cnt1 = 0, cnt2 = 0, tmp;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(board[i][j] == 'X') cnt1++;
                else if (board[i][j] == 'O') cnt2++;
        if(cnt1 - cnt2 < 0 || cnt1 - cnt2 > 1)
            return false;
        for(int i = 0; i < 3; i++) {
            tmp = check(board[i][0], board[i][1], board[i][2]);
            flag[tmp] = true;
            tmp = check(board[0][i], board[1][i], board[2][i]);
            flag[tmp] = true;
        }
        tmp = check(board[0][0], board[1][1], board[2][2]);
        flag[tmp] = true;
        tmp = check(board[0][2], board[1][1], board[2][0]);
        flag[tmp] =true;
        if(flag[1] && flag[2])
            return false;
        if(!flag[1] && !flag[2] || flag[1] && cnt1 - cnt2 == 1 || flag[2] && cnt1 == cnt2)
            return true;
        return false;
    }
};
