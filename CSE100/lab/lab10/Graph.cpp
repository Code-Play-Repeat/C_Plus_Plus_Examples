#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
	edges[make_pair(vert1,vert2)] = weight;
}

bool Graph::FindVertex(string vert1) {
	list<string>::iterator it;
	for (it=vertices.begin(); it!=vertices.end();it++)	
	    if(vert1 == *it)
		return true;
	return false;
}

int Graph::FindEdgeCost(string vert1, string vert2){
	map<pair<string,string>,int>::iterator eit;
	for (eit = edges.begin(); eit != edges.end(); eit++)
		if ((*eit).first.first == vert1 && (*eit).first.second == vert2)
			return (*eit).second;
	return -1;
}

int Graph::IsReachable(string vert1, string vert2) {
	map<string, string> color;
	map<string, int> distance;
	map<string, string> pi;
	queue<string> Q;
	
	list<string>::iterator it1;
	
	for(it1=vertices.begin();it1!=vertices.end();it1++)
	{
		color[*it1] = "WHITE";
		distance[*it1] = INT_MAX;
		pi[*it1] = "NIL";
	}

	color[vert1] = "GRAY";
	distance[vert1] = 0;
	pi[vert1] = "NIL";
	Q.empty();
	Q.push(vert1);

	map<pair<string,string>,int>::iterator eit;
	while(!(Q.empty())){
		string u = Q.front();
		Q.pop();
		for(eit=edges.begin(); eit!=edges.end(); eit++)
		{
			string adj;
			if ((*eit).first.first == u){
				adj = (*eit).first.second;
				if (color[adj] == "WHITE"){
			    		color[adj] = "GRAY";
					distance[adj] = distance[u] + 1;
					pi[adj] = pi[u];
					Q.push(adj);
			    
				}
			}
		}
		color[u] = "BLACK";
	}
	if (distance[vert2] != INT_MAX)
		return distance[vert2];
	
	return -1;
}



/*int main() {
    Graph G;
}*/
