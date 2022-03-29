#include <vector>
#include <iostream>

#define INF 999

using namespace std;

struct Solution
{
	vector<int> D;
	vector<int> P;
};


Solution dijkstra(vector<vector<int>> graph, int source_vertex)
{
	Solution dijkstra_solution;

	
	
	
	
	
	// Implement here!





	return dijkstra_solution;
}



void print_D_and_P_arrays(Solution soln)
{





	// Implement here!





}



void print_shortest_paths(Solution soln, int source_vertex, int v_r)
{





	// Implement here!





}


void print_matrix(vector< vector<int> > dist)
{





	// Implement here!





}


int main()
{
	Solution soln1;
	Solution soln2;


	vector<vector<int>> graph1 = {	{ 0, 7, 4, 6, 1 },
									{ INF, 0, INF, INF, INF },
									{ INF,2, 0, 5,INF },
									{ INF, 3, INF, 0, INF },
									{ INF, INF, INF, 1, 0} };

	vector<vector<int>> graph2 = {	{0, 7, 5},
									{INF, 0, -5},
									{INF, INF, 0} };

	

	cout << "**********Given Test Cases**********\n\n";

	// Source vertex = v1
	cout << "Without Negative Edges:\n\n";
	cout << "Graph 1:\n\n";
	cout << "v1 is the source vertex:\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(graph1);
	cout << "\n\n";

	soln1 = dijkstra(graph1, 1);
	print_D_and_P_arrays(soln1);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph1.size(); i++)
	{
		print_shortest_paths(soln1, 1, i);
		cout << endl;
	}
	cout << "\n" << endl;

	cout << "With Negative Edges:\n\n";
	cout << "Graph 2:\n\n";
	// Source vertex = v1
	cout << "v1 is the source vertex:\n\n";

	cout << "\t1\t2\t3\n";
	cout << "---------------------------------------------\n";
	print_matrix(graph2);
	cout << "\n\n";

	soln2 = dijkstra(graph2, 1);
	print_D_and_P_arrays(soln2);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph2.size(); i++)
	{
		print_shortest_paths(soln2, 1, i);
		cout << endl;
	}
	cout << "\n" <<"WRONG!  Should be v1 -> v2 -> v3 \n\n" << endl;

	

	cout << "**********OurTest Cases**********\n\n";

	cout << "Without Negative Edges:\n\n"; 
	

	
	// Implement here!



	cout << "With Negative Edges:\n\n";


	// Implement here!

	
	cout << "\n" << endl;
	system("pause");
	return 0;
}
