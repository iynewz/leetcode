/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function (s, t) {
  let arrayS = s.split("").sort();
  let arrayT = t.split("").sort();
  // arrayS.push('0');
  let len = arrayS.length;
  for (let i = 0; i < len; i++) {
    if (arrayS[i] != arrayT[i]) {
      return arrayT[i];
    } else continue;
  }
  return arrayT[arrayT.length - 1];
};
