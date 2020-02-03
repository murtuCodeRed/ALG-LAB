#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perms[40][40];
int costM[40][40];
int counter = 0;
int arr[40];
int cities;
int opt_cost;
int start_city;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void genPerm(int arr[], int l, int r){
    if(l == r){
        for(int i=0; i<cities; i++){
            perms[counter][i] = arr[i];
        }
        counter++;
    }
    else{
        for(int k = l; k<=r; k++){
            swap((arr+l), (arr+k));
            genPerm(arr, l+1, r);
            swap((arr+l), (arr+k));
        }
    }
}

void genArr(int cities){
    for(int i=0; i<cities; i++){
        arr[i] = i;
    }
}

void tsp(){
    genArr(cities);
    genPerm(arr, 0, cities-1);

    opt_cost = (int) INFINITY;

    for(int i=0; i<counter; i++){
        if(perms[i][0] == start_city){
            int cost = 0;
            int j;
            printf("%d ", perms[i][0]);
            for(j=1; j<cities; j++){
                 printf("%d ", perms[i][j]);
                 cost+=costM[perms[i][j-1]][perms[i][j]];
            }
            printf("%d ", perms[i][0]);
            cost+=costM[perms[i][j-1]][perms[i][0]];
            if(cost<opt_cost)
                opt_cost = cost;
            printf("\t\tcost=%d\n", cost);
        }
    }
}

int main(){
    printf("Enter number of cities:\n");
    scanf("%d", &cities);
    printf("Enter costM:\n");
    for(int i =0; i<cities; i++){
        for(int j = 0; j<cities; j++){
            scanf("%d", &costM[i][j]);
        }
    }
    printf("Enter starting city:\n");
    scanf("%d", &start_city);
    tsp();
    printf("Optimal cost = %d\n", opt_cost);
}