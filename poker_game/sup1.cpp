#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

bool FileEmpty(string fileName){
  ifstream fin(fileName);
  if(fin.fail()){
    cout<<"Error!"<<endl;
    exit(1);
  }
  string c;
  if(fin>>c)
    return true;
  else
    return false;
}

void printVec(vector<int>obj){
  for(int i=0;i<obj.size();++i){
    cout<<obj[i]<<' ';
  }
  cout<<endl;
}

bool isThreeOfApair(vector<int>obj){
  if(obj.size()!=5)
    return false;

  for(int i=0;i<5;i++)
    obj[i]%=13;

  sort(obj.begin(),obj.end());
  int repeat=1,max_repeat=1,sec_repeat=1;
  for(int i=0;i<5;++i){
    if (obj[i]==obj[i+1]){
      repeat++;
      if (repeat>max_repeat){
        sec_repeat=max_repeat;
        max_repeat=repeat;
      }
      else if (repeat<max_repeat && repeat>sec_repeat)
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

void B_sort(vector<int>&obj){
  sort(obj.begin(),obj.end());
  int i,j,len=obj.size();
  for(i=0;i<len-1;i++){
    for(j=0;j<len-1-i;j++){
      if(obj[j]<52 && obj[j+1]<52){
        if(obj[j]%13>obj[j+1]%13)
          swap(obj[j],obj[j+1]);
        }
      }
    }
  }

int main(){
  vector<int>obj;
  int r;
  for(int i=0;i<5;++i){
    cin>>r;
    obj.push_back(r);
  }
  if(isThreeOfApair(obj))
    cout<<'Y'<<endl;
  else
    cout<<'N'<<endl;
}
