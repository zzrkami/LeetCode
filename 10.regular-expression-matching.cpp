/*给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
返回一个布尔值，表示匹配是否覆盖整个输入字符串（而非部分）。
输入：s = "aa", p = "a",输出：false.输入：s = "aa", p = "a*",输出：true,输入：s = "ab", p = ".*",输出：true
*/

/*
思路：感觉难点在于如何定义*和.这两个符号的作用。
1.开始循环遍历字符串内的字符s，当s[i]等于p[0]的时候，内部有一个循环用于遍历字符规律p，
2.遍历p的时候，定义.如果if当前p的字符是.那么就直接continue
定义*，if当前p的字符是*，先判断p[j-1]是不是.如果是.，直接就可以返回true了
如果不是.，那么就判断p[j-1]与s[i]是否相等，相等就i++，不相等就countinue了，继续判断s[j]和p[i]是否相等
3.如果p[0]等于*直接就可以返回false了，放到前面
有个问题*我理解错了，他不是匹配前一个字符，而是匹配0个或多个前一个元素
那么对*的定义就要全部修改，
重新定义*，if当前p的字符是*，先判断p[j-1]是不是.，如果是.，那么就判断p[j+1]和s[i]是否相等，不相等继续i++，
如果相等则判断j+1是否是最后一位，如果是则返回true，如果不是（写到这里我感觉逻辑判断有点复杂，难写了，感觉思路出了问题）
我又有一个误解，我以为p只需要和s一部分匹配，但是是要完全匹配
感觉会是一个反复嵌套回归的过程
*/

// #include <iostream>

// using namespace std;

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         if (p[0] == '*') return false;
//         int i =0 ,j =0;//s和p的位置
//         while(i<s.size() && j<p.size())
//         {
//             if (p[j] == '.') 
//             {  
//                  j++,i++;
//                 continue;
//             }
//             if(p[j] == '*')
//             {
//                 if (p[j-1] == '.') 
//                 {  
//                     i++;    
//                     continue;
//                 }
//                 if(p[j-1] == s[i]) 
//                 {
//                     i++;
//                     continue;
//                 }
//                 else 
//                 {
//                     i++,j++;
//                     continue;
//                 }
//             }
//             if(p[j] == s[i])
//             {
//                 i++,j++;
//                 continue;
//             }
//             if(p[j+1] == '*' && j+1 < p.size() )
//             {
//                 i++;
//                 j = j+2;
//                 continue;
//             }
//             else return false;
//         }
//         if (i == s.size() && p[p.size() - 1] == '*')
//         {
//             return true;
//         }
//         if (i == s.size() && p[p.size() - 1] == '.')
//         {
//             return true;
//         }
//         if (i == s.size() && p[p.size() - 1] == s[s.size() - 1])
//         {
//             return true;
//         }
//         else return false;;
        
//     }
// };
/*
string s = "mississippi";
string p = "mis*is*ip*.";输出错了
对于有多个*的情况无法应对
*/

/*
这里面涉及到了一个叫做正则化表达方面的知识，我个人学习了一下，认为是一个很有用的一种检索查找的方法。
甚至还可以用相当成熟的库函数来实现，例如regex
*/


/*
方法二：创建出一个二维的矩阵来记录该步数之前是否是匹配的，每一步都会与前面的情况关联，如果是匹配的最后一步就会是true
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // dp[i][j] 表示 s 的前 i 个字符能否与 p 的前 j 个字符匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // 空串匹配空模式

        // 处理 p 开头可能出现的 "a*" 之类的情况，它们可以匹配空串
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                // * 可以与前面的字符一起忽略（匹配 0 次）
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // * 匹配 0 次：忽略 p[j-2] 和 *
                    dp[i][j] = dp[i][j - 2];
                    // 或者 * 匹配至少一次：要求 p[j-2] 与 s[i-1] 匹配，
                    // 且 s 的前 i-1 个字符也能与当前模式匹配（即 dp[i-1][j]）
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    // 普通字符或 '.'，必须当前字符匹配，且前面也匹配
                    if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    string s = "mississippi";
    string p = "mis*is*ip*.";
    Solution x;
    bool result;
    result = x.isMatch(s,p);
    cout<<result<<endl;
    return 0;
}