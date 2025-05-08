#include <stdio.h>
#include <time.h>

int x(int n){
    if(n <= 1) return 1;
    return x(n-1) + x(n-2);
}

int main(){
    int n = 10;
    int N_Max = 1000;
    double total_time = 0;

    for (int i = 0; i < N_Max; i++){
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    
    printf("tempo medio: %f segundos\n", total_time / N_Max);

    return 0;
}