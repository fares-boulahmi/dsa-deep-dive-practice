// O(n^2)
function print(n, c) {
  let print = "";
  for (let j = 0; j < n; j++) {
    print += c + 1;
  }
  console.log(print);
}
function square(n) {
  for (let i = 0; i < n; i++) {
    print(n, i);
  }
}
// square(4);

// O(n^3)
function cube(n) {
  for (let i = 0; i < n; i++) {
    console.log("the start of drawing face", i + 1);

    for (let j = 0; j < n; j++) {
      print(n, j);
    }
  }
}
// cube(4);

// O(log n)

function logFunc(n) {
  if (n === 0) return "Done";
  console.log(n);
  n = Math.floor(n / 2);
  return logFunc(n);
}

// logFunc(16);

function logN(n) {
  while (n > 1) {
    n = Math.floor(n / 2);
    console.log(n);
  }
}

// logN(13);


