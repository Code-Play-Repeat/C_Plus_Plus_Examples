#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include "MinPriorityQueue.cpp"


using namespace std;

// character set containing the set of characters used and their
// frequencies.
struct charSet
{
	char ch;
	int freq;
	charSet(char xch, int xfreq)
	{
		ch = xch;
		freq = xfreq;
	}
};


//end of character set --------------------------------------------

class Node {
public:
    char name;
    int f;
    Node *left, *right;
    string code;

    Node() {
        name = "";
        code = "";
        f = INT_MAX;
        left = right = 0;
    }

    Node(int ff, char n) {
        name = n;
        f = ff;
        left = right = 0;
        code = "";
    }

    ~Node() {
        delete left;
        delete right;
    }
};

// huffman algorithm
void HuffmanCode (vector < charSet > C)
{
	int n = C.size();


	Q<Node> *q = new Q<Node > (n);
   	for (int i = 0; i < n; i++) {
        	q->insert(new Node(C[i].freq, C[i].ch));
    	}

    	for (int i = 0; i < n - 1; i++) {
        	Node *x = q->extractMin();
        	Node *y = q->extractMin();
       		Node *z = new Node(x->f + y->f, x->name + y->name);
        	z->left = x;
        	z->right = y;
        	q->insert(z);
    	}
	Node *root = q->extractMin();
	
}





// main //


int main()
{
    	char n = '1';
	vector < charSet > C;
	vector < char > chstr;
	int freq [6];
	for (int i = 0; i < 6; i++)
	    freq[i] = 0;
	n = toupper(n);
	while (n != 'Z')
    	{
	  	cin >> n;
		n = toupper(n);
		if (n != 'Z')
			chstr.push_back(n);

	}

	for (int i = 0; i < chstr.size(); i++)
	{
		int k = (int)chstr[i] - (int)'A';
		freq[k]++;
	}
	cout << endl;
	for (int i = 0; i < 6; i++)
		C.push_back(charSet((char)i + 'A', freq[i]));

	HuffmanCode(C);	
}
