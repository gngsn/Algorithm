function solution(gems) {
    var answer = [];
    var map = new Map();
    for (var g = 0; g < gems.length; g++) {
        var arr = map.get(gems[g]);
        if (arr === undefined) arr = [g];
        else arr.push(g);
        map.set(gems[g], arr);
    }
    var start = 0;
    var end = 0;
    for (var g = 0; g < gems.length; g++) {
        var num = map.get(gems[g]);
        if (arr.includes(num)) start = num;
        else arr.push(g);
        map.set(gems[g], arr);
    }
    // check(map.keys(), map);
    console.log(map);
    return answer;
}

function check (key, map) {
    if (key === undefined) return;
    var k = 0;
    while (k !== undefined) {
        k = key.next().value;
        var values = map.get(k);
    }
    console.log('values : ', values);
}

var test1 = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"];
var test2 = ["AA", "AB", "AC", "AA", "AC"];
var test3 = ["XYZ", "XYZ", "XYZ"];
var test4;
var test5;

var result = solution(test1);
console.log(result);