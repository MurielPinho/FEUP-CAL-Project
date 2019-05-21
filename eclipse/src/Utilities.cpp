#include "Utilities.h"

vector<pair<int,int>> edgesPair;

void displayGraph(Graph<Local> g){
	GraphViewer *gv = new GraphViewer(100000, 100000, true);

	//cout << "grafos" << endl;
		gv->setBackground("background.jpg");
		gv->createWindow(100000, 100000);
		gv->defineVertexColor("blue");
		gv->defineEdgeColor("black");

		for(unsigned j = 0; j < g.getLocals().size(); j++)
		{
			gv->addNode(g.getLocals().at(j).getId(), g.getLocals().at(j).getX(), g.getLocals().at(j).getY());
		}

		for(unsigned j = 0; j < g.getLocals().size(); j++)
		{
			gv->addEdge(j, edgesPair.at(j).first, edgesPair.at(j).second, EdgeType::UNDIRECTED);
		}

		Sleep(100); // use sleep(1) in linux ; Sleep(100) on Windows

		gv->rearrange();
}


void loadGraph(string nodes, string edges, string tags, Graph<Local> & city){
	edgesPair.clear();
	ifstream infile;
	//GETTING NODES
	infile.open(nodes);
	if(!infile.is_open())
	{
		cerr << "Error opening " << nodes << endl;
		exit (1);
	}


	string line;
	getline(infile, line); //retira numero de nodes
	int befX, befY;
	bool flag = true;
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
		int x, y;
		int id;
		sID=(data.at(0));
		sID.erase(0,1);
		sX=data.at(1);
		sX.erase(find(sX.begin(), sX.end(), ' '));
		sY=data.at(2);
		sY.erase(sY.find(')'));
		sY.erase(find(sY.begin(), sY.end(), ' '));
		id=stoi(sID);
		x=stoi(sX);
		y=stoi(sY);
		if(flag)
		{
			befX = x;
			befY = y;
			x *= 0;
			y *= 0;
		}
		else
		{
			x -= befX;
			y = (y - befY)*-1;
		}
		flag = false;
		const Local aux(id, x, y);
		city.addVertex(aux); //adiciona no graph
		//res->addNode(id,x,y); //adiciona no viewer
	}
	infile.close();
	//GETTING EDGES
	infile.open(edges);
	if(!infile.is_open())
	{
		cerr << "Error opening " << edges << endl;
		exit (1);
	}

	getline(infile, line); //retira numero de edges
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
		edgesPair.push_back(make_pair(id1,id2));
		const Local src = city.getNode(id1), dest = city.getNode(id2);
		city.addEdge(src, dest, 0);
		//res->addEdge(cnt, id1, id2, EdgeType::UNDIRECTED);
	}
	infile.close();
/*
	//GETTING TAGS
	infile.open(tags);
	if(!infile.is_open())
	{
		cerr << "Error opening " << tags << endl;
		exit (1);
	}

	getline(infile, line); //retira numero de tags
	//int cnt = 0;
	//Alimenta tags
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
			for(unsigned j = 0; j < city.getLocals().size(); j++)
			{
				if(city.getLocals().at(j).getId() == id)
				{
					city.getLocals().at(j).setTag(tag);
					break;
				}
			}
			i--;
		}
	}
	infile.close();
*/
}
