var teacher = "Sanket"; // global
function ask(question) {// global
    console.log(teacher, question); // global, ask
}

function fun() { // global
    var teacher = "Pulkit"; // fun
    ask("why");
}

fun();