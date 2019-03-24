let rec calculator a =
  match a with
  |X -> 
  |INT b-> b
  |ADD (x,y) -> calculator(x) + calculator(y)
  |SUB (x,y) -> calculator(x) - calculator(y)
  |MUL (x,y) -> calculator(x) * calculator(y)
  |DIV (x,y) -> calculator(x) / calculator(y)
  |SIGMA (x,y,z) -> if (calculator x= calculator y) then (z y) else (z x) + SIGMA ((x+1), y, z);;