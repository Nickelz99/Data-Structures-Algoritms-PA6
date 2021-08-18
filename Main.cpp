#include "Graph.h"
using namespace std;


int main(int argc, char* argv[])
{
	graph g1;
	ifstream in(argv[1]);
	in >> g1;
	cout << g1 << endl << endl;
	g1.graph_trace();



	return 0;
}