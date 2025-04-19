x = 10
function f(x)
    x = x+1
    y=x
    function g(x,y)
        print(x.." ".. y)
    end
    return g(x,y)
end

f(x)