// how to know where to apply dp?
// - if the question asks total number of ways (count) / maximum ans / minimum ans
// i.e, - try all the ways types - count the ways / best way
// use recursion

// steps to write recurrence relation (approach / shortcut) : 
// 1. Try to represent the problem in terms of index
// 2. Do all possible stuffs on that index according to the problem statement
// 3. Sum of all stuffs -> count all ways
//      or, min(of all stuffs) -> min
//      or, max(of all stuffs) -> max


// f(index){
//     if (index==0)return 1;
//     if (index==1) return 1;

//     return f(index-1) + f(index-2);
// }

// this is same as fibonacci
// so do this using Memoization
// then tabulation and then space optimization