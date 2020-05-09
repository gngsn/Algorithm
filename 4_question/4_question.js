const solution = (k, room_number) => {
    var answer = new Map;
    return room_number.map( room => {
        return match(answer, room);
    });
}

const match = (answer, r) => {
    var i = answer.get(r);
    if (i === undefined) {
        answer.set(r, r+1);
        return r;
    }
    var update = match(answer, i);
    answer.set(r, update);
    return update;
}


var test1 = 10;
var test2 = [1, 3, 4, 1, 3, 1];

var result = solution(test1, test2);
console.log(result);