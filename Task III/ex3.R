# Create some example data:
set.seed(1234)
x = matrix(c(rep(1, 30), sample(10:60, size = 30, replace = T), rnorm(30,70,10), rnorm(30,170,15), rexp(30, 1/3)), ncol = 5) # this is the X-matrix data
beta = c(0.15, 0.05, 0.05, 0.9, 0.1)

# Import Cpp
Rcpp::sourceCpp("ex3.cpp")

# R vs. Cpp
sim_beta_r = sapply(1:10000, function(sim) solve(crossprod(x)) %*% crossprod(x, x %*% beta + rnorm(nrow(x))))
sim_beta_cpp = sim_reg(x, beta)