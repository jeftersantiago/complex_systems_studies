using Random, Plots
interval = (2.3, 4);
max_iter = 1000;

r = range(interval[1], interval[2], step=0.001)
X = zeros(length(r), max_iter);
x0 = randn();
for i = 1:length(r)
    X[i, 1] = x0;
    for j = 1:max_iter - 1
        X[i, j+1] = r[i] * X[i, j] * (1 - X[i, j]);
        println("X_n+1 = ", X[i, j+1]);
    end
end

# X[:, end-100:end] only use's the last values ploted
# The values for r between 0 and 1 aren't important to the plot.
plot(r, X[:, end-100:end],
    seriestype = :scatter,
    markercolor = :green,
    background_color = :black,
    markerstrokecolor=:match,
    markersize = 0.8,
    markeralpha = 0.3,
    markerstrokewidth = 0,
    legend = false,
    grid = false,
    );
savefig("Bifurcation Diagram.png");
