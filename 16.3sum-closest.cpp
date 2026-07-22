/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个在 不同下标位置 的整数，使它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在恰好一个解。
示例 1：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
示例 2：
输入：nums = [0,0,0], target = 1
输出：0
解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
*/

/*
思路，三数之和的拓展，感觉可以计算三数之和与目标数之间的差值，并且每次都记录下最优的差值，然后最后再返回
同样还是两层循环，如果差值计算为0的时候就可以直接返回0结束了
外循环同样是i从0开始，内循环同样是l和r两个指针，差值大于0时，l++否则就，r--
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result = 0;//返回最接近的和
        int best_difference = 2147483647;//最好的差值
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;//左右指针
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                int difference = target - sum;
                if (abs(difference) < abs(best_difference))
                {
                    best_difference = difference;
                    result = sum;
                }
                if (difference == 0)
                {
                    return sum;
                }
                if (difference < 0) r--;
                if (difference > 0) l++;

            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {10,20,30,40,50,60,70,80,90};
    int target = 1;
    Solution x;
    int result;
    result = x.threeSumClosest(nums,target);
    cout << result << endl;
    return 0;
}