class Node {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

const a = new Node(2);
const b = new Node(8);
const c = new Node(3);
const d = new Node(-1);
const e = new Node(7);

a.next = b;
b.next = c;
c.next = d;
d.next = e;

// my try before the instructor 
/* const sumList = (head) => {
    let sum = 0;
    let current = head;
    while(current !== null) {
        sum += current.val;
        current = current.next;
    }
    if (current === null ) console.log(sum);
    
};

 */

/* const sumList = (head , sum = 0) => {
     if (head === null) return console.log(sum);
    sum += head.val;
    sumList(head.next , sum);
};
 */
// const sumList = (head) => {
//     let sum = fillValues(head , 0);
//     return console.log(sum);
// };

// const fillValues = (head , sum) => {
//     if (head === null) return sum;
//     sum += head.val;    
//     return fillValues(head.next , sum);
// };

// the instructor code 
/* const sumList = (head) => {
    let sum = 0;
    let current = head;
    while(current !== null) {
        sum += current.val;
        current = current.next;
    }
    return sum;    
};
 */
const sumList = (head) => {
    if (head === null) return 0;
    return head.val + sumList(head.next);
    
};

// sumList(a); // 19
console.log(sumList(a));