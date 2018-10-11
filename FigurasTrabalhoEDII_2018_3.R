

N <- c(1000, 5000, 10000, 50000, 100000, 500000)

timeQuickDeputados <- c(0.0056664, 0.0324112, 0.081429, 0.991236, 3.54128, 81.0648)
timeQuickInteiros <- c(0.0001218, 0.000612, 0.0012832, 0.0070532, 0.0132982, 0.0649264)

compQuickDeputados <- c(11261, 79790, 197640, 2551915, 8899232, 197527310)
compQuickInteiros <- c(11959, 74228, 154858, 884967, 1860703, 1042638)

copiasQuickDeputados <- c(6652, 52054, 147580, 2289060, 8360755, 194814933)
copiasQuickInteiros <- c(2464, 16120, 36380, 234282, 516125, 3143521)

plot(x = N, y = timeQuickDeputados, pch = 8, col = "red", ylab = "Tempo de CPU (segundos)", log = "y", ylim = c(0.0001, 100))
points(x= N, y = timeQuickInteiros, pch = 12, col = "blue")
legend(x = 50000, y = 40,
       legend = c("Inteiros", "Deputados"),
       col = c("blue", "red"), pch = c(12, 8), lwd = 1)


plot(x = N, y = compQuickDeputados, pch = 8, col = "red", ylab = "Número de Comparações", log = "y")
points(x= N, y = compQuickInteiros, pch = 12, col = "blue")
legend(x = 50000, y = 1e+08,
       legend = c("Inteiros", "Deputados"),
       col = c("blue", "red"), pch = c(12, 8), lwd = 1)

plot(x = N, y = copiasQuickDeputados, pch = 8, col = "red", ylab = "Número de Cópias", log = "y")
points(x= N, y = copiasQuickInteiros, pch = 12, col = "blue")
legend(x = 50000, y = 1e+08,
       legend = c("Inteiros", "Deputados"),
       col = c("blue", "red"), pch = c(12, 8), lwd = 1)





