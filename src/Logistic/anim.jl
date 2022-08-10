using Plots

p = plot([], zeros(0), leg=false);
anim = Animation();

interval = (2.3, 4);
max_iter = 1000;

r = range(interval[1], interval[2], step=0.001)
X = zeros(length(r), max_iter);


last = 100;
x0 = randn();

for i in r 
    pts = [];
    x = 0.1;
    for j = 1:max_iter
        push!(pts, X);
        x = i * x * (1 - x);
    end
    global p = scatter!(p, i * ones(last), pts[max_iter - last: max_iter], label=nothing, ms=0.5, c=:black);
    frame(anim);
end
gif(anim, "Logistic.gif", fps = 25);
