/* 
七个不同的符号代表罗马数字，其值如下：
符号 值 I 1 V 5 X 10 L 50 C 100 D 500 M 1000
罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：
 * 如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，
 将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
 * 如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，
 例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。
 仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
 * 只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。
 你不能多次附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
示例：输入：num = 3749 输出： "MMMDCCXLIX"
解释：
3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
  40 = XL 由于 50 (L) 减 10 (X)
   9 = IX 由于 10 (X) 减 1 (I)
注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位
*/

/*
思路：1.分为7个判断语句，分别把num除1000，500，...1，如果能够得到数则通过for循环，把相应的罗马数字加到字符串上面
2.但是有两个特殊情况，一个是4另一个是9，遇到这两个数字的处理是难点，如果遇到4和9，则同样分别需要3个判断语句，一共六个
3.遇到9时判断num是在[900，90)，[90,9]，[9,0]，4也同理，然后把相应的罗马数字加到字符串上面
4.补充说明，如果f = num除1000得到不为0，那么num = num - 1000*f，以此类推 直到num被为0
5.可以通过创建一个罗马数字映射的数组减少if语句，通过循环判断
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};//罗马字符
        vector<int> roman_ns = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};//罗马字符对应的数字
        string ronman_num;//用来记录整数转为的罗马字符
        for (int i = 0; i < roman.size(); i++)
        {
            int n = num / roman_ns[i];
            num = num - n * roman_ns[i];
            while (n != 0)
            {   --n;
                ronman_num = ronman_num + roman[i];
            }
        }
        return ronman_num;
    }
};


//看到一个不错的写法
// class Solution {
// public:
//     string intToRoman(int num) {
//         vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//         vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//         string res;
//         for(int i = 0; i < val.size(); i++){
//             while(num >= val[i]){
//                 res += roman[i];
//                 num -= val[i];
//             }
//         }
//         return res;
//     }
// };



int main(){
    int height = 3749;
    Solution x;
    string result;
    result = x.intToRoman(height);
    cout<<result<<endl;
    return 0;
}