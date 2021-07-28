"use strict";
var teacher = "Sanket";
function fun() {
    var teacher = "Pulkit";
    function gun(question) {
        console.log(teacher, question);
    }
    gun("What do u teach ? ");
}

console.log(teacher);
fun();
gun("??");