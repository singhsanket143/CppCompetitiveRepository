// normal loop
```
fun() {
	for i = 0 : i < n : i+=1
		print("Hello")

}
```
f(n) = n -> for the above algo
O(n), theta(n), omega(n)


----------------------------------------------
// constant loop
```
fun() {
	n = int(input()) # one operation

	for i = 0:i < 10**6; i+=1
		print("Hello")
}
```
For the above function the rate of growth of time w.r.t input is const
f(n) = 10**6
O(1) , theta(1), omega(1)

--------------------------------------------------
// separate loops
```
fun() {
	n = int(input())
	m = int(input())
	for i = 0: i < n:i+=1
		if i % 2 == 0:
			print("even")
		print("Hello")
	for i = 0: i < m:i+=1
		print("world")
}
```
f(n, m) = 3n + m

O(n+m)


----------------------------------------------------

// nested loop
```
fun() {
	n = int(input())
	m = int(input())
	for i = 0: i < n:i+=1
		if i % 2 == 0:
			print("even")
		print("Hello")
		for j = 0: j < m:j+=1
			print("world")
}
```
O(n*m)

m + m + m + m + m....... -> n*m (when one iteration of outer loop goes, the inner goes m times)

---------------------------------------------------

```
fun() {
	for i = 1: i <= n; i = i*2
		print("Hello")
		print("World")
		print("To")
		print("Codechef")
}
```
f(n) = 4*k

values of i -> 1 , 2, 4, 8, 16, ....... 2**k (this has k terms as loop runs k times)

2**k <= n (taking log base 2 both sides)

log(2**k) <= log(n)

k * log2 <= logn

k <= logn

f(n) = 4*k 

f(n) <= 4*logn

O(logn)


-----------------------------------------------------
```
fun() {
	n = int(input())
	i = n	
	while(i >= 1):
		i = i / 2
}
```
O(logn)

n, n/2, n/4, n/8 ........ n/(2**k) (k terms)

n/(2**k) = 1

n = 2**k

k = logn

----------------------------------------------------
```
fun() {
	n = int(input())
	if(n%3 == 0) {
		print("Hello")
		print("World")
		print("To")
		print("Codechef")
	} else {
		print("Unacademy")
	}
}
```
f(n) = 4 + 1
or f(n) = 1	+ 1 (+ 1 for if check)

O(1) -> constant



-------------------

next: Space complexity, Complexity for recursive algos(both time and space), properties of notations, Master theorem -> formula and proof






































