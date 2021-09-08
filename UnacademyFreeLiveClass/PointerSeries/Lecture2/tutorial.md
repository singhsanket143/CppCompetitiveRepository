## How pointers helps us to manipulate data in the heap ? 

### The memory of a process is majorly divided in two big parts - Stack and Heap. (There are some other segments as well)

 - Stack Memory
    - Stack memeory is used to store the context of a function call. 
        Linear memory area
        fun() -> gun() -> fun1()
 - Heap Memory
    - Heap memory is a big pool of memory where we can store data. 


# How to allocate heap memory in C lang ? 
 - malloc -> This is a function in C lang which helps us to allocate data on Heap
 - malloc takes the size of the memory you want to block
 - malloc returns a void pointer

# How to allocate heap memory in C++ ? 
 - We have an operator `new` that helps us to initialise a variable inside heap memory
 - the `new ` operator takes the type of the bucket in order to initialise it in the heap memory
 - `new` returns a pointer of the type of the bucket

# How to de-allocate heap memory in C lang ? 
 - free - this is a function in C lang which helps us to de-allocate data on heap

# How to de-allocate heap memory in C++ ?
 - `delete` operator in order to de-allocate memory 

-------------------
If we want to allocate something in stack, we can just do : int x = 10;


## What is a void pointer ? 
It is a pointer with no associated data type to it. 

Ex of basic pointer: `int* ptr = &x;`
Ex of void pointer: `void* ptr =  &x;` , at the address of x, we don't know what type of bucket it is, so my pointer calls itself void pointer as it is type agnostic
We cannot dereference it. 
In order to derefernece we need to typecast it


## What is a dangling pointer ? 
A pointer that previously pointed to a memory location but that location has been deleted or freed. This type of pointer is dangling pointer.

## What is a NULL pointer ? 
It is a pointer which points to nothing.

## What is a Wild Pointer ? 
A pointer which has not been initialized ever is a wild pointer as it can have any garbage (non null garbage can also be there based on compiler).


## What is a function pointer ? 
These are special type of pointers that points to a function. 

