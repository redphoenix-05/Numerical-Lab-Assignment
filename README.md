<h1 align="center">Numerical Methods Lab Assignment</h1>

# Table of Contents
1. [Features](#features)
2. [Requirements](#requirements)
3. [Algorithm Explanation](#algorithm-explanation)
5. [Contributions](#contributions)

---

# Features

- **Input Flexibility**: Accepts user input for any number of linear equations.
- **Pivoting**: Uses partial pivoting for numerical stability.
- **Solution Display**: Prints each variable's solution if a unique solution exists.
- **Error Detection**: Handles cases where no solution exists.

---

# Requirements

- **C++ Compiler**: GCC, Clang, or any C++11 compatible compiler.
- **Console Input**: Basic command-line interface for matrix input.

---

# Algorithm Explanation

## Linear Equations
---
## Jacobi Iterative Method

The Jacobi iterative method can solve any number of systems of linear equations.

1. This program first checks if the augmented matrix provided is diagonally dominant or not. The `diagonal()` function performs this check. If the matrix is diagonally dominant or convertible to a diagonally dominant form, it keeps or converts the matrix to that form and returns `true`. If the matrix is not diagonally dominant or convertible, it returns `false`, and the program exits since the Jacobi method requires the augmented matrix to be in this form.

2. If `true`,  the program proceeds to solve the equations. The tolerance and the maximum number of iterations are set in the program.

3. It takes the set of initial variable values in a vector (`x0`, `y0`, `z0`, ...) and, for each equation (or row of the matrix), calculates the next set of variable values (`x1`, `y1`, `z1`, ...) using the `nextVal()` function and stores them in another vector.

4. Now, it checks if the difference between each of the new set of values and old values is less than the tolerance. If not, it loops repeatedly until the difference is less than the tolerance or it reaches the maximum number of iterations.

---

## Gauss-Seidel Iterative Method

The Gauss-Seidel iterative method can solve any number of systems of linear equations. It generally requires fewer iterations to converge than the Jacobi iterative method.

1. The first two steps are the same as the Jacobi iterative method.

2. It takes the set of initial variable values in a vector (`x0`, `y0`, `z0`, ...) and, for each equation (or row of the matrix), calculates the next set of variable values (`x1`, `y1`, `z1`, ...) using the `nextVal()` function and updates them immediately in the previous vector. Therefore, in each iteration, the updated values of variables are used.

3. Now, it checks if the difference between each of the new set of values and old values is less than the tolerance. If not, it loops repeatedly until the difference is less than the tolerance or it reaches the maximum number of iterations.

---

## LU Factorization Method

This method solves a system of linear equations for 2, 3, and 4 variables. Since LU factorization operates on constant time, the equations are hardcoded without loops.

1. First, the user selects the number of equations to solve, i.e., 2, 3, or 4. The program then flows to the corresponding block where equations are hardcoded. It takes the coefficients as input from the user.

2. It calculates the elements of the upper triangular matrix `U` and the lower triangular matrix `L` by performing forward and backward substitutions on the values step-by-step based on user input.

3. After decomposing into `L` and `U`, it solves the linear equation by performing forward substitution to get intermediate variables (`x`) and then backward substitution to solve for final variables (`y`), which is the output.

---

## Gauss Elimination Method

The Gauss Elimination method is a technique for solving systems of linear equations by transforming the system's augmented matrix into an upper triangular form, then performing back substitution to find solutions. Here's a step-by-step explanation of its working principle:

1. **Input Matrix Creation :**
   - The augmented matrix is constructed from the system of linear equations.
   - This matrix includes coefficients of the variables and the constants from each equation.

2. **Partial Pivoting :**
   - The algorithm searches within each column (starting from the left) for the row with the largest absolute value in that column below or at the current pivot.
   - If a larger value is found, the algorithm swaps the rows, placing the row with the largest value at the current pivot position. This step ensures numerical stability.

3. **Forward Elimination :**
   - Starting from the first row, the algorithm eliminates the variable in the current column for all rows below it.
   - A "factor" is calculated as the ratio of the target row's element to the pivot row's element.
   - This factor is then used to update each element in the target row, reducing the coefficients below the pivot to zero and transforming the matrix to upper triangular form.

4. **Row Normalization :**
   - Once the matrix is in upper triangular form, each row is normalized by dividing by the pivot value (the diagonal element).
   - This transforms each pivot in the diagonal to 1, simplifying further calculations.

5. **Back Substitution :**
   - The algorithm starts from the last row and moves upwards, calculating the value of each variable by isolating it using known values from rows below.
   - Each variable is substituted back into the equations to simplify the remaining equations and calculate the preceding variables.

6. **Result Extraction :**
   - After back substitution, the final values of the variables are extracted from the matrix.
   - Each variable's value corresponds to the result of a specific equation and is displayed as the solution to the system.

This process results in the solution for the system of equations, provided the matrix does not contain rows that make the system inconsistent (i.e., rows that suggest no solution exists).

---

## Gauss-Jordan Elimination Method

The Gauss-Jordan Elimination method is an extension of the Gaussian elimination method. It further simplifies the system of linear equations by transforming the matrix into a reduced row echelon form. This enables solving the system directly and uniquely. Here is a step-by-step explanation of the working principle:

1. **Input Matrix Creation :**
   - The augmented matrix is constructed from the system of linear equations.
   - This matrix includes coefficients of the variables and the constants from each equation.

2. **Partial Pivoting :**
   - Starting from the first row, the algorithm identifies the row with the largest absolute value in each column below or at the current pivot.
   - If necessary, rows are swapped to bring the largest value to the top, stabilizing the computations.

3. **Forward Elimination :**
   - Using each pivot row, the algorithm eliminates the variable in the current column for all rows below.
   - A "factor" is computed based on the target row’s element relative to the pivot row’s element.
   - The matrix is updated so that all elements below each pivot are zero, resulting in an upper triangular form.

4. **Backward Elimination (Gauss-Jordan Step) :**
   - Starting from the bottom row, the algorithm eliminates each variable in columns above each pivot, ensuring each pivot is the only non-zero entry in its column.
   - A scaling factor is used to transform the matrix elements, achieving reduced row echelon form.

5. **Normalization of Rows :**
   - Each row is normalized so that the pivot value is 1.
   - This final transformation results in each row containing a single variable with a value, simplifying the solution extraction.

6. **Result Extraction :**
   - After transforming the matrix to reduced row echelon form, the values of each variable are directly extracted.
   - Each variable's value corresponds to the result of a specific equation, and these values are displayed as the solution to the system.

This method yields the solution to the system of equations (if a unique solution exists) directly after row reduction.

---

## Non linear equations
---
## Secant Method

This method finds all real roots of a polynomial function by combining the Secant Method (an iterative root-finding algorithm) with synthetic division to simplify the polynomial progressively. Below is a step-by-step explanation of the working principle:

1. **Polynomial Input :**
   - The degree of the polynomial and its coefficients are provided as input by the user.
   - The coefficients are entered starting with the highest degree term.

2. **Secant Method for Root-Finding :**
   - The Secant Method is an iterative numerical method used to find approximate roots of the polynomial.
   - Two initial guesses for the root are chosen.
   - In each iteration, the function evaluates the polynomial at the two points to calculate a new approximation of the root.
   - The process is repeated until the function value at the new approximation is close enough to zero, within a specified tolerance level.

3. **Root Extraction and Display :**
   - When an approximation of the root is found within the tolerance, it is displayed as one of the polynomial's roots.
   - This root is then used in the next step to reduce the polynomial's degree.

4. **Synthetic Division :**
   - Synthetic division uses the discovered root to divide the polynomial, creating a new polynomial of one degree lower.
   - This simplified polynomial is now used as input for the next round of root-finding with the Secant Method.
   - This step repeats until all roots of the polynomial are found.

5. **Termination :**
   - The process continues until the polynomial is reduced to a constant, meaning all roots have been identified.
   - The method terminates after all real roots are extracted and displayed.

This approach provides an efficient way to find multiple roots of a polynomial using the Secant Method iteratively combined with synthetic division to simplify the polynomial after each root is found.

---

## Newton-Raphson Method

This method finds all real roots of a polynomial function by combining the Newton-Raphson method (an iterative root-finding algorithm) with synthetic division to progressively simplify the polynomial. Below is a step-by-step explanation of the working principle:

1. **Polynomial Input :**
   - The degree of the polynomial and its coefficients are provided as input by the user.
   - The coefficients are entered starting with the highest degree term.

2. **Derivative Calculation :**
   - The polynomial's derivative is calculated to enable the Newton-Raphson method, which requires both the polynomial and its derivative for each iteration.
   - This derivative provides the slope at any given point on the polynomial.

3. **Newton-Raphson Method for Root-Finding :**
   - The Newton-Raphson method uses an initial guess and iteratively refines it to approximate the root.
   - In each iteration, the method calculates the function value and its derivative at the current point.
   - A new approximation for the root is computed by moving towards the point where the polynomial value is zero.
   - This process continues until the function value at the new approximation is close enough to zero (within a specified tolerance).

4. **Root Extraction and Display :**
   - When an approximate root is found within the tolerance, it is displayed as one of the polynomial's roots.
   - This root is then used in the next step to reduce the polynomial’s degree.

5. **Synthetic Division :**
   - The discovered root is used in synthetic division to divide the polynomial, creating a new polynomial of one degree lower.
   - This simplified polynomial is used as input for the next round of root-finding with the Newton-Raphson method.
   - The process repeats, using each successive root to reduce the polynomial further.

6. **Termination :**
   - The method continues until the polynomial is reduced to a constant, meaning all roots have been found.
   - The process stops after all real roots have been extracted and displayed.

This approach combines the rapid convergence of the Newton-Raphson method with synthetic division, making it efficient for finding multiple roots of a polynomial by iteratively simplifying the polynomial after each root is identified.

---

## False Position Method

The False Position method can solve any system of linear equations.

1. The `fn()` function calculates the value of the polynomial for a given value of `x` and a vector of coefficients.

2. The `false_Position()` function applies the False Position method to find a root in the interval `[a, b]` with a specified tolerance. It first checks if `fn(a, coefficient) * fn(b, coefficient) >= 0`. If this condition holds, there may be no root within `[a, b]`, so the function returns immediately. In the main loop, it calculates an approximate root `c`. The loop iterates until the function value `fn(c, coefficient)` is within the specified tolerance, or the interval width `[b - a]` becomes smaller than the tolerance. If a root is found, it’s added to the roots vector, and the function returns.

3. The `All_roots()` function scans the interval `[start, ending]` in increments of `step`. For each subinterval `[i, i + step]`, it checks if the function changes sign. If so, there may be a root in that interval, so it calls `false_Position()`.

4. The  `false_position()` gets input from the user, including the polynomial degree and coefficients. It calculates `xmax` to determine a search interval from `-xmax` to `xmax`, providing a reasonable range for root-finding based on the polynomial’s characteristics. The program then calls `All_roots` to find and print all roots within this range.

---

## Bisection Method

The Bisection method can solve any system of linear equations.

1. The `f` function evaluates the polynomial at a given value of `x` using a vector of coefficients.

2. The `Bisection()` function is used to find a root within an interval `[a, b]` using the specified tolerance. First, it checks if `f(a) * f(b) >= 0`, meaning there’s no guarantee of a root within the interval. If so, it returns without further calculations. It initializes an iteration counter and continues refining the interval until the width is less than the tolerance. In each iteration, it calculates the midpoint `c` of the interval. If `f(c) == 0.0`, `c` is an exact root, so it adds `c` to the roots vector and returns. Otherwise, it checks whether the sign change occurs in the interval `[a, c]` or `[c, b]` and updates the interval boundaries accordingly.

3. The `all_roots()` function iterates over a range (`start` to `ending`), incrementing by `step` to check each subinterval `[i, i + step]`. If the function changes sign within an interval, it calls `Bisection()` with that interval and stores the result in the roots vector. Once all roots within the specified range are found, it prints each root.

4. The `bisection()` function calculates `xmax` to set the search interval to `[-xmax, xmax]`, providing a reasonable range for root-finding based on the polynomial’s behavior. It then calls `all_roots` with a step size of `0.01` and a tolerance of `1e-6` to find and print all roots within the range.

---

## Differential Equations
---
## Runge-Kutta (RK) Method

The Runge-Kutta method is an effective technique to solve up to five ordinary differential equations.

1. This program first sets up five functions for solving equations. A switch-case structure exists to choose which function to execute.

2. The `fn()` function takes the current values of `x` and `y` and a parameter `num` to select the equation to be executed.

3. The `runge_Kutta()` function uses the fourth-order Runge-Kutta method to compute and print the values of `x` and `y` over a specified range. `x` and `y` are initialized with the initial values `x0` and `y0`. The step size `h` and the total interval `(interval_2 - x0)` are used to compute the number of steps. For each step, four intermediate slopes, `k1`, `k2`, `k3`, and `k4`, are calculated. These slopes are used to update `y` by a weighted average. `x` is incremented by the step size `h` at each iteration.

4. The `r_k()` function gets input from the user to select one of the five predefined equations. The `runge_Kutta()` function is called with five parameters to compute and display the solution for each step.

---

## Matrix Inversion

This program finds the inverse of any n x n singular matrix using the Jordan elimination method and row echelon form.

1. The program first takes input `n` and creates an n x 2n matrix using a vector. The first `n` columns are initialized with the user's given matrix, and the next `n` columns are initialized with an identity matrix.

2. It checks if any row has `0` as a pivot element. If so, it swaps with another row. If no swapping is possible and the pivot element is still zero, the matrix is singular, and the inverse is not possible. The program exits.

3. It transforms the n x n lower triangular matrix to 0 while performing operations on the entire n x 2n matrix. Then it passes the whole matrix to the `jordanEli()` function to perform the same operations on the upper triangular matrix.

4. Now, the matrix from the nth column to 2n-th column represents the inverse matrix, which is printed.

---

# Contributions

#### 1. Md. Sorup Rohan - 2107018 - https://github.com/soruprohan
#### 2. Ariyan Aftab Spandan - 2107045 - https://github.com/redphoenix-05
#### 3. Md. Sabith - 2107091 - https://github.com/sabithbinfarid
