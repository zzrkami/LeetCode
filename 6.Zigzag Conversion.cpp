// 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
// 输入：s = "PAYPALISHIRING", numRows = 3
// 输出："PAHNAPLSIIGYIR"

/*

思路：
1.第一列的字母数量是等于numrows，并且每隔numRows-1个字母数量都是numRows，除此之外的列字母都是1
2.应该要把每numRows-1列为一组，向下是numRows个，斜过去是2numRows-2个，这一组的数量加起来刚好就是2numRows-2
可以让字符串长度除于这个得到组的数量，然后再推断出列的数量ncolumn
3.如果能得到列的数量ncolumn，就可以直接设置一个（numRows，ncolumn）的矩阵来存储字符串，不过这样做的话感觉会浪费不少存储空间
4.那就不用上面3的方法，干脆每个组都为一个字符串，然后观察可以发现，第一行就每个组的第一个字符，第二行就是第二个字符和倒数第1个字符，
第三行第三个字符和倒数第3个字符，就是这样子的话就不会造成空间浪费
5.然后就使用numRows个字符串，存储各个组对应的字符，最后再把numRows个字符串组合成一个字符串
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows);
};

string Solution::convert(string s, int numRows){
    if(numRows == 1)
    {
        return s;
    }
    
    int num_group = 2 * numRows - 2;//每组的字符数量
    int groups = s.size() / num_group + 1;//分成小组的数目
    vector<string> s_gropus(groups); 
    for (int i = 0; i < groups; i++) //分出groups个小组
    {
       s_gropus[i] = s.substr(i * num_group , num_group);
    }

    vector<string> s_rows(numRows);
    //第一行补充越界判断
    for(int i = 0; i < groups; i++)
    {
        if (s_gropus[i].size() > 0)
            s_rows[0] = s_rows[0] + s_gropus[i][0];
    }

    for(int i = 1; i < numRows - 1; i++)//获取中间行的字符串
    {
        for(int j = 0; j < groups; j++)
        {
            //分开两次if，不用&&捆绑，不新增变量
            if (i < s_gropus[j].size())
            {
                s_rows[i] = s_rows[i] + s_gropus[j][i];
            }
            int pos2 = num_group - i;
            if (pos2 < s_gropus[j].size())
            {
                s_rows[i] = s_rows[i] + s_gropus[j][pos2];
            }
        }
    }
    //最后一行补充越界判断
    int lastIdx = numRows - 1;
    for(int i = 0; i < groups; i++)
    {
        if (lastIdx < s_gropus[i].size())
            s_rows[lastIdx] = s_rows[lastIdx] + s_gropus[i][lastIdx];
    }

    string z_string;
    for(int i = 0; i < numRows; i++)//拼接每一行的字符串
    {
        z_string = z_string + s_rows[i];
    }
    return z_string;
}

//改进思路，或许可以不创建那么多个字符串组，不过懒得改了，能跑就行
int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution x;
    string z_s;
    z_s = x.convert(s,numRows);
    cout<<z_s<<endl;
}