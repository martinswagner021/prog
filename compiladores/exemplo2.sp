const TAM = 10;
type vetor = array [15] of integer;
type aluno = record
	nota1 : real;
	nota2 : real
end; 
var A, B, C, D : integer;
var E : vetor;
var F : aluno;
var G : boolean;
function fatorial(a:integer) : integer
var i : integer;
begin
	i := 1;
	result:=1;
	while i < a do
	begin
		result:=result*i;
		i:=i+1
	end
end
function exp(a: real; b: real) : real
var i : integer;
begin
	i := 1;
	result := a;
	if b == 0 then
		result := 1
	else
	while i < b do
	begin
		result := a * a;
		i := i + 1
	end
end
function lerDados : aluno
begin
	write "digite as notas do aluno";
	read result.nota1;
	read result.nota2
end
function maior(a : vetor) : integer
var i : integer;
begin
	i := 0;
	result := a[0];
	while i < 15 do
		if a[i] > result then
			result := a[i]
end
function menor(a : vetor) : integer
var i : integer;
begin
	i := 0;
	result := a[0];
	while i < 15 do
		if a[i] < result then
			result := a[i]
end
function media(a : vetor) : integer
var m : integer;
begin
	m := maior(a) + menor(a);
	result := m / 2
end
begin
	A := TAM + 20;
	B := fatorial(A);
	C := exp(A,B);
	D := media(E);
	F := lerDados()
end