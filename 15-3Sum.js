/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  const result = [];
  function sortNumber(a, b) {
    return a - b;
  }
  const sortedArray = nums.sort(sortNumber);

  for (let i = 0; i < nums.length - 2; i++) {
    if (sortedArray[i] > 0) {
      break;
    }
    /*deduplicate arrays */
    if (i > 0 && sortedArray[i] == sortedArray[i - 1]) {
      continue;
    }
    let secondPointer = i + 1;
    let thirdPointer = nums.length - 1;
    while (secondPointer < thirdPointer) {
      let sum =
        sortedArray[i] + sortedArray[secondPointer] + sortedArray[thirdPointer];
      if (sum == 0) {
        result.push([
          sortedArray[i],
          sortedArray[secondPointer],
          sortedArray[thirdPointer],
        ]);
        secondPointer++;
        while (
          nums[secondPointer] === nums[secondPointer - 1] &&
          secondPointer < thirdPointer
        )
          secondPointer++;
      } else if (sum > 0) {
        thirdPointer--;
      } else {
        secondPointer++;
      }
    }
  }

  return result;
};
