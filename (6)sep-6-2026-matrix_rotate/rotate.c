#include <stdio.h>


void rotate_ninety_degree(int matrix[][3], int rows, int cols){
    
    int rotated_matrix[cols][rows];

    for(int col = 0; col < cols; col++){

        for(int row = 0; row < rows; row++){
            rotated_matrix[col][row] = matrix[rows - 1 - row][col]; 
        }

    }

    // copy rotated matrix into original matrix
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            matrix[row][col] = rotated_matrix[row][col];
        }
    }

}


void print_rotated_matrix(int matrix[][3], int rows, int cols){

    printf("[");
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            printf("%d,", matrix[row][col]);
        }
        if(row < rows - 1){
            printf("\n");
        }
    }
    printf("]");

}

int main(void){

    int matrix[][3] = {{ 1, 2 ,3},
                       { 4, 5, 6},
                       { 7, 8, 9}};

    int rows = (sizeof(matrix)/sizeof(matrix[0]));
    int cols = (sizeof(matrix[0])/sizeof(matrix[0][0]));


    // printf("%d, %d", rows, cols);

    rotate_ninety_degree(matrix, rows, cols);
    print_rotated_matrix(matrix, rows, cols);

    return 0;
}