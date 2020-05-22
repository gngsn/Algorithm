function solution(p) {
    var answer = '';
    if (p == ' ') {
        return ' ';
    }
    answer = split_right_str(p);

    return answer;
}

function check_perfect_str(p) {
    var stack = [];
    if (p == '') return false;
    for (var i = 0; i < p.length; i++) {
        if (str === '(') {
            var str = p[i];
            stack.push(str);
        } else {
            var pop = stack.pop();
            if (pop === undefined) {
                return true;
            }
        }
    }
    return false;
}


// 균형잡힌 괄호 문자열
function split_right_str(p) {
    // 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행 
    // -> 수행한 결과 문자열을 u에 이어 붙인 후 반환
    // var stack = [];
    var u = '';
    var v = '';
    var count = 0;

    for (var i = 0; i < p.length; i++) {
        var str = p[i];
        if (str == '(') {
            count++;
        } else {
            count--;
        }
        u += str;
        if (count == 0) {
            v = p.substring(i + 1, p.length);
            u = rearrange_str(u);
            if ( v == '') {
                return u;
            }
            v = split_right_str(v);
            v = rearrange_str(v);
            return u + v;
        }
    }
}

function rearrange_str(p) {
    var result = '';
    var checkSum = 0;
    var left = '';
    for (var i = 0; i < p.length; i++) {
        
        var str = p[i];
        if (str === ')') {
            checkSum--;
            result += str;
        } else {
            if(checkSum < 0) {
                left += str;
            } else {
                result += str; 
            }
            checkSum++;
        }
        if (checkSum === 0){
            result = left + result;
        }
    }
    return result;
}