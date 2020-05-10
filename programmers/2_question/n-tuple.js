function solution(s) {
    var arr = s.split('{');
    var list = [
        []
    ];
    var j = 0;
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] !== '') {
            l = arr[i].split('}')[0].split(',');
            list[l.length - 1] = l;
            j++;
        }
    }
    var tuple = [];
    // 오반데....
    for (var li = 0; li < list.length; li++) {
        for (var comp of list[li]) {
            for (var i = li; i < list.length; i++) {
                for (var l of list[i]) {
                    if (comp === l) {
                        const idx = list[i].indexOf(l)
                        if (idx > -1) list[i].splice(idx, 1);
                        break;
                    }
                }
            }
            tuple.push(comp * 1);
        }
    }
    return tuple;
}


var test1 = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
var test2 = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
var test3 = "{{20,111},{111}}";
var test4 = "{{4,2,3},{3},{2,3,4,1},{2,3}}";

var result = solution(test3);
console.log(result);