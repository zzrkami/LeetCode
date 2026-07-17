// 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

/*思路：和之前第5题有点像
1.不过似乎也不用那么复杂，直接把整个整数x拆成一个数组x_arr[];并且获得x的长度x_length，如果是负数直接返回false
2.然后进入循环，循环次数等于x_length/2;然后每次就是判断x_arr[i] == x_arr[x_length - i - 1]
这么做似乎空间消耗比较高
还可以把后面反转，同样是循环x_length/2次，后半截和前半截相等即可，
不过如果长度是偶数的情况还好，是奇数的情况的话，还得去掉中间的数字，还可以通过判断后边和前半截相等，或者后半截/10和前半截相等
*/


#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int x_half = 0;//用来记录后半截
        if (x!=0 && x%10==0 ) return false;

        while(x > x_half)
        {
            int f = x % 10;
            x = x /10;
            x_half = x_half *10 +f;
        }
        if (x == x_half || x == x_half/10) return true;
        else return false;
        
    }
};

int main()
{
    int x = -131;
    Solution s;
    bool result = s.isPalindrome(x);
    cout << result <<endl;
    return 0;
}