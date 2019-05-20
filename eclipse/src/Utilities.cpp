#include "Utilities.h"


void displayGraph(string map){

	GraphViewer *gv = loadGraph("Mapas\Porto\T04_nodes_X_Y_Porto.txt", "Mapas\Porto\T04_edges_Porto.txt", "Mapas\Porto\T04_tags_Porto.txt");
	if(map != "Porto")
		gv = loadGraph(NULL, NULL, NULL);


	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);
	gv->rearrange();
	Sleep(100);
	gv->closeWindow();
}


GraphViewer* loadGraph(string nodes, string edges, string tags){
	GraphViewer *res = new GraphViewer(600, 600, true);

	res->defineVertexColor("blue");
	res->defineEdgeColor("black");

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
		locais.push_back(new Local(id, x, y));
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
	//GETTING TAGS
	infile.open(edges);
	if(!infile.is_open())
	{
		cerr << "Error opening " << tags << endl;
	}

	getline(infile, line); //retira numero de tags
	//int cnt = 0;
	//Alimenta edges
	while (getline(infile, line))
	{
		string tag;
		tag = line;
		getline(infile, line);
		int i = stoi(line);
		while(i)
		{
			int id;
			getline(infile, line);
			id = stoi(line);
			for(unsigned j = 0; j < locais.size(); j++)
			{
				if(locais.at(i)->getId() == id)
				{
					locais.at(i)->setTag(tag);
					res->setVertexLabel(id, tag);
					break;
				}
			}
			i--;
		}
	}
	infile.close();

	return res;
}
