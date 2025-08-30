class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
       
        for(int i = 0 ; i < n ; i++)
        {
            unordered_set<char>st;
            for(int j = 0 ; j < n ; j++)
            {
              //  cout<<"hello";
                if(st.count(board[i][j]))
                {
                  //  cout<<"asdf";
                    return 0;
                }
                if(board[i][j]!='.')
                st.insert(board[i][j]);
               
            }
        }

         for(int i = 0 ; i < n ; i++)
        {
            unordered_set<char>st;
            for(int j = 0 ; j < n ; j++)
            {
                if(st.count(board[j][i]))
                {
                    return 0;
                }
                if(board[j][i]!='.')
                st.insert(board[j][i]);
            }
        }
        for(int row = 0 ; row < 3 ; row++)
        {
            for(int col = 0 ; col < 3 ; col++)
            {
                unordered_set<char>st;
                for(int i = 0 ; i < 3 ; i++)
                {
                    for(int j = 0 ; j < 3 ; j++)
                    {
                        int r = row*3+i;
                        int c = col*3+j;
                        if(st.count(board[r][c]))
                    {
                        return 0;
                    }
                    if(board[r][c]!='.')
                    st.insert(board[r][c]);
                    }

                }
            }
        }
        return 1;
    }
};