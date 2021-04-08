class Node:
	key = ""
	value = 0
	next = None
	def __init__(self, key, value):
		self.key = key
		self.value = value

class HashMap:
	cs = 0
	ts = 1
	arr = []

	def __init__(self, ts):
		self.ts = ts
		self.arr = [None]*ts

	def hashfunc(self, key):
		sum = 0
		factor = 1
		for i in range(len(key)):
			sum = ((sum%self.ts) + (ord(key[i])*factor)%self.ts)%self.ts
			factor = ((factor%self.ts) * (37%self.ts))%self.ts;

		return sum

	def rehash(self):
		print("Now rehashing")
		old_size = self.ts
		self.ts *= 2
		li = self.arr
		self.arr = [None]*self.ts
		self.cs = 0
		for i in range(old_size):
			temp = li[i]
			while temp != None:
				self.insert(temp.key, temp.value)
				temp = temp.next

	def insert(self, key, value):
		bi = self.hashfunc(key)
		node = Node(key, value)
		if self.arr[bi] == None:
			self.arr[bi] = node 
		else:
			# collision
			node.next = self.arr[bi]
			self.arr[bi] = node 
		self.cs += 1
		load_factor = self.cs / self.ts
		print(load_factor, self.cs, self.ts)
		if load_factor > 0.5:
			self.rehash()

	def search(self, key):
		bi = self.hashfunc(key)
		temp = self.arr[bi]
		while temp != None:
			if(temp.key == key):
				return temp.value
			temp = temp.next
		return None

	def update(self, key, value):
		if(self.search(key) == None):
			return False
		bi = self.hashfunc(key)
		temp = self.arr[bi]
		while(temp != None):
			if temp.key == key:
				temp.value = value
			temp = temp.next
		return True

	def display(self):
		for i in range(self.ts):
			temp = self.arr[i]
			if(temp == None):
				print("empty")
			else:
				while temp != None:
					print(f"key: {temp.key} -> value: {temp.value}", end = " | ")
					temp = temp.next
				print()


hashmap = HashMap(2)
hashmap.insert("mango", 1)
hashmap.insert("apple", 2)
hashmap.insert("appy", 11)
hashmap.insert("apipie", 81)
hashmap.insert("banana", 19)
hashmap.insert("bananpie", 100)
hashmap.insert("mangopie", 100)
hashmap.insert("applepie", 100)
hashmap.insert("api", 100)
hashmap.display()
