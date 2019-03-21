#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "graph.h"

int main(void){
    graph g = NULL;
    int vertex1,vertex2;
    int size=0;
    graph_t type = DIRECTED;
    if(1==scanf("%d", &size)){
        g = graph_new(size);
    }
    while(2==scanf("%d%d", &vertex1, &vertex2)){
        g = graph_add_edge(g,vertex1,vertex2,type);
    }

    print_graph(g);
    graph_dfs(g);
    g = graph_free(g);
    return EXIT_SUCCESS;
}


