class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            vector<int> hash(10,0);
            for(int j = 0;j<9;j++){
                if(board[i][j] != '.'){
                    hash[board[i][j] - '0']++;
                }
            }
            for(int j = 0;j<10;j++){
                if(hash[j]>1) return false;
            }
        }

        for(int i = 0;i<9;i++){
            vector<int> hash (10,0);
            for(int j = 0;j<9;j++){
                if(board[j][i] != '.'){
                    hash[board[j][i] - '0']++;
                }
            }
            for(int j = 0;j<10;j++){
                if(hash[j]>1) return false;
            }
        }
        for(int i = 0;i<7;i+=3){
            for(int j = 0;j<7;j+=3){
                vector<int> hash(10,0);
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        if(board[i+k][j+l] != '.'){
                            hash[board[i+k][j+l] - '0']++;
                        }
                    }
                }
                for(int k = 0;k<10;k++){
                    if(hash[k]>1) return false;
                }
            }
        }

        
        return true;
    }
};