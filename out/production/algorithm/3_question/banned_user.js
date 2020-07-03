function solution(user_id, banned_id) {
    var answer = 1;
    var matchArr = [
        []
    ];
    var sameBan = [];

    for (var i = 0; i < banned_id.length; i++) {
        if (banned_id[i - 1] === banned_id[i] && i > 0) {
            sameBan.push(i - 1);
            sameBan.push(i);
            console.log('sameBan : ', sameBan);
        }
        var matchId = [];
        for (var id of user_id) {
            if (matchId.includes(id)) continue;
            if (banned_id[i].length !== id.length) continue;
            var copyId = id;
            var array = banned_id[i].split('*');
            for (var reg of array) {
                if (!copyId.match(reg) && reg != '') {
                    break;
                }
                copyId = copyId.substring(reg.length + 1, copyId.length);
            }
            if (copyId == '') {
                matchId.push(id);
                continue;
            }
        }
        matchArr[i] = matchId;

    }
    matchId = [
        []
    ];
    sameBan.filter((item, index) => array.indexOf(item) === index);
    if (sameBan.length > 0) {
        for (i in sameBan) {
            if (matchArr[sameBan[i]].length == sameBan.length) {
                answer++;
            }
        }
    }
}



var test1 = ["frodo", "fradi", "crodo", "abc123", "frodoc"];
var test2 = ["fr*d*", "abc1**"];

var test3 = ["frodo", "fradi", "crodo", "abc123", "frodoc"];
var test4 = ["*rodo", "*rodo", "******"];

var test5 = ["frodo", "fradi", "crodo", "abc123", "frodoc"];
var test6 = ["fr*d*", "*rodo", "******", "******"];

// var result = solution(test1, test2);
// var result = solution(test3, test4);
var result = solution(test5, test6);
// console.log(result);