#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "ArgumentManager.h"
#include "btree.h"
using namespace std;

int main(int argc, char *argv[])
{
  ArgumentManager am(argc, argv);
  ifstream fin(am.get("input"));
  ofstream fout(am.get("output"));
    
  string str_num;
  int num;
  vector<int> array;
  
  while(fin>>str_num){
    num=stoi(str_num);
    array.push_back(num);
  }
  
  for(int i =0;i<array.size();i++){
    tree.insert(array[i]);
  }
    
  return 0;
}
