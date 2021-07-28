function create(arr) {
    let i = 0;
    function temp() {
        const el = arr[i];
        i++;
        return el;
    }
    return temp;
}

const result = create([1,2,3]);
console.log(result);
console.log(result());
console.log(result());
