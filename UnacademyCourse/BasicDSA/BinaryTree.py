import sys

class Node:
	data = -1
	left = None
	right = None

	def __init__(self, data):
		self.data = data


def buildBTRec():
	d = int(input())
	if d == -1:
		return None

	root = Node(d)
	root.left = buildBTRec()
	root.right = buildBTRec()
	return root

def preorder(root):
	if(root == None):
		return

	print(root.data, end = ", ")
	preorder(root.left)
	preorder(root.right)


def inorder(root):
	if(root == None):
		return

	inorder(root.left)
	print(root.data, end = ", ")
	inorder(root.right)


def postorder(root):
	if(root == None):
		return

	postorder(root.left)
	postorder(root.right)
	print(root.data, end = ", ")


def countNodes(root):
	if(root == None):
		return 0

	c1 = countNodes(root.left)
	c2 = countNodes(root.right)
	return 1+c1+c2


def height(root):
	if(root == None):
		return 0

	return 1 + max(height(root.left), height(root.right))


total_tilt = 0
def tilt(root): # this function returns sum of nodes of tree
	if(root == None):
		return 0

	global total_tilt
	left_sum = tilt(root.left)
	right_sum = tilt(root.right)
	total_tilt += abs(left_sum - right_sum)
	return left_sum + right_sum + root.data


def levelorderlevelwise(root):
	qu = []
	if(root == None):
		print("Empty tree")
		return
	qu.append(root)
	qu.append(None)
	while qu:
		curr = qu.pop(0)
		if curr == None:
			print()
			if qu:
				qu.append(None)
		else:
			print(curr.data, end = " ")
			if curr.left != None:
				qu.append(curr.left)
			if curr.right != None:
				qu.append(curr.right)


def topviewhelper(root, dist, mp):
	if(root == None):
		return

	if mp.get(dist) == None:
		mp[dist] = root.data

	topviewhelper(root.left, dist-1, mp)
	topviewhelper(root.right, dist+1, mp)
	return


def topview(root):
	mp = {}
	topviewhelper(root, 0, mp)
	min_dist , max_dist = 10000000000, -10000000000
	for k in mp.keys():
		if k < min_dist:
			min_dist = k
		if k > max_dist:
			max_dist = k 

	i = min_dist
	while i <= max_dist:
		print(mp[i], end = " ")
		i += 1

def bottomviewhelper(root, dist, mp):
	if(root == None):
		return

	
	mp[dist] = root.data

	bottomviewhelper(root.left, dist-1, mp)
	bottomviewhelper(root.right, dist+1, mp)
	return


def bottomview(root):
	mp = {}
	bottomviewhelper(root, 0, mp)
	min_dist , max_dist = 10000000000, -10000000000
	for k in mp.keys():
		if k < min_dist:
			min_dist = k
		if k > max_dist:
			max_dist = k 

	i = min_dist
	while i <= max_dist:
		print(mp[i], end = " ")
		i += 1

def isBSTHelper(root):
	if(root == None):
		return (True, -sys.maxsize, sys.maxsize)

	leftresult = isBSTHelper(root.left)
	rightresult = isBSTHelper(root.right)
	is_bst = (leftresult[0] == True) and (rightresult[0] == True) and (leftresult[1] < root.data) and (rightresult[2] >= root.data)
	max_ = max(root.data, leftresult[1], rightresult[1])
	min_ = min(root.data, leftresult[2], rightresult[2])
	return (is_bst, max_, min_)



def isBST(root):
	result = isBSTHelper(root)
	return result[0]


def diameter_helper(root):
	if root == None:
		return (-1, 0)

	lr = diameter_helper(root.left)
	rr = diameter_helper(root.right)

	h = max(lr[0], rr[0])+1
	dia = max(lr[1], rr[1], lr[0]+rr[0]+2)
	return (h, dia)

def diameter(root):
	result = diameter_helper(root)
	return result[1]

idx = 0
def buildHelper(pre, ino, inlo, inhi, mp):
	if inlo > inhi :
		return None

	global idx

	nn = Node(pre[idx])
	# s = -1
	# for i in range(inlo, inhi+1):
	# 	if(pre[idx] == ino[i]):
	# 		s = i
	# 		break

	s = mp.get(pre[idx])

	idx += 1
	nn.left = buildHelper(pre, ino, inlo, s-1, mp)
	nn.right = buildHelper(pre, ino, s + 1, inhi, mp)
	return nn

def buildBTUsingPREIN(pre, ino):
	mp = {}
	for i in range(len(ino)):
		mp[ino[i]] = i

	root = buildHelper(pre, ino, 0, len(ino)-1, mp)
	return root

# root = buildBTRec()
# print()
# preorder(root)
# print()
# inorder(root)
# print()
# postorder(root)
# print()
# print(countNodes(root))
# print(height(root))
# tilt(root)
# print(total_tilt)
# levelorderlevelwise(root)
# topview(root)
# print()
# bottomview(root)
# print()
# print(isBST(root))

pre = [4,5,2,3,6,7,1]
ino = [5,4,6,3,7,2,1]

root1 = buildBTUsingPREIN(pre, ino)
postorder(root1)
"""
1
2
-1
-1
3
5
7
10
-1
-1
33
-1
-1
8
-1
-1
6
-1
-1

"""
