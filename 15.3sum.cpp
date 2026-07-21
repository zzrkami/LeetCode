/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
*/

/*
思路：
想到一个暴力解法，外侧一个大循环i从第一个数到最后一个数，内测再加一个循环j从i到最后一个数，直接num[i]+num[j],然后取反得到x，
再第三个循环k从j到最后一个数，找到num[k] = x，找到则为三元组,但是计算复杂度高的吓人接近n^3

第二个想法，我们需要先把数组排序，这三元组的数的符号肯定是有正有负的，除非全是0，排序之后外层是一个i=0开始的大循环
内层再一个循环（l<r），三个值加起来为sum，左l=i+1，右r=n-1开始往内，若sum=0，则为一个三元数组（然后l++，r--），sum<0则l++，否则r--
关键是去重：外循环中，如果i往后遇到相同的num[i]则跳过，
内循环中，也需要跳过相同的数
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;//和result用于存储三元组的
        int n = nums.size();
        for (int i = 0; i < n ; i++)
        {
            int l = i + 1, r = n - 1;//左右指针
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l<r &&nums[l] ==nums[l+1])
                    {
                        l++;
                    }
                    while (l<r &&nums[r] ==nums[r-1])
                    {
                        r--;
                    }
                    l++,r--;
                }
                if (sum < 0) l++;
                if (sum > 0) r--;

            }
        }
        return result;
    }
};

//易错点重复值跳过的位置设置，还有需要加上条件l<r，不然会越界

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution x;
    vector<vector<int>> result;
    result = x.threeSum(nums);
    for (auto &v : result)
    {
        cout << "[";
        for (int i = 0; i < v.size(); i++)
        {
            if(i > 0) cout << ",";
            cout << v[i];
        }
        cout << "] ";
    }
    cout << endl;
    cout<<endl;
    return 0;
}