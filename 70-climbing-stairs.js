var climbStairs = function (n) {
  const f = [1, 2, 3];
  for (let i = 3; i < n; i++) {
    f.push(f[i - 1] + f[i - 2]);
  }
  return f[n - 1];
};
