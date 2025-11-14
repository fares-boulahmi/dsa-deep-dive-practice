let arr = [];
let start = 0;

let target = Math.round(Math.random() * 1024 + 1);
target = 1555;
let timeCalled = 0;

for (let index = 1; index <= 1024; index++) {
  arr.push(index);
}
let end = arr.length - 1;

function binarySearchM(arr, start, end, target) {
  // base case first el the target
  if (arr[0] == target)
    return console.log("success found the target at first index ");

  // stop case for target bigger then last el
  if (arr[arr.length - 1] < target)
    return console.error("target bigger than the last element ");

  // stop case for target less then first el
  if (arr[0] > target)
    return console.error("target is less than the first element ");

  // find the middle point in the array
  let middlePoint = start + Math.round((end - start) / 2);
  console.log(
    "the call number is ",
    ++timeCalled,
    "and the middle point is ",
    middlePoint
  );

  //   return for found target
  if (arr[middlePoint] == target) {
    console.log(
      "success found the target at index",
      middlePoint,
      arr[middlePoint]
    );
    return "Done";
  }
  if (timeCalled > 20) {
    return "stop";
  }
  //   if target is less than the middle point will search in second half and the start become the middle point else will search in first half and the search will be in first half and the end will be the middle point
  if (arr[middlePoint] < target) {
    return binarySearchM(arr, middlePoint, end, target);
  } else {
    return binarySearchM(arr, start, middlePoint, target);
  }
}

// the instructor solution
function binarySearchI(arr, start, end, target) {
  console.log("the call number is ", ++timeCalled);
  console.log(arr.slice(start, end));

  if (start > end) return false;
  let midIndex = Math.floor((start + end) / 2);
  if (arr[midIndex] == target) return true;
  if (arr[midIndex] > target)
    return binarySearchI(arr, start, midIndex - 1, target);
  else return binarySearchI(arr, midIndex + 1, end, target);
}

binarySearchM(arr, start, end, target);
console.log("*******************************************************");
console.log("*******************************************************");
timeCalled = 0;

console.log(binarySearchI(arr, start, end, target));
