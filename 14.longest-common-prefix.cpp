/*
编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
示例1：
输入：strs = ["flower","flow","flight"]
输出："fl"
示例2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/

/*
思路：首先感觉就是直接拿第一个字符串s1为例子，然后两层循环，外层循环s1的字符，内层循环剩下的n-1个字符串，对比字符是否相等
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s1 = strs[0];//拿第一个字符串s1为例子
        string l_pre;//用来记录最长前缀
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (s1[i] == strs[j][i]) continue;
                else return l_pre;
            }
            l_pre = l_pre + s1[i];
        }
        return l_pre;
    }
};

int main(){
    vector<string> strs = {"love","loss","lover"};
    Solution x;
    string result;
    result = x.longestCommonPrefix(strs);
    cout<<result<<endl;
    return 0;
}