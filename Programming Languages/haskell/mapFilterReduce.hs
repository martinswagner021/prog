mapeia x [] = []
mapeia x (cab:cauda) = (x cab):(mapeia x cauda)

filtra f [] = []
filtra f (cab:cauda)
 | (f cab) = cab:(filtra f cauda)
 | otherwise = filtra f cauda

reduce f acc [] = acc
reduce f acc (cab:cauda) = f cab (reduce f acc cauda)
