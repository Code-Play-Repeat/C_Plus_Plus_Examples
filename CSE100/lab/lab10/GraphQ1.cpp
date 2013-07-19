#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include "Graph.cpp"
#include <map>
using namespace std;

int main (){
	Graph G1;
	vector<string> vertices;
	string input = " ";
	string input2 = " ";
	int input3 = 0;
	while (input != "END"){
		cin >> input;
		if (input == "END")
			break;
		G1.vertices.push_back(input);
	}
	input = " ";
	while (input != "END"){
		
		cin >> input;
		if (input == "END")
			break;
		else{
			cin >> input2; 
			cin >> input3;
		}
		//cout << input << " " << input2 << " " << input3 << endl;	
		if (G1.FindVertex(input) && G1.FindVertex(input2))
			G1.AddEdge(input,input2,input3);
		/*else
			cout << "Vertices or Vertex does not exist" << endl;*/
	}
	G1.PrintOut();
}
