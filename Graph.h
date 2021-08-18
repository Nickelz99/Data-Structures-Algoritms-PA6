#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

class graph 
{
private:
	vector<vector<int>>adj_M;
	stack<int> Path;
	int Verts = 0;
public:
	graph() {} // constructor
	void insert(int in, int in2); // insert function
	void print_stack(stack<int> traced);
	bool Search(vector<vector<int>>dup, int Vert);
	void graph_trace();
	friend istream& operator>>(istream& in, graph& g);
	friend ostream& operator<<(ostream& out, graph& g);

};