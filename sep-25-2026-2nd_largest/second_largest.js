let arr = [1, 0, -1, 0, 1, 0, -1, 1, 0];

function distinctSecondLargest(arr) {
  let sorted_arr = [...new Set(arr)].sort((a, b) => a - b);
  console.log(sorted_arr);
  return sorted_arr[sorted_arr.length - 2];
}

console.log(distinctSecondLargest(arr));
