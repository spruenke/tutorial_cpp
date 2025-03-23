#include<RcppArmadillo>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export()]]
arma::mat t_test_cpp(const arma::mat x, const int n1, const int n2) {
   arma::mat x1 = x.rows(0, n1 - 1), x2 = x.rows(n1, n1 + n2 - 1);
   arma::rowvec delta = arma::mean(x1, 0) - arma::mean(x2, 0);
   arma::rowvec ss1 = ((double)n1 - 1.0) * arma::var(x1, 0), ss2 = ((double)n2 - 1.0) * arma::var(x2, 0);
   arma::rowvec varp = (ss1 + ss2) / ((double)n1 + (double)n2 - 2.0);
   return arma::trans(delta / (arma::sqrt(varp * (1.0 / (double)n1 + 1.0 / (double)n2))));
}