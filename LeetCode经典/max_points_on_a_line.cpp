#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <algorithm>
using namespace std;

#define INFINITE 3.40282e+38
/*
map用浮点数k存储可能会有误差，两种解决办法：
  1. 存储浮点数时，强制保留n(>6)位数
  2. 存储除数和被除数都除以最大公约数的值 map<pair<int, int>, int>
*/
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	//辗转相除法基于的定理： gcd(a, b) == gcd(b, a % b)
	int gcd(int a, int b){
		return (b == 0) ? a : gcd(b, a % b);
	}
    int maxPoints(vector<Point> &points) {
    	int size = points.size();
    	if(size < 2) return size; 
    	
    	int retMax = 0;
    	for(int i = 0; i < size; ++i){
    		unordered_map<float, int> mm;
    		int tmpMax = 0;
    		int duplicate = 0;
    		for(int j = 0; j < size; ++j){
    			if(i == j) continue;
    			Point p = points[i];
    			Point q = points[j];
    			float k = 0;
    			if(p.x == q.x) k = INFINITE;
    			else k = (p.y - q.y) * 1.0 / (p.x - q.x);

    			if(p.x == q.x && p.y == q.y){
    				++duplicate;
    			}
    			else{
    				if(mm.find(k) != mm.end()) ++mm[k];
    				else mm[k] = 2;
    			}

    			if(mm[k] > tmpMax) tmpMax = mm[k];  			
    		}
    		if(tmpMax == 0 && duplicate > 0) ++duplicate;
    		if(tmpMax + duplicate > retMax) retMax = tmpMax + duplicate;
    	}
    	return retMax;
    }
};

int main(){
	Solution sol;
	vector<Point> points = 
    /*
	{
		Point(0, 0),
		Point(-1, -1),
		Point(2, 2)
	};
	
	/*
	{
		//Point(0, 0),
		Point(0, 0)
	};
	*/
	/*
	{
		Point(1, 1),
		Point(1, 1),
		Point(2, 2),
		Point(2, 2)
	};
	*/
	/*
	{
		Point(2, 5),
		Point(2, 5),
		Point(2, 6),
		Point(4, 10),
		Point(4, 10)
	};
	*/
	{//expected : 2
		Point(0, 0),
		Point(94911151,94911150),//浮点数精度问题
		Point(94911152,94911151)
	};

	cout << sol.maxPoints(points) << endl;
}