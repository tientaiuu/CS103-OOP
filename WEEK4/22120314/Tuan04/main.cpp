#include "MyTime.h"

int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    CMyTime time1;
    CMyTime time2(5, 15, 20);

    time1.Input(inputFileName);

    time1.Output(outputFileName);
    time2.Output(outputFileName);

    ++time1;
    --time2;
    time1.Output(outputFileName);
    time2.Output(outputFileName);

    CMyTime sum = time1 + time2;
    CMyTime sub = time1 - time2;

    sum.Output(outputFileName);
    sub.Output(outputFileName);
    
    time1 += 5;
    time1.Output(outputFileName);

    if (time1 >  time2) {
        cout << "Time 1 > Time 2." << endl;
    }
    else if (time1 < time2) {
        cout << "Time 1 < Time 2." << endl;
    }
    else {
        cout << "Time 1 = Time 2." << endl;
    }

    return 0;
}
