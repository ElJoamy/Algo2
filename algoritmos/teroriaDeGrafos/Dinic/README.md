Basicamenmte la manera en la que opera Dinic, es aplicando BFS para poder encontar los posiblemente varios caminos los cuáles contienen el mínimo número de aristas desde el nodo fuente hasta el nodo objetivo, una vez hecho esto se utiliza DFS para poder recorrerlos todos, y hacer todas las aumentaciones en solo un paso. La complejidad del algoritmo de Dinic es de O(n^2m).