// ToString()
var x = null; // "null"
console.log("" + x);

var un = undefined; // "undefined"
console.log("" + undefined);

var b = true; // "true"
console.log("" + b);

var num = 4.1223; // "4.1223"
console.log("" + num);

var nzero = -0; // "0"
console.log("" + nzero);

console.log("" + []); // [] -> ""
console.log("" + {}); // {} ->[object Object]

console.log("" + [1,2,3]);

console.log("" + [1, null, undefined]); // -> "1,," and not "1,null,undefined"

console.log("" + [[[], [], []], []]); // -> ",,,"

console.log("" + [,,]);

var obj = {unacademy: "codechef"};
console.log("" + obj);

var new_obj = {
    x: 1,
    y: 2,
    toString() {
        return "Hello world";
    }
}
console.log("" + new_obj);

// ToNumber()

console.log(10 - ""); // -> "" - 0
console.log(10 - "0"); // -> "0" - 0
console.log(10 - "-0"); // -> "-0" - -0
console.log(10 - "   0008   "); // -> "   0008  " - 8
console.log(10 - ">"); // -> "" - 0
console.log(10 - "0xaf"); // "0xaf" -> 175

console.log(10 - undefined); // undefined -> NaN
console.log(10 - null); // null -> 0

console.log(10 - false); // false - 0
console.log(10 - true); // true - 1

console.log(10 - [""]);

console.log(10- ["0"]); // 0
console.log(10 - ["-0"]); // 0

console.log(10 - [null]);
console.log(10 - [undefined]);

console.log(10 - {});

console.log(10 - {valueOf() {return 3}});

// ToBoolean()
if(true && (function() {return false;})()) {
    console.log("hi")
} else {
    console.log("bye");
}

console.log(1 < 2 < 3); // 
console.log(3 > 2 > 1); // 1 > 1


/// eqwuality operators
console.log(42 == [42]); //[42] -> "42" -> 42

var a1 = [];
var a2 = [];
console.log([] == []);
console.log(a1 == a1);

console.log({} == !{}); // [] == false -> [] == 0 -> 0 == 0 -> true

if(a1.length > 0) {
    console.log("hey");
}