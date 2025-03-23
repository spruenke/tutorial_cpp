#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export()]]
arma::vec beta_est(const arma::mat X, const arma::vec y){
   arma::mat xx = X.t() * X;
   arma::mat xy = X.t() * y;
   arma::vec beta_hat = inv_sympd(xx) * xy; // inv(xx) should work, too
   return beta_hat;
}