Rcpp::sourceCpp("ex1.cpp")
X = rnorm(5)
Y = rnorm(5, 3)
A = matrix(rexp(25), ncol = 5)
B = matrix(rexp(25, 0.5), ncol = 5)

# a
X + Y
sum_cpp(X,Y)

# b
t(X) %*% Y
inner_prod_cpp(X,Y)

# c
X%*%t(Y)
outer_prod_cpp(X,Y)

# d
sqrt(sum((X-Y)**2))
sqNorm(X,Y)

# e
p = 5
(sum(abs(X-Y)**p))**(1/p)
p_norm_cpp(X,Y)

# f
A%*%t(B)
outer_prod2_cpp(A,B)

# g
A * B
had_prod_cpp(A,B)

# h
all(A > B)
compare_cpp(A,B)