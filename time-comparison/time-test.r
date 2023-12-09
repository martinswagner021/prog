N <- 100000
x <- (1:N)

start = Sys.time()

for (i in 1:N){
  max = 1
  for (j in i:N){
    if (x[j] > x[max]) max = j
  }
  aux = x[i]
  x[i] = x[max]
  x[max] = aux
}

end = Sys.time()
(end-start)*60

print(paste0('time taken: ',end-start))
  