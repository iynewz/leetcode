/**
 * @param {number} num
 * @return {number}
 */

var addDigits = function (num) {
  let arrayNum = num.toString().split("");
  let len = arrayNum.length;
  if (len == 1) {
    return num;
  }
  let sum;
  while (len > 1) {
    sum = 0;
    for (let i = 0; i < len; i++) {
      sum = sum + parseInt(arrayNum[i]);
    }
    arrayNum = sum.toString().split("");
    len = arrayNum.length;
  }
  return sum;
};
