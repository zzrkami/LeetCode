/*给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出并返回这两个正序数组的 中位数 
算法的时间复杂度应该为 O(log (m+n)) 

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/

/*思路：
我认为本质是一个排序的一个问题，要把两个数组排序成一个大数组，然后取中位数即可
问题就在于用什么排序算法可以让时间复杂度为O(log (m+n))
用归并排序！
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

//写完发现时间复杂度是O(m+n)没达到要求
// double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//      double median = 0.0;
//      int m,n;
//      m = nums1.size();
//      n = nums2.size();
//      int nums3_length = m+n;
//      vector<int> nums3(nums3_length);
//      int i = 0, j = 0, k = 0;
//      for(i = 0; i < nums3_length; i++){
//         if (j < m && k<n)
//         {
        
//         if (nums1[j] < nums2[k])
//         {
//             nums3[i] = nums1[j];
//             j++;
//         }
//         else 
//         {
//             nums3[i] = nums2[k];
//             k++;
//         }
//         }
//         else if(j==m && k<n)
//         {
//             nums3[i] = nums2[k];
//             k++;
//         }
//         else if (j<m && k==n)
//         {
//             nums3[i] = nums1[j];
//             j++;
//         }
//     }

//      if(nums3_length%2 == 0)
//      {
//         median = double(nums3[nums3_length/2-1]+nums3[nums3_length/2])/2;
//      }
//      else
//      {
//         median = nums3[(nums3_length)/2];
//      }
//      return median;
// }

/*思路2：使用2分查找
将两个数组分为左半部分和右半部分
并且要让两个左半部分都小于右半部分
把两个数组把左半部分到一半即可
*/
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 保证 nums1 是更短数组，避免 left2 越界，同时二分次数最少
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int median_index = (m + n + 1) / 2; // 左半总元素数
    int left1 = 0;    // 二分左边界：nums1 左半最少取 0 个元素
    int right1 = m;   

    while (left1 <= right1) { 
        int i = (left1 + right1) / 2;    // 当前试探的 nums1 左半元素个数
        int left2 = median_index - i;    

        int l1 = (i == 0) ? INT_MIN : nums1[i - 1]; 
        int r1 = (i == m) ? INT_MAX : nums1[i];     
        int l2 = (left2 == 0) ? INT_MIN : nums2[left2 - 1]; 
        int r2 = (left2 == n) ? INT_MAX : nums2[left2];     

        if (l1 > r2) {
            // nums1 左半太大，切分点左移
            right1 = i - 1;
        } else if (l2 > r1) {
            // nums2 左半太大，切分点右移
            left1 = i + 1;
        } else {
            // 切分结束，直接计算中位数
            if ((m + n) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                return max(l1, l2);
            }
        }
    }

    return 0.0;
}


int main(){
    vector<int> nums1; 
    vector<int> nums2;
    nums1 = {1,2};
    nums2 = {1,5,7,9};
    double median;
    Solution s;
    median =s.findMedianSortedArrays(nums1,nums2);
    cout<<median<<endl;

}