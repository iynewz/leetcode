/*
 * @lc app=leetcode id=22 lang=typescript
 *
 * [22] Generate Parentheses
 */

// @lc code=start

/*turn into binary, define 0 = '(' and 1 = ')' */

var generateParenthesis = function (n) {
  let k = 1 << (2 * n);
  const result = [];
  for (let i = 0; i < k; i++) {
    const stack = [];
    let ok = true; // flag variable
    let ans = [];
    for (let j = 0; j < 2 * n; j++) {
      let d = (i & (1 << j)) == 0;
      if (d) {
        ans.push("(");
        stack.push(0);
      } else if (stack.length > 0 && stack[stack.length - 1] == 0) {
        ans.push(")");
        stack.pop();
      } else {
        ok = false;
        break;
      }
    }
    if (ok && stack.length == 0) {
      result.push(ans.join(""));
    }
  }
  return result;
};
// @lc code=end
