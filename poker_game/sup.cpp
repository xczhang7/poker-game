#include "functions.h"
#include<fstream>

#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

void insertVec(ofstream &s, vector<int>obj){
  for(int i=0;i<obj.size();++i){
    switch(obj[i]/13){
      case 0:s<<SPADE;break;
      case 1:s<<CLUB;break;
      case 2:s<<HEART;break;
      case 3:s<<DIAMOND;
    }
    switch(obj[i]%13){
      case 0:s<<"A ";break;
      case 10:s<<"J ";break;
      case 11:s<<"Q ";break;
      case 12:s<<"K ";break;
      default:
        s<<obj[i]%13+1<<' ';
    }
  }
}

bool inVec(string str,vector<string>obj){
  for(int i=0;i<obj.size();++i){
    if (obj[i]==str) return true;
  }
  return false;
}

void remVec(string fileName, vector<int>obj){
  vector<string>obj1;
  string itr;
  for(int i=0;i<obj.size();++i){
    switch(obj[i]/13){
      case 0:itr=SPADE;break;
      case 1:itr=CLUB;break;
      case 2:itr=HEART;break;
      case 3:itr=DIAMOND;
    }
    switch(obj[i]%13){
      case 0:itr=itr+"A";break;
      case 10:itr=itr+"J";break;
      case 11:itr=itr+"Q";break;
      case 12:itr=itr+"K";break;
      default:
        itr=itr+to_string(obj[i]%13+1);
    }
  obj1.push_back(itr);
  }

  vector<string>obj2;
  ifstream fin;
  fin.open(fileName);
  if(fin.fail()){
    cout<<"Error!"<<endl;
    exit(1);
  }
  string str;
  while(fin>>str){
    if(!inVec(str,obj1))
      obj2.push_back(str);
    }
  fin.close();

  ofstream fout(fileName);
  if(fout.fail()){
    cout<<"Error!"<<endl;
    exit(1);
  }
  for(int j=0;j<obj2.size();++j)
    fout<<obj2[j]<<' ';
  fout.close();
}

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
  for(int i=0;i<2;++i){
    cin>>item;
    obj.push_back(item);
  }
  remVec("s.txt",obj);

  fout.close();

  return 0;
}
