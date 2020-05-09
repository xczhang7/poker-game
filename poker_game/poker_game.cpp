#include "functions.h"
#include "version 2.h"
#include<stdio.h>

int main(){
  //
  print_guide();
  char command;
  cin>>command;
  while(command!='s'){
    if(command=='t'){print_chart();}
    else{cout<<"Please follow the guide!"<<endl;}
    cout<<"Command: ";
    cin>>command;
  }
  //
  player players[3];
  int a[3]={0,1,2};
  srand(time(NULL));
  for(int i=2;i>=1;--i)
    swap(a[i],a[rand()%i]);
  for(int i=0;i<3;++i){
    cout<<"Enter your name, player "<<i+1<<": ";
    cin>>players[a[i]].player_name;
  }
  cout<<"Your orders: "<<endl;
  for(int i=0;i<3;++i){
    cout<<i+1<<". "<<players[i].player_name<<';'<<endl;
    players[i].file_name=players[i].player_name+".txt";
  }
  cout<<endl;

  vector<int>card;
  InitCard(card);
  DealCard(card,players[0].hand,players[1].hand,players[2].hand);
  insertVec(players[0].file_name,players[0].hand);
  insertVec(players[1].file_name,players[1].hand);
  insertVec(players[2].file_name,players[2].hand);

  string winner;
  vector<int>last;
  vector<int>now;
  int i,breaks=0;
  while (winner.size()==0){
    for(i=0;i<3;i++){
      guide();
      cout<<'\n'<<players[i].player_name<<" goes."<<endl;
      cout<<"Command: ";
      cin>>command;
      while(command!='&'){
        switch(command){
          case 't': {
            print_chart();
            cout<<"Command:";
            cin>>command;
            break;
          }
          case 'p': {
            cout<<players[i].player_name<<" choose not to play, "
              <<players[(i+1)%3].player_name<<" continue."<<endl;
            command='&';
            breaks++;
            break;
          }
          case 'c':{
            cout<<"Cards "<<players[i].player_name<<" going to play:"<<endl;
            now=creatVec();
            print_vec(now);
            if(validPlay(last,now,players[i].hand)){
              remVec(players[i].file_name,now);
              rem(now,players[i].hand);
              last=now;
              command='&';
              break;
            }
            else{
              cout<<"Invalid play! Use command t to get the number-card table. Or open your file to check your hands."<<endl;
              cout<<"Command:";
              cin>>command;
              break;
            }
          }
          default:{
            cout<<"Invalid command, try again."<<endl;
            cout<<"Command:";
            cin>>command;
            break;
          }
        }
      }
      if(FileEmpty(players[i].file_name)){
        winner=players[i].player_name;
        break;
      }
      if(breaks==2){
        vector<int>().swap(last);
        vector<int>().swap(now);
        breaks=0;
      }
    }

  }
  cout<<"Winner of the game is "<<winner<<endl;
  char *ch;
  for(int i=0;i<3;++i){
    ch=const_cast<char*>(players[i].file_name.c_str());
    remove(ch);
  }
  return 0;
  }
