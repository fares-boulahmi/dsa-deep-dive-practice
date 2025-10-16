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


const o = new Node('O');
const l = new Node('L');
const j = new Node('J');
const k = new Node('K');



a.next = b;
b.next = c;
c.next = d;
d.next = e;
e.next = f;


o.next = l;
l.next = j;
j.next = k;

// const zipperList = (headOne , headTwo) => {
//     let currentOne = headOne.next;
//     let currentTwo = headTwo;
//     let tail = headOne;
//     let count = 0;
//     while(tail !== null) {
//         if ((count % 2) == 0) {

//             if (currentTwo === null) return ;
//             tail.next = currentTwo;
//             currentTwo = currentTwo.next;
//         } else {
//             if (currentOne === null) return ;
//             tail.next = currentOne;
//             currentOne = currentOne.next;
//         }
//         tail = tail.next;
//         count++;
//     }
// };

const zipperList = (headOne , headTwo) => {
    if (headOne === null || headTwo === null) return;
    const nextHeadOne = headOne.next;
    const nextHeadTwo = headTwo.next;
    headOne.next = headTwo;
    headTwo.next = nextHeadOne;
    
    return zipperList(nextHeadOne , nextHeadTwo);

};

// zipperList(a , o);

// instructor implement 
/* const zipperLists = (head1 , head2) =>  {
    let tail = head1;
    let current1 = head1.next;
    let current2 = head2;
    let count = 0;
    while (current1 !== null && current2 !== null) {
        if (count % 2 === 0 ) {
            tail.next = current2;
            current2 = current2.next;
        } else {
           tail.next = current1;
           current1 = current1.next; 
        }
        tail = tail.next;
        count++
    }

    if (current1 !== null) tail.next = current1;
    if (current2 !== null) tail.next = current2;

    return head1;

};
 */
const zipperLists = (head1 , head2) => {
    if (head1 === null && head2 === null) return null;
    if (head1 === null) return head2;
    if (head2 === null) return head1;

    const next1 = head1.next;
    const next2 = head2.next;
    head1.next= head2;
    head2.next = zipperLists(next1 , next2);

    return head1;

};
// zipperLists(a , o);


const linkedListValue = (head) => {
    const  values = [];
    let current = head;
    while (current !== null) {
        values.push(current.val);
        current = current.next;
    }
    return values;
};

// console.log(linkedListValue(a));
console.log(linkedListValue(zipperLists(a , o)));

