#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
using namespace std;
using matrix = vector<vector<int> >;

// maximum size of matrix 
#define MAX 1000

matrix matA(MAX, vector<int>(MAX, 0));
matrix matB(MAX, vector<int>(MAX, 0));
matrix matC(MAX, vector<int>(MAX, 0));

void calculateMatrix(){

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            int sum = 0;
            for (int k = 0; k < MAX;k++){
                sum += matA[i][k] * matB[k][j];
            }
            matC[i][j] = sum;
        }
    }

}

void printMatrix(matrix c){
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c[0].size();j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}
int main(){
    
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
    printMatrix(matA);
    printMatrix(matB);
    */

    clock_gettime(CLOCK_MONOTONIC, &start);
    //code
    calculateMatrix();

    clock_gettime(CLOCK_MONOTONIC, &finish);

    //printMatrix(matC);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    cout<<"Time: "<<elapsed<<"s"<<endl;

    return 0;
}

