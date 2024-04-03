#include<stdio.h>

int mat[10][10], i, j;
int n;

void readGraph() {
    printf("Enter no. of vertices : ");
    scanf("%d", &n);

    printf("If vertices are adjacent enter 1 othrwise 0\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("\nV%d is adjacent to %dV : ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayAdjList() {
    printf("\nAdjacency matrix of given graph is :\n");
    for(i=0; i<n; i++) {
        printf("V%d : ", i+1);
        for(j=0; j<n; j++) {
            if(mat[i][j]) {
                printf(" V%d ->", j+1);
            }
            
        }
        printf(" NULL\n");
    }
}

int main() {
    readGraph();
    displayAdjList();
    return 0;
}