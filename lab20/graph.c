#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

/**
 * struch of the graph
 * edges represent the edge of the graph
 * size is the size of the graph
 * vertices represent each vertex of the graph
 **/
struct graphrec {
    int **edges;
    int size;
    vertex *vertices;
};

struct vertexrec {
    int predecessor;
    int distance;
    state_t state;
    int finish;
};

/**
 * creates a new graph
 * @param vertices_v is the vertex of desired graph
 **/
graph graph_new(int vertices_s){
    int i;
    int j;
    graph result = emalloc(sizeof *result);
    result->size = vertices_s;
    result->vertices = emalloc(result->size * sizeof(result->vertices[0]));
    result->edges = emalloc(result->size * sizeof(result->edges[0]));
    for(i=0;i<vertices_s;i++){
        result->edges[i] = emalloc(result->size * sizeof(result->edges[0][0]));
    }

    for(i=0;i<result->size;i++){
        for(j=0;j<result->size;j++){
            result->edges[i][j] = 0;
        }
    }
    return result;
}

/**
 * prints out the adjacency list for thegraph
 * @param g is the graph
 **/
void print_graph(graph g){
    int i=0;
    int j=0;
    printf("adjacency list:\n");
    for(i=0;i<g->size;i++){
        printf("%d | ", i);
        for(j=0;j<g->size;j++){
            if(g->edges[i][j] == 1){
                printf("%d ", j);
            }
        }
        printf("\n");
    }

}

/**
 * Meory allocated is now being deallocated at the end of the program
 * @param g is the graph whose memory is deallocated
 **/
graph graph_free(graph g){
    int i;
    for(i=0;i<g->size;i++){
        free(g->edges[i]);
    }
    
    free(g->edges);
    free(g->vertices);
    free(g);
    return g;
}

/**
 * adds an edge to the graph
 * @param g is the graph to add the edge to
 * @param v1 is a vertex of the graph
 * @param v2 is a vertex of the graph
 * @param t is the type f the graph
 **/
graph graph_add_edge(graph g,int v1,int v2,graph_t t){
    if(t==DIRECTED){
        g->edges[v1][v2]=1;
    }
    else {
        g->edges[v1][v2]=1;
        g->edges[v2][v1]=1;
    }
    return g;
}

/**
 * performs breadth first search
 * @param g is the graph to be searched
 * @param source is the vertex from which yu measure distance from
 **/
void graph_bfs(graph g,int source){
    queue q= queue_new(g->size);
    int i=-1;
    int u;
    state_t unv = UNVISITED;
    state_t vis = VISITED_SELF;
    state_t vid = VISITED_DESCENDANTS;

    for(i=0;i<g->size;i++){
        g->vertices[i].state = unv;
        g->vertices[i].distance = -1;
        g->vertices[i].predecessor = -1;
    }
    g->vertices[source].state = vis;
    g->vertices[source].distance = 0;
    enqueue(q,source);

    while(queue_size(q)!=0){
        u = dequeue(q);
        for(i=0;i<g->size;i++){
            if(g->edges[u][i] == 1 && g->vertices[i].state == unv){
                g->vertices[i].state = vis;
                g->vertices[i].distance = 1+g->vertices[u].distance;
                g->vertices[i].predecessor = u;
                enqueue(q,i);
            }
      
        }
        g->vertices[u].state = vid;
    }
    printf("\n");
    printf("Vertex Distance pred\n");
    for(i=0;i<g->size;i++){
        printf("%d\t%d\t%d\n", i, g->vertices[i].distance, g->vertices[i].predecessor);
    }
    q = queue_free(q);

}





