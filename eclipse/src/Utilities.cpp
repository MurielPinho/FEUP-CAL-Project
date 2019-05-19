#include "Utilities.h"


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


GraphViewer* loadGraph(string nodes, string edges, string tags){
	GraphViewer *res = new GraphViewer(600, 600, true);

	ifstream infile;
	//GETTING NODES
	infile.open(nodes);
	if(!infile.is_open())
	{
		cerr << "Error opening " << nodes << endl;
	}

	string line;
	getline(infile, line); //retira numero de nodes
	//Alimenta nodes
	while (getline(infile, line))
	{
		stringstream lines (line);
		string value;
		vector<string> data;

		while (getline(lines, value, ','))
		{
			data.push_back(value);
		}
		string sID,sX,sY;
		long double x, y;
		int id;
		sID=(data.at(0));
		sID.erase(0,1);
		sX=data.at(1);
		sX.erase(find(sX.begin(), sX.end(), ' '));
		sY=data.at(2);
		sY.erase(sY.find(')'));
		sY.erase(find(sY.begin(), sY.end(), ' '));
		id=stoi(sID);
		x=stold(sX);
		y=stold(sY);
		res->addNode(id,x,y);
	}
	infile.close();
	//GETTING EDGES
	infile.open(edges);
	if(!infile.is_open())
	{
		cerr << "Error opening " << edges << endl;
	}

	getline(infile, line); //retira numero de edges
	int cnt = 0;
	//Alimenta edges
	while (getline(infile, line))
	{
		stringstream lines (line);
		string value;
		vector<string> data;

		while (getline(lines, value, ','))
		{
			data.push_back(value);
		}
		string sID1,sID2;
		int id1, id2;
		sID1=data.at(0);
		sID1.erase(0,1);

		sID2=data.at(1);
		sID2.erase(sID2.find(')'));
		sID2.erase(find(sID2.begin(), sID2.end(), ' '));

		id1=stoi(sID1);
		id2=stoi(sID2);
		res->addEdge(cnt, id1, id2, EdgeType::UNDIRECTED);
		cnt++;
	}
	infile.close();

	return res;
}
