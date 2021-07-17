var num = 10;
var dec = 10.12;
var bool = true; // false/true
var un = undefined;
var str = "string";
var obj = {};
console.log(num, dec, bool);
console.log(typeof num, typeof dec, typeof bool, typeof str, typeof obj, typeof undefined);


//// Objects
var x = {};
var y = {"name": "Sanket Singh"};
var z = {name: "Sanket Singh"};
x.name = "Sanket Singh";

console.log(x, y, z, x.age);

var arr = [1,2,3,4,5];
console.log(arr);
console.log(typeof arr);
arr.name = "Sanket";
console.log(arr.length);

var fun = function() {}
console.log(typeof fun); // function is a subtype of object


///////////////
console.log(1 + "2");
console.log(1 - "2");
console.log(1 - "Sanket");

var m = Number("39");
var n = Number("Sanket");
var o = NaN;
console.log(m, n, typeof n, typeof o);
console.log(isNaN(m)); // false
console.log(isNaN(n)); // true
console.log(isNaN("Hey")); // true

console.log(m === NaN); // false;
console.log(n === NaN); // false

console.log(Number.isNaN(m));
console.log(Number.isNaN(n));

/////////////////////
var pzero = 0;
var nzero = -0; // IEEE 754
console.log(pzero, nzero);
console.log(pzero === nzero); // instead of this
console.log(Object.is(nzero, -0));
console.log(Object.is(pzero, 0));
console.log(Object.is(nzero, 0));


