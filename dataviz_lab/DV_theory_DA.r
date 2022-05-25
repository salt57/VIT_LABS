init <- par(no.readonly = TRUE)
par(mfcol=c(1,2))

barplot(VADeaths, col = rainbow(5), main = "Virginia Deaths based on age and gender", xlab = "Categories", ylab = "Deaths")
legend("topright", legend = attr(VADeaths, "dimnames")[[1]], title = "AGE", fill = rainbow(5))
barplot(colMeans(VADeaths), main = "Deaths in Virginia based on rural or urban", xlab = "Categories", ylab = "Mean Deaths", col = rainbow(4))

par(init)
