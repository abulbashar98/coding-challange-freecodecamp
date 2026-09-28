let matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];

function rotate_matrix(matrix) {
  let rotated_matrix = [];

  let row = [];

  for (let col = 0; col < matrix[0].length; col++) {
    let row = [];

    for (let i = matrix.length - 1; i >= 0; i--) {
      row.push(matrix[i][col]);
    }
    rotated_matrix.push(row);
  }

  return rotated_matrix;
}

result = rotate_matrix(matrix);
console.log(result);
