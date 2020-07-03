function solution(expression) {
    var answer = 0;
    let arr = [muladdmin(expression)];
    arr.push(mulminadd(expression));
    arr.push(addminmul(expression));
    arr.push(addmulmin(expression));
    arr.push(minaddmul(expression));
    arr.push(minmuladd(expression));

    console.log (arr);
    return arr.reduce(function (prev, curr) {
        if (prev < 0) prev *= -1;
        if (curr < 0) curr *= -1;
        console.log(prev);
        console.log(curr);
        return prev > curr ? prev*1 : curr*1;
    });
}

function cal(exp, regex) {
    var str = exp.match(regex);
    while (str !== null) {
        var result = eval(str[0]);
        console.log('result : ', result);
        var exp = exp.replace(regex, result);
        str = exp.match(regex);
    }
    return exp;
}

function muladdmin (exp) {
    if (!exp.includes('*')) return 0;
    exp = cal(exp, new RegExp(/[-]?(\d*)\*[+*-]?(\d*)/));
    exp = cal(exp, /[-]?(\d*)\+(\d*)/);
    return exp = cal(exp, /[-]?(\d+)\-[-+*]?(\d+)/);
}
function mulminadd (exp) {
    if (!exp.includes('*')) return 0;
    exp = cal(exp, new RegExp(/[-]?(\d*)\*[+*-]?(\d*)/));
    exp = cal(exp, /[-]?(\d+)\-[-+*]?(\d+)/);
    return exp = cal(exp, /[-]?(\d*)\+(\d*)/);
}
function addminmul (exp) {
    if (!exp.includes('+')) return 0;
    exp = cal(exp, /[-]?(\d*)\+(\d*)/);
    exp = cal(exp, /[-]?(\d+)\-[-+*]?(\d+)/);
    return exp = cal(exp, new RegExp(/[+-]?(\d*)\*[+*-]?(\d*)/));
}
function addmulmin (exp) {
    if (!exp.includes('+')) return 0;
    exp = cal(exp, /[-]?(\d*)\+(\d*)/);
    exp = cal(exp, new RegExp(/[-]?(\d*)\*[+*-]?(\d*)/));
    return exp = cal(exp, /[-]?(\d+)\-[-+*]?(\d+)/);
}
function minaddmul (exp) {
    if (!exp.includes('-')) return 0;
    exp = cal(exp, /[-]?(\d+)\-[-+*]?(\d+)/);
    console.log('exp : ', exp);
    exp = cal(exp, /[-]?(\d*)\+(\d*)/);
    console.log('exp : ', exp);
    return exp = cal(exp, new RegExp(/[-]?(\d*)\*[+*-]?(\d*)/));
}
function minmuladd (exp) {
    if (!exp.includes('-')) return 0;
    exp = cal(exp, /[-]?(\d+)\-[-+*]?(\d+)/);
    exp = cal(exp, /[-]?(\d*)\+(\d*)/);
    return exp = cal(exp, new RegExp(/[-]?(\d*)\*[+*-]?(\d*)/));
}


var test1 = "100-200*300-5000-20";
var test2 = "50*6-3*2";
var test3 = "50+2";
var test4 = 300;

var result = solution(test3);
console.log('\n\n\n 답! ', result);