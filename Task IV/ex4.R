data(iris)
Rcpp::sourceCpp("ex4.cpp")

# C++
tapply_cpp(iris$Sepal.Length, iris$Species)
# Check with R
tapply(iris$Sepal.Length, iris$Species, mean)