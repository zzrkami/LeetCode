/*给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
*/

/*
思路：第一想法是计算出所有两两垂线之间可以容纳的水，但是一想到时间复杂度直接变成O(n!)，就感觉不可能是正解了
这道题要综合考虑长度和宽度，这导致并不是找到最高两个就行的，
从数组左边和右边出发，每次只移动矮的那一个
*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;//用于记录最多的水容量
        int n = height.size();//数组长度
        int left = 0; //左边开始位置
        int right = n -1 ; //右边开始位置
        int now_water = 0;//记录当前的水容量
        for ( int i = 0; i < n - 1; ++i)
        {
            if (height[left] > height[right]) //长度高的是左边,但是要用短的那边做计算（易错）
            {
                now_water = height[right] * (right - left);//用于记录当前的水容量
                --right;
            }
            else 
            {
                now_water = height[left] * (right - left);
                ++left;
            }
            if(now_water > max_water) max_water = now_water;
        }
        return max_water;
    }
};

int main(){
    vector<int> height = {4,3,2,1,4};
    Solution x;
    int result;
    result = x.maxArea(height);
    cout<<result<<endl;
    return 0;
}