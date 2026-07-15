/*给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
示例 ：输入：x = 123,输出：321
输入：x = 120,输出：21*/

/*思路：
创建一个数x_rev,
判断数x_rev的值是否超过范围[−2147483648,2147483647]，大于则结束循环，返回0。
然后将x不断的%10取最后一位数f，然后把f乘10加到x_rev
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int x_min = -2147483648;
        int x_max = 2147483647;
        int x_rev = 0;//存储反转的数
        int f = 0;//存储余数
        while (x != 0)
        {
            f = x % 10;
            if(x_rev > x_max/10 || (x_rev == x_max/10 && f > 7) )
            return 0;
            if(x_rev < x_min/10 || (x_rev == x_min/10 && f < -8) )
            return 0;
            x = x / 10;
            x_rev = x_rev*10 + f;
        }
        return x_rev;
    }
};

int main(){
    int x = 12345;
    Solution s;
    int y = s.reverse(x);
    cout<<y<<endl;
    return 0;
}