#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
class Board{
private:
    vector <char> board;

public:
    Board(vector<char>);
    Board();
    vector<char> getBoard();
    void setBoard(int,int,int);
    int getBox(int,int);
    char getType(int);
    void showBoard();


};
Board::Board(){}

Board::Board(vector <char> _board){
board=_board;

}
void Board::setBoard(int x,int y,int z){
 board.clear();
 int a;
 a=x-z;
 for (int i = 0; i < z; ++i) {
            board.push_back('S');
        }


        for (int i = 0; i < y; ++i) {
             board.push_back('L');
        }


        for (int i = 0; i < (a-y); ++i) {
             board.push_back('N');
        }
        random_shuffle ( board.begin(), board.end() );
        board.push_back('+');
}

void Board::showBoard(){
for (int i = 0; i < board.size() ; ++i) {
             cout<<board[i]<<" ";
        }

cout<<endl;
for (int i = 0; i < board.size() ; ++i) {
             cout<<i+1;
        }
}
int Board::getBox(int A ,int B){
int C;
C=A+B;
return C;
}
char Board::getType(int B){
char U;
U=board[B-1];
return U;
}
vector<char> Board::getBoard(){
return board;
}

//---------------------------------------------------------------------------

class Player{
private:
    vector<vector<int>> players;

public:
    Player(vector<vector<int>> );
    Player();
    void setPlayers(int);
    vector<vector<int>> getPlayers();
};
Player::Player(){}

Player::Player(vector<vector<int>> _players){
players=_players;
}
void Player::setPlayers(int x){
 players.clear();
 for (int i = 0; i < x; ++i) {
             players.push_back({i+1, 1 , 1}); // jugador, turno, casilla
        }
}

vector<vector<int>> Player::getPlayers(){
return players;
}

//-------------------------------------------------------



class Snakes:public Board{

public:
    int getSnakes(vector<char>);

};
int Snakes::getSnakes(vector<char> board){
return count(board.begin(),board.end(),'S');
}

class Ladder : public Board{

public:
    int getLadders(vector<char> board);
};

int Ladder::getLadders(vector<char> board){
return count(board.begin(),board.end(),'L');
}

class MANUAL:public Board{
public:
void startM(vector<char> ACTIVEboard, vector<vector<int>> playersIN, int turns,int pen,  int rew ){
    cout<<"GAME STARTED"<<endl;
    // jugador, turno, casilla

    Board board1(ACTIVEboard);
    Player players1(playersIN);
    int z,A,C,E;
    char D,x;
    while (playersIN [0][1] < turns){
    for (int i = 0; i < playersIN.size(); ++i) {
        cout<<playersIN.size();

        cout<<"Press C to continue next turn, or E to end the game"<<endl;
        cin>>x;
        if(x!='C' && x!='E'){
        cout<<"NOT VALID"<<endl;
        }
        if(x=='E'){
            return;
        }
        if(x=='C'){
             z= (rand()% 6 + 1);
              A=playersIN[i][2];
              C=board1.getBox(z,A);
              E=C;
              D=board1.getType(C);
        if(D=='S'){
            E=E-pen;
        }
        if(D=='L'){
            E=E+rew;
        }

        cout << "Turn: " << playersIN[i][1]
     << ", Player "<< playersIN[i][0]
     <<" Box: " << A
     << ", Dice: " << z
     << ", Type: " << D
     << ", Box: " << E << endl;
        playersIN[i][2]= E;

        playersIN[i][1]=(playersIN[i][1])+1;

        if(E>=30){
        cout<<"PLAYER "<<playersIN[i][0]<<" WON"<<endl;
        return;
     }
        }


    }
    }
    cout<<"YOU HAVE REACHED THE LIMIT OF TURNS ALLOWED"<<endl;


}
};

class AUTOM: public Board, public Player{
public:
    void startA(vector<char> ACTIVEboard, vector<vector<int>> playersIN, int turns, int pen, int rew ){
     int z,x,C,E;
    char D;
    cout<<"GAME STARTED"<<endl;
    // jugador, turno, casilla
    Board board1(ACTIVEboard);
    Player players1(playersIN);
    while (playersIN [0][1] < turns){

         for (int i = 0; i < playersIN.size(); ++i) {
              z= (rand()% 6 + 1);
              x=playersIN[i][2];
              C=board1.getBox(z,x);
              E=C;
              D=board1.getType(C);
        if(D=='S'){
            E=E-pen;
        }
        if(D=='L'){
            E=E+rew;
        }

        cout << "Turn: " << playersIN[i][1]
     << ", Player "<< playersIN[i][0]
     <<" Box: " << x
     << ", Dice: " << z
     << ", Type: " << D
     << ", Box: " << E << endl;

        playersIN[i][2]= E;

        playersIN[i][1]=(playersIN[i][1])+1;

        if(E>=30){
        cout<<"PLAYER "<<playersIN[i][0]<<" WON"<<endl;
        return;
     }
        }

    }
    cout<<"YOU HAVE REACHED THE LIMIT OF TURNS ALLOWED"<<endl;

    }

};

//PROFE MI CODIGO NO CORRIA, SI HABÍA HECHO VARIOS ARCHIVOS
//PERO EL CODEBLOCKS SE TRABA NO SÉ POR QUÉ
