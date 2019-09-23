#include<iostream>
#include<vector>
using namespace std;
//统计一个数字在排序数组中出现的次数。
class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int begin = 0, end = data.size() - 1;
        if(end < 0 || k < data[begin] || k > data[end]) return 0;
        int mid;
        while(begin <= end){
        	mid = (begin + end) >> 1;
        	if(data[mid] < k) begin = mid + 1;
        	else if(data[mid] > k) end = mid - 1;
        	else break;
        }

        if(begin > end) return 0;

        mid = (begin + end) >> 1;
        int count = 1, i = mid - 1, j = mid + 1;
        while(i >= begin && data[i--] == k) ++count;
        while(j <= end && data[j++] == k) ++count;

        return count;
    }
};

/*
链接：https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2
来源：牛客网

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto resultPair = equal_range(data.begin(), data.end(),k);
        return resultPair.second - resultPair.first;
    }
};

//因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;     
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};
*/