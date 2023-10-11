#ifndef TimeHandling_H_
#define TimeHandling_H_

#include <chrono> //NOLINT (build/c++11)
#include <iostream>

using namespace std;

//Timer class decloration
class Timer {
    public:
    double runTime;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point Reset();
    double CurrentTime();
    friend ostream & operator<<(ostream &out, Timer &ct);
};
//reset funtion starts the clock timer
chrono::high_resolution_clock::time_point Timer::Reset() {
    return start;
}
//CurrentTime function returns the runtime of the code segment
double Timer::CurrentTime() {
    //ends timer and assigns value to variable end
    auto end = chrono::high_resolution_clock::now();
    //finds runtime value from start to end in micro seconds
    runTime = chrono::duration<double, micro>(end - start).count();
    return runTime;
}
//overload output operator to print out runtime
ostream & operator<<(ostream &out, Timer &ct) {
    out << "CPU time: " << ct.CurrentTime() << " microseconds";
    return out;
}



#endif // TimeHandling_H_