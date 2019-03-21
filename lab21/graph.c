#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"

static int step;

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
 * static function used in depth frst search
 * @param g is the graph to be searched
 * @param v is the vertes of the graph
 **/
static void visit(graph g,int v){
    int i;
    g->vertices[v].state = VISITED_SELF;
    step++;
    g->vertices[v].distance = step;

    for(i=0;i<g->size;i++){
        if(g->edges[v][i] == 1 && g->vertices[i].state == UNVISITED){
            g->vertices[i].predecessor = v;
            visit(g,i);
        }
    }
    step++;
    g->vertices[v].state = VISITED_DESCENDANTS;
    g->vertices[v].finish = step;
}

/**
 * perfoms the depth first search on the graph
 * @param g is the graph on whic depth first will be performed
 **/
void graph_dfs(graph g){
    int i;
    for(i=0;i<g->size;i++){
        g->vertices[i].state = UNVISITED;
        g->vertices[i].predecessor = -1;
    }
    step = 0;
    for(i=0;i<g->size;i++){
        if(g->vertices[i].state == UNVISITED){
            visit(g,i);
        }
    }
    printf("Vertex Distance Predecessor Finish\n");
    for(i=0;i<g->size;i++){
        printf("%d\t%4d\t%3d\t%7d\n", i,g->vertices[i].distance,g->vertices[i].predecessor,g->vertices[i].finish);
    }
}


























   




