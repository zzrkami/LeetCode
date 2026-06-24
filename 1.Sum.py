# 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
# 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
# 你可以按任意顺序返回答案。

#我写的
# class Solution:
#     def twoSum(self, nums: List[int], target: int) -> List[int]:
#         for i in range(len(nums)):
#             for j in range(i+1,len(nums)):
#                 if target == nums[i] + nums[j]:
#                     return [i,j]
                    

#改进后的
# 用一个字典（哈希表）存储已经遍历过的数字和它的下标
# 遍历数组，对于每个数字 nums[i]，计算需要找的补数：complement = target - nums[i]
# 如果补数已经在哈希表里，说明找到了答案，直接返回 [哈希表里的下标, i]
# 如果不在，就把当前数字和下标存入哈希表，继续遍历
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {} # 键：数字，值：下标
        for i, num in enumerate(nums):
            complement = target - num
            if complement in hashmap:
                return [hashmap[complement], i]
            hashmap[num] = i
        
if __name__ == "__main__":
    nums = [2,7,11,15]
    target = 9
    s = Solution()  # 第一步：创建实例
    result = s.twoSum(nums, target)  # 第二步：通过实例调用
    print(result)