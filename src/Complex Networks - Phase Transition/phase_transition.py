import networkx as nx
import numpy as np
import matplotlib.pyplot as plt
import time 

# numero de nós no grafo
n = 500 
# Lista de probabilidades p de criação de arestas.
p = np.linspace(0, 0.1, n)

# Lista com tamanho dos maiores componentes
largest_cc = []
start_time = time.time()
# Cria grafo de Erdos-Renyi para cada probabilidade p e
# armazena o valor do maior componente na lista.
for i in range(n):
    # Lista de grafos aleatorios com probabilidade p.
    er = nx.gnp_random_graph(n,p[i])
    # Tamanho do maior componente para cada probabilidade.
    largest_cc.append(len(max(nx.connected_components(er), key=len)))

total_time = time.time() - start_time
print("For n = ", n)
print("--- %s seconds ---" % total_time )

plt.plot(p, largest_cc)
plt.xlabel("Probabilidade p")
plt.ylabel("Tamanho do maior componente")
plt.show()
