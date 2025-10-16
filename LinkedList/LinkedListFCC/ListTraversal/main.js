class Node {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

const a = new Node(4);
const b = new Node(44);
const d = new Node(444);
const c = new Node(4444);

a.next = b;
b.next = c;
c.next = d;

// A -> B -> C -> D -> NULL
// 5 -> 55 -> 5555 -> 555 -> NULL

const PrintLinkedList = (head) => {
    let current = head;
    while (current !== null) {
        console.log(current.val);
        current = current.next;
    }
};

const PrintLinkedListRecursive = (head) => {
    if (head === null ) return;
    console.log(head.val);
    PrintLinkedListRecursive(head.next);
    
};


// PrintLinkedList(a);


PrintLinkedListRecursive(a);