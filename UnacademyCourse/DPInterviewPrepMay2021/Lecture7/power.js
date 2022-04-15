function power(x, n) {
    let ans = 1;
    for(let i = 1; i <= n; i++) {
        ans = ans * x;
    }
    return ans;
}

console.log(power(10, 4))