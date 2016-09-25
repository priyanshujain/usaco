/*
ID: priyans8
LANG: C++
TASK: beads
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string process(string st, int n){
  string str = "";
  str += st.substr(n);
  if (n!=0) {
    str += st.substr(0,n);
  }
  return str;
}

int count(string str){
  int sum =0;
  //forward
  char ch;
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == 'w') {
      sum++;
    }else{
      ch = str[i];
      for (size_t j = i; j < str.length(); j++) {
        if (str[j] == ch || str[j] == 'w') {
          sum++;
        }else{
          break;
        }
      }
      break;
    }
  }
  //backward
  for (size_t i = str.length()-1; i >=0; i--) {
    if (str[i] == 'w') {
      sum++;
    }else{
      ch = str[i];
      for (size_t j = i; j >=0; j--) {
        if (str[j] == ch || str[j]== 'w') {
          sum++;
        }else{
          break;
        }
      }
      break;
    }
  }
  if (sum > str.length()) {
    sum = str.length();
  }
  return sum;
}

int main() {
  ifstream fin("beads.in");
  ofstream fout("beads.out");

  int n=0;
  fin>>n;
  string st = "";
  fin>>st;
  int max = -1;
  for (size_t i = 0; i < st.length(); i++) {
    string str = process(st ,i);
    int m =count(str);
    if (m>max) {
      max =m;
    }
  }
  fout << max << endl;
  return 0;
}
