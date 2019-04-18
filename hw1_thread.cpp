#include<iostream>
#include<math.h>
#include<time.h>
#include<fstream>
#include<thread>
#include<mutex>
#include<vector>

#include<unistd.h>

using namespace std;

long counter = 3;
//long limit = 100;
long limit = pow(10,10);
mutex m;

bool isPrime(int n){
    for(int i=3; i <= n/2;i += 2){
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
        counter += 2;
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
    
    for(int i=0;i<8;i++){
        tv.emplace_back(&primePrint);
    }

    for(thread& t : tv){
        t.join();
    }

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    elapsed = elapsed / 60;

    cout << "\nTotal Time : " << elapsed << " min" << endl;

    //write the result

    ofstream outfile;
    outfile.open("result_t8.txt");

    outfile<<"8 Thread: "<<elapsed<<" min"<<endl;
    outfile.close();

    return 0;
}
