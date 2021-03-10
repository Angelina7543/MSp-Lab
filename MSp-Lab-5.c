#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge
{
    int source, destination, weight;
};

struct Graph
{
    int V, R; // V - kolicestvo vershina, R - kolicestvo reber

    struct Edge* edge;
};

struct Graph* createGraph(int V, int R)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));

    graph->V = V;

    graph->R = R;

    graph->edge = (struct Edge*) malloc( graph->R * sizeof( struct Edge ) );

    return graph;
}

void FinalSolution(int dist[], int n)
{
	// Rezulitat
    printf("\nVersina\tRasstoianie ot ishodnoi versini\n");
    int i;

    for (i = 0; i < n; ++i){
		printf("%d \t\t %d\n", i, dist[i]);
	}
}

void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;

    int R = graph->R;

    int StoreDistance[V];

    int i,j;


    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;

    StoreDistance[source] = 0;

    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < R; j++)
        {
            int u = graph->edge[j].source;

            int v = graph->edge[j].destination;

            int weight = graph->edge[j].weight;

            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }


    for (i = 0; i < R; i++)
    {
        int u = graph->edge[i].source;

        int v = graph->edge[i].destination;

        int weight = graph->edge[i].weight;

        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("Etot graf soderjit tikl otritatelinih reber\n");
    }

    FinalSolution(StoreDistance, V);

    return;
}

int main()
{
    int V,R,S;  // V = kolicestvo versin, R = kolicestvo reber, S - ishodnaia versina

	printf("Vvedite kolicestvo versin v grafe\n");
    scanf("%d",&V);

	printf("Vvedite kolicestvo reber v grafe\n");
    scanf("%d",&R);

	printf("Vvedite nomer ishodnoi versini\n");
	scanf("%d",&S);

    struct Graph* graph = createGraph(V, R);

    int i;
    for(i=0;i<R;i++){
        printf("\nVvedite svoistva kraia %d svoistv Istocnik, naznacenie, ves sootvetstvenno \n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }

    BellmanFord(graph, S);

    return 0;
}
