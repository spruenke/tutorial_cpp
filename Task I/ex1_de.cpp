#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export()]]
double pNorm(const arma::vec x, const arma::vec y, double p = 2.0) {
  arma::vec z = arma::abs(x - y);
  arma::vec z_p = arma::pow(z, p);
  double result = std::pow(arma::sum(z_p), 1.0 / p); // here we need std::pow instead of arma::pow as the left-hand side expects a double
  return result;
}

