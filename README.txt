Projeto de Teoria dos grafos - Algoritmos
Autores: Emmanuel Araujo Toscano Faceiro Lima e Filipe Simões Mota

Descrição sobre os algoritmos:
Cada algoritmo tem seu formato de entrada podendo alguns ter seu vertice
de origem informado na ultima linha do arquivo de input

Dijkstra:
	- Recebe: 
		numero de vértices, numero de arestas
		M Arestas
		Vertice de origem
	Obs: aceita somente pesos positivos

Bellman:
	- Recebe: 
		numero de vértices, numero de arestas
		M Arestas
		Vertice de origem
	Obs: aceita pesos positivos e negativos
Floyd:
	
	- Recebe: 
		Numero de vértices, Matriz de adjacência
		0 para posições que indicam o próprio vertice,
		i para posições inicialmente inalcançaveis,
		positivos > 0 para custos de alcançe de vertices iniciais alcançaveis
	Obs: aceita pesos positivos e negativos
Prim:
	- Recebe:
		Numero de vértices, numero de arestas
		M Arestas
	Obs: Aceita apenas vertices positivos maiores que 0, o vertice marcado como numero 1 sempre será a origem
