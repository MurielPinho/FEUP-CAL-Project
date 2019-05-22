#include "graphviewer.h"
#include "Graph.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void displayGraph(Graph<Local> g);
void displayGraph(vector<Local> g);
void loadGraph(string nodes, string edges, string tags, Graph<Local> & city);
