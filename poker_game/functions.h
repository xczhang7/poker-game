#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

struct player{
  int order;
  string player_name,file_name;
  vector<string>hand;
};

#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

void print_chart(){
  for(int i=0;i<52;++i){
      switch(i/13){
        case 0:
        cout<<SPADE;break;
        case 1:
        cout<<CLUB;break;
        case 2:
        cout<<HEART;break;
        case 3:
        cout<<DIAMOND;break;
      }

      if(i%13==0){cout<<"A ";}
      else if(i%13>0&&i%13<10){cout<<i%13+1<<' ';}
      else if(i%13==10){cout<<"J ";}
      else if(i%13==11){cout<<"Q ";}
      else if(i%13==12){
        cout<<"K "<<endl;
        for(int j=i-12;j<i;j++){
          if(j%13==9){cout<<setw(3)<<left<<j<<' ';}
          else{cout<<setw(2)<<left<<j<<' ';}
        }
        cout<<setw(2)<<left<<i<<endl;
        cout<<endl;
      }
    }
    cout<<"Red Joker"<<'\t'<<"Black Joker"<<endl;
    cout<<setw(9)<<left<<52<<'\t'<<53<<endl;
    cout<<'\n'<<endl;
  return;
}

void print_guide(){
  for(int f=0;f<60;f++){cout<<'*';}
  cout<<endl;
  cout<<"******";
  cout<<setfill('*')<<setw(54)<<left<<
  "Welcome to our game: fight the landlord. Enjoy!"<<endl;
  cout<<setfill(' ');
  for(int f=0;f<60;f++){cout<<'*';}
  cout<<'\n'<<endl;
  cout<<"1. Enter 't' to get the table of Numbers and cards."<<endl;
  cout<<"2. Enter 's' to start the game.\n"<<endl;
  cout<<"Command: ";
}

bool isFourTwo(vector<int>obj){
  if(obj.size()!=6)
    return false;
  for(int i=0;i<6;i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());
  int repeat=1,max_repeat=1;
  for(int i=0;i<5;++i){
    if (obj[i]==obj[i+1]){
      repeat++;
      if (repeat>max_repeat)
        max_repeat=repeat;
    }
    else
      repeat=1;
    }
  if (max_repeat==4)
    return true;
  else
    return false;
}

bool isBoomber(vector<int>obj){
  if(obj.size()!=4)
    return false;

  for(int i=0;i<4;i++)
    obj[i]%=13;
  for(int i=0;i<3;++i){
    if (obj[i]!=obj[i+1])
      return false;
    }
    return true;
}

bool isRocket(vector<int>obj){
  if(obj.size()!=2)
    return false;

  sort(obj.begin(),obj.end());
  if(obj[0]==52 && obj[1]==53)
    return true;
  else
    return false;
}

bool isOnePair(vector<int>obj){
  if(obj.size()!=2)
    return false;

  for(int i=0;i<2;i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());
  if(obj[0]==obj[1])
    return true;
  else
    return false;
}

bool isThree(vector<int>obj){
  if(obj.size()!=3)
    return false;

  for(int i=0;i<3;i++)
    obj[i]%=13;
  for(int i=0;i<2;++i){
    if (obj[i]!=obj[i+1])
      return false;
    }
    return true;
}

bool isThreeofAkind(vector<int>obj){
  if(obj.size()!=4)
    return false;
  for(int i=0;i<4;i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());
  int repeat=1,max_repeat=1;
  for(int i=0;i<3;++i){
    if (obj[i]==obj[i+1]){
      repeat++;
      if (repeat>max_repeat)
        max_repeat=repeat;
    }
    else
      repeat=1;
    }
  if (max_repeat==3)
    return true;
  else
    return false;
}

bool isThreeOfApair(vector<int>obj){
  if(obj.size()!=5)
    return false;
  for(int i=0;i<5;i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());
  int repeat=1,max_repeat=1,sec_repeat=1;
  for(int i=0;i<4;++i){
    if (obj[i]==obj[i+1]){
      repeat++;
      if (repeat>max_repeat)
        max_repeat=repeat;
      else if (repeat<max_repeat&&repeat>sec_repeat)
        sec_repeat=repeat;
    }
    else
      repeat=1;
    }
  if (max_repeat==3&&sec_repeat==2)
    return true;
  else
    return false;
}

bool isStraight(vector<int>obj){
  if(obj.size()<5)
    return false;

  for(int i=0;i<obj.size();i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());
  for(int i=0;i<obj.size()-1;++i){
    if (obj[i]!=obj[i+1]-1)
      return false;
    }
  return true;
}

bool isPairStraight(vector<int>obj){
  if(obj.size()<6||obj.size()%2!=0)
    return false;

  for(int i=0;i<obj.size();i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());
  for(int i=0;i<obj.size()-1;i+=2){
    if (obj[i]!=obj[i+1])
      return false;
    if(i+2<obj.size()){
      if(obj[i]!=obj[i+2]-1)
        return false;
    }
  }
  return true;

}

bool isThreeStraight(vector<int>obj){
  if(obj.size()<6||obj.size()%3!=0)
    return false;

  for(int i=0;i<obj.size();i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());
  for(int i=0;i<obj.size()-1;i+=3){
    if (obj[i]!=obj[i+1]||obj[i]!=obj[i+1])
      return false;
    if(i+3<obj.size()){
      if(obj[i]!=obj[i+3]-1)
        return false;
    }
  }
  return true;

}

bool isPlane(vector<int>obj){
  if(obj.size()<8)
    return false;
  for(int i=0;i<obj.size();i++)
    obj[i]%=13;
  sort(obj.begin(),obj.end());

  vector<int>body;
  vector<int>wings;

  for(int i=0;i<obj.size();i++){
    if(i+2<obj.size()&&obj[i]==obj[i+1]&&obj[i]==obj[i+2]){
        body.push_back(obj[i]);
        i+=2;
      }
    else
      wings.push_back(obj[i]);
    }
//
  for(int j=0;j<body.size()-1;j++){
    if(body[j]!=body[j+1]-1)
      return false;
  }

  if(wings.size()==body.size()){
    for(int j=0;j<body.size()-1;j++){
      if(wings[j]==wings[j+1])
        return false;
    }
    return true;
  }

  else if (wings.size()==2*body.size()){
    for(int i=0;i<wings.size()-1;i+=2){
      if (wings[i]!=wings[i+1])
        return false;
      }
    return true;
  }

  return false;
}

string cardType(vector<int>obj){
  if(obj.size()==1)
    return "Single";
  else if(isFourTwo(obj))
    return "FourTwo";
  else if(isBoomber(obj))
      return "Boomber";
  else if(isRocket(obj))
      return "Rocket";
  else if(isOnePair(obj))
      return "OnePair";
  else if(isThree(obj))
      return "Three";
  else if(isThreeofAkind(obj))
      return "ThreeofAkind";
  else if(isThreeOfApair(obj))
      return "ThreeOfApair";
  else if(isStraight(obj))
      return "Straight";
  else if(isPairStraight(obj))
      return "PairStraight";
  else if(isThreeStraight(obj))
      return "ThreeStraight";
  else if(isPlane(obj))
      return "Plane";
  else
      return "Invalid Play!";
}
