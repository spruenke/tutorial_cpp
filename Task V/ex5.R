Rcpp::sourceCpp("ex5.cpp")

# Generate data
nsim = 1e4
n_1 = 10; n_2 = 12
data_sim = matrix(rnorm((n_1 + n_2) * nsim), ncol = nsim)

# R-Version for t-tests:
t_test_r = function(x, samples = 1, n_1 = 0, mu = 0){
   n = nrow(x)
   if(samples == 1){
      colvars = n / (n-1) * (colMeans(x**2) - colMeans(x)**2)
      stats = sqrt(nrow(x)) * (colMeans(x) - mu) / sqrt(col_vars)
   } else if (samples == 2){
      n_2 = n - n_1
      var_1 = n_1 / (n_1 - 1) * (colMeans(x[1:n_1,]**2) - colMeans(x[1:n_1,])**2)
      var_2 = n_2 / (n_2 - 1) * (colMeans(x[(n_1 + 1):n,]**2) - colMeans(x[(n_1 + 1):n,])**2)
      sd_pool = sqrt( ((n_1 - 1) * var_1 + (n_2 - 1) * var_2) / (n_1 + n_2 - 2) )
      stats = (colMeans(x[1:n_1,] - colMeans(x[(n_1 + 1):n,] / (sd_pool * sqrt(1/n_1 + 1/n_2))
                                             }
   return(stats)
   }

# Run
t_results = t_test_r(data_sim, 2, n_1)
cpp_results = t_test_cpp(data_sim, 2, n_1)