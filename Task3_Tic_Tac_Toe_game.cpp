#include <iostream>
#include <vector>

using namespace std;
void displayboard(vector<char>&store){
    cout<<store[0]<<" "<<store[1]<<" "<<store[2]<<endl;
    cout<<store[3]<<" "<<store[4]<<" "<<store[5]<<endl;
    cout<<store[6]<<" "<<store[7]<<" "<<store[8]<<endl;
}
bool markboard(vector<char>&store,int pos,char mark){
    if(pos>9||pos<1){return false;}
    if(store[pos-1]=='x'||store[pos-1]=='o'){return false;}
    store[pos-1]=mark;return true;
}
int checkboard(vector<char>&store){
    //checking for X
    bool xwin=false;
    if(store[0]=='X'&&(store[1]=='X'&&store[2]=='X')){xwin=true;}
    if(store[3]=='X'&&(store[4]=='X'&&store[5]=='X')){xwin=true;}
    if(store[6]=='X'&&(store[7]=='X'&&store[8]=='X')){xwin=true;}
    if(store[0]=='X'&&(store[4]=='X'&&store[8]=='X')){xwin=true;}
    if(store[2]=='X'&&(store[4]=='X'&&store[6]=='X')){xwin=true;}
    if(store[0]=='X'&&(store[3]=='X'&&store[6]=='X')){xwin=true;}
    if(store[1]=='X'&&(store[4]=='X'&&store[7]=='X')){xwin=true;}
    if(store[2]=='X'&&(store[5]=='X'&&store[8]=='X')){xwin=true;}
    if(xwin){return 1;}
    bool Owin=false;
    if(store[0]=='O'&&(store[1]=='O'&&store[2]=='O')){Owin=true;}
    if(store[3]=='O'&&(store[4]=='O'&&store[5]=='O')){Owin=true;}
    if(store[6]=='O'&&(store[7]=='O'&&store[8]=='O')){Owin=true;}
    if(store[0]=='O'&&(store[4]=='O'&&store[8]=='O')){Owin=true;}
    if(store[2]=='O'&&(store[4]=='O'&&store[6]=='O')){Owin=true;}
    if(store[0]=='O'&&(store[3]=='O'&&store[6]=='O')){Owin=true;}
    if(store[1]=='O'&&(store[4]=='O'&&store[7]=='O')){Owin=true;}
    if(store[2]=='O'&&(store[5]=='O'&&store[8]=='O')){Owin=true;}
    if(Owin){return 2;}
    return 0;
}
int main()
{
    cout<<endl<<"Welcome to Tic Tac Toe game."<<endl<<endl;;
    while(true){
        cout<<"This game is played in a series of multiple rounds."<<endl;
        cout<<"How many rounds you want to play"<<endl;
        int rounds;
        cin>>rounds;
        cout<<endl<<"One last step before starting."<<endl;
        cout<<"Enter name of palyer1"<<endl;
        string player1;
        cin>>player1;
        cout<<"Enter name of player2"<<endl;
        string player2;
        cin>>player2;
        cout<<player1<<"your symbol is"<<" X "<<endl;
        cout<<player2<<"your symbol is"<<" O "<<endl;
        int score1=0;int score2=0;
        cout<<endl<<"Game starts!!!"<<endl;
        bool turnplayer1=true;
        while(rounds){rounds--;
        vector<bool> visited(10,false);
        vector<char>board={'1','2','3','4','5','6','7','8','9'};
        int turn;
        if(turnplayer1){turnplayer1=false;turn=1;}else{turn=2;turnplayer1=true;}
        for(int i=0;i<10;i++){
            cout<<"current board is"<<endl;displayboard(board);
            int a=checkboard(board);
            if(i==9){cout<<"It's a draw"<<endl;}
            if(a==1){displayboard(board);cout<<player1<<" Wins!!!"<<endl;score1++;break;}
            if(a==2){displayboard(board);cout<<player2<<" Wins!!!"<<endl;score2++;break;}
            bool movenext=false;
            while(!movenext){
                if(turn==1){cout<<player1<<" enter your input please"<<endl;int pos;cin>>pos;movenext=markboard(board,pos,'X');}
                if(turn==2){cout<<player2<<" enter your input please"<<endl;int pos;cin>>pos;movenext=markboard(board,pos,'O');}
                if(movenext){if(turn==1){turn=2;}else{turn=1;}}
                else{cout<<"Please enter a valid input and try again"<<endl;}
            }
        }
        
        }
        cout<<player1<<" total score is "<<score1<<endl;
        cout<<player2<<" total score is "<<score2<<endl;
        if(score1>score2){cout<<"Winner is "<<player1<<"!!!"<<endl;}
        else if(score1<score2){cout<<"Winner is "<<player2<<"!!!"<<endl;}
        else{cout<<"Both players had equal score ,so it's a Draw."<<endl;}

        bool playagain;
        while(true){
            cout<<"Enter 0 to exit game 1 to play again"<<endl;
            int inputuser;
            cin>>inputuser;
            if(inputuser==0){playagain=false;break;}
            else if(inputuser==1){playagain=true;break;}
            else{cout<<"Please enter a valid input"<<endl;}
            }
            if(playagain){continue;}
            else{break;}
    }

    return 0;
}