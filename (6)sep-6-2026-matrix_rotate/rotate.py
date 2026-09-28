
matrix = [[ 1, 2, 3],
          [ 4, 5, 6],
          [ 7, 8, 9]]


def rotate_matrix(matrix):

    rotated_matrix = []
    rows = len(matrix)
    cols = len(matrix[0])

    for col in range(cols):

        new_row = []

        for row in range(rows -1, -1, -1):
            new_row.append(matrix[row][col])


        rotated_matrix.append(new_row)


    return rotated_matrix

result = rotate_matrix(matrix)

print(result)

