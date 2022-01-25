/** a and b are strings, a = '23342'
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
  /* though you can use strings as numbers in JS, the proper way to do it is map the string into int */
  const arrayA = a
    .split("")
    .reverse()
    .map((d) => parseInt(d, 10));
  const arrayB = b
    .split("")
    .reverse()
    .map((d) => parseInt(d, 10));
  let arrayOut = [];
  let carry = 0;

  /* make array A and B the same length */

  while (arrayA.length < arrayB.length) {
    arrayA.push(0);
  }

  while (arrayB.length < arrayA.length) {
    arrayB.push(0);
  }

  for (let i = 0; i < arrayA.length; i++) {
    arrayOut.push(arrayA[i] ^ arrayB[i] ^ carry);
    if (arrayA[i] + arrayB[i] + carry >= 2) {
      carry = 1;
    } else {
      carry = 0;
    }
  }
  if (carry == 1) {
      arrayOut.push(1);
  }
  return arrayOut.reverse().join('');
};
