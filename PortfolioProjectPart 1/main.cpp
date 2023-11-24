#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mut;

void countUpandDown(int& x){
    mut.lock(); //locks method
    if (x == 0){ //counts up
        while (x < 20){
            x++;
            cout << x << endl; //prints x
        }
    }
    else{
        while (x > 0){
            x--;
            cout << x << endl;
        }
    }
    mut.unlock(); //unlocks method
}

int main()
{
    int x = 0;
    try{
        std::thread threadOne(countUpandDown, std::ref(x)); //makes threadOne
        threadOne.join(); //joins threadOne, forces threadOne to finish
        std::thread threadTwo(countUpandDown, std::ref(x)); //makes threadTwo
        threadTwo.join(); //joins threadTwo
    }
    catch(std::exception &e){ //catches all errors and prints to log
        cout << "Fatal error in program's execution. See log for details." << endl;
        cerr << "One or more threads failed to start." << endl; //if thread fails to open or close, this is printed
    }
}
