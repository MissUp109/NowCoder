#include<iostream>
#include<vector>
using namespace std;

/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
*/
//超时
/*
class Solution {
public:
    int InversePairs(vector<int> data) {
        int size = data.size();
        if(size < 2) return 0;
        int* IParr = new int[size]();
        merge(data, 0, size - 1, IParr);
        int sum = 0;
        for(int i = 0; i < size; ++i)
            if(sum >= 1000000007 - IParr[i]) 
                sum += (IParr[i] - 1000000007);
            else sum += IParr[i];
        return sum;
    }

    void merge(vector<int> &data, int begin, int end, int* &IParr){
        if(begin >= end) return;
        int mid = (begin + end) / 2;
        int i = begin, j = mid + 1;
        while(i <= mid){
            if(data[i] > data[j]) IParr[i]++;
            if(++j > end){++i; j = mid + 1;}
        }
        merge(data, begin, mid, IParr);
        merge(data, mid + 1, end, IParr);
    }
};*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        int size = data.size();
        if(size < 2) return 0;
        count = 0;
        MergeSort(data, 0, size - 1);
        return count;
    }

    void MergeSort(vector<int> &data, int begin, int end){
        if(begin == end) return;
        int mid = (begin + end) >> 1;
        MergeSort(data, begin, mid);
        MergeSort(data, mid + 1, end);
        Merge(data, begin, mid, end);
    }

    void Merge(vector<int> &data, int begin, int mid, int end){
        int *tmp = new int[end - begin + 1];
        int i = begin, j = mid +1, k = 0;
        while(i <= mid && j <= end){
            if(data[i] < data[j]) tmp[k++] = data[i++];
            else {
                int add = mid - i + 1;
                if(count >= 1000000007 - add) count += (add - 1000000007);
                else count += add;
                tmp[k++] = data[j++];
            }
        }

        while(i <= mid) tmp[k++] = data[i++];
        while(j <= end) tmp[k++] = data[j++];

        for(k = 0; k < end - begin + 1; ++k)
            data[begin + k] = tmp[k];
        delete[] tmp;
    }
private:
    int count;
};


int main(){
	Solution sol;
    //vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
    vector<int> data = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
	cout << sol.InversePairs(data) << endl;
}