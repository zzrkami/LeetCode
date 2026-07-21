/*13. 罗马数字转整数 - 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。
示例,输入:s = "III",输出: 3*/

/*
思路:和之前第12题整数转罗马很像
继续创建两个罗马字符的对应表(改为创建一个哈希值对应的表，主要是后面有一个判断要写)，不过这次是遍历roman的字符表，如果有对给加上对应数字
不过问题在于有一些特别的字符他是两个的，不能一个个读字符到最后，也就是每一次还需要考虑当前字符和下一位字符
关键是循环的条件和判断的条件怎么设置了
*/


#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp ={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int num_ronman = 0;//用来记录罗马字符转为的整数
        for (int i = 0; i < s.size(); i++)
        {
            if (i+1 < s.size() && (mp[s[i]] < mp[s[i + 1]]))//如果当前字符比之后的字符对应的值大说明就是两个连起来的
            {
                num_ronman = num_ronman + mp[s[i + 1]] - mp[s[i]];
                i++;
            }
            
            else
            {
                num_ronman = num_ronman + mp[s[i]];
            }
        }
        return num_ronman;
    }
};

int main(){
    string s = "LVIII";
    Solution x;
    int result;
    result = x.romanToInt(s);
    cout<<result<<endl;
    return 0;
}