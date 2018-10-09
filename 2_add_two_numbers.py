# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None
def addTwoNumbers(l1, l2):
		return addTwoNumbers1(l1, l2, 0)

def num_reverse(num):
	if num == 0:
		return None
	else:
		snum = str(num)
		index = len(snum) - 1
		result = ListNode(snum[index])
		current = result
		index -= 1
		while index>=0:
			newnode = ListNode(snum[index])
			current.next = newnode
			current = newnode
			index -= 1
		
		return result

def addTwoNumbers1(l1, l2, x):
	if l1 == None and l2 == None:
		return num_reverse(x)
	elif l1 == None and l2 != None:
		t = l2.val + x
		x = t // 10
		c = t % 10
		newnode = ListNode(c)
		newnode.next = addTwoNumbers1(None, l2.next, x)
		return newnode
	elif l1 != None and l2 == None:
		t = l1.val + x
		x = t // 10
		c = t % 10
		newnode = ListNode(c)
		newnode.next = addTwoNumbers1(l1.next, None, x)
		return newnode
	else:
		t = l1.val + l2.val + x
		x = t // 10
		c = t % 10
		newnode = ListNode(c)
		newnode.next = addTwoNumbers1(l1.next, l2.next, x)
		return newnode
# class Solution:
    # def addTwoNumbers(self, l1, l2):
    #     """
    #     :type l1: ListNode
    #     :type l2: ListNode
    #     :rtype: ListNode
    #     """
    #     num1 = 0
    #     num2 = 0
    #     digit_index_1 = 0
    #     digit_index_2 = 0
    #     current_1 = l1
    #     current_2 = l2
    #     while current_1:
    #     	num1 += current_1.val * (10**digit_index_1)
    #     	digit_index_1 += 1
    #     	current_1 = current_1.next

    #     while current_2:
    #     	num2 += current_2.val * (10**digit_index_2)
    #     	digit_index_2 += 1
    #     	current_2 = current_2.next

    #     num = str(num1 + num2)
    #     length = len(num)
        
    #     num_index = length -1
    #     result = ListNode(num[num_index])
    #     while num_index >=0:
    #     	newnode = ListNode(num[num_index])
    #     	result
    #     	num_index -= 1
	# def addTwoNumbers(self, l1, l2):
	# 	return addTwoNumbers1(l1, l2, 0)

	# def num_reverse(self, num):
	# 	if num == 0:
	# 		return None
	# 	else:
	# 		snum = str(num)
	# 		index = len(snum) - 1
	# 		result = ListNode(snum[index])
	# 		current = result
	# 		index -= 1
	# 		while index>=0:
	# 			newnode = ListNode(snum[index])
	# 			current.next = newnode
	# 			current = newnode
	# 			index -= 1
	# 			return result

	# def addTwoNumbers1(self, l1, l2, x):
	# 	if l1 == None and l2 == None:
	# 		return num_reverse(x)
	# 	elif l1 == None and l2 != None:
	# 		t = l2.val + x
	# 		c = t - (t%10)
	# 		x = t % 10
	# 		newnode = ListNode(c)
	# 		newnode.next = addTwoNumbers1(None, l2.next, x)
	# 		return newnode
	# 	elif l1 != None and l2 == None:
	# 		t = l1.val + x
	# 		c = t - (t%10)
	# 		x = t % 10
	# 		newnode = ListNode(c)
	# 		newnode.next = addTwoNumbers1(l1.next, None, x)
	# 		return newnode
	# 	else:
	# 		t = l1.val + l2.val + x
	# 		c = t - (t%10)
	# 		x = t % 10
	# 		newnode = ListNode(c)
	# 		newnode.next = addTwoNumbers1(l1.next, l2.next, x)
	# 		return newnode
if __name__ == '__main__':
	# l1 = ListNode(1)
	# current = l1
	# for i in range(2,101):
	# 	newnode = ListNode(i)
	# 	current.next = newnode
	# 	current = newnode
	# current = l1
	# while current:
	# 	print(current.val)
	# 	current = current.next

	# l1 = ListNode(2)
	# l1.next = ListNode(4)
	# l1.next.next = ListNode(3)

	# l2 = ListNode(5)
	# l2.next = ListNode(6)
	# l2.next.next = ListNode(4)

	l1 = ListNode(5)
	l2 = ListNode(5)

	r = addTwoNumbers(l1,l2)
	# s = Solution()
	# r = s.addTwoNumbers(l1, l2)
	while r:
		print(r.val)
		r = r.next
        