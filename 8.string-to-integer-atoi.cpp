/*请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。
函数 myAtoi(string s) 的算法如下：
空格：读入字符串并丢弃无用的前导空格（" "）
符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
舍入：如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
返回整数作为最终结果。
示例 :输入：s = "42",输出：42,输入：s = " -042",输出：-42,
输入：s = "1337c0d3",输出：1337,输入：s = "words and 987",输出：0
*/

/*
思路：1.开始遍历字符串的字符，有个疑问读出来的数是ascii字符吗? 如果读到负号，就记录下来，之后给结果加个负号
2.如果读取到字母就停下来，返回数字，如果是0，则即使有负号也为0。
3.如果超过范围[−2147483648,2147483647]，但要再前一步判断，判断条件大概是：在最大最小除10然后加减余数之间，然后停下
总之感觉会有很多个if语句
注意点：前导空格要跳过，前置0也要跳过，
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long sti = 0;///用来返回的数字
        int flag = 1, flag_n = 0;//用来判断正负的，和统计"+,-出现次数"
        int x_min = -2147483648;
        int x_max = 2147483647;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ' && !flag_n) continue;//读到空格跳过
            //还未读取符号和数字，遇到非数字且非正负号字符，直接返回结果
            if ((s[i] < '0'|| s[i] > '9') && s[i] !='-' && s[i]!= '+' && !flag_n)
            {
                return sti;
            }
            
             if( (s[i] < '0'|| s[i] > '9') && flag_n )//非数字字符，并且已经读取过符号了，结束
            {
                break;
            }
            if(sti == 0 && flag_n == 0)//还没读取到数和符号的时候
            {
                if (s[i] == '-')
                {   
                    flag = -1;
                    flag_n = 1;
                }
                if (s[i] == '+')
                {
                    flag = 1;
                    flag_n = 1;
                }
                if ((s[i] >= '0'&& s[i] <= '9'))
                {
                    flag = 1;
                    flag_n = 1;
                }
            }
            if(s[i] >= '0'&& s[i] <= '9')
            {   
                int num_s = s[i] - '0'; //0对应的ASCII是48，以此获取具体的整数
                if (flag == 1)
                {
                    if(sti > x_max/10 || (sti == x_max/10 && num_s > 7) )
                        return x_max;
                }
                if (flag == -1)
                {
                    if(sti > x_max/10 || (sti == x_max/10 && num_s > 8) )
                        return x_min;
                }

                sti = sti*10 + num_s;
            }
        }
        long long ans = sti * flag;
        //兜底边界判断
        if(ans < x_min) return x_min;
        if(ans > x_max) return x_max;
        return (int)ans;
    }
};
int main(){
    string x = "-2147483648";
    // string x = "-987";
    Solution s;
    int y = s.myAtoi(x);
    cout<<y<<endl;
    return 0;
}