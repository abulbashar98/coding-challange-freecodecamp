const number = "+00 (358) 234-0182";

function isSpam(number) {
  let countryCode = number.slice(1, number.indexOf(" "));
  let areaCode = number.slice(number.indexOf("(") + 1, number.indexOf(")"));
  let localNumber = number.slice(number.indexOf(")") + 2).replace("-", "");

  // --------------------------------
  //   check 1st condition
  // --------------------------------

  if (countryCode.length > 2 || countryCode[0] != "0") {
    return true;
  }

  // --------------------------------
  // check 2nd condition
  // --------------------------------

  let areaInt = Number(areaCode);

  if (areaInt < 200 || areaInt > 900) {
    return true;
  }

  // --------------------------------
  // check 3rd condition
  // --------------------------------

  let sumOfFirstThreeInLocal =
    Number(localNumber[0]) + Number(localNumber[1]) + Number(localNumber[2]);

  let four_last_digits = localNumber.slice(3);

  if (four_last_digits.includes(String(sumOfFirstThreeInLocal))) {
    return true;
  }

  // --------------------------------
  // check 4th condition
  // --------------------------------

  let digits = "";

  for (let char of number) {
    if (/[0-9]/.test(char)) {
      digits += char;
    }
  }

  let count = 1;
  for (let i = 1; i < digits.length; i++) {
    if (digits[i] == digits[i - 1]) {
      count++;

      if (count >= 4) {
        return true;
      }
    } else {
      count = 1;
    }
  }

  return false;
}

if (isSpam(number)) {
  console.log("The given number is a spam");
} else {
  console.log("The number is valid");
}
