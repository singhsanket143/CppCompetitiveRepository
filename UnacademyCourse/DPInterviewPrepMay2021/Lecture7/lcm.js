function gcd(a, b) {
    if(b > a) {
        // swap the two numbers
        let c = a;
        a = b;
        b = c;
    }
    while(b != 0) { // this loop will end when b becomes 0
        let rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

function lcm(a, b) {
    return (a*b) / gcd(a, b);
}

console.log(lcm(12, 16))