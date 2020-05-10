function solution(board, moves) {
    var answer = 0;
    var basket = [];

    for (var move of moves) {
        for (var i = 0; i < board[0].length; i++) {
            var n = board[i][move-1];
            if (n !== 0) {
                basket.push(n);
                board[i][move-1] = 0;
                break;
            }
        }
    }
    for (var i = 0; i < basket.length-1; i++) {
        var a = basket[i];
        var b = basket[i + 1];
        if (a === b) {
            answer += 2;
            basket.splice(i, 1);
            basket.splice(i, 1);
            i = -1;
        }
    }
    return answer;
}


var board = [
    [0, 0, 0, 0, 0],
    [0, 0, 1, 0, 3],
    [0, 2, 5, 0, 1],
    [4, 2, 4, 4, 2],
    [3, 5, 1, 3, 1]
];

var moves = [1, 5, 3, 5, 1, 1, 4];
var result = solution(board, moves);
console.log(result);