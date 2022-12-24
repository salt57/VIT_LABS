# sourish gupta - 20BCE0453
#init <- par(no.readonly = TRUE)
#par(mfrow=c(2,1))
par(mar = c(5, 4, 8, 5), xpd = TRUE)
plot()
dates <- c("2020-05-31", "2020-06-01", "2020-06-02", "2020-06-03", "2020-06-04", "2020-06-05", "2020-06-06", "2020-06-07", "2020-06-08", "2020-06-09", "2020-06-10", "2020-06-11", "2020-06-12", "2020-06-13", "2020-06-14")
attrs <- c("deaths","active cases", "recoveries")
data <- matrix(c(5164, 86984, 182143-86984, 5394, 91819, 190535-91819, 5598, 95527, 198706-95527, 5815, 100303, 207615-100303, 6075, 104107, 216919-104107, 6348, 109462, 226770-109462, 6642, 114073, 236657-114073, 6929, 119293, 246628-119293, 7200, 124430, 256611-124430, 7471, 129314, 266598-129314, 7745, 135206, 276583-135206, 8102, 141029, 286579-141029, 8498, 147195, 297535-147195, 8884, 154330, 308993-154330, 9195, 162379, 320922-162379), nrow = 3, ncol = 15, byrow = FALSE)
cols <- c("darkred", "lightblue", "darkorange")
barplot(data, ylab = "Date", xlab = "Number Of Cases Sourish Gupta - 20BCE0453", las = 2, main = "COVID-19 cases in India sourish gupta - 20BCE0453", horiz = TRUE, names.arg = dates, col = cols, cex.names = 0.5, axes = FALSE)
legend("top", legend = attrs, fill = cols, horiz = TRUE)

#par(init)

