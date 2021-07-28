for(var i = 0; i < 10; i++) {
    // console.log(i);
}
console.log("Value of i: ", i);

function fun() {
    console.log(x);
    // x = 9;
    var x = 10;
    function gun() {
        var y = 20;
        console.log(x, y);
    }
    gun();
    printHello();
    // console.log(x, y);
}
// console.log("Test: ",x);
fun(); 
// console.log("Test: ",x);


function printHello() {
    console.log("print hello");
}



//---------------------------
console.log("Let demo\n");

for(let j = 0; j < 10; j++) {
    // some code
}
// console.log(j);


let x = 1;
if( x == 1) {
    let x = 2;
    console.log(x);
}
console.log(x);

console.log(a);
var f = function test() {
    console.log(b);
}
var a = 10;
let b = 3;
f();
// tdz -> temporal dead zone


function abs(x, y) {
    if(x > y) {
        let tmp = x;
        x = y;
        y = tmp;
    }
    return y - x;
}

function get(str) {
    // something
}
function test(str) {
    try {
        var resp = get(str);
    } catch (err) {
        var resp = -1;
    }
    return resp;
}

///////
if(true) {
    const q = 10;
    console.log(q);
    // q = 67;
}
// console.log(q);


const arr = [10,20];
arr.push(30);
arr = [];
