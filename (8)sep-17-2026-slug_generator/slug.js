let arbitrary_string = "  ?H^3-1*1]0! W[0%R#1]D  ";

// create a valid url string
function slug_generator(arbitrary_string) {
  let result = [];

  let lower_str = arbitrary_string.toLowerCase();

  let previous_was_space = false;

  for (let char of lower_str) {
    //check if char is a number or alphabet
    if (/[a-zA-Z0-9]/.test(char)) {
      result.push(char);
      previous_was_space = false;
    } else if (char == " ") {
      if (result.length > 0 && !previous_was_space) {
        result.push("%20");
        previous_was_space = true;
      }
    }

    // ignore everything else except a digit or an alphabet or an empty space...
  }

  if (result.length > 0 && result[result.length - 1] == "%20") {
    result.pop();
  }

  return result.join("");
}

let slug = slug_generator(arbitrary_string);

console.log(slug);
