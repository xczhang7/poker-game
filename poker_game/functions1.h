#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

//如果我函数出错了，你可以直接根据我写在函数顶上的描述重写。
//或者告诉我哪些test_case过不了。
//我知道合作写代码这问题没法解决。


//struct里储存了三个元素，玩家的名字，
//对应的手牌文件的名字，还有储存有他手牌信息的vector。
struct player{
  string file_name;
  string player_name;
  vector<string>hand;
};

//为了打印出红桃方片这些图像。
#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

//检查文件是否为空。请检查一下写对没。
bool FileEmpty(string fileName){
  ifstream fin;
  string ch;
  fin.open("a.txt");
  ch=fin.get();
  if(fin.eof())
    return true;
  fin.close();
  return false;
}

//节省时间，不用看。
void guide(){
  cout<<"Please input command:"<<endl;
  cout<<"1.t: See the number-card chart;"<<endl;
  cout<<"2.p: choose not to play in this round;"<<endl;
  cout<<"3.c: play a hand;"<<endl;
}


//输入vector<int>，再把手牌输入到对应文件里。要检查。
void insertVec(string fileName, vector<int>obj){
  ofstream s;
  s.open(fileName);
  if(s.fail()){
    cout<<"error!"<<endl;
    exit(1);
  }

  sort(obj.begin(),obj.end());
  for(int j=0;j<obj.size();j++)
    cout<<obj[j]<<' ';
  cout<<'\n'<<endl;

  for(int i=0;i<obj.size();++i){
    if(obj[i]<51){
      switch(obj[i]/13){
        case 0:s<<SPADE;break;
        case 1:s<<CLUB;break;
        case 2:s<<HEART;break;
        case 3:s<<DIAMOND;break;
      }
      switch(obj[i]%13){
        case 0:s<<"A ";break;
        case 10:s<<"J ";break;
        case 11:s<<"Q ";break;
        case 12:s<<"K ";break;
        case 1: case 2: case 3:
        case 4: case 8: case 7:
        case 6: case 5: case 9:
          s<<obj[i]%13+1<<' ';break;
        }
      }
      else{
        switch(obj[i]%13){
          case 0:s<<"B_Jack ";break;
          case 1:s<<"R_Jack ";break;
        }
      }
    }
    s.close();
}

//判断string在不在vector里。是辅助下面写的remVec函数的。
bool inVec(string str,vector<string>obj){
  for(int i=0;i<obj.size();++i){
    if (obj[i]==str) return true;
  }
  return false;
}

//从文件中删牌。输入一个装有出牌的vector，把这些牌从文件里去掉。
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
    cout<<"2Error!"<<endl;
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

//节省时间。
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

//节省时间。
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


//以下都要检查。
//判断四带二。
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

//判断炸弹
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

//判断王炸
bool isRocket(vector<int>obj){
  if(obj.size()!=2)
    return false;

  sort(obj.begin(),obj.end());
  if(obj[0]==52 && obj[1]==53)
    return true;
  else
    return false;
}

//判断对子
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

//判断单出三张一样的牌
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

//判断三带一
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

//判断三带二
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

//判断顺子
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

//判断连对
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

//判断飞机不带翅膀。就是没有散牌。
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

//判断飞机
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

//输入玩家出牌，就是一个vector<int>,返回牌型（以string表示）。
//以上那些bool函数都是这个函数的辅助。
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
      return "Invalid Play";
}

//以下函数用于判断玩家出的牌合不合理。我详细说下。
//我的想法是，首先判断他出的是不是王炸或者炸弹。
//然后看他出的牌类型和上家一不一样。
//如果一样，还有个大小判断的问题。
//比如上家出了对4，你出对3肯定不行。
//我的解决思路是，找出“权重”来，比权重。
//比如三带二，看的是“三”，与二无关。
//比哪张牌，我就把那张牌的数字抽出来比较。

//这几个函数我写的很糙。现在他们连A>4都判断不了，只知道比较纯数字。
//很需要检查重写。

//这个是调取”权重“的函数。
int cardWeight(vector<int>obj){
  if(obj.size()==1)
    return obj[0];
  else if(isFourTwo(obj)){
    for(int i=0;i<6;i++)
      obj[i]%=13;
    sort(obj.begin(),obj.end());
    return obj[3];
  }
  else if(isBoomber(obj))
      return obj[0];
  else if(isOnePair(obj))
      return obj[0];
  else if(isThree(obj))
      return obj[0];
  else if(isThreeofAkind(obj)){
    for(int i=0;i<4;i++)
      obj[i]%=13;
    sort(obj.begin(),obj.end());
    return obj[2];
  }
  else if(isThreeOfApair(obj)){
    for(int i=0;i<5;i++)
      obj[i]%=13;
    sort(obj.begin(),obj.end());
    return obj[2];
  }
  else if(isStraight(obj)){
    for(int i=0;i<obj.size();i++)
      obj[i]%=13;
    sort(obj.begin(),obj.end());
    return obj[0];
  }
  else if(isPairStraight(obj)){
    for(int i=0;i<obj.size();i++)
      obj[i]%=13;
    sort(obj.begin(),obj.end());
    return obj[0];
  }
  else if(isThreeStraight(obj)){
    for(int i=0;i<obj.size();i++)
      obj[i]%=13;
    sort(obj.begin(),obj.end());
    return obj[0];
  }

  else if(isPlane(obj)){
    for(int i=0;i<obj.size();i++)
      obj[i]%=13;
    sort(obj.begin(),obj.end());

    vector<int>body;

    for(int i=0;i<obj.size()-2;i++){
      if(obj[i]==obj[i+1]&&obj[i]==obj[i+2]){
        body.push_back(obj[i]);
        i+=2;
      }
    }
    return body[0];
  }
}

//这个是判断出牌合不合理的函数。
bool validPlay(vector<int>last,vector<int>now){
  string type_last,type_now;
  type_last=cardType(last);
  type_now=cardType(now);
  if (last.size()==0) return true;
  else if (type_now=="Invalid Play") return false;
  else if (type_now=="Rocket") return true;
  else if (type_last!="Boomber"&&type_now=="Boomber")return true;
  else if (type_now==type_last && cardWeight(now)>cardWeight(last))
      return true;
  return false;
}

//这个函数的目的是读取玩家输入，用Vector来储存他们的出牌信息。
vector<int> creatVec(){
  vector<int>g;
  int k,n=0;
  while(cin>>k){
    g.push_back(k);
    n++;
    if(cin.get()=='\n')break;
  }
  return g;
}
