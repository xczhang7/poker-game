#include "functions.h"

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
  for(int i=0;i<3;++i){
    cout<<i+1<<". "<<players[i].player_name<<';'<<endl;
    players[i].file_name=players[i].player_name+".txt";
  }
  cout<<endl;

  vector<int>obj;
  ofstream fout(players[0].file_name);

  if (fout.fail()){
    cout<<"Error!"<<endl;
    exit(1);
  }

  int item;
  for(int i=0;i<6;++i){
    cin>>item;
    obj.push_back(item);
  }
  isFourTwo(obj);
  for(int i=0;i<6;++i)
    cout<<obj[i]<<' ';

  fout.close();

  return 0;
}
