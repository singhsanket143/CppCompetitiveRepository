function *create() {
    // yield 1;
    // yield 2;
    // yield 3;

    const n = 10;
    const m = yield n;
    yield 5 + m;
    yield 6;
}

const result = create();
console.log(result);
console.log(result.next());
console.log(result.next(2));
console.log(result.next(3));
console.log(result.next());





async function asyncFunc() {
    // fetch data from a url endpoint
    const response = await axios.get("/some_url_endpoint"); // "hi" {value: "hi", onfullfillment: []}
    const data = await response.json();
  
    return data;
  }
  asyncFunc();
  console.log("me first");