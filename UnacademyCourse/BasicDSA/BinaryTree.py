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


root = buildBTRec()
print()
preorder(root)
print()
inorder(root)
print()
postorder(root)
print()
print(countNodes(root))


"""

1
2
3
-1
-1
-1
4
5
-1
6
-1
-1
7
-1
-1

"""
