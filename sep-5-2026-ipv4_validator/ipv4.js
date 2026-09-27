const ipv4_address = "255.01.50.111";

function isValidIPv4(ipv4_address) {
  let splitted_array_by_dot = ipv4_address.split(".");
  console.log(splitted_array_by_dot);

  let element_count = 0;

  for (let [index, element] of splitted_array_by_dot.entries()) {
    if (element == "") {
      return false;
    } else if (element.length > 1 && element[0] == "0") {
      return false;
    }

    for (let char of element) {
      if (char < "0" || char > "9") {
        return false;
      }
    }

    element = parseInt(element);

    if (element < 0 || element > 255) {
      return false;
    }

    element_count++;
  }

  if (element_count != 4) {
    return false;
  }

  return true;
}

console.log(isValidIPv4(ipv4_address));
