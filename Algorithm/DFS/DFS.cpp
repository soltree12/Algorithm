/*
Input :
1 //test case 개수
9 1 // 정점의 개수, 시작 정점
1 2 // 정점 간 연결 관계. 1과 2가 연결
1 3
2 4
2 5
4 8
5 8
3 6
3 7
6 8
7 8
-1 -1 // 입력 끝

Output:
#1 1 2 3 4 5 6 7 8 // 방문한 정점 순서
*/
#include <vector>
#include <iostream>

/* 노드 */
class Node
{
public:
	int number; // 고유 번호
	std::vector<Node*> link; // 자신과 연결된 노드들의 집합
	bool visited = false; // 방문 여부
};

/* 노드 두 개를 이어주는 함수 */
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