#include <RcppArmadillo>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export()]]
arma::vec beta_est(const arma::mat X, const arma::vec y){
   arma::mat xx = X.t() * X;
   arma::mat xy = X.t() * y;
   arma::vec beta_hat = inv_sympd(xx) * xy; // inv(xx) should work, too, but since xx is symmetric inv_sympd might be more efficient
   return beta_hat;
}