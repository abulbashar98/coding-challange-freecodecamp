let rgbString = "rgb(243, 177, 24)";

function convertToHex(rgbString) {
  let extractedValuesArrayFromString = rgbString
    .replace("rgb(", "")
    .replace(")", "")
    .split(",");

  console.log(extractedValuesArrayFromString);

  let r = Number(extractedValuesArrayFromString[0]);
  let g = Number(extractedValuesArrayFromString[1]);
  let b = Number(extractedValuesArrayFromString[2]);

  return (
    "#" +
    r.toString(16).padStart(2, "0") +
    g.toString(16).padStart(2, "0") +
    b.toString(16).padStart(2, "0")
  );
}

result = convertToHex(rgbString);

console.log(result);
