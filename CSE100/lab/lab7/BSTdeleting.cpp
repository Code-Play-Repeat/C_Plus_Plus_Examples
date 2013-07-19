#include <iostream>
#include <stdlib.h>
#include "BST.h"

using namespace std;

int main(int argc,char **argv)
{
  // Create an empty Binary Search Tree
  BST Tree;
  string input = "";
  while (input !="ENDINSERT")
  {
     cin >> input;
     if (input != "ENDINSERT")
     	Tree.Insert(input);     
  }
  while (input !="ENDDELETE")
  {
	cin >> input;
    	if (input != "ENDDELETE")
     	   Tree.Delete(input);   
  }

  Tree.Print("POST");
}
