/** 给你一个字符串 s，找到 s 中最长的 回文 子串。
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
*/

/*思路：中心扩散法
核心：回文分两种
奇数长度：以单个字符为中心扩散（bab 中心是 a）
偶数长度：以两个相邻字符中间为中心扩散（bb 中心在两个 b 中间）
流程：
遍历每一个位置 i；
分别以 i、i&i+1 为中心，左右向外扩张，直到左右字符不相等；
每次扩散得到合法回文，对比长度，更新全局最长子串。
方案一：
出满足回文判定的函数，
2.定义一个最长回文字符串longest_S
3.长度1为开始，然后遍历原始字符串S，满足的会问判定的就存入
4.长度每次都加1
5.直到长度等于原始字符串S的长度则停止
方案二：
写辅助函数 expand：输入左右边界，向外扩散，返回当前中心能得到的最长回文字串
规则：左指针向左、右指针向右，只要左右字符相等就继续扩，不等停止。
初始化 longest_S 存最终最长回文，默认等于第一个字符（单个字符一定是回文）
遍历字符串每一个下标 i：
情况 1：奇数回文，中心 i，调用 expand(i,i)
情况 2：偶数回文，中心在 i 和 i+1 中间，调用 expand(i,i+1)
每次扩散得到一段回文字串，对比长度：
若当前回文更长，就更新 longest_S
遍历完所有中心点直接结束，不用循环字符串长度
*/


#include <iostream>
#include <string>
using namespace std;
///超时了..........
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         // 兜底：至少单个字符是回文，防止空串
//         string longest_s = s.substr(0, 1);
//         int n = s.size();
//         // 字符串首尾指针边界，用于expand判断越界
//         char* strStart = &s[0];
//         char* strEnd = &s[n - 1];

//         for (int len = 1; len <= n; len++) // len 子串长度，替换原i避免重名
//         {
//             for (int j = 0; j <= n - len; j++) // j 子串起点
//             {
//                 if (len % 2 != 0) // 奇数长度回文，单中心
//                 {
//                     char* mid = &s[j + len / 2];
//                     string back_s = expand(mid, mid, len / 2, strStart, strEnd);
//                     if (back_s.size() > longest_s.size())
//                         longest_s = back_s;
//                 }
//                 else // 偶数长度，双中心
//                 {
//                     char* mid1 = &s[j + len / 2 - 1];
//                     char* mid2 = mid1 + 1;
//                     string back_s = expand(mid1, mid2, len / 2 - 1, strStart, strEnd);
//                     if (back_s.size() > longest_s.size())
//                         longest_s = back_s;
//                 }
//             }
//         }
//         return longest_s;
//     }
//     // 首尾边界参数，限制指针不越界
//     string expand(char* l, char* r, int maxStep, char* strHead, char* strTail);
// };

// string Solution::expand(char* l, char* r, int maxStep, char* strHead, char* strTail)
// {
//     int step = 0;
//     // 向外扩散，带边界保护
//     while (step < maxStep && l > strHead && r < strTail && *l == *r)
//     {
//         l--;
//         r++;
//         step++;
//     }
//     // 退出循环时l、r已经多走一步，拉回真实回文边界
//     if (*l != *r)
//     {
//         l++;
//         r--;
//     }
//     // 拼接 l ~ r 之间全部字符生成回文
//     string res;
//     char* cur = l;
//     while (cur <= r)
//     {
//         res += *cur;
//         cur++;
//     }
//     return res;
// }

///新的
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        string maxStr = s.substr(0, 1);

        // 中心扩散：遍历每个中心点
        auto expand = [&](int l, int r) -> string {
            // 下标边界保护，不越界
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // 退出循环时l、r多走一步，截取有效区间 [l+1, r-1]
            return s.substr(l + 1, r - l - 1);
        };

        for (int i = 0; i < n; i++) {
            // 奇数回文：中心i
            string odd = expand(i, i);
            // 偶数回文：中心i与i+1中间
            string even = expand(i, i + 1);

            // 更新最长
            if (odd.size() > maxStr.size()) maxStr = odd;
            if (even.size() > maxStr.size()) maxStr = even;
        }
        return maxStr;
    }
};


int main() {
    string s = "babad";
    Solution x;
    cout << x.longestPalindrome(s) << endl;
    return 0;
}