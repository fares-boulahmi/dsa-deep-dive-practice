*IntroductiontoAlgorithms:6.006*

Massachusetts Institute of Technology

Instructors: Erik Demaine, Jason Ku, and Justin Solomon Lecture 3: Sorting

**Lecture3:Sorting**

**SetInterface(L03-L08)**

| Container | build(X) len() | given an iterable X, build set from items in X return the number of stored items |
| --- | --- | --- |
| Static | find(k) | return the stored item with key k |
| Dynamic | insert(x) delete(k) | add xto set (replace item with key x.keyif one already exists) remove and return the stored item with key k |
| Order | iterord()

findmin()

findmax()

findnext(k) findprev(k) | return the stored items one-by-one in key order return the stored item with smallest key

return the stored item with largest key

return the stored item with smallest key larger than k return the stored item with largest key smaller than k |
- Storing items in an array in arbitrary order can implement a (not so efficient) set
- Stored items sorted increasing by key allows:

**–**faster find min/max (at first and last index of array)

**–**faster finds via binary search: *O*(log*n*)

| Set

Data Structure |  |  | Operations *O*(*·*) |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|  |  |  | Container |  | Static |  | Dynamic |  | Order |  |  |  |
|  |  |  | build(X) |  | find(k) |  | insert(x) delete(k) |  | findmin() findmax() | findprev(k) findnext(k) |  |  |
| Array |  |  | *n* |  | *n* |  | *n* |  | *n* | *n* |  |  |
| Sorted Array |  |  | *n*log*n* |  | log*n* |  | *n* |  | 1 | log*n* |  |  |
- But how to construct a sorted array efficiently?

2 *Lecture3:Sorting*

**Sorting**

- Given a sorted array, we can leverage binary search to make an efficient set data structure.
- **Input**: (static) array *A*of *n*numbers
- **Output**: (static) array *B*which is a sorted permutation of *A***–Permutation**: array with same elements in a different order

**–Sorted**: *B*[*i−*1]*≤B*[*i*]for all *i∈{*1*, . . . , n}*

- Example: [8*,*2*,*4*,*9*,*3]*→*[2*,*3*,*4*,*8*,*9]
- A sort is **destructive**if it overwrites *A*(instead of making a new array *B*that is a sorted version of *A*)
- A sort is **inplace**if it uses *O*(1)extra space (implies destructive: in place *⊆*destructive)

**Permutation Sort**

- There are *n*!permutations of *A*, at least one of which is sorted
- For each permutation, check whether sorted in Θ(*n*)
- Example: [2*,*3*,*1]*→{*[1*,*2*,*3]*,*[1*,*3*,*2]*,*[2*,*1*,*3]*,*[2*,*3*,*1]*,*[3*,*1*,*2]*,*[3*,*2*,*1]*}*

1 defpermutation_sort(A):

2 ’’’SortA’’’

3 forBinpermutations(A): #O(n!)

4 ifis_sorted(B): #O(n)

5 returnB #O(1)

- permutationsortanalysis:

**–**Correct by case analysis: try all possibilities (Brute Force)

