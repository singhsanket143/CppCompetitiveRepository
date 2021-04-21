from queue import PriorityQueue
class MaxHeapEl():
	def __init__(self, x):
		self.x = x

	def __lt__(self, o):
		return self.x > o.x

	def __str__(self):
		return str(self.x)

max_heap = PriorityQueue()
max_heap.put(MaxHeapEl(10))
max_heap.put(MaxHeapEl(200))
max_heap.put(MaxHeapEl(30))
max_heap.put(MaxHeapEl(40))
max_heap.put(MaxHeapEl(-10))

print(max_heap.get())
print(max_heap.get())
print(max_heap.get())

