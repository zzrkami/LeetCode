# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# 输出：[8,9,9,9,0,0,0,1]



#我忽然意识ListNode是不是只是链表里面的其中一个节点而已，并不是整个链表

from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def display_listnode(l: Optional[ListNode]) -> None:
    # 用临时变量遍历，永远不要修改传入的头指针
    current = l
    # 只要当前节点不是None，就继续
    while current is not None:
        print(current.val, end=" -> ")  # 打印值，后面加箭头
        current = current.next  # 走到下一个节点
    # 最后打印None，表示链表结束
    print("None")
    

def len_listnode(l: Optional[ListNode]):#计算链表长度
    n = 0
    current = l
    while current != None:
            n = n+1
            current = current.next
    return n



#思路：首先是通过循环从后往前遍历两个链表的每一个元素，然后把连个链表的每一个数相加，
# 1：两个链表的长度不一定一样 （通过插入0使得两个链表大小相同）
# 2：相加后得到的链表长度可能还要+1   
# 3：链表的长度还需要是逆序的  （可以通过不断的向前插入）（忽然发现不需要向前插入，直接接在后面就行了）
# 4：两数相加大于9时是不是还需要一个中间变量加到下一个节点上（与问题2可对应）
#方案：
#1.先通过循环得到两个链表的长度，以短链表长度开始相加到短链表当前元素为空。
#2.将两个链表对应的数不停相加，将得到的值创建为一个新的节点，得到的值通过向前插入得到新的链表。

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = ListNode() #得到逆序新链表
        current1 = l1
        current2 = l2
        current3 = l3 #相加得到的当前节点,作为得到逆序新链表
        len1 = len_listnode(l1)
        len2 = len_listnode(l2)
        if len1 > len2:
            flag = 0 #进位
            while current2 != None:
                total = current1.val + current2.val + flag
                if total > 9:  #当相加的数大于9时要进位
                    flag = 1
                    total = total - 10
                else : 
                    flag = 0
                current3.next = ListNode(total)
                current3 = current3.next
                current1 = current1.next
                current2 = current2.next
            while current1 != None:
                total = current1.val + flag
                if total > 9:  #当相加的数大于9时要进位
                    flag = 1
                    total = total - 10
                else : 
                    flag = 0
                current3.next = ListNode(total)
                current3 = current3.next
                current1 = current1.next    
        else:
            flag = 0 #进位
            while current1 != None:
                total = current1.val + current2.val + flag
                if total > 9:  #当相加的数大于9时要进位
                    flag = 1
                    total = total - 10
                else : 
                    flag = 0
                current3.next = ListNode(total)    
                current3 = current3.next
                current1 = current1.next
                current2 = current2.next
            while current2 != None:
                total = current2.val + flag
                if total > 9:  #当相加的数大于9时要进位
                    flag = 1
                    total = total - 10
                else : 
                    flag = 0
                current3.next = ListNode(total)
                current3 = current3.next
                current2 = current2.next
        if flag == 1: current3.next = ListNode(1)
        l3 = l3.next
        return l3

             
        #while l1

# 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# 输出：[8,9,9,9,0,0,0,1]

if __name__ == "__main__":
    l1 = ListNode(9,ListNode(9,ListNode(9,ListNode(9,ListNode(9,ListNode(9,ListNode(9)))))))
    l2 = ListNode(9,ListNode(9,ListNode(9,ListNode(9))))
    # l1 = ListNode(2,ListNode(4,ListNode(3)))
    # l2 = ListNode(5,ListNode(6,ListNode(4)))
    s = Solution()
    l3 = s.addTwoNumbers(l1, l2)
    display_listnode(l1)
    display_listnode(l2)
    display_listnode(l3)



    

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # 哑节点：简化头节点的处理
        dummy = ListNode()
        current = dummy
        carry = 0  # 进位
        
        # 只要还有节点没处理完，或者还有进位，就继续循环
        while l1 or l2 or carry:
            # 空节点的值当作0处理
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            # 计算总和、进位和当前节点值
            total = val1 + val2 + carry
            carry = total // 10  # 十位作为新的进位
            current.next = ListNode(total % 10)  # 个位作为当前节点值
            
            # 移动所有指针
            current = current.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        
        # 返回真正的头节点（哑节点的下一个）
        return dummy.next