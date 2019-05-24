#include "Utilities.h"

vector<pair<int,int>> edgesPair;

void displayGraph(Graph<Local> g){

	int maxX = ceil(g.getLocals().at(0).getX()), maxY = ceil(g.getLocals().at(0).getY());

	for(unsigned i = 1; i < g.getLocals().size(); i++)
	{
		if(maxX < ceil(g.getLocals().at(i).getX()))
			maxX = ceil(g.getLocals().at(i).getX());
		if(maxY < ceil(g.getLocals().at(i).getY()))
			maxY = ceil(g.getLocals().at(i).getY());
	}

	GraphViewer *gv = new GraphViewer(maxX, maxY, false);

		gv->setBackground("background.jpg");
		gv->createWindow(maxX, maxY);
		gv->defineVertexColor("blue");
		gv->defineEdgeColor("black");

		for(unsigned j = 0; j < g.getLocals().size(); j++)
		{
			Vertex<Local> *a = g.findVertex(g.getLocals().at(j));
			gv->addNode(a->getInfo().getId(), a->getInfo().getX(), a->getInfo().getY());
			gv->setVertexLabel(a->getInfo().getId(),a->getInfo().getTag());
		}

		for(unsigned j = 0; j < g.getLocals().size(); j++)
		{
			gv->addEdge(j, edgesPair.at(j).first, edgesPair.at(j).second, EdgeType::UNDIRECTED);
		}
/*
		for(unsigned j = 0; j < g.getLocals().size(); j++)
		{
			gv->setVertexLabel(g.findVertex(g.getLocals().at(j))->getInfo().getId(), g.findVertex(g.getLocals().at(j))->getInfo().getTag());
		}
*/
		Sleep(100); // use sleep(1) in linux ; Sleep(100) on Windows

		gv->rearrange();
}

void displayGraph(vector<Local> g){

	int maxX = ceil(g.at(0).getX()), maxY = ceil(g.at(0).getY());

	for(unsigned i = 1; i < g.size(); i++)
	{
		if(maxX < ceil(g.at(i).getX()))
			maxX = ceil(g.at(i).getX());
		if(maxY < ceil(g.at(i).getY()))
			maxY = ceil(g.at(i).getY());
	}

	GraphViewer *gv = new GraphViewer(maxX, maxY, false);

		gv->setBackground("background.jpg");
		gv->createWindow(maxX, maxY);
		gv->defineVertexColor("blue");
		gv->defineEdgeColor("black");

		for(unsigned j = 0; j < g.size(); j++)
		{
			//cout << g.at(j).getX() << " " << g.at(j).getY() << endl;
			gv->addNode(g.at(j).getId(),g.at(j).getX(), g.at(j).getY());
		}

		for(unsigned j = 0; j < g.size()-1; j++)
		{
			gv->addEdge(j, g.at(j).getId(), g.at(j+1).getId(),EdgeType::UNDIRECTED);
		}
/*
		for(unsigned j = 0; j < g.getLocals().size(); j++)
		{
			gv->setVertexLabel(g.getLocals().at(j).getId(), g.getLocals().at(j).getTag());
		}
*/
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
		double w;
		w = sqrt(pow(dest.getX()-src.getX(), 2)+pow(dest.getY()-src.getY(), 2));
		city.addEdge(src, dest, w);
		city.addEdge(dest, src, w);
		//res->addEdge(cnt, id1, id2, EdgeType::UNDIRECTED);
	}
	infile.close();

	//GETTING TAGS
	infile.open(tags);
	if(!infile.is_open())
	{
		cerr << "Error opening " << tags << endl;
		exit (1);
	}
	unsigned nTags;
	getline(infile, line); //retira numero de tags

	nTags = stoi(line);
	for(unsigned i = 0; i < nTags; i++)
	{
		getline(infile, line);
		string tag = line;
		getline(infile, line);
		unsigned num = stoi(line);
		for(unsigned j = 0; j < num; j++)
		{
			getline(infile, line);
			city.findVertex(Local(stoi(line),0,0))->getInfo().setTag(tag);
		}
	}

	infile.close();
}
