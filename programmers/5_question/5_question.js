var numArr = [];
const solution = (stones, k) => {
    var answer = 0;
    while (check(stones, k)) {
        stones = jump(stones, k);
        console.log('stones : ', stones);
    }
    return;
}

const jump = (stones) => {
    return stones.map(e => e - 1);
}

const check = (stones, k) => {
    if (stones.length === 0) return false;
    // console.log('stones : ', stones);
    return removeZero(stones, 0, k);
}

const removeZero = (stones, start, k) => {
    if (start > stones.length) return true;
    idx = stones.indexOf(0, start);
    console.log('start : ', start);
    if (idx === -1) return true;
    numArr[idx] = idx;
    if (numArr.length === 0) return true;
    stones.splice(idx, 1);
    var n = k;
    n = checkMin(numArr, idx - 1, n);
    // console.log('n : ', k);
    // console.log('numArr : ', numArr);
    // console.log('idx : ', idx);
    if (!checkPl(numArr, idx + 1, n)) return false;
    removeZero(stones, idx + k, k);
}

const checkMin = (numArr, idx, k) => {
    if (numArr[idx] !== idx) return k;
    return checkMin(numArr, idx - 1, k - 1);
}

const checkPl = (numArr, idx, k) => {
    if (k == 0) return false;
    if (numArr[idx] !== idx) return true;
    console.log('sdsd : ', k); 
    return checkPl(numArr, idx + 1, k - 1);
}

var test1 = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1];
var test2;
var test3;
var test4;
var test5;
var k = 3;

var result = solution(test1, 3);
console.log(result);