#include<RcppArmadillo>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export()]]
arma::vec tapply_cpp(const arma::vec x, const arma::vec grp){
   arma::vec grps = arma::unique(grp);
   int d = grps.n_elem;
   arma::vec results(d);
   
   for(int i = 0; i < d; i++){
      double current_grp = grps(i);
      arma::uvec ind = arma::find(grp == current_grp);
      results(i) = arma::mean(x.elem(ind));
   }
   return results;
}