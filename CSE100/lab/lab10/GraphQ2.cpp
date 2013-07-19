#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include "Graph.cpp"
#include <map>
#include <utility>
using namespace std;

int main (){
	Graph G2;
	vector<string> operation1;
	vector<pair<string, string> > operation2;
	vector<pair<string, string> > operation3;
	int freq [3];
	string input = " ";
	string input2 = " ";
	int input3 = 0;
	int operation = -1;
	while (input != "END"){
		cin >> input;
		if (input == "END")
			break;
		G2.vertices.push_back(input);
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
		if (G2.FindVertex(input) && G2.FindVertex(input2))
			G2.AddEdge(input,input2,input3);
		/*else
			cout << "Vertices or Vertex does not exist" << endl;*/
	}
	
	while (operation != 0){
		cin >> operation;
		if (operation == 0)
			break;
		else if (operation == 1){
			//cout << "Operation 1" << endl;
			cin >> input;
			operation1.push_back(input);
			freq[0]++;

		}
		else if (operation == 2){
			//cout << "Operation 2" << endl;
			cin >> input  >> input2;
			operation2.push_back(make_pair(input,input2));
			freq[1]++;
		}
		else if (operation == 3){
			//cout << "Operation 3" << endl;
			cin >> input >> input2;
			operation3.push_back(make_pair(input,input2));
			freq[2]++;
		}
	}
		if (freq[0] != 0){
			//cout << "Operation 1" << endl;
			for (int k = 0; k < operation1.size(); k++)
				if (G2.FindVertex(operation1[k]))
				cout << 1 << endl;
else
	cout << 0 << endl;
		}
		if (freq[1] != 0){
			//cout << "Operation 2" << endl;
			for (int j = 0; j < operation2.size(); j++)
				cout << G2.FindEdgeCost(operation2[j].first, operation2[j].second) << endl;
		}
		if (freq[2] != 0){
			//cout << "Operation 3" << endl;
			for (int l = 0; l < operation3.size(); l++)
				cout << G2.IsReachable(operation3[l].first,operation3[l].second) << endl;
		}
			

		
}
