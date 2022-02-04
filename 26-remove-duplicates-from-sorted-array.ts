function removeDuplicates(nums:number[]):number{
    let len = nums.length;
    let cur = 0;
    for(let i = 1; i < len; i++) {
        if (nums[cur] == nums[i]) {
            continue;
        }else {
            cur++;
            nums[cur] = nums[i];
        }
    }
    return cur+1;
}