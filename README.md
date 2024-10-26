## Jacobi Iterative Method

The Jacobi iterative method can solve any number of systems of linear equations.

1. This program first checks if the augmented matrix provided is diagonally dominant or not. The `diagonal()` function performs this check. If the matrix is diagonally dominant or convertible to a diagonally dominant form, it keeps or converts the matrix to that form and returns `true`. If the matrix is not diagonally dominant or convertible, it returns `false`, and the program exits since the Jacobi method requires the augmented matrix to be in this form.

2. If `true`, the program proceeds to solve the equations. The tolerance and the maximum number of iterations are set in the program.

3. It takes the set of initial variable values in a vector (`x0`, `y0`, `z0`, ...) and, for each equation (or row of the matrix), calculates the next set of variable values (`x1`, `y1`, `z1`, ...) using the `nextVal()` function and stores them in another vector.

4. Now, it checks if the difference between each of the new set of values and old values is less than the tolerance. If not, it loops repeatedly until the difference is less than the tolerance or it reaches the maximum number of iterations.

---

## Gauss-Seidel Iterative Method

The Gauss-Seidel iterative method can solve any number of systems of linear equations. It generally requires fewer iterations to converge than the Jacobi iterative method.

1. The first two steps are the same as the Jacobi iterative method.

2. It takes the set of initial variable values in a vector (`x0`, `y0`, `z0`, ...) and, for each equation (or row of the matrix), calculates the next set of variable values (`x1`, `y1`, `z1`, ...) using the `nextVal()` function and updates them immediately in the previous vector. Therefore, in each iteration, the updated values of variables are used.

3. Now, it checks if the difference between each of the new set of values and old values is less than the tolerance. If not, it loops repeatedly until the difference is less than the tolerance or it reaches the maximum number of iterations.

---

## Matrix Inversion

This program finds the inverse of any n x n singular matrix using the Jordan elimination method and row echelon form.

1. The program first takes input `n` and creates an n x 2n matrix using a vector. The first `n` columns are initialized with the user's given matrix, and the next `n` columns are initialized with an identity matrix.

2. It checks if any row has `0` as a pivot element. If so, it swaps with another row. If no swapping is possible and the pivot element is still zero, the matrix is singular, and the inverse is not possible. The program exits.

3. It transforms the n x n lower triangular matrix to 0 while performing operations on the entire n x 2n matrix. Then it passes the whole matrix to the `jordanEli()` function to perform the same operations on the upper triangular matrix.

4. Now, the matrix from the nth column to 2n-th column represents the inverse matrix, which is printed.

---

## LU Factorization Method

This method solves a system of linear equations for 2, 3, and 4 variables. Since LU factorization operates on constant time, the equations are hardcoded without loops.

1. First, the user selects the number of equations to solve, i.e., 2, 3, or 4. The program then flows to the corresponding block where equations are hardcoded. It takes the coefficients as input from the user.

2. It calculates the elements of the upper triangular matrix `U` and the lower triangular matrix `L` by performing forward and backward substitutions on the values step-by-step based on user input.

3. After decomposing into `L` and `U`, it solves the linear equation by performing forward substitution to get intermediate variables (`x`) and then backward substitution to solve for final variables (`y`), which is the output.

---
