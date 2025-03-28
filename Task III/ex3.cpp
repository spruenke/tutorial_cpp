#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

arma::vec data_gen(const arma::mat X, const arma::vec beta) {
  arma::vec epsilon = arma::randn(X.n_rows);
  return X * beta + epsilon;
}

arma::vec beta_est(const arma::mat X, const arma::vec y) {
  arma::mat xx = X.t() * X; // instead of X.t() arma::trans(X) also works
  arma::mat xy = X.t() * y;
  arma::vec beta_hat = arma::inv_sympd(xx) * xy;
  return beta_hat;
}

// [[Rcpp::export()]]
arma::mat sim_reg(const arma::mat X, const arma::vec beta, const int n_sim = 10000) {
  arma::mat betas(X.n_cols, n_sim);
  for(int i = 0; i < n_sim; i++) {
    betas.col(i) = beta_est(X, data_gen(X, beta));
  }
  
  return betas;
}