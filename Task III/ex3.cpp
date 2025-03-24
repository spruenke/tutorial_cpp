#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

arma::mat data_gen(const arma::mat X, const arma::vec beta){
      arma::vec epsilon = arma::randn(X.n_rows); 
      arma::mat y = epsilon + X * beta + epsilon;
      return y;
}

// insert the beta_est function from before at this place

// [[Rcpp::export()]]
arma::mat sim_reg(const arma::mat X, const arma::vec beta, const int n_sim = 1e4){
      arma::mat betas(X.n_cols, n_sim);
      for(int i = 0; i < n_sim; i++){
         betas.col(i) = beta_est(X, data_gen(X, beta));
      }
      return betas;
}