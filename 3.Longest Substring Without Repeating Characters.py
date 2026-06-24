# 输入: s = "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
# 0 <= s.length <= 5 * 104
# s 由英文字母、数字、符号和空格组成

#思路：
#从头开始遍历，在新建一个字符串ss（只记录不重复的字符）
#每次往后一个字符就往这个字符串里面的字符进行对比，每次遇到新的字符就放到新的字符串ss，直到遍历完
#最后统计新的字符串长度
#忽然发现理解错了，他说要统计的是最短的不重复的字符串，而不是一个字符串里面不重复字符的个数
#新思路：先建立一个最长子字符串和一个当前子字符串，一样的需要先遍历，
#但是如果遍历到当前字符存在于当前子字符串中了（重复了），就把当前的子字符串与最长子字符串进行长度对比，如果更长这当前子字符串为最长字符串
#然后继续新的当前子字符串直到遍历结束

#还是有错上述思路在dvdf中会输出2

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: return len(s)
        longeest_s = s[0] #最长子字符串
        current_s = s[0] #当前子字符串
        for i in range(1,len(s)):
            current_s_new = ""
            if s[i] in current_s:
                if len(current_s) >= len(longeest_s):
                    longeest_s = current_s
                for j in range(current_s.find(s[i])+1, len(current_s)):
                    current_s_new = current_s_new + current_s[j]
                current_s = current_s_new + s[i] 
            else: current_s = current_s + s[i]
            # print(current_s)
        if len(current_s) > len(longeest_s): longeest_s = current_s
        # print(longeest_s)
        return len(longeest_s)

#优化
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         if len(s) == 0: return len(s)
#         longeest_s = s[0] #最长子字符串
#         current_s = s[0] #当前子字符串
#         for i in range(1,len(s)):
#             current_s_new = ""
#             if s[i] in current_s:
#                 if len(current_s) >= len(longeest_s):
#                     longeest_s = current_s
#                 current_s = current_s[current_s.find(s[i])+1:] + s[i]
#             else: current_s = current_s + s[i]
#             # print(current_s)
#         if len(current_s) > len(longeest_s): longeest_s = current_s
#         # print(longeest_s)
#         return len(longeest_s)


#"jbpnbwwd"
#loddktdji
#"ggububgvfk"
#"dvdf"
if __name__ == "__main__":
    a = "dvdf"
    s = Solution()
    n = s.lengthOfLongestSubstring(a)
    print(n)