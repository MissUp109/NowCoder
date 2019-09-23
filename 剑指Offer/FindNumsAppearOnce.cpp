#include <iostream>
#include <vector>
using namespace std;
//一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字

//链接：https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811
//来源：牛客网

class Solution { //如果将所有所有数字相异或，则最后的结果肯定是那两个只出现一次的数字异或的结果
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      if(data.size() < 2) return;
      int size = data.size();
      int temp = data[0];
      for(int i = 1; i < size; i++) 
        temp = temp ^ data[i];
      if(temp == 0) return;

      int index = 0;
      while((temp & 1) == 0){ //括号不可以去
        temp = temp >> 1;
        ++index;
      }

      *num1 = *num2 = 0;
      for(int i = 0; i < size; i++){
        if(IsBit(data[i], index)) *num1 ^= data[i];
        else *num2 ^= data[i];
      }
    }

    bool IsBit(int num,int index){
      num = num >> index;
      return (num & 1);//括号不可以去
    }
};

//by leah
/*
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) {
        if(data.size() < 2) return;
        unordered_map<int, int> mm;
        for(int i = 0; i < data.size(); ++i){
            if(mm.count(data[i]) > 0) ++ mm[data[i]];
            else mm[data[i]] = 1;
        }
        bool flag = false;
        for(auto &i: mm){
            if(flag && i.second == 1){
                *num2 = i.first;
                break;
            }
            if(!flag &&i.second == 1){
                *num1 = i.first;
                flag = true;
            }
        }
    }
};*/