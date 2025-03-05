#include<RcppArmadillo>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export()]]
arma::vec t_test_cpp(const arma::mat x, const int samples = 1, const int n_1 = 0, const double mu = 0){
   int nsim = x.n_cols; int n = x.n_rows;
   arma::vec stats(nsim);
   if(samples == 1){
      arma::vec sds = arma::stddev(x, dim = 0);
      arma::vec means = arma::mean(x, dim = 0);
      stats = std::sqrt(n) * (means - mu) % (1/sds);
   }else if(samples == 2){
      int n_2 = n - n_1;
      arma::mat x_1 = x.rows(1, n_1); arma::mat x_2 = x.rows((n_1 + 1), n);
      arma::vec means_1 = arma::mean(x_1, dim = 0); arma::vec means_2 = arma::mean(x_2, dim = 0);
      arma::vec vars_1 = arma::var(x_1, dim = 0); arma::vec vars_2 = arma::var(x_2, dim = 0);
      arma::vec var_pool = ((n_1 - 1) % vars_1 + (n_2 - 1) % vars_2) % (1 / (n_1 + n_2 - 2));
      arma::vec sd_pool = std::sqrt(var_pool);
      arma::vec frac = sd_pool % std::sqrt(1/n_1 + 1/n_2);
      arma::vec stats = (means_1 - means_2) % (1/frac);
   }
   return stats;
}