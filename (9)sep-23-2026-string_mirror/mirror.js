let str1 = "!dlroW !olleH";
let str2 = "Hello World";

// check str1 and str2 is a mirror string or not, only consider alphabetical character
function isMirror(str1, str2) {
  let final_str1 = "";
  let final_str2 = "";

  // remove all the characters including empty space from str1 except alphabets
  for (char of str1) {
    if (/[a-zA-Z]/.test(char)) {
      final_str1 += char;
    }
  }

  // remove all the characters including empty space from str2 except alphabets
  for (char of str2) {
    if (/[a-zA-Z]/.test(char)) {
      final_str2 += char;
    }
  }

  // return the equality of reversed str1 and str2
  return final_str1.split("").reverse().join("") == final_str2;
}

console.log(isMirror(str1, str2));
