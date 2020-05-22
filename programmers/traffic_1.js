function solution(lines) {
    var answer = 0;
    var hour = 0;
    var min = 0;
    var sec = 0;
    lines.map( (line) => {
        var [_, time, pTime] = line.split(' ');
        var nowHour = time.split(':')[0];
        var nowMin = time.split(':')[1];
        var endTime = time.split(':')[2];
        if (endTime < pTime) {
            if (nowMin==='00') {
                nowHour -= 1;
                nowMin = 60;
            }
            endTime = 60.0;
            nowMin -= 1;
        }
        var startTime = endTime - pTime;
        if (hour == nowHour && min == nowMin) {
            
        }
        console.log(time, pTime);
    });
    return answer;
}



lines =  [
    '2016-09-15 01:00:04.002 2.0s',
    '2016-09-15 01:00:07.000 2s'
];

solution(lines);