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
    vector <int> VAL;

public:
    Board(vector<char>,vector <int>);
    Board();
    vector<char> getBoard();
    vector<int> getBoardVAL();
    void setBoard(int,int,int);
    void setBoardVAL(int,int,vector<char>);
    int getBox(int,int);
    char getType(int);
    void showBoard();
    void showBoardVAL();


    int operator+(int index) const {
        if (index >= 0 && index < board.size()) {
            int result = VAL[index];


            if (board[index] == 'S') {


                int penalty = (VAL[index]);
                result = -penalty;
            }
            if (board[index] == 'L') {

                int bonus = (VAL[index]);
                result = bonus;
            }
                 return result;
        }


}
};
Board::Board(){};
Board::Board(vector <char> _board,vector<int> _val){
board=_board;
VAL = _val;
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

}

void Board::setBoardVAL(int x,int y,vector<char> B){
 VAL.clear();
 int a;

 for (int i = 0; i < board.size(); ++i) {
        if(B[i]=='L'){
        VAL.push_back(y);
        }
        if(B[i]=='S'){
        VAL.push_back(x);
        }
         if(B[i]=='N'){
        VAL.push_back(0);
        }
}
}
void Board::showBoard(){
    cout<<" "<<endl;
for (int i = 0; i < board.size() ; ++i) {
             cout<<board[i]<<" ";
        }
}

void Board::showBoardVAL(){
for (int i = 0; i < VAL.size() ; ++i) {
             cout<<VAL[i]<<" ";
        }

cout<<endl;

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
vector<int> Board::getBoardVAL(){
return VAL;
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
class Turn{
private:
    int playerTURN;
    int player;
    int box;
    int dice;
    char type;
    int newbox;

    public:
        Turn();
        Turn(int,int,int,int,char,int);
friend ostream& operator<<(ostream& os, const  Turn& turn)
{
    os << "Turn: " << turn.playerTURN
           << ", Player: " << turn.player
           << ", Box: " << turn.box
           << ", Dice: " << turn.dice
           << ", Type " << turn.type
           << ", New Box: " << turn.newbox;
    return os;
}

};

Turn::Turn(){}

Turn::Turn(int _playerTURN, int _player, int _box, int _dice, char _type, int _newBox){

playerTURN=_playerTURN;
player=_player;
box=_box;
dice=_dice;
type=_type;
newbox=_newBox;

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
void startM(vector<char> ACTIVEboard,vector<int> ACTIVEboardVAL, vector<vector<int>> playersIN, int turns,int pen,  int rew ){
    cout<<"GAME STARTED"<<endl;
    // jugador, turno, casilla

    Board board1(ACTIVEboard,ACTIVEboardVAL);
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

              D=board1.getType(C);

            int newBox = board1 + (C-1);
            E= C+newBox;
    Turn turn1(playersIN[i][1],playersIN[i][0],A,z,D,E);
    cout<<turn1<<endl;

        playersIN[i][1]=(playersIN[i][1])+1;

        if(E>=(board1.getBoard()).size()-1){
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
    void startA(vector<char> ACTIVEboard,vector<int> ACTIVEboardVAL, vector<vector<int>> playersIN, int turns, int pen, int rew ){
     int z,x,C,E;
    char D;
    cout<<"GAME STARTED"<<endl;
    // jugador, turno, casilla
    Board board1(ACTIVEboard,ACTIVEboardVAL);
    Player players1(playersIN);
    while (playersIN [0][1] < turns){

         for (int i = 0; i < playersIN.size(); ++i) {
              z= (rand()% 6 + 1);
              x=playersIN[i][2];
              C=board1.getBox(z,x);
              E=C;
              D=board1.getType(C);
//sobrecarga operador +
            int newBox = board1 + (C-1);
            E= C+newBox;
//sobrecarga operador <<
        Turn turn1(playersIN[i][1],playersIN[i][0],x,z,D,E);
        cout << turn1<<endl;

        playersIN[i][2]= E;

        playersIN[i][1]=(playersIN[i][1])+1;

        if(E>=(board1.getBoard()).size()){
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
