let n = 5;

for(let row = 1; row <= n; row++) {
    let str = "";
    for(let spaces = 1; spaces <= n-row; spaces++) {
        str += " "
    }
    for(let stars = 1; stars <= 2*row-1; stars++) {
        str += "*";
    }
    console.log(str);
}