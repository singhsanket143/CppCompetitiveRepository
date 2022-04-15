let n = 10;

let a = 0, b = 1;

if(n >= 0) {
    console.log(a);
}
if(n >= 1) {
    console.log(b);
}

for(let i = 2; i <= n; i++) {
    let c = a + b; // fi = fi-2 + fi-1 // b-> fi-1, a ->fi-2
    console.log(c);
    a = b;
    b = c;
}

