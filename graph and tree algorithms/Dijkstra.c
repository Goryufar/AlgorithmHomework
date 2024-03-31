#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct vertex {
    int name;
    int d;
    struct edge *edges;
};

struct edge {
    struct vertex *start;
    struct vertex *end;
    int weight;
    struct edge *next; 
};

struct graph {
    int size;
    struct vertex *vertices;
};
void print_graph(struct graph *g) {
    printf("Graph:\n");
    for (int i = 0; i < g->size; ++i) {
        printf("Vertex %d:\n", g->vertices[i].name);
        printf("    Edges:\n");
        struct edge *e = g->vertices[i].edges;
        while (e != NULL) {
            printf("        (%d -> %d, weight: %d)\n", e->start->name, e->end->name, e->weight);
            e = e->next;
        }
    }
}
struct graph *create_graph(int size) {
    struct graph *g = malloc(sizeof(struct graph));
    if (!g) {
        fprintf(stderr, "no enough memory!\n");
        exit(2);
    }
    g->size = size;
    g->vertices = malloc(size * sizeof(struct vertex));
    for (int i = 0; i < size; ++i) {
        g->vertices[i].name = i; 
        g->vertices[i].d = INT_MAX; 
        g->vertices[i].edges = NULL; 
    }
    return g;
}

void add_edge(struct graph *g, int start, int end, int weight) {
    struct edge *new_edge = malloc(sizeof(struct edge));
    if (!new_edge) {
        fprintf(stderr, "no enough memory!\n");
        exit(2);
    }
    new_edge->start = &(g->vertices[start]);
    new_edge->end = &(g->vertices[end]);
    new_edge->weight = weight;
    new_edge->next = g->vertices[start].edges;
    g->vertices[start].edges = new_edge; 
}


int main() {

    struct graph *g = create_graph(5);

    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 4, 5);
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 4, 2);
    add_edge(g, 2, 3, 4);
    add_edge(g, 3, 2, 6);
    add_edge(g, 3, 0, 7);
    add_edge(g, 4, 1, 3);
    add_edge(g, 4, 2, 9);
    add_edge(g, 4, 3, 2);
    
    print_graph(g);


    return 0;
}