**–**Running time: Ω(*n*!*·n*)which is **exponential**:(

**SolvingRecurrences**

- **Substitution**: Guess a solution, replace with representative function, recurrence holds true **RecurrenceTree**: Draw a tree representing the recursive calls and sum computation at nodes **MasterTheorem**: A formula to solve many recurrences (R03)

*Lecture3:Sorting* 3

**SelectionSort**

- Find a largest number in prefix A[:i+1]and swap it to A[i]
- Recursively sort prefix A[:i]
- Example: [8*,*2*,*4*,*9*,*3]*,*[8*,*2*,*4*,*3*,*9]*,*[3*,*2*,*4*,*8*,*9]*,*[3*,*2*,*4*,*8*,*9]*,*[2*,*3*,*4*,*8*,*9]

1 defselection_sort(A,i=None): #T(i)

2 ’’’SortA[:i+1]’’’

3 if i is None: i = len(A) - 1 # O(1)

4 if i > 0: # O(1)

5 j=prefix_max(A,i) #S(i)

6 A[i],A[j]=A[j],A[i] #O(1)

7 selection_sort(A,i- 1) #T(i- 1)

8

9 defprefix_max(A,i): #S(i)

10 ’’’ReturnindexofmaximuminA[:i+1]’’’

11 if i > 0: # O(1)

12 j=prefix_max(A,i- 1) #S(i- 1)

13 ifA[i]<A[j]: #O(1)

14 returnj #O(1)

15 returni #O(1)

- prefixmaxanalysis:

**–**Base case: for *i*= 0, array has one element, so index of max is *i*

**–**Induction: assume correct for *i*, maximum is either the maximum of A[:i]or A[i],

returns correct index in either case.

**–***S*(1)=Θ(1)*, S*(*n*) =*S*(*n−*1)+Θ(1)

*∗*Substitution: *S*(*n*)=Θ(*n*)*, cn*=Θ(1)+*c*(*n−*1)=*⇒*1=Θ(1)

- selectionsortanalysis: *∗*Recurrence tree: chain of *n*nodes with Θ(1)work per node, P*n−*1 *i*=01=Θ(*n*)

**–**Base case: for *i*= 0, array has one element so is sorted

**–**Induction: assume correct for *i*, last number of a sorted output is a largest number of

the array, and the algorithm puts one there; then A[:i]is sorted by induction

**–***T*(1)=Θ(1)*, T*(*n*) =*T*(*n−*1)+Θ(*n*)

*∗*Substitution: *T*(*n*)=Θ(*n*2)*,* *cn*2=Θ(*n*) +*c*(*n−*1)2=*⇒c*(2*n−*1)=Θ(*n*)

*∗*Recurrence tree: chain of *n*nodes with Θ(*i*)work per node, P*n−*1 *i*=0*i*=Θ(*n*2)

4 *Lecture3:Sorting*

**InsertionSort**

- Recursively sort prefix A[:i]
- Sort prefix A[:i+1]assuming that prefix A[:i]is sorted by repeated swaps
- Example: [8*,*2*,*4*,*9*,*3]*,*[2*,*8*,*4*,*9*,*3]*,*[2*,*4*,*8*,*9*,*3]*,*[2*,*4*,*8*,*9*,*3]*,*[2*,*3*,*4*,*8*,*9]

1 definsertion_sort(A,i=None): #T(i)

2 ’’’SortA[:i+1]’’’

3 if i is None: i = len(A) - 1 # O(1)

4 if i > 0: # O(1)

5 insertion_sort(A,i- 1) #T(i- 1)

6 insert_last(A,i) #S(i)

7

8 definsert_last(A,i): #S(i)

9 ’’’SortA[:i+1]assumingsortedA[:i]’’’

10 if i > 0 and A[i] < A[i - 1]: # O(1)

11 A[i],A[i- 1]=A[i- 1],A[i] #O(1)

12 insert_last(A,i- 1) #S(i- 1)

- insertlastanalysis:

**–**Base case: for *i*= 0, array has one element so is sorted

**–**Induction: assume correct for *i*, if A[i]>=A[i- 1], array is sorted; otherwise,

swapping last two elements allows us to sort A[:i]by induction

**–***S*(1)=Θ(1)*, S*(*n*) =*S*(*n−*1) + Θ(1)=*⇒S*(*n*)=Θ(*n*)

- insertionsortanalysis:

**–**Base case: for *i*= 0, array has one element so is sorted

**–**Induction: assume correct for *i*, algorithm sorts A[:i]by induction, and then

insertlastcorrectly sorts the rest as proved above

**–***T*(1)=Θ(1)*, T*(*n*) =*T*(*n−*1)+Θ(*n*) =*⇒T*(*n*)=Θ(*n*2)

*Lecture3:Sorting* 5

**MergeSort**

- Recursively sort first half and second half (may assume power of two)
- Merge sorted halves into one sorted list (two finger algorithm)
- Example: [7*,*1*,*5*,*6*,*2*,*4*,*9*,*3]*,*[1*,*7*,*5*,*6*,*2*,*4*,*3*,*9]*,*[1*,*5*,*6*,*7*,*2*,*3*,*4*,*9]*,*[1*,*2*,*3*,*4*,*5*,*6*,*7*,*9]

1 defmerge_sort(A,a=0,b=None): #T(b- a=n)

2 ’’’SortA[a:b]’’’

3 ifbisNone:b=len(A) #O(1)

4 if 1 < b - a: # O(1)

5 c = (a + b + 1) // 2 # O(1)

6 merge_sort(A,a,c) #T(n/2)

7 merge_sort(A,c,b) #T(n/2)

8 L,R=A[a:c],A[c:b] #O(n)

9 merge(L,R,A,len(L),len(R),a,b) #S(n)

10

11 def merge(L, R, A, i, j, a, b): # S(b- a = n)

12 ’’’MergesortedL[:i]andR[:j]intoA[a:b]’’’

13 if a < b: # O(1)

14 if (j <= 0) or (i > 0 and L[i - 1] > R[j - 1]): # O(1)

15 A[b - 1] = L[i - 1] # O(1)

16 i = i - 1 # O(1)

17 else: #O(1)

18 A[b - 1] = R[j - 1] # O(1)

19 j = j - 1 # O(1)

20 merge(L, R, A, i, j, a, b - 1) # S(n- 1)

- mergeanalysis:

**–**Base case: for *n*= 0, arrays are empty, so vacuously correct

**–**Induction: assume correct for *n*, item in A[r]must be a largest number from remaining

prefixes of Land R, and since they are sorted, taking largest of last items suffices;

remainder is merged by induction

**–***S*(0)=Θ(1)*, S*(*n*) =*S*(*n−*1) + Θ(1)=*⇒S*(*n*)=Θ(*n*)

- mergesortanalysis:

**–**Base case: for *n*= 1, array has one element so is sorted

**–**Induction: assume correct for *k < n*, algorithm sorts smaller halves by induction, and

then mergemerges into a sorted array as proved above.

**–***T*(1)=Θ(1)*, T*(*n*) = 2*T*(*n/*2)+Θ(*n*)

*∗*Substitution: Guess *T*(*n*)=Θ(*n*log*n*)

*cn*log*n*=Θ(*n*) + 2*c*(*n/*2)log(*n/*2)=*⇒cn*log(2)=Θ(*n*)

*∗*Recurrence Tree: complete binary tree with depth log2*n*and *n*leaves, level *i*has 2*i* nodes with *O*(*n/*2*i*)work each, total: Plog2*n i*=0(2*i*)(*n/*2*i*) = Plog2*n i*=0*n*=Θ(*n*log*n*)

are

6.006 Introduction to Algorithms

Spring 2020

For information about citing these materials or our Terms of Use, visit: