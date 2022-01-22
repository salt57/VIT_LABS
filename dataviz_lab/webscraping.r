#WEBSCRAPPING
#Step 1: Install the package rvest
install.packages('rvest')
################################################################################################

# Step 2: Loading the rvest package
library('rvest')
################################################################################################

# Step 3: Specifying the url for desired website to be scraped
url <- 'https://www.imdb.com/chart/moviemeter/?ref_=nv_mv_mpm'
################################################################################################

#Step 4: Reading the HTML code from the website
webpage <- read_html(url)
################################################################################################

#Step 5: Using CSS selectors to scrape the runtime of a movie
rating_data <- html_nodes(webpage,'strong')
################################################################################################

#Step 6: Converting the runtime html data to text and print
rating_data <- html_text(rating_data)
rating_data
################################################################################################

#Step 7: Convert the runtime text data into numeric and print
rating_data<-as.numeric(rating_data)
rating_data

var(rating_data)
mean(rating_data)
################################################################################################

#SCATTERPLOT

mtcars
attach(mtcars)

plot(wt,mpg,main="Scatterplot example",xlab="car weight",ylab="Miles per Gallon",axes=TRUE)

plot(wt,mpg,main="Scatterplot example",xlab="car weight",ylab="Miles per Gallon",axes=FALSE)

plot(wt,mpg,main="Scatterplot example",xlab="car weight",ylab="Miles per Gallon",xlim=c(2.5,5), ylim=c(15,30),axes=TRUE)

pairs(~wt+mpg+disp+cyl,data=mtcars,main="Scatterplot Matrix")
install.packages("scatterplot3d")
library(scatterplot3d)
scatterplot3d(wt,disp,mpg,main="3d Scatterplot")

scatterplot3d(wt,disp,mpg,main="3d Scatterplot",type="h")

scatterplot3d(wt,disp,mpg,main="3d Scatterplot",type="h",highlight.3d = TRUE)
dev.off()
install.packages("rgl")
library(rgl)
plot3d(wt,disp,mpg,col="red",size=3)
