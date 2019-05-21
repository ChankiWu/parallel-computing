#include<iostream>
#include<math.h>
#include<time.h>
#include<fstream>
#include<thread>
#include<mutex>
#include<vector>

#include<unistd.h>

using namespace std;

long counter = 2;
//long limit = pow(10,9);
long limit = 100;
mutex m;

bool isPrime(int n){
    for(int i=2; i <= sqrt(n);++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}


void primePrint(){

    long x = 0;

    while(counter < limit){

        //safely increase the shared counter in this concurrent execution
        m.lock();
        x = counter;
        counter += 1;
        m.unlock();

        if(isPrime(x)){ 
            printf("%ld ", x);
        }
    }

}

int main(){


	struct timespec start, finish;
    double elapsed;

    //create a group of threads
    vector<thread> tv;

    clock_gettime(CLOCK_MONOTONIC, &start);
    
    for(int i=0;i<4;i++){
        tv.emplace_back(&primePrint);
    }

    for(thread& t : tv){
        t.join();
    }

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    cout << "\nTotal Time : " << elapsed << " s" << endl;

    //write the result

    /*
    ofstream outfile;
    outfile.open("result_t4.txt");

    outfile<<"4 Thread: "<<elapsed<<" s"<<endl;
    outfile.close();
    */

    return 0;
}
