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
const e = new Node('E');
const f = new Node('F');

a.next = b;
b.next = c;
c.next = d;
d.next = e;
e.next = f;


/* const reverseList = (head) => {
    let current = head;
    let prev = null;
    while (current !== null) {
        let next = current.next ;
        current.next = prev;
        prev = current;
        current = next;
    }
        return prev;
} */

/* const reverseList = (head , prev = null) => {
    if (head === null) return prev;
    const next = head.next ;
    head.next = prev;
    prev  = head ;
    head = next;
    return reverseList(head, prev );
} */

// instructor implment 
const reverseList = (head , prev = null) => {
    if (head === null) return prev;
    const next = head.next ;
    head.next = prev;
    return reverseList(next, head );
}


const linkedListValue = (head) => {
    const  values = [];
    let current = head;
    while (current !== null) {
        values.push(current.val);
        current = current.next;
    }
    return values;
};

console.log(linkedListValue(reverseList(a)));
console.log(linkedListValue(reverseList(f)));
console.log(linkedListValue(reverseList(a)));
