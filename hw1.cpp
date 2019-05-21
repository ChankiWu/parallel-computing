#include<iostream>
#include<math.h>
#include<time.h>
#include<fstream>
using namespace std;

// https://www.programiz.com/cpp-programming/examples/prime-number
// https://zh.cppreference.com/w/cpp/thread/thread

bool isPrime(int n){
    for(int i=2; i <= sqrt(n);i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void primePrint(){
    long i = 2;
    //long limit = pow(10,9);
    long limit = 100;

    while(i < limit){

        if(isPrime(i)){
            printf("%ld ", i);
        }

        i += 1;
    }
}

int main(){
   
	struct timespec start, finish;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);
    primePrint();
    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    cout<< "\nTotal Time : " << elapsed << " s" << endl;

    //write the result
    /*
    ofstream outfile;
    outfile.open("result.txt");
    outfile<<"Single Thread: "<<elapsed<<" s"<<endl;
    outfile.close();
    */

    return 0;
}
