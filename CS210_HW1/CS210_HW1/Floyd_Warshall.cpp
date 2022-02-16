#include <vector>
#include <iostream>

#define INF 999

using namespace std;

struct Solution
{
	vector<vector<int> > D;
	vector<vector<int> > P;	
};



Solution floyd_warshall(vector<vector<int> > graph)
{
	Solution floyds_solution;






	// Implement here





	return floyds_solution;
}


void print_matrix(vector< vector<int> > dist)
{




	// Implement here



}


void print_shortest_paths(Solution soln, int v_q, int v_r)
{
	
	
	
	// Implement here



}



int main()
{

	Solution soln1;
	Solution soln2;


	vector<vector<int> > graph1 = { {0,1,INF,1,5},
									{9,0,3,2,INF},
									{INF,INF,0,4,INF},
									{INF,INF,2,0,3},
									{3,INF,INF,INF,0} };

	vector<vector<int> > graph2 = { {0,4,5},
									{2,0,INF},
									{INF,-3,0} };

	soln1 = floyd_warshall(graph1);
	soln2 = floyd_warshall(graph2);


	cout << "**********Given Test Cases**********\n\n";
	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(graph1);

	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(soln1.D);

	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(soln1.P);

	cout << "\n\n";

	// Print actual shortest paths
	for (int i = 0; i < soln1.P.size(); i++)
	{
		for (int j = 0; j < soln1.P[i].size(); j++)
		{
			if (soln1.P[i][j] != -1)
			{
				cout << "v" << i + 1 << " -> ";
				print_shortest_paths(soln1, i, j);
				cout << "v" << j + 1 << "\n";
			}
		}
	}
	
	
	
	cout << "--------------------------------------------------------\n\n";
	cout << "\n\n";
	cout << "\t1\t2\t3\n";
	cout << "--------------------------------\n";
	print_matrix(graph2);

	cout << "\n\n";
	cout << "\t1\t2\t3\n";
	cout << "--------------------------------\n";
	print_matrix(soln2.D);

	cout << "\n\n";
	cout << "\t1\t2\t3\n";
	cout << "--------------------------------\n";
	print_matrix(soln2.P);

	cout << "\n\n";

	// Print actual shortest paths
	for (int i = 0; i < soln2.P.size(); i++)
	{
		for (int j = 0; j < soln2.P[i].size(); j++)
		{
			if (soln2.P[i][j] != -1)
			{
				cout << "v" << i + 1 << " -> ";
				print_shortest_paths(soln2, i, j);
				cout << "v" << j + 1 << "\n";
			}
		}
	}
	cout << "--------------------------------------------------------\n\n";



	cout << "**********Our Test Cases**********\n\n";

	
	// Implement here


	return 0;
}