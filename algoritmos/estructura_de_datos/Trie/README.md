El problema que soluciona el Trie, es el problema de tener que consultar si ciertas palabras existen en alguna estructura de datos. Gracias al Trie, podemos resolver este problema en una complejidad O(n).

Un extra que se le puede añadir al Trie, es un método llamado: deleteWord(), en donde se recorre toda la palabra que se desea eliminar utilizando recursividad hasta llegar al final de la palabra; posteriormente se van eliminando los nodos volviendo arriba, verificando que los nodos no tengan hijos restantes, para así no borrar accidentalmente un nodo que era parte de otra palabra
