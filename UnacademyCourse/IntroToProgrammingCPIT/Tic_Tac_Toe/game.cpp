#include<iostream>

struct Player {
    std::string name;
    int score;
    int rating;
    char symbol;
};

char board[3][3];

bool judge_row(char ch) {
    if(board[0][0] == ch and board[0][1] == ch and board[0][2] == ch) return true;
    else if(board[1][0] == ch and board[1][1] == ch and board[1][2] == ch) return true;
    else if(board[2][0] == ch and board[2][1] == ch and board[2][2] == ch) return true;
    else return false;
}

bool judge_col(char ch) {
    if(board[0][0] == ch and board[1][0] == ch and board[2][0] == ch) return true;
    else if(board[0][1] == ch and board[1][1] == ch and board[2][1] == ch) return true;
    else if(board[0][2] == ch and board[1][2] == ch and board[2][2] == ch) return true;
    else return false;
}

bool judge_diag(char ch) {
    if(board[0][0] == ch and board[1][1] == ch and board[2][2] == ch) return true;
    else if(board[0][2] == ch and board[1][1] == ch and board[2][0] == ch) return true;
    else return false;
}

void init_board() {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
}

void print_board() {
    for(int row = 0; row < 3; row++) {
        std::cout<<"| ";
        for(int col = 0; col < 3; col++) {
            std::cout<<board[row][col]<<" | ";
        }
        std::cout<<"\n";
        std::cout<<"---------------\n";
    }
}

void start_game() {
    Player p1, p2;
    p1.score = p2.score = 0;
    p1.symbol = 'O';
    p2.symbol = 'X';
    std::cout<<"What is the name for p1 ? \n";
    std::cin>>p1.name;
    std::cout<<"What is the name for p2 ? \n";
    std::cin>>p2.name;

    int games;
    std::cout<<"How many games you want to play ? ";
    std::cin>>games;
    for(int i = 0; i < games; i++) {
        int counter = 0;
        int turn = true; // true -> p1, false -> p2
        init_board();
        print_board();
        while(counter < 9) {
            Player curr_player = (turn) ? p1 : p2;
            std::cout<<curr_player.name<<" Where you want to place the symbol\n";
            int x, y;
            std::cin>>x>>y; // 0 based indexing given
            if(board[x][y] != ' ') {
                std::cout<<"Invalid input, please try again\n";
                continue;
            } else {
                board[x][y] = curr_player.symbol;
            }
            print_board();
            
            bool result = false;
            result = result or judge_row(curr_player.symbol);
            result = result or judge_col(curr_player.symbol);
            result = result or judge_diag(curr_player.symbol);
            if(result == true) {
                std::cout<<curr_player.name<<" has won the game!!!\n";
                if(turn) p1.score += 1;
                else p2.score += 1;
                
                break;
            }
            turn = not turn;
            counter++;
            if(counter == 9) {
                std::cout<<"Its a draw!!!\n";
            }
        }
    }

    std::cout<<"Score of "<<p1.name<<" is "<<p1.score<<"\n";
    std::cout<<"Score of "<<p2.name<<" is "<<p2.score<<"\n";

}

int main() {
    init_board();
    start_game();
    return 0;
}