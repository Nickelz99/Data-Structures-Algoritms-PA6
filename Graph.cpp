#include "Graph.h"
using namespace std;



void graph::insert(int in , int in2)
{
	--in;
	--in2;
	adj_M[in][in2] = 1;
	adj_M[in2][in] = 1;

}





istream& operator>>(istream& in, graph& g)
{
	int Vs;
	int Eds;
	in >> Vs >> Eds;
	g.Verts = Vs;
	for (int j = 0; j < Vs; j++)
	{
		vector<int>v;
		for (int i = 0; i < Vs; i++)
		{
			v.push_back(0);

		}
		g.adj_M.push_back(v);

	}
	int v1 = 0;
	int v2 = 0;
	for (int z = 0; z < Eds; z++)
	{
		in >> v1 >> v2;
		g.insert(v1, v2);
	}
	return in;
}




ostream& operator<<(ostream& out, graph& g)
{
	
	for (int i = 0; i < g.adj_M.size(); i++)
	{
		vector<int>output;
		cout << i + 1 << " -> ";
		for (int j = 0; j < g.adj_M[i].size(); j++)
		{
			if (g.adj_M[i][j] == 1) //&& j!= g.adj_M[i].size()-1)
			{
				//cout << j + 1 << " -> ";
				output.push_back(j+1);
			}
			//else if (g.adj_M[i][j] == 1 && j == g.adj_M[i].size() - 1)
			//{
			//	//cout << j + 1;
			//	output.push_back(j + 1);
			//}


		}
		for (int x = 0; x < output.size(); x++)
		{
			if (x != output.size()-1)
			{
				cout << output[x] << " -> ";
			}
			else
			{
				cout << output[x] << endl;
			}
		}

	}
	return out;
}

void graph::print_stack(stack<int> traced)
{
	while (traced.size() != 0)
	{
		cout << "(" << traced.top() + 1 << ",";
		traced.pop();
		if (traced.size()!= 1)
		{
			cout << traced.top() + 1 << ") -> ";
		}
		else
		{
			cout << traced.top() + 1 << ")";
			cout << endl;
			traced.pop();
		}

	}

}




bool graph::Search(vector<vector<int>>dup, int Vert)
{
	int edges_exist = 0;
	Path.push(Vert);
	//vector<vector<int>>dup(adj_M);

	//for (int i = 0; i < adj_M.size(); ++i)
	//{
	//	for (int j = 0; j < adj_M[i].size(); ++j)
	//	{
	//		dup[i].push_back(adj_M[i][j]);
	//	}
	//}
	for (int i = 0; i < dup.size(); ++i)
	{
		for (int j = 0; j < dup[i].size(); ++j)
		{
			if (dup[i][j] == 1)
			{
				edges_exist = 1;
			}
		}
	}
	if (edges_exist != 1)
	{
		return true;
	}
	else
	{
		for (int j = 0; j < dup[0].size(); ++j)
		{
			if (dup[Vert][j] == 1)
			{

				dup[Vert][j] = 0;
				dup[j][Vert] = 0;

				bool cont = Search(dup, j);
				if (cont)
				{
					return true;
				}
				else
				{
					dup[Vert][j] = 1;
					dup[j][Vert] = 1;
				}
			}

		}
		Path.pop();
		return false;
	}
}

	void graph::graph_trace()
	{
		int VT = 0;
		bool no_sol = true;
		while (VT < adj_M.size())
		{
			Path.empty();
			vector<vector<int>>dup(adj_M);
			if (Search(dup, VT))
			{
				no_sol = false;
				cout << "This starting vertex: " << VT+1 << " has a solution" << endl;
				cout << "Solution with Start Vertex: " << VT + 1  << endl;
				print_stack(Path);
				while (!Path.empty())
				{
					Path.pop();
				}
			}
			else
			{
				cout << "This starting vertex: " << VT + 1 << " has no solution" << endl;
			}
			VT++;
		}
		if (no_sol)
		{
			cout << "There is no solution for this graph" << endl;
		}
	};









