#include <vector>
#include <iostream>

/* ��� */
class Node
{
public:
	int number; // ���� ��ȣ
	std::vector<Node*> link; // �ڽŰ� ����� ������ ����
	bool visited = false; // DFS���� �湮 ����
};

/* ��� �� ���� �̾��ִ� �Լ� */
void linkNode(Node* n1, Node* n2)
{
	n1->link.push_back(n2);
	n2->link.push_back(n1);
}

/* DFS(depth-first search) */
void dfs(Node* v)
{
	std::cout << v->number << " ";
	v->visited = true;
	std::vector<Node*>::iterator iter = v->link.begin();
	for (; iter != v->link.end(); ++iter)
	{
		if ((*iter)->visited == false)
		{
			dfs(*iter);
		}
	}
}

int main()
{
	int testSize;
	std::cin >> testSize;
	for (int i = 0; i < testSize; i++)
	{
		int nodeNum, start;
		std::cin >> nodeNum >> start;
		std::vector<Node> graph(nodeNum);
		for (int i = 0; i < nodeNum; i++)
		{
			graph[i].number = i;
		}
		int n1, n2;
		while (true)
		{
			std::cin >> n1 >> n2;
			if (n1 == -1 && n2 == -1)
			{
				break;
			}
			linkNode(&graph[n1], &graph[n2]);
		}
		dfs(&graph[start]);
	}
}