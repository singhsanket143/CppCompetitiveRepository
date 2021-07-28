var teacher = "Sanket Singh"; // global
function fun() { // global scope
    teacher = "Pulkit"; // scope of global;
    console.log("Hello world"); // global scope
}

function gun() { // global scope
    var student = "Arjun"; // local to gun
    console.log(student, teacher); // global
}

fun(); // global
gun(); // global