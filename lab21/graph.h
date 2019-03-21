#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

typedef enum vertex_state {UNVISITED, VISITED_SELF, VISITED_DESCENDANTS} state_t;

typedef enum graph_type {DIRECTED, UNDIRECTED} graph_t;

typedef struct graphrec *graph;
typedef struct vertexrec vertex;

extern graph graph_new(int vertices_s);
extern graph graph_free(graph g);
extern graph graph_add_edge(graph g,int v1,int v2, graph_t t);
extern void print_graph(graph g);
extern void graph_dfs(graph g);


#endif


