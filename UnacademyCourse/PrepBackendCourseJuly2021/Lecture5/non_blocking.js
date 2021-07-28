function printHello() {
    console.log("Hello");
}

function blockForSec() {
    for(let i = 0; i < 1000000000; i++) {}
    console.log("Unblocked");
}

console.log("Start");
setTimeout(printHello, 0);
blockForSec();
console.log("Me First");
blockForSec();
