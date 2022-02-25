# Sourish Gupta - 20BCE0453
# Q1 a)
seq(from = 1, to = 5, by = 1)

# Sourish Gupta - 20BCE0453
# Q1 b)
mw=c("m", "w")
rep(mw, 3)

# Sourish Gupta - 20BCE0453
# Q1 c)
rep(1:4, 3)

# Sourish Gupta - 20BCE0453
# Q1 d)
rep(4:1, each=3)

# Sourish Gupta - 20BCE0453
# Q1 e)
rep(1:5, 1:5)

# Sourish Gupta - 20BCE0453
# Q1 f)
rep(seq(from=1, to=11, by=2), each=2)

# Sourish Gupta - 20BCE0453
# Q2 a)
sqrt(16)
16^0.5
43^2

# Sourish Gupta - 20BCE0453
# Q2 b)
log10(1000)
log(1000)
exp(log(1000))

# Sourish Gupta - 20BCE0453
# Q2 c)
log2(64)

# Sourish Gupta - 20BCE0453
# Q2 d)
?log

# Sourish Gupta - 20BCE0453
# Q2 e)
pi
round(pi)
round(pi, digits=4)
trunc(pi)

# Sourish Gupta - 20BCE0453
# Q2 f)
round(sin(pi))
round(cos(pi))
round(sin(pi/2))
round(cos(pi/2))



# Sourish Gupta - 20BCE0453
# Q3 a) 
2 + 3

# Sourish Gupta - 20BCE0453
# Q3 b) 
x = 2 + 3
x

# Sourish Gupta - 20BCE0453
# Q3 c)
y = c(2, 3)
y
sum(y)

# Sourish Gupta - 20BCE0453
# Q3 d)
v = c(5: 40)
v

# Sourish Gupta - 20BCE0453
# Q3 e)
length(v)

# Sourish Gupta - 20BCE0453
# Q3 f)
v[10]

# Sourish Gupta - 20BCE0453
# Q3 g)
v[-10]

# Sourish Gupta - 20BCE0453
# Q3 h)
z = c(3:10)
z + 5

# Sourish Gupta - 20BCE0453
# Q3 i)
2 * z

# Sourish Gupta - 20BCE0453
# Q3 j)
w = c(6.9, 2.7, 0, -11.3, 5.5, -7.8, 4.1, 3.2)
w + z

# Sourish Gupta - 20BCE0453
# Q3 k)
w * z

# Sourish Gupta - 20BCE0453
# Q3 l)
w / z

# Sourish Gupta - 20BCE0453
# Q3 m)
w^2

# Sourish Gupta - 20BCE0453
# Q4 a)
4+6

# Sourish Gupta - 20BCE0453
# Q4 b)
x<-6 
y<-4 
z<-x+y 
z 

# Sourish Gupta - 20BCE0453
# Q4 c)
ls()

# Sourish Gupta - 20BCE0453
# Q4 d)
sqrt(16)

# Sourish Gupta - 20BCE0453
# Q4 e)
rm(x,y)
ls()

# Sourish Gupta - 20BCE0453
# Q4 f)
z<-c(5,9,1,0)
z


# Sourish Gupta - 20BCE0453
# Q5 i)
x<-c(5,9) 
y<-c(1,0) 
z<-c(x,y)

# Sourish Gupta - 20BCE0453
# Q5
x<-1:10
seq(1,9,by=2)
seq(8,20,length=6)
x<-seq(1,10)
rep(0,100)
rep(1:3,6)
rep(1:3,c(6,6,6))
rep(1:3,rep(6,3))

# Sourish Gupta - 20BCE0453
# Q6
x<-c(6,8,9) 
y<-c(1,2,4) 
x+y
x*y 
x<-c(6,8,9)
x+2

# Sourish Gupta - 20BCE0453
# Q7
x<-c(4,2,6) 
y<-c(1,0,-1) 
length(x)
sum(x)
sum(x^2)
x+y
x*y
x-2
x^2

# Sourish Gupta - 20BCE0453
# Q8
7:11
seq(2,9)
seq(4,10,by=2)
seq(3,30,length=10)
seq(6,-4,by=-2)

# Sourish Gupta - 20BCE0453
# Q9
rep(2,4) 
rep(c(1,2),4) 
rep(c(1,2),c(4,4)) 
rep(1:4,4) 
rep(1:4,rep(3,4))

# Sourish Gupta - 20BCE0453
# Q10
x<- c(7.5,8.2,3.1,5.6,8.2,9.3,6.5,7.0,9.3,1.2,14.5,6.2) 
mean(x) 
var(x) 
summary(x) 
x[1:6] 
x[7:12] 
summary(x[1:6])

# Sourish Gupta - 20BCE0453
# Q11
x<- c(5,9,2,3,4,6,7,0,8,12,2,9)
x[2]
x[2:4]
x[c(2,3,6)]
x[c(1:5,10:12)]
x[-(10:12)]

# Matrices:
# Sourish Gupta - 20BCE0453
# Q1
x<-c(5,7,9) 
y<-c(6,3,4) 
z<- cbind(x,y) 
z 

# Sourish Gupta - 20BCE0453
# Q2
dim(z)

# Sourish Gupta - 20BCE0453
# Q3
rbind(z,z)

# Sourish Gupta - 20BCE0453
# Q4
z<-matrix(c(5,7,9,6,3,4),nrow=3)
z

# Sourish Gupta - 20BCE0453
# Q5
z<-matrix(c(5,7,9,6,3,4),ncol=3)
z

# Sourish Gupta - 20BCE0453
# Q6
z<-matrix(c(5,7,9,6,3,4),nr=3,byrow=T)
z

# Sourish Gupta - 20BCE0453
# Q7
z<-matrix(c(5,7,9,6,3,4),nr=3,byrow=F) 
z

# Sourish Gupta - 20BCE0453
# Q8
y<-matrix(c(1,3,0,9,5,-1),nrow=3,byrow=T)
y

# Sourish Gupta - 20BCE0453
# Q9
y+z

# Sourish Gupta - 20BCE0453
# Q10
y*z

# Sourish Gupta - 20BCE0453
# Q11
x<-matrix(c(3,4,-2,6),nrow=2,byrow=T)
x

# Sourish Gupta - 20BCE0453
# Q12
y%*%x

# Sourish Gupta - 20BCE0453
# Q13
t(z)

# Sourish Gupta - 20BCE0453
# Q14
solve(x)

# Sourish Gupta - 20BCE0453
# Q15 a)
z[1,1]

# Sourish Gupta - 20BCE0453
# Q15 b)
z[c(2,3),2]

# Sourish Gupta - 20BCE0453
# Q15 c)
z[,2]

# Sourish Gupta - 20BCE0453
# Q15 d)
z[1:2,]

# Sourish Gupta - 20BCE0453
# Q16
x<-matrix(c(3,2,-1,1), nrow=2, byrow=T)
x
y<-matrix(c(1,4,0,0,1,-1), nrow=2, byrow=T)
y
2*x
x*x
x%*%x