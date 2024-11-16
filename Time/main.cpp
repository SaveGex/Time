#include "Time.h"

using namespace std; 

int main() {
    try {
        Time t1(-5, 30, 20); // ���������� ��� ������� �������
    }
    catch (const exception& e) {
        cerr << "Caught exception in main: " << e.what() << endl;
    }

    try {
        Time t2(1, 30, 80); // ����������� ��������
        cout << t2 << endl;

        Time t3;
        t3 += t2; // ��������� ����
        cout << t3 << endl;

        t3 -= Time(0, 120, 0); // ³������� ����
        cout << t3 << endl;
    }
    catch (const exception& e) {
        cerr << "Caught exception in main: " << e.what() << endl;
    }

    return 0;
}
