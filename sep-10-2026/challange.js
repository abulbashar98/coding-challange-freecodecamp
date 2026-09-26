const arr1 = ["I", "like", "freeCodeCamp"];
const arr2 = ["I", "like", "rocks"];

let semantic_diff_in_alphabetical_order = [...new Set([...arr1, ...arr2])]
  .filter((value) => arr1.includes(value) != arr2.includes(value))
  .sort((a, b) => {
    return a - b;
  });

console.log(semantic_diff_in_alphabetical_order);
