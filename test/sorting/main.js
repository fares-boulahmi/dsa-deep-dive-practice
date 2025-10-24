let arr = [4, 5, 48, 9, 151, 33, 8, 66, 19];

function prefix_max(arr, i) {
    console.log("return index of maximum in arr[i + 1] ");
    if (i > 0) {
        console.log("the i > 0", i);
        let j = prefix_max(arr, i - 1);
        console.log("the j is :", j);

        if (arr[i] < arr[j]) {
            console.log("arr[i] > arr[j]", j);

            return j;
        }
    }
    console.log("i : ", i);

    return i;
}

let result = prefix_max(arr, arr.length - 1);
console.log("result was ", result);