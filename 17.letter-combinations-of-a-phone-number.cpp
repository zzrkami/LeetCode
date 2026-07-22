/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：
输入：digits = "2"
输出：["a","b","c"]*/

/*
思路：可以观察到输出是输入字符串s长度l的3^l长，
1.创建一个字符串数组例如s[2] = “abe”,一共是一层大循环，循环输入的数字长度
2.定义两个字符串组合的操作s_combination(),直接递归拼接就可以了,每次凭借当前的res和输入新的list[i]
3.然后在循环中不断使用
问题：1.s[2] = “abe”还得拆成"a","b","c"很麻烦，感觉得一步到位
2.如果digits.size() == 1直接返回对应的字符就行
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> list = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        char ch = digits[0];
        int num_digit = ch - '0';
        for (int i = 0; i < list[num_digit].size(); i++)
        {
            res.push_back(string(1,list[num_digit][i]));
        }
        
        if (digits.size() == 1) return res;
        
        for (int i = 1; i < digits.size(); i++)
        {
            char ch = digits[i];
            int num_digit = ch - '0';
            res = s_combination(res, list[num_digit]);
        }
        return res;
        
    }
    vector<string> s_combination (vector<string> a , string b){
        vector<string> res;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                string s = a[i] + b[j];
                res.push_back(s);
            }
            
        }
        return res;
    }
};
int main(){
    string nums = "234";
    Solution x;
    vector<string> result;
    result = x.letterCombinations(nums);
    cout << '[';
    for (auto &v : result)
    {
        cout << '"';
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << '"';
        cout << ' ';
    }
    cout << ']';
    cout << endl;
    return 0;
}