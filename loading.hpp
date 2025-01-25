#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void delayRealTime(int milliseconds) {
    // บันทึกเวลาเริ่มต้น
    auto start = chrono::steady_clock::now();

    while (true) {
        // เวลาปัจจุบัน
        auto now = chrono::steady_clock::now();

        // คำนวณเวลาที่ผ่านไป
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - start).count();

        // ออกจากลูปเมื่อเวลาผ่านไปถึงที่กำหนด
        if (elapsed >= milliseconds) {
            break;
        }
    }
}

void Loadingber(){
    char a = 177, b = 219;
    cout << "\033[92m\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\tLoading....... \n";
    cout << "\n\t\t\t\t\t";
    for(int n=0;n<=29;n++){
    cout << a;
    }
    cout << "\r";
    cout << "\t\t\t\t\t";
    for(int n=0;n<=29;n++){
    cout << b;
    delayRealTime(50);
    }
    cout << "\033[0m";
    system("cls");
}