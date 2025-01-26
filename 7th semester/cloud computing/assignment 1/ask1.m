U = rand(1,1000)

histogram(U)
histogram(U,'Normalization','probability')
cdfplot(U)

U10 = 10 + (15-10) * U
histogram(U10)
histogram(U10,'Normalization','probability')
cdfplot(U10)

lambda1 = 1
N1 = 1000
afixeis1 = exprnd(1/lambda1, 1, N1)

lambda = 2
N = 1000
afixeis = exprnd(1/lambda, 1, N)

figure
subplot(2, 1, 1)
histogram(afixeis1)


subplot(2, 1, 2)
histogram(afixeis)
histogram(afixeis,'Normalization','probability')
cdfplot(afixeis)

figure
histogram(afixeis1)
hold on
histogram(afixeis2)
hold off

figure
subplot(2,1,1)
cdfplot(afixeis1)