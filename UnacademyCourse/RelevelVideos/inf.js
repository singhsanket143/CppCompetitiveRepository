process.stdin.resume();
process.stdin.setEncoding('utf8');
 
let inputString = "";
let currentLine = 0;
var M = 1000000007;
 
process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
});
 
process.stdin.on("end", (_) => {
    inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
        return string.trim();
    });
    solve();
});
function readLine() {
    return inputString[currentLine++];
}
 
 
function val(sum,X,N){
    return(sum[X%N]+((Math.floor(X/N)%M)*sum[N])%M)%M;
}

function solve(){
    let inp = readLine().split(" ").map((x) => parseInt(x));
    let T = parseInt(inp[0],10);
    while(T--){
        inp = readLine().split(" ").map((x) => parseInt(x));
 
        let N = parseInt(inp[0],10);
        let arr = [];
        inp = readLine().split(" ").map((x) => parseInt(x));
        for(let i=1;i<=N;i++){
            arr[i] = parseInt(inp[i-1],10);
        }
        inp = readLine().split(" ").map((x) => parseInt(x));
        let Q = parseInt(inp[0],10);
        let L = new Array(Q).fill(0);
        let R = new Array(Q).fill(0);
        inp = readLine().split(" ").map((x) => parseInt(x));
        for(let i=0;i<Q;i++){
            L[i] = parseInt(inp[i],10);
        }
        inp = readLine().split(" ").map((x) => parseInt(x));
        for(let i=0;i<Q;i++){
            R[i] = parseInt(inp[i],10);
        }
        let sum = new Array(N+1).fill(0);
        sum[0] = 0;
        for(let i=1;i<=N;i++){
            sum[i] = (sum[i-1]+arr[i])%M;
        }
        for(let i=0;i<Q;i++){
            console.log((val(sum,R[i],N)-val(sum,L[i]-1,N)+M)%M)
        }
    }
}
 
