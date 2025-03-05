# Create some example data:
set.seed(1234)
x = matrix(c(rep(1, 30), sample(10:60, size = 30, replace = T), rnorm(30,70,10), rnorm(30,170,15), rexp(30, 1/3)), ncol = 5) # this is the X-matrix data
y =  x %*% c(0.15, 0.05, 0.05, 0.9, 0.1) + rnorm(30) # y = X beta + epsilon

# Import Cpp
Rcpp::sourceCpp("ex2.cpp")

# R vs. Cpp
beta_r = solve(crossprod(x)) %*% crossprod(x, y)
beta_cpp = beta_est(x, y)