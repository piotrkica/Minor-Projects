% Piotr Kica 
% Równanie transportu ciepła 

% -k(x) * u''(x) = 0
% u(2) = 0
% u'(0) + u(0) = 20
% k(x) = 1 dla x [0,1] oraz k(x) = 2 dla x (1,2]
% Omega = [0,2]

global N;
global range;
global h;

N = 50; % Nmax = 70
range = 2;
h = range/N;

% Funkcje bazowe i ich pochodne dla danego przedziału
e = @(k) (@(x) e_y(x,k));
e_der = @(k) (@(x) e_der_y(x,k));

% Wypełnianie macierzy B
B_matrix = sparse(N,N);
for k = 1:N
    B_matrix(k,k) = b_u_v(e(k),e(k), e_der(k),e_der(k)); %#ok<*SPRIX>
    if k < N
        B_matrix(k,k+1) = b_u_v(e(k),e(k+1), e_der(k),e_der(k+1));
        B_matrix(k+1,k) = b_u_v(e(k+1),e(k), e_der(k+1),e_der(k));
    end
end


% Wypełnianie macierzy L
L_matrix = zeros(N:1);
for i=1:N
    v = e(i);
    L_matrix(i) = -20*v(0);
end

% Wyliczenie macierzy U
U_matrix = L_matrix/B_matrix;

% Wypisane macierzy w konsoli
B_matrix %#ok<*NOPTS>
L_matrix
U_matrix

% Funkcja będąca szukaną krzywą
u_fun = @(x) u_fun_y(x, U_matrix);

% Rysowanie wykresu
fplot(u_fun,[0 2]);


% Funkcja licząca wartość funkcji bazowej w punkcie dla danego przedziału
function y = e_y(x,k)
    global h
    if ( h*(k-1) <= x & x < h*k) %#ok<*AND2>
        y = -x/h+k;
    elseif (h*(k-2) <= x & x < h*(k-1))
        y = x/h-k+2;
    else
        y = 0;
    end
end 

% Funkcja licząca pochodną funkcji bazowej w punkcie dla danego przedziału
function y = e_der_y(x,k)
    global h
    if ((k-2)*h <= x & x < (k-1)*h)
        y = 1/h;
    elseif ((k-1)*h <= x & x < k*h)
        y = -1/h;
    else
        y = 0;
    end
end

% Funkcja k(x) 
function y = k_fun(x)
    if (x >= 0 & x <= 1)
        y = 1;
    elseif (x > 1 & x <= 2)
        y = 2;
    else
        y = 0;
    end
end

% Funkcja licząca wartość elementu macierzy b dla danych funkcji bazowych
function result = b_u_v(u, v, u_der, v_der)
    result = integral(@(x)(k_fun(x) * u_der(x) * v_der(x)), 0, 2, 'ArrayValued', true) - u(0) * v(0);
end

% Funkcja licząca wartość krzywej w punkcie
function y = u_fun_y(x, U_matrix)
    global N
    y = 0;
    for i=1:N
        y = y + e_y(x,i) * U_matrix(i);
    end
end