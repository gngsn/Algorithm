function solution(s) {
    var answer = 0;
    for (var comp =1; comp < s.length/2+1; comp++ ) {
        var strArr = []; 
        for (var split =0; split+comp < s.length+1; split+=comp ) {
            var str = s.substring(split, split+comp);
            strArr.push(str);
        }
        var length = 0;
        for (var index=0; index < strArr.length; index++) {
            var count = 0;
            while (count < strArr.length) {
                if(strArr[index] !== strArr[index+count+1]) break;
                count++;
            }
            if (count != 0) {
                length += (1+comp);
                index += count;
            } else {
                length += comp;
            }
        }
        length += s.length % comp;
        if ( (answer > length) || comp == 1) {
            answer = length;
        }
    }    
    return answer;
}