// function teacher() {}
// var fun = function () { // anonymous function expression
//     // console.log();
//     var n = null;
//     console.log(n.toString());
// }

// var fun1 = function gun() { // named function expression
//     var n = null;
//     console.log(n.toString());
// }

// console.log(teacher);
// console.log(fun);
// fun();
// console.log(gun);



[1, 2, 3, 4, 5].map(function factorial (n) {
    return !(n > 1) ? 1 : factorial(n - 1) * n;
});