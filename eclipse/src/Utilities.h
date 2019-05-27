#include "graphviewer.h"
#include "Graph.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Funcao que faz display do grafo recebido como parametro.
 */ 
void displayGraph(Graph<Local> g);

/**
 * Funcao que faz display do grafo recebendo um vector de Locais como parametro.
 */
void displayGraph(vector<Local> g);

/**
 * Funcao que carrega o grafo escolhido pelo utilizador, colocando os nos, edges e tags.
 */
void loadGraph(string nodes, string edges, string tags, Graph<Local> & city);
