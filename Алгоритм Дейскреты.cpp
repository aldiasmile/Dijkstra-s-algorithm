#include "stdafx.h"

/*! \file main.cpp
Главный файл проекта
*/
#include <iostream>
using namespace std;

/** fn void Dijkstra(int **GR, int st,int V)
Алгоритм Дейкстры
*/
void Dijkstra(int **GR, int st,int V)
{
	int *distance, count, index, i, u, m = st + 1;
	bool *visited;
	distance = new int[V];
	visited = new bool[V];
	for (i = 0; i<V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count<V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i<V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i<V; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i]<distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (i = 0; i<V; i++) if (distance[i] != INT_MAX)
		cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
}
/** \fn void main()
Главная функция проекта
*/
void main()
{
	setlocale(LC_ALL, "Rus");
	int start,  n,m;
	cout << "Количество строк и столбцов"<<endl;
	cin>> n;
	m = n;
	
	int**GR = new int*[n];
	for (int t = 0; t < n; t++)
		for (int i = 0; i < m; ++i)
			GR[t] = new int[m];

		for (int t = 0; t < n; ++t)
	    for (int i = 0; i < m; ++i)
		cin >> GR[t][i];

	for (int t = 0; t < n; ++t){
		for (int i = 0; i < m; ++i)
		{
			cout << GR[t][i]<<'\t' ;
		}
		cout << "\n";
	}

	cout << "Начальная вершина >> "; cin >> start;
	Dijkstra(GR, start - 1,n);
	system("pause>>void");
}
