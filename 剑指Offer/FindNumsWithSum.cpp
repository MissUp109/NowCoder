/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

//链接：https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b
//数列满足递增，设两个头尾两个指针i和j，若ai + aj == sum，就是答案（相差越远乘积越小）
class Solution {
public:
    vi FindNumbersWithSum(const vi& a,int sum) {
        vector<int> res;
        int n = a.size();
        int i = 0, j = n - 1;
        while(i < j){
            if(a[i] + a[j] == sum){
                res.push_back(a[i]);
                res.push_back(a[j]);
                break;
            }
            while(i < j && a[i] + a[j] > sum) --j;
            while(i < j && a[i] + a[j] < sum) ++i;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        if(array.size() < 2) return ret;
        unordered_map<int, int> mm;
        for(int i = 0; i < array.size(); ++i)
            if(mm.count(array[i]) > 0) mm[array[i]]++;
            else mm[array[i]] = 1;
        
        int mul = INT_MAX; int tmp[2];
        for(auto &i: mm){
            if(mm.count(sum - i.first) > 0){
                if((i.second > 1 && i.first == sum - i.first || 
                   i.first < sum - i.first) && mul > i.first * (sum - i.first)){
                    tmp[0] = i.first;
                    tmp[1] = sum - i.first;
                    mul = tmp[0] * tmp[1];
                }
            }
        }
        
        if(mul < INT_MAX){
            ret.push_back(tmp[0]); 
            ret.push_back(tmp[1]);
        }
        return ret;
    }
};