#include "Time.h"

using namespace std; 

int main() {
    try {
        Time t1(-5, 30, 20); // Негативний час викликає виняток
    }
    catch (const exception& e) {
        cerr << "Caught exception in main: " << e.what() << endl;
    }

    try {
        Time t2(1, 30, 80); // Автоматична корекція
        cout << t2 << endl;

        Time t3;
        t3 += t2; // Складання часу
        cout << t3 << endl;

        t3 -= Time(0, 120, 0); // Віднімання часу
        cout << t3 << endl;
    }
    catch (const exception& e) {
        cerr << "Caught exception in main: " << e.what() << endl;
    }

    return 0;
}
