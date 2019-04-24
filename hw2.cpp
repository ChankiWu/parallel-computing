#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
using namespace std;
using matrix = vector<vector<int> >;

matrix calculateMatrix(matrix A, matrix B){
    matrix C(A.size(), vector<int> (B[0].size(), 0));
    if(A[0].size() != B.size()) {
        cerr<<"invalid input."<<endl;
        return C;   //invalid
    }

    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < B[0].size(); j++){
            int sum = 0;
            for (int k = 0; k < A[0].size();k++){
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    return C;
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

    matrix A;
    matrix B;

    int a1[3] = {1,2,3};
    int a2[3] = {4,5,6};

    int b1[4] = {1,2,3,4};
    int b2[4] = {5,6,7,8};
    int b3[4] = {9,10,11,12};

    A.push_back(vector<int>(a1,a1+3));
    A.push_back(vector<int>(a2,a2+3));

    B.push_back(vector<int>(b1,b1+4));
    B.push_back(vector<int>(b2,b2+4));
    B.push_back(vector<int>(b3,b3+4)); 

    clock_gettime(CLOCK_MONOTONIC, &start);
    //code

    printMatrix(calculateMatrix(A, B));

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    cout<<"Time: "<<elapsed<<"s"<<endl;

    
    return 0;
}

