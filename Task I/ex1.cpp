#include <RcppArmadillo>
// [[Rcpp::depends(RcppArmadillo)]]

// a
//[[Rcpp::export()]]
arma::vec sum_cpp(const arma::vec X, const arma::vec Y){
   return X + Y;
}

// b
//[[Rcpp::export()]]
arma::mat inner_prod_cpp(const arma::vec X, const arma::vec Y){
   return X.t() * Y;
}

// c
//[[Rcpp::export()]]
arma::mat outer_prod_cpp(const arma::vec X, const arma::vec Y){
   return X * Y.t();
}

// d
//[[Rcpp::export()]]
double sqNorm(const arma::vec X, const arma::vec Y){
   arma::vec z = X - Y;
   arma::vec z_sq = arma::pow(z,2);
   double result = std::sqrt(arma::sum(z_sq));
   return result;
}

// e
//[[Rcpp::export()]]
double p_norm_cpp(const arma::vec X, const arma::vec Y, const double p=2.0){
   arma::vec z = X - Y;
   arma::vec z_pow = arma::pow(z, p);
   double result = std::pow(arma::sum(z_pow), (1.0/p));
   return result;
}

// f
//[[Rcpp::export()]]
arma::mat outer_prod2_cpp(const arma::mat A, const arma::mat B){
   return A * B.t();
}

// g
//[[Rcpp::export()]]
arma::mat had_prod_cpp(const arma::mat A, const arma::mat B){
   return A % B;
}

// h
//[[Rcpp::export()]]
bool compare_cpp(const arma::mat A, const arma::mat B){
   bool compare = all(arma::vectorise(A - B) > 0);
   return compare;
}


