#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <numeric>
#include <vector>
#include <algorithm>
#include "classes.cpp"

using namespace std;

class MyGame
{
public:
void start()
{
Board board1;
Snakes sn;
Ladder ld;
Player players1;
MANUAL manual;
AUTOM autom;
board1.setBoard(30,3,3);
players1.setPlayers(2);
    int n,l,s;
    /*board1.setBoard(n,l,s);*/
    char x,D;
    int penaltySnakes = 3;
    int rewardLadder = 3;
    int A,C,E,F,z,turnsP;
    turnsP=50;
    string gamemode;
    gamemode = "manual";
    while (x!= 'E'){
    cout<<"Welcome to the game 'Snakes n Ladders', press S to start, E to exit, M to access SETTINGS"<<endl;
    cout<<"Current mode: "<< gamemode <<endl;
    cin>>x;
    if(x!='S' && x!='E' && x!= 'M'){
        cout<<"NOT VALID"<<endl;
        }
    if(x=='S'){
       cout<<"GAME STARTED"<<endl;
       if(gamemode == "manual"){
        manual.startM(board1.getBoard(),players1.getPlayers(),turnsP,penaltySnakes,rewardLadder);

       }
    if(gamemode == "auto"){
    autom.startA(board1.getBoard(),players1.getPlayers(),turnsP,penaltySnakes,rewardLadder);
    }
    }
    if(x=='M'){
    int modeGAME;

    int y,r;
    y=1;
    while(y!=9){
    cout<<"Current board: "<<endl;
    board1.showBoard();
    cout<<"Number of tiles: "<<(board1.getBoard()).size()<<endl;
     cout<<""<<endl;
     cout<<"Number of players: "<<(players1.getPlayers()).size()<<endl;
     cout<<""<<endl;

    cout<<"SETTINGS"<<endl;
    cout<<"1.-Modify number of tiles"<<endl;
    cout<<"2.-Modify number of snakes on board"<<endl;
    cout<<"3.-Modify number of ladders on board"<<endl;
    cout<<"4.-Modify penalty for snakes"<<endl;
    cout<<"5.-Modify reward for ladders"<<endl;
    cout<<"6.-Modify number of players"<<endl;
    cout<<"7.-Modify number of turns"<<endl;
    cout<<"8.-GAME TYPE"<<endl;
    cout<<"9.-Return"<<endl;
    cin>>y;
    if(y==1){
    cout<<"New number of tiles: ";
    cin>>r;
    board1.setBoard(r,sn.getSnakes(board1.getBoard()),ld.getLadders(board1.getBoard()));
    }
    if(y==2){
    cout<<"New number of SNAKES: ";
    cin>>r;
    board1.setBoard(((board1.getBoard()).size()),ld.getLadders(board1.getBoard()),r);
    }
    if(y==3){
    cout<<"New number of LADDERS: ";
    cin>>r;
    board1.setBoard(((board1.getBoard()).size()),r, sn.getSnakes(board1.getBoard()));
    }
    if(y==4){
    int newP;
    cout << "Current penalty for snakes= "<< penaltySnakes<<endl;
    cout<<"NEW PENALTY= ";
    cin>> newP;
    penaltySnakes = newP;
    }
    if(y==5){
    int newR;
    cout << "Current reward for ladders= "<< penaltySnakes<<endl;
    cout<<"NEW REWARD= ";
    cin>> newR;
    rewardLadder = newR;
    }
    if(y==6){
    cout<<"New number of players: ";
    cin>>r;
    players1.setPlayers(r);
    }
    if(y==7){
    cout<<"New number of turns: ";
    cin>>r;
    turnsP = r;
    }
    if(y==8){

    cout<<"New number of turns: ";
    cout<<"1. Manual ";
    cout<<"2. Auto ";
    cin>>modeGAME;
    if(modeGAME == 1){
        gamemode = "manual";
    }
    if(modeGAME == 2){
        gamemode = "auto";
    }
    if(modeGAME != 2 && modeGAME != 1){
        cout<<"NOT VALID"<<endl;
    }
    }
    }
    }
}
return;
}
};
int main()
{

//cout<<rand()% 6 + 1;

MyGame g;
g.start();
cout<<"GAME ENDED"<<endl;
return 0;
}
