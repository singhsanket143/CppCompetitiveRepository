"use strict";
var teacher = "Sanket";
function fun() {
    teacher = "Pulkit";
    content = "JS"; // fun scope
    console.log("Unacademy");
}

fun();
console.log(content);
console.log(teacher);