// 문자열 p를 이루는 '(' 와 ')' 의 개수는 항상 같음
// p가 이미 올바른 괄호 문자열이라면 그대로 return 
function solution(p) {
    var answer = '';
    if (p == ' ') {
        return '';
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
            console.log('uuuu : ', u);
            v = p.substring(i + 1, p.length);
            console.log('\nvvvv : ', v, '\n');
            u = rearrange_str(u);
            if ( v == '') {
                return u;
            }
            v = split_right_str(v);
            v = rearrange_str(v);
            console.log('u : ', u);
            console.log('\nv : ', v, '\n');
            return u + v;
        }
    }
}

function rearrange_str(p) {
    console.log('ppp : ', p);
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


test1 = "(()())()";
test2 = "))((";
test3 = "()))((()";
test4 = ")()()()(";


var result = solution(test4);
console.log('\n\n', test4, 'result  : ', result);







// 더 이상 분할 X -> false , 할 게 더잇음 true
function check_split_end(p) {
    if (p === '') return false;
    var right = 0;
    var left = 0;
    for (var i = 0; i < p.length; i++) {
        var str = p[i];
        if (str == '(') {
            right++;
        } else {
            left++;
        }
        if ((right === left) && (i !== p.length - 1)) {
            return true;
        }
    }
    return false;
}