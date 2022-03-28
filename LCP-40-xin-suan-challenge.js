/* greedy,[https://leetcode-cn.com/problems/uOAnQW/](https://leetcode-cn.com/problems/uOAnQW/)
排序，先取最大的 `cnt` 个，如果和是偶数直接输出；如果是奇数就取 `Math.max（一个已取的最小的奇数换成剩下未取的最大的偶数，一个已取的最小的偶数换成剩下未取的最大奇数）` */

/**
 * @param {number[]} cards
 * @param {number} cnt
 * @return {number}
 */

var maxmiumScore = function (cards, cnt) {
  let ans = 0;
  let cardsSorted = cards.sort((a, b) => b - a); // 从大到小排
  console.log(cardsSorted);
  for (let i = 0; i < cnt; i++) {
    ans += cardsSorted[i];
  }
  if (ans % 2 == 0) {
    return ans;
  } else {
    // 已选中的最小奇数 minOdd -替换成-> 未选中的最大偶数
    // 已选中的最小偶数 minEven -替换成-> 未选中的最大奇数
    let minOdd = 999;
    let minEven = 1000;
    for (let i = 0; i < cnt; i++) {
      minOdd =
        cardsSorted[i] % 2 == 0 ? minOdd : Math.min(minOdd, cardsSorted[i]);
      minEven =
        cardsSorted[i] % 2 == 0 ? Math.min(minEven, cardsSorted[i]) : minEven;
    }
    console.log(minEven, minOdd);
    let maxOdd = 1;
    let maxEven = 0;
    let len = cards.length;
    if (len == cnt) {
      return 0; // corner case，第一次提交漏了这个
    } else {
      for (let i = cnt; i < len; i++) {
        maxOdd =
          cardsSorted[i] % 2 == 0 ? maxOdd : Math.max(maxOdd, cardsSorted[i]);
        maxEven =
          cardsSorted[i] % 2 == 0 ? Math.max(maxEven, cardsSorted[i]) : maxEven;
      }
      let ans1 = ans - minOdd + maxEven;
      let ans2 = ans - minEven + maxOdd;
      return Math.max(ans1, ans2);
    }
  }
};
