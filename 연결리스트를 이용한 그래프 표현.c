#include <stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 30
typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
} GraphNode;
//그래프 노드 구조체 정의해주기

//그래프타입 구조체 정의하기
typedef struct GraphType{
	int n; //정점의 개수
	GraphNode *adjList[MAX_VERTEX];
}GraphType;

void createGraph(GraphType* g)
{
	int v;
	g->n=0; //정점 개수 0
	for(v=0; v< MAX_VERTEX; v++) 
		//인접리스트 배열 주소값 초기화
		g->adjList[v] = NULL; //포인터로 연결되어 있던 간선들이 다 끊어진다!
}

void insertVertex(GraphType* g, int v)
{
	if(((g->n)+1)>MAX_VERTEX){
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++; //정점 개수 1증가
}

void insertEdge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if(u>=g->n || v>=g->n) { //그래프의 없는 정점일 경우!
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));//노드타입 동적 할당
	node->vertex = v;//정점 저장
	node->link = g->adjList[u];// 배열에 저장된 정점 리스트의 처음 주소를 저장
	g->adjList[u] = node;//현재 추가된 노드의 주소를 리스트의 주소값으로 저장;
}

void print_adjList(GraphType* g)
{
	int i;
	GraphNode* p;
	for(i=0; i<g->n; i++){
		printf("\n정점 %C의 인접리스트 ", i+65);
		p = g->adjList[i];  //i번째 정점의 시작주소 저장
		while(p!=NULL){
			printf(" -> %c", p->vertex+'A');  //정점 0~4를 A~D로 출력
			p = p->link;//다음 링크로 이동	
		}
	}
}

int main()
{
	int i;
	GraphType *G;
	G = (GraphType *)malloc(sizeof(GraphType));

	createGraph(G); 
	for(i=0; i<4; i++)
		insertVertex(G, i);
	insertEdge(G, 0, 1);
	insertEdge(G, 1, 3);
	insertEdge(G, 1, 2);
	insertEdge(G, 1, 0);
	insertEdge(G, 2, 3);
	insertEdge(G, 2, 1);
	insertEdge(G, 3, 2);
	insertEdge(G, 3, 1);
	
	printf("<G의 인접 리스트>");
	print_adjList(G);
		
  return 0;
} 
