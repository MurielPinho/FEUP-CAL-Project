#include "graphviewer.h"
#include "Empresa.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
extern vector<Local*> locais;

void displayGraph(string map);
GraphViewer* loadGraph(string nodes, string edges, string tags);
