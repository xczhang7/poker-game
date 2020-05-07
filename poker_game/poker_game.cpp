#include "functions.h"
#include "version 2.h"

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
  vector<int>p1;
  vector<int>p2;
  vector<int>p3;
  InitCard(card);
  DealCard(card,p1,p2,p3);

  insertVec(players[0].file_name,p1);
  insertVec(players[1].file_name,p2);
  insertVec(players[2].file_name,p3);



  string winner;
  vector<int>last;
  vector<int>now;
  int i;
  while (winner.empty()){
    for(i=0;i<3;i++){
      guide();
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
            i++;
            cout<<"Command: ";
            cin>>command;
            break;
          }
          case 'c':{
            cout<<"Cards you going to play:"<<endl;
            now=creatVec();
            if(validPlay(last,now)){
              remVec(players[i].file_name,now);
              last=now;
              command='&';
              break;
            }
            else{
              cout<<"Invalid play!"<<endl;
              cout<<"Comand:";
              cin>>command;
              break;
            }
          }
        }
      }
    }
  }

  return 0;
  }
