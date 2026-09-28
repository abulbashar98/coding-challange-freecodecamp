const originalString = "National Aeronautics and Space Administration";

const ignoreList = ["a", "for", "an", "and", "by", "of"];

function buildAcronym(originalString, ignoreList) {
  // 1st use split() to split this original string and create an array

  let splitted_array = originalString.split(" ");
  //   console.log(splitted_array);

  let acronym = "";

  for (let [index, element] of splitted_array.entries()) {
    if (index == 0 || !ignoreList.includes(element.toLowerCase())) {
      acronym += element[0].toUpperCase();
    }
  }

  return acronym;
}

let acronym_result = buildAcronym(originalString, ignoreList);

console.log(acronym_result);
