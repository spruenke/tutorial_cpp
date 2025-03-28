#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export()]]
arma::vec beta_est(const arma::mat X, const arma::vec y) {
  arma::mat xx = X.t() * X; // instead of X.t() arma::trans(X) also works
  arma::mat xy = X.t() * y;
  arma::vec beta_hat = arma::inv_sympd(xx) * xy;
  return beta_hat;
}