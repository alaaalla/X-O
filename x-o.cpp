#include<iostream>
using namespace std; 
char player ='X';
char Matrix [3][3]={'1','2','3','4','5','6','7','8','9'};
void Draw(){
  cout<<" ------- \n";
  for(int r=0;r<3;r++){
    cout<<"| ";
    for(int c=0;c<3;c++){
      cout<<Matrix[r][c]<<" ";}
      cout<<"|\n";
    }
    cout<<" ------- \n";
}

void replace(){
  char pos;
  cout<<"Enter your position ("<<player<<") \n";
  cin>>pos;
  for(int r=0;r<3;r++){
    for(int c=0;c<3;c++){
      if (Matrix[r][c]==pos){
        Matrix[r][c] = player;}
      }
    }
    if(player=='X') 
    player='O';
    else {player='X';}
}

char checkWinner(){
  int X=0,O=0,counter=0;
  for(int r=0;r<3;r++){
    for(int c=0;c<3;c++){
      if(Matrix[r][c]=='X')X++;
      else if(Matrix[r][c]=='O')O++;
      if(X==3)return 'X';
      if(O==3)return 'O';
    }
    X=0,O=0;
  }
  for(int c=0;c<3;c++){
    for(int r=0;r<3;r++){
      if(Matrix[r][c]=='X')X++;
      else if(Matrix[r][c]=='O')O++;
      if(X==3)return 'X';
      if(O==3)return 'O';
    }
    X=0,O=0;
  }

  if(Matrix[0][0]=='X'&& Matrix[1][1]=='X'&& Matrix[2][2]=='X')
   return 'X';
  else if(Matrix[0][0]=='O'&& Matrix[1][1]=='O'&& Matrix[2][2]=='O')
   return 'O';

  else if(Matrix[0][2]=='X'&& Matrix[1][1]=='X'&& Matrix[2][0]=='X')
    return 'X';
  else if(Matrix[0][2]=='O'&& Matrix[1][1]=='O'&& Matrix[2][0]=='O')
   return 'O';

for (int r=0;r<3;r++){
  for(int c=0; c<3; c++){
    if(Matrix[r][c]!='X' && Matrix[r][c]!='O')counter++;
  }
}
if(counter==0)return'F';
return'*';
}
int main(){
  while(checkWinner()=='*'){
    Draw();
    replace();
    checkWinner();
  }
  Draw();
  if(checkWinner()=='X'){
    cout<<"\nThe winner is player X\n";
  }
  if(checkWinner()=='O'){
    cout<<"\nThe winner is player O\n";
  }
  if(checkWinner()=='F'){
    cout<<"\nThere is no winner\n";
  }
  return 0;
}