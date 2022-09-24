using DelimitedFiles

function iter(z,c)
    n = 0
    while abs(z) < 4
        z = z^2+c ;
        n+=1;
    end
    return n
end

coord(x,y,w,h) = complex((x-w/2)/(h/2), (y-h/2)/(h/2))

palette(n) = string(min(3n + 55, 255)," ", min(1n, 255)," ", min(2n, 255));

julia(c) = (w, h, x, y) -> palette(iter(coord(x,y,w,h), c))

function writePng(f; width=4800,height=3200, file="julia.png")
    open(file, "w") do out
        write(out, string("P3\n", width, " ", height, "\n255\n"))
        writedlm(out, [f(width,height,i,j) for j = 1:height, i = 1:width], '\n')
    end
end

writePng(julia(-0.7269 + 0.1889im))
