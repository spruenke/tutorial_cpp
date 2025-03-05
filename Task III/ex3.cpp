#include <RcppArmadillo>
// [[Rcpp::depends(RcppArmadillo)]]

arma::mat data_gen(const arma::mat X, const arma::vec beta){
   int n_row = X.n_rows, n_col = X.n_cols;
   arma::mat epsilon = arma::randn(n_row, n_col);
   arma::mat y = epsilon.each_col() + X * beta;
   return y;
}

// Here, we do not export since we use this function within the same cpp file;
// If we do not plan to call this function in R there is no need to export it
arma::vec beta_est(const arma::mat X, const arma::vec y){
   arma::mat xx = X.t() * X;
   arma::mat xy = X.t() * y;
   arma::vec beta_hat = inv_sympd(xx) * xy; // inv(xx) should work, too, but since xx is symmetric inv_sympd might be more efficient
   return beta_hat;
}

// [[Rcpp::export()]]
arma::mat sim_reg(const arma::mat X, const arma::vec beta, const int seed = 1234, const int n_sim = 10000){
   arma::arma_rng::set_seed(seed);
   arma::mat betas(X.ncols, n_sim);
   arma::mat y = data_gen(X, beta);
   for(int i = 0; i < n_sim; i++){
      betas.col(i) = beta_est(X, y);
   }
   return betas;
}