function solution(numbers, hand) {
    var answer = '';
    var right = 10;
    var left = 10;
    var l = [1, 4, 7];
    var r = [3, 6, 9];
    var graph = [
        [0,4,3,4,3,2,3,2,1,2,1],
        [4,0,1,2,1,2,3,2,3,4],
        [3,1,0,1,2,1,2,3,2,3,4],
        [4,2,1,0,3,2,1,4,3,2],
        [3,1,2,3,0,1,2,1,2,3],
        [2,2,1,2,1,0,1,2,1,2,3],
        [3,3,2,1,2,1,0,3,2,1],
        [2,2,3,4,1,2,1,0,1,2],
        [1,3,2,3,2,1,2,1,0,1,2],
        [2,4,3,2,3,2,1,2,1,0]
    ]
    for (var num of numbers) {
        console.log('num : ', num);
        if (r.includes(num)) {
            right = num;
            answer += 'R';
        } else if (l.includes(num)) {
            left = num;
            answer += 'L';
        } else {
            console.log('right : ', right);
            var rightNum = graph[num][right];
            var leftNum = graph[num][left];
            if (rightNum < leftNum) {
                right = num;
                answer += 'R';
            } else if (rightNum > leftNum) {
                left = num;
                answer += 'L';
            } else {
                if (hand === 'right') {
                    right = num;
                    answer += 'R';
                } else {
                    left = num;
                    answer += 'L';
                }
            }
        }
    }
    return answer;
}



var test1 = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5];
var test2 = "right";
var test3 = [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2];
var test4 = "left";
var test5 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
var test5 = "right";


var result = solution(test3, test4);
// LRLLLRLLRRL
console.log(result);