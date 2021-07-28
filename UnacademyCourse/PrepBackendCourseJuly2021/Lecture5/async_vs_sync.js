function printHello() {
    console.log("hello");
}

setTimeout(printHello, 2000); // t = 1ms -> registry
console.log("Ended"); // t = 2ms