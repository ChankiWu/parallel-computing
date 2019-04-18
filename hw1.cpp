#include<iostream>
#include<math.h>
#include<time.h>
#include<fstream>
using namespace std;

// https://www.programiz.com/cpp-programming/examples/prime-number
// https://zh.cppreference.com/w/cpp/thread/thread

bool isPrime(int n){
    for(int i=3; i <= n/2;i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void primePrint(){
    long i = 3;
    long limit = pow(10,10);
    //long limit = 100;

    while(i < limit){

        if(isPrime(i)){
            printf("%ld\n", i);
        }

        i += 2;
    }
}

int main(){
   
	clock_t startTime,endTime;

    startTime = clock();
    primePrint();
    endTime = clock();

    double res = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    res = res / 60;
    cout << "Total Time : " << res << " min" << endl;

    //write the result
    ofstream outfile;
    outfile.open("result.txt");
    outfile<<"Single Thread: "<<res<<" min"<<endl;
    outfile.close();

    return 0;
}
