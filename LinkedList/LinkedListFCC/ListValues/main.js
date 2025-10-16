class Node {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

const a = new Node('A');
const b = new Node('B');
const c = new Node('C');
const d = new Node('D');

a.next = b;
b.next = c;
c.next = d;

// A -> B -> C -> B => [ 'A', 'B', 'C', 'D' ]
// my try before the instructor 
/* const linkedListValue = (head) => {
    let arr = [];
    let current = head;
    while (current !== null) {
        arr.push(current.val);
        current = current.next;
    }
    if (current === null) {
        console.log(arr);
    }
};

*/
// const linkedListValue = (head , arr = []) => {
//     if (head === null) {
//         console.log(arr);
//         return;
//     }
//     arr.push(head.val);
//     linkedListValue(head.next , arr);
    
// }; => this will lead to multiple create of arrays 

//  the instructor try 
/* const linkedListValue = (head) => {
    const  values = [];
    let current = head;
    while (current !== null) {
        values.push(current.val);
        current = current.next;
    }
    return values;
};

const linkedListValue = (head) => {
    const values = [];
    fillValues(head , values);
    return values;
};

const fillValues = (head , values) => {
    if (head === null) return;
    values.push(head.val);
    fillValues(head.next , values);
}
 */


const linkedListValue = (head) => {
    const values = [];
    fillValues(head , values);
    return console.log(values);
};

const fillValues = (head , values) => {
    if (head === null) return;
    values.push(head.val);
    fillValues(head.next , values);
};
linkedListValue(a);