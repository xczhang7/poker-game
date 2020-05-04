#include "functions.h"

#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

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
    cout<<"Enter your names: ";
    cin>>players[a[i]].player_name;
  }
  cout<<"Your orders: "<<endl;
  for(int i=0;i<3;++i)
    cout<<i+1<<". "<<players[i].player_name<<';'<<endl;
  cout<<endl;



  return 0;
}
