#include<iostream>
#include<time.h>
#include<vector>
#include<mutex>
using namespace std;
using matrix = vector<vector<int> >;
  
// maximum size of matrix 
#define MAX 1000
  
// maximum number of threads 
#define MAX_THREAD 100
  
matrix matA(MAX, vector<int>(MAX, 0));
matrix matB(MAX, vector<int>(MAX, 0));
matrix matC(MAX, vector<int>(MAX, 0));
int step = 0; 
mutex m;

void* multi(void* arg) 
{   
    m.lock();
    int core = step++; 
    m.unlock();

    // Each thread computes 1/MAX th of matrix multiplication 
    for (int i = core * MAX / MAX_THREAD; i < (core + 1) * MAX / MAX_THREAD; i++)  
        for (int j = 0; j < MAX; j++)  
            for (int k = 0; k < MAX; k++)  
                matC[i][j] += matA[i][k] * matB[k][j]; 

} 
  
// Driver Code 
int main() 
{   
    struct timespec start, finish;
    double elapsed;

    // Generating random values in matA and matB 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++) { 
            matA[i][j] = rand() % 100; 
            matB[i][j] = rand() % 100; 
        } 
    } 
    
    /*
    // Displaying matA 
    cout << endl 
         << "Matrix A" << endl; 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++)  
            cout << matA[i][j] << " "; 
        cout << endl; 
    } 
  
    // Displaying matB 
    cout << endl 
         << "Matrix B" << endl; 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++)  
            cout << matB[i][j] << " ";         
        cout << endl; 
    } 
    
    */

    clock_gettime(CLOCK_MONOTONIC, &start);

    // declaring four threads 
    pthread_t threads[MAX_THREAD]; 
  
    // Creating four threads, each evaluating its own part 
    for (int i = 0; i < MAX_THREAD; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, multi, (void*)(p)); 
    } 
  
    // joining and waiting for all threads to complete 
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);     
    
    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    /*
    // Displaying the result matrix 
    cout << endl 
         << "Multiplication of A and B" << endl; 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++)  
            cout << matC[i][j] << " ";         
        cout << endl; 
    }
    */

    cout << "\nTotal Time : " << elapsed << " s" << endl;

    return 0; 
} 