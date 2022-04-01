console.log(getPermutations("abc"));

function getPermutations(str) {

	if (str.length == 0) {
		let arr = [];
		arr.push("");
		return arr;
	}

	let ch = str.charAt(0);

	let ros = str.substring(1);

	let rr = getPermutations(ros);

	let mr = [];
	console.log("rr is ", rr)
	for (let j = 0; j < rr.length; j++) {
        let val = rr[i];
		console.log("val is", ""+val)
		for (let i = 0; i <= val.length; i++) {
			// console.log(val);
			// console.log(val.substring(i));
			// console.log(val.substring(ch));
			let res = val.substring(0, i) + ch + val.slice(i);
			mr.push(res);
		}
	}

	return mr;

}