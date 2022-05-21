import networkx as nx
import numpy as np
import matplotlib.pyplot as plt
import time 

star_time = time.time()

# numero de nós no grafo
n = 500 

# Lista de probabilidades p de criação de arestas.
p = np.linspace(0, 0.1, n)

# Lista de grafos aleatorios com probabilidade p.
er = [nx.gnp_random_graph(n, i) for i in p]

# Tamanho do maior componente para cada probabilidade.
largest_cc = [len(max(nx.connected_components(er[i]), key=len)) for i in range(n)]

print("For n = ", n)
print("--- %s seconds ---" % (time.time() - star_time) )

plt.plot(p, largest_cc)
plt.xlabel("Probabilidade p")
plt.ylabel("Tamanho do maior componente")
plt.show()
