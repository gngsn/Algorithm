function solution(lines) {
    var count = 0;
    for (var i = 0; i < lines.length; i++) {
        var cc = 1;
        var check = lines[i];
        var sec = check.split(' ')[1].split(':')[2];
        for (var j = i + 1; j < lines.length; j++) {
            var com = lines[j];
            var pt = com.split(' ')[2].split('s')[0] * 1;
            var chour = com.split(' ')[1].split(':')[0];
            var cmin = com.split(' ')[1].split(':')[1];
            var csec = com.split(' ')[1].split(':')[2] * 1;
            if (csec < pt) {
                if (cmin === '00') {
                    chour -= 1;
                    cmin = 60;
                }
                csec = 60.0;
                cmin -= 1;
            }
            var st = (csec - pt) * 1.0;
            console.log(i, '번째', j);
            console.log('\nsec : ', sec);
            console.log('st : ', st);
            if (sec > 59.0) {
                sec -= 59.0;
            }
            if (st >59.0 ) {
                st -= 59.0;
            }

            var gap = (sec - st);
            gap = Math.floor(gap*10000)/10000;
            console.log('gap : ', gap);
            if (gap < 1.0 && gap > 0.0) {
                cc++;
                console.log('cc : ', cc, '\n\n');
            }
        }
        if (count < cc) {
            count = cc;
        }
    }
    return count;
}


var lines1 = [
    '2016-09-15 01:00:04.002 2.0s',
    '2016-09-15 01:00:07.000 2s'
];

var lines2 = [
    '2016-09-15 20:59:57.421 0.351s',
    '2016-09-15 20:59:58.233 1.181s',
    '2016-09-15 20:59:58.299 0.8s',
    '2016-09-15 20:59:58.688 1.041s',
    '2016-09-15 20:59:59.591 1.412s',
    '2016-09-15 21:00:00.464 1.466s',
    '2016-09-15 21:00:00.741 1.581s',
    '2016-09-15 21:00:00.748 2.31s',
    '2016-09-15 21:00:00.966 0.381s',
    '2016-09-15 21:00:02.066 2.62s'
];
var lines3 = ["2016-09-15 00:00:00.000 3s"];
var lines5 = ["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"];
var lines4 = [
    "2016-09-15 20:59:57.421 0.351s",
    "2016-09-15 20:59:58.233 1.181s",
    "2016-09-15 20:59:58.299 0.8s",
    "2016-09-15 20:59:58.688 1.041s",
    "2016-09-15 20:59:59.591 1.412s",
    "2016-09-15 21:00:00.464 1.466s",
    "2016-09-15 21:00:00.741 1.581s",
    "2016-09-15 21:00:00.748 2.31s",
    "2016-09-15 21:00:00.966 0.381s",
    "2016-09-15 21:00:02.066 2.62s"
];

console.log(solution(lines4));