using Plots

lims = (0, 4.0);
iter = 1000; 
#                                #steps
rvs = LinRange(lims[1], lims[2], 6001);

# 2 colunm matrix
# with this i can make a scatter plot of the values.
X = zeros(length(rvs), iter);

x0 = 0.5 ;

for i = 1 : length(rvs)
    X[i, 1] = x0;
    for j = 1 : iter - 1
        # X_n+1 = r * Xn * (1 - Xn)
        X[i, j+1] = rvs[i] + X[i, j] * (1 - X[i, j]);
    end
end

plot(rvs, X[:, end-100:end],
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

savefig("logistic.pdf");
