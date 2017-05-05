#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

const int N = 30000;
const int trials = 20;


int sequentialSearch(const int* A, int n, int K);

//global results variable
int results[N];

double average;

int main()
{
    cout << "***Sequential Search" << endl;
    //create an array of ints with N values
    int* A = new int[N];
    //fill A with random ints between 0 and N*10
    for(int i = 0; i < N; i++){
        A[i] = rand() % (N*10);
    }

    //calculate keys to search for outside of runtime
    for (int i = 0; i < N; i++){
        results[i] = rand() % (N*10);
    }

    for (int i = 0; i < trials; i++){
        //get start time
        clock_t start_time = clock();

        for(int i = 0; i < N; i++){
            results[i] = sequentialSearch(A,N,results[i]);
        }

        clock_t end_time = clock();

        double elapsed_time = (end_time - start_time) / double(CLOCKS_PER_SEC) / double(N) * 1000.0;

        cout << "Time taken to run N (" << N << ") operations was " << elapsed_time << endl;
        average += elapsed_time;
    }
     average = average / trials;
     cout << "Average time was :" << average << endl;

}

int sequentialSearch(const int* A, int n, int K){
        int i = 0;
        while( i < n && A[i] != K){
            i++;
        }
        if(i < n){
            return i;
        }
        else{
            return -1;
        }
}
