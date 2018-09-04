/*
Input :
1 // test case ���� 
7 1 7 // ������ ����, �׸��� ���� ����, ���� ���� 
9 // ���� ���� 
1 2 4 // 1->2, ����� 4 
1 3 2
2 4 1
2 5 2
3 4 7
3 6 3
4 7 3
5 7 1
6 7 5

Output :
#1 7 // �ּ� ���
*/

#include <iostream>
#include <vector>

#define INF 2e9
using namespace std;

class Node;
class Edge;

/* ��� */
class Node {
public:
	bool isVisited = false; // �湮 ����
	int distance=INF; // ���������� �ش� ������ ���µ� ��� ���
	vector<Edge*> edges; // �������� ����� �迭

	~Node(){
		vector<Edge*>::iterator iter = edges.begin();
		for(; iter != edges.end(); ++iter)
		{
			delete (*iter);
		}
		edges.clear();
	}
};

/* ���� */
class Edge {
public:
	Edge(Node *to, int cost) : to(to), cost(cost) {}
	Node *to; // ���� ���
	int cost; // ���
};

/* �ܓ��� �׷����� �������� ��带 �����ϴ� �Լ� */
void linkNode(Node* from, Node* to, int cost)
{
	from->edges.push_back(new Edge(to,cost));
}

/* ���ͽ�Ʈ�� �Լ� */
int dijkstra(vector<Node>& graph, Node *from, Node *to)
{
	Node *curNode=from;
	from->distance = 0;
	
	while(true)
	{
		/* �湮���� ���� ��� �� ���� distance�� ���� ��带 ���� */
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

		/* ��� ��带 �湮�ߴٸ� Ž�� ����*/
		if (minNode == NULL) break;

		/* ���� ���� ����� ��� ����� distance ���� ���� */
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

