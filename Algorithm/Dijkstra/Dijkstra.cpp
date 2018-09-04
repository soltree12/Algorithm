/*
Input :
1 // test case 개수 
7 1 7 // 정점의 개수, 그리고 시작 정점, 도착 정점 
9 // 간선 개수 
1 2 4 // 1->2, 비용은 4 
1 3 2
2 4 1
2 5 2
3 4 7
3 6 3
4 7 3
5 7 1
6 7 5

Output :
#1 7 // 최소 비용
*/

#include <iostream>
#include <vector>

#define INF 2e9
using namespace std;

class Node;
class Edge;

/* 노드 */
class Node {
public:
	bool isVisited = false; // 방문 여부
	int distance=INF; // 시작점에서 해당 노드까지 가는데 드는 비용
	vector<Edge*> edges; // 간선들이 저장된 배열

	~Node(){
		vector<Edge*>::iterator iter = edges.begin();
		for(; iter != edges.end(); ++iter)
		{
			delete (*iter);
		}
		edges.clear();
	}
};

/* 간선 */
class Edge {
public:
	Edge(Node *to, int cost) : to(to), cost(cost) {}
	Node *to; // 목적 노드
	int cost; // 비용
};

/* 단뱡향 그래프를 기준으로 노드를 연결하는 함수 */
void linkNode(Node* from, Node* to, int cost)
{
	from->edges.push_back(new Edge(to,cost));
}

/* 다익스트라 함수 */
int dijkstra(vector<Node>& graph, Node *from, Node *to)
{
	Node *curNode=from;
	from->distance = 0;
	
	while(true)
	{
		/* 방문하지 않은 노드 중 가장 distance가 작은 노드를 선택 */
		int minDist = INF;
		Node *minNode = NULL;
		for (unsigned int j = 0; j < graph.size(); j++)
		{
			if (graph[j].isVisited==false && minDist > graph[j].distance)
			{
				minDist = graph[j].distance;
				minNode = &graph[j];
			}
		}

		/* 모든 노드를 방문했다면 탐색 종료*/
		if (minNode == NULL) break;

		/* 현재 노드와 연결된 모든 노드의 distance 값을 갱신 */
		curNode = minNode;
		curNode->isVisited = true;
		for (unsigned int j = 0; j < curNode->edges.size(); j++)
		{
			Node *nextNode = curNode->edges[j]->to;
			if (nextNode->distance > curNode->edges[j]->cost + curNode->distance)
			{
				nextNode->distance = curNode->edges[j]->cost + curNode->distance;
			}
		}
	}
	return to->distance;
}

int main()
{
	int testSize = 0;
	cin >> testSize;
	for (int t = 0; t < testSize; t++)
	{
		int graphSize = 0;
		cin >> graphSize;
		graphSize++;

		vector<Node> graph(graphSize);

		int startNum = 0; 
		int endNum = 0;
		int edgeSize = 0;
		cin >> startNum;
		cin >> endNum;
		cin >> edgeSize;

		for (int i = 0; i < edgeSize; i++)
		{
			int fromNum, toNum, cost;
			cin >> fromNum >> toNum >> cost;

			linkNode(&graph[fromNum], &graph[toNum], cost);
		}

		cout<<"#"<<t+1<<" "<<dijkstra(graph, &graph[startNum], &graph[endNum])<<endl;
	}
}

