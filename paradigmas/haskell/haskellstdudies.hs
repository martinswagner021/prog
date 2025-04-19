rotations (cab:cauda) n
 | n /= length cab:cauda = cauda ++ [cab] : rotations (cauda ++ [cab]) (n+1)
