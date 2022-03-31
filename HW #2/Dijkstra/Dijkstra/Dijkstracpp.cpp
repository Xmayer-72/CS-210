#include <vector>
#include <iostream>
#include <String>

#define INF 999

using namespace std;

int minDist(int dist[], bool SPfound[]);

struct Solution
{
	vector<int> D;
	vector<int> P;
};

int dist[6];
bool SPfound[6];

Solution dijkstra(vector<vector<int>> graph, int source_vertex)
{
	Solution dijkstra_solution;






	
	for (int index = 0; index <= 5; index++) {
		dist[index] = INF;
		SPfound[index] = false;
	}
	
	dist[source_vertex] = 0;

	for (int i = 0; i <= 5; i++) {
		int m = minDist(dist, SPfound);
		SPfound[i] = true;
		for (int j = 0; j <= 5; j++) {
			if (SPfound[j] && graph[m][j] && dist[m] != INF && dist[m] + graph[m][j] < dist[j])
				dist[j] = dist[m] + graph[m][j];
		}
	}





	return dijkstra_solution;
}

int minDist(int dist[], bool SPfound[]) {

	int min1 = INF;
	int min2 = INF;

	for (int k = 0; k < 5; k++) {
		if (SPfound[k] == false && dist[k] <= min1) {
			min1 = dist[k];
			min2 = k;
		}
	}
	return min2;

}

void print_D_and_P_arrays(Solution soln)
{
	cout << "D array:";
	for(int var: soln.D)
	{
		cout << var << " -> ";
	}

	cout << "\nP array:";
	for (int var : soln.P)
	{
		cout << var << " -> ";
	}
}



void print_shortest_paths(Solution soln, int source_vertex, int v_r)
{





	for (int i = 0; i < 5; i++) {
		char str = 5 + i;
		cout << str << "\t\t\t" << dist[i] << endl;
	}





}


void print_matrix(vector< vector<int> > dist)
{
	for (vector<int> vect:dist)
	{
		for (int num: vect)
		{
			printf("%4d ", num);
		}
		cout << "\n";
	}
}


int main()
{
	Solution soln1;
	Solution soln2;


	vector<vector<int>> graph1 = { { 0, 7, 4, 6, 1 },
									{ INF, 0, INF, INF, INF },
									{ INF,2, 0, 5,INF },
									{ INF, 3, INF, 0, INF },
									{ INF, INF, INF, 1, 0} };

	vector<vector<int>> graph2 = { {0, 7, 5},
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
	cout << "\n" << "WRONG!  Should be v1 -> v2 -> v3 \n\n" << endl;



	cout << "**********OurTest Cases**********\n\n";

	cout << "Without Negative Edges:\n\n";



	Solution soln3;


	vector<vector<int>> graph3 = { { 0, 6, 5, 2, 3 },
									{ INF, 0, INF, INF, INF },
									{ INF,2, 0, 5,INF },
									{ INF, 3, INF, 0, INF },
									{ INF, INF, INF, 1, 0} };

	cout << "Without Negative Edges:\n\n";
	cout << "Graph 1:\n\n";
	cout << "v1 is the source vertex:\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(graph3);
	cout << "\n\n";

	soln3 = dijkstra(graph3, 1);
	print_D_and_P_arrays(soln3);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph3.size(); i++)
	{
		print_shortest_paths(soln3, 1, i);
		cout << endl;
	}
	cout << "\n" << endl;



	cout << "With Negative Edges:\n\n";

Solution soln4;


	vector<vector<int>> graph4 = { { 0, 6, 5, 2, 3 },
									{ INF, 0, INF, INF, INF },
									{ INF,2, 0, -5,INF },
									{ INF, 3, INF, 0, INF },
									{ INF, INF, INF, 1, 0} };

	cout << "Without Negative Edges:\n\n";
	cout << "Graph 1:\n\n";
	cout << "v1 is the source vertex:\n\n";
	cout << "\t1\t2\t3\t4\t5\n";
	cout << "---------------------------------------------\n";
	print_matrix(graph4);
	cout << "\n\n";

	soln4 = dijkstra(graph4, 1);
	print_D_and_P_arrays(soln4);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph4.size(); i++)
	{
		print_shortest_paths(soln4, 1, i);
		cout << endl;
	}
	cout << "\n" << endl;


	cout << "\n" << endl;
	system("pause");
	return 0;
}
