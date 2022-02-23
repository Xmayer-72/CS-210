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

	int i, j, k;

	floyds_solution.D = graph;
	int n = graph.size();


	for (k = 0; k < n; k++) {

		// Choose all vertices as source one at a time

		for (i = 0; i < n; i++) {

			// Choose all vertices as destination for the source above

			for (j = 0; j < n; j++) {
				
				// If the vertex k is on the shortest path from
				// i to j, then update the distance
				
				if (floyds_solution.D[i][j] > (floyds_solution.D[i][k] + floyds_solution.D[k][j])
					&& (floyds_solution.D[k][j] != INF
						&& floyds_solution.D[i][k] != INF))

					floyds_solution.D[i][j] = floyds_solution.D[i][k] + floyds_solution.D[k][j];
			}
		}
	}

	return floyds_solution;
}


void print_matrix(vector< vector<int> > dist)
{
	int n = dist.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
				<< "     ";
			else
				cout << dist[i][j] << "     ";
		}
		cout << endl;
	}
}


void print_shortest_paths(Solution soln, int v_q, int v_r)
{



	if (soln.P[v_q][v_r] != 0) {
		print_shortest_paths(soln, v_q, soln.P[v_q][v_r]);
		cout << "v" << soln.P[v_q][v_r];
		print_shortest_paths(soln, soln.P[v_q][v_r], v_r);
	}
	
	




}



int main()
{

	Solution soln1;
	Solution soln2;
	Solution soln3;


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
	cout << "Graph 1: ";
	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(graph1);
	cout << "\n\n";
	cout << "Distance (D): ";
	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(soln1.D);
	cout << "\n\n";
	cout << "Path (P): ";
	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(soln1.P);
	cout << "\n\n";

	cout << "APSP: ";
	cout << "\n\n";
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
	cout << "Graph 2: ";
	cout << "\n\n";
	cout << "\t1\t2\t3\n";
	cout << "--------------------------------\n";
	print_matrix(graph2);
	cout << "\n\n";
	cout << "Distance (D): ";
	cout << "\n\n";
	cout << "\t1\t2\t3\n";
	cout << "--------------------------------\n";
	print_matrix(soln2.D);
	cout << "\n\n";
	cout << "\n\n";
	cout << "Path (P): ";
	cout << "\t1\t2\t3\n";
	cout << "--------------------------------\n";
	print_matrix(soln2.P);
	cout << "\n\n";

	cout << "APSP: ";
	cout << "\n\n";
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


	vector<vector<int> > graph3 = { {0, 2, INF},
									{-4,0,INF},
									{INF,5,0} };

	soln3 = floyd_warshall(graph3);

	cout << "Graph 3: ";
	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(graph3);
	cout << "\n\n";
	cout << "Distance (D): ";
	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(soln3.D);
	cout << "\n\n";
	cout << "Path (P): ";
	cout << "\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(soln3.P);
	cout << "\n\n";

	cout << "APSP: ";
	cout << "\n\n";
	for (int i = 0; i < soln3.P.size(); i++)
	{
		for (int j = 0; j < soln3.P[i].size(); j++)
		{
			if (soln3.P[i][j] != -1)
			{
				cout << "v" << i + 1 << " -> ";
				print_shortest_paths(soln3, i, j);
				cout << "v" << j + 1 << "\n";
			}
		}
	}

	system("pause");
	return 0;
}