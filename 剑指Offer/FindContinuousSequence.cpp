#include <iostream>
#include <vector>
using namespace std;

//输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

//链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
//双指针，滑动窗口技巧
//当总和小于sum，大指针继续+
//否则小指针+
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        int phigh = 2,plow = 1;
         
        while(phigh > plow){
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if( cur < sum)
                phigh++;
             
            if( cur == sum){
                vector<int> res;
                for(int i = plow; i<=phigh; i++)
                    res.push_back(i);
                allRes.push_back(res);
                plow++;
            }
             
            if(cur > sum)
                plow++;
        }
         
        return allRes;
    }
};

//单纯分析数学公式
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        if(sum < 3) return ret;
        for(int n = sqrt(2 * sum); n >= 2; --n){//n * n < 2 * sum
            int tmp = 2 * sum + n - n * n;
            if(tmp % (2 * n) == 0){
                int k = tmp / (2 * n);
                if(k >= 0 && k <= sum / 2){
                    vector<int> oneRet;
                    for(int i = 0; i < n; ++i)
                        oneRet.push_back(k + i);
                    ret.push_back(oneRet);
                }
            }
        }
        return ret;
    }
};