"""
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F

Petya has the word 𝑡, he wants to make the word 𝑝 from it. Petya begins to delete the letters in a certain order, which is described as a permutation of indices of the letters of the word 𝑡: 𝑎1…𝑎|𝑡|. Note that after deleting a letter, the numbering does not change.

His brother Vasya is afraid that Petya may delete too many letters, so he will not get the word 𝑝 in the end. Vasya's task is to stop his brother at some point and finish deleting himself in such a way, that the resulting word will be 𝑝. Since Petya likes this activity, Vasya wants to stop him as late as possible. Your task is to tell how many letters Petya can delete out before Vasya stops him.

It is guaranteed that the word 𝑝 can be obtained by deleting letters from 𝑡.


ababcba
abb
5 3 4 1 7 6 2

ans-3
"""

def check(mid, t, p, arr):
	temp = "" # temp will show how t looks after mid deletions
	s = set()
	for i in range(0, mid):
		s.add(arr[i] - 1)
	len_t = len(t)
	for i in range(0, len_t):
		if i not in s:
			temp += t[i]

	i, j, len_temp, len_p = 0, 0, len(temp), len(p)
	while i < len_temp and j < len_p:
		if i < len_temp and temp[i] != p[j]:
			i += 1
		elif i < len_temp and j < len_p and temp[i] == p[j]:
			i += 1
			j += 1

	return j == len_p


t = input()
p = input()
arr = [int(x) for x in input().split()]

if len(p) == 0:
	print(len(t))

lo, hi = 0, len(t) - len(p) + 1 # set the search space
ans = -1
while(lo <= hi):
	mid = lo + (hi - lo) // 2
	if check(mid, t, p, arr) == True:
		ans = mid
		lo = mid + 1
	else:
		hi = mid - 1

	
print(ans)










