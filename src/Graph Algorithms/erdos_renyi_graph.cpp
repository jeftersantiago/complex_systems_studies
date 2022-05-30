#include<list>
#include<random>
#include<iostream>

class Graph{
public:
    std::vector<std::vector<bool>> adjMatrix;
    
    // Generates an Erdos-Renyi random graph (undirected).
    std::vector<std::vector<bool>> Erdos_Renyi_Graph(int n, double p){

        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 mt(rd()); 
        std::uniform_real_distribution<double> random_dist(0, 1.0);
        /*
          std:: cout << "Probability = " << p << std::endl;
          std::cout << "Random Distribution = " << random_dist(mt) << std::endl;
        */

        std::vector<std::vector<bool>> adjMatrix(n, std::vector<bool>(n,false));
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                adjMatrix[i][j] = adjMatrix[j][i] = random_dist(mt) < p;
            }
        }
        return adjMatrix;
    }
    void printMatrix(std::vector<std::vector<bool>> M){
    	for (auto l : M) {
    		for (auto el : l) {
                std::cout << el << " ";
    		}
            std::cout << std::endl;
    	}
        std::cout << std::endl;
    }
    Graph(int n, double p){
        adjMatrix = Erdos_Renyi_Graph(n, p);            
        printMatrix(adjMatrix);
    }
};
int main(){
    int n;
    double p;
    std::cin >> n >> p;
    Graph g(n, p);
    return 0;
}
