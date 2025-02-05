/*Tic Tac Toe


Represent the board
2D   int board[3][3]
1D    int board[9]
integer int board;
*/
//C does not initalize varaibles
#include <iostream>
using namespace std;
#include <cassert>
class game{

    char board[3][3];
// 
public:

game(){
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        board[i][j]='_';
}
void set(int r, int c, char player){
	assert(r<3 && r>=0 && c<3 && c>=0);
	board[r][c]=player;

}
char get(int r, int c, char player){
	assert(r<3 && r>=0 && c<3 && c>=0);
	return board[r][c];
}
void print(){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
        cout << board[i][j] << " ";
    
    
    }
    cout <<"\n";
}

void generate_boards(int index){
    if(index==9){
        //print board
        print();
        return;
    }
    int r=index/3;
    int c=index%3;
    board[r][c]='X';
    generate_boards(index+1);
    board[r][c]='O';
    generate_boards(index+1);
    board[r][c]='-';
    generate_boards(index+1);
}

void generate_all_board(){
    generate_boards(0);
}

};

int main(){
game g;
g.generate_all_board();
}

