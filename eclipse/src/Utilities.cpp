#include "Utilities.h"

using namespace std;

void displayGraph(string map){
	GraphViewer *gv = new GraphViewer(600, 600, true);

		gv->setBackground("background.jpg");

		gv->createWindow(600, 600);
		gv->defineVertexColor("blue");
		gv->defineEdgeColor("black");

		gv->addNode(0);
		gv->addNode(1);
		gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);

		Sleep(100); // use sleep(1) in linux ; Sleep(100) on Windows

		gv->removeEdge(0);
		gv->removeNode(1);
		gv->addNode(2);
		gv->rearrange();

		Sleep(100);

		gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);

		gv->setVertexLabel(0, "Isto e um no");
		gv->setEdgeLabel(1, "Isto e uma aresta");

		gv->setVertexColor(2, "green");
		gv->setEdgeColor(1, "yellow");

		gv->rearrange();

}


GraphViewer* loadGraph(string map){
	GraphViewer *res;

	ifstream infile;
	infile.open(map);

	if(!infile.is_open())
	{
		cerr << "Error opening " << map << endl;
	}

	string line;
	getline(infile, line);
	int numNodes = stoi(line);
	for(int i = 0; i < numNodes; i++){
		getline(infile, line);
		long id;
		double x, y;
		id = stoul(line.substr(1, line.find_first_of(",")));
		x = stod(line.substr(line.find_first_of(" "), line.find_last_of(",")-line.find_first_of(" ")));
		y = stod(line.substr(line.find_last_of(" "), line.find_first_of(")")-line.find_last_of(" ")));
		res->addNode(id, x, y);
	}

	return res;
}
