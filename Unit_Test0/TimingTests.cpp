/************************************************************************************
                  ** CPP **
Module: ������������ ������ ���������� ��������.

************************************************************************************/
#include <iostream>
#include "TimingTest.h"
#include <fstream>
//===================================================================================
#include "timing.h"

using namespace std;

//===================================================================================

ofstream fout("report.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt


void timing_msElapsed_Test() {//��������� ������� timing_msElapsed
    int n = 10;
    uint64_t millis = timing_millis();
    for (int i = 0; i < n; i++) {
        timing_processTimer();
    }
    millis = timing_msElapsed(millis);
    if (millis == n) {
        cout << "timing_msElapsed_Test is OK" << endl;
        fout << "timing_msElapsed_Test is OK\n";
    }
    else {
        cout << "timing_msElapsed_Test is NOT OK" << endl;
         fout << "timing_msElapsed_Test is NOT OK\n";
    }
    

}

void timing_seconds_Test()//��������� ������� ������
{
    uint64_t seconds = 0;
    uint64_t millis = timing_millis();
    for (int i = millis; i < millis + 1000; i++) {
        timing_processTimer();
    }
    seconds = timing_seconds();

    if (seconds == 1) {
        cout << "timing_seconds_Test is OK" << endl;
         fout << "timing_seconds_Test is OK\n";
    }
    else{
     cout << "timing_seconds_Test is NOT OK" << endl;
      fout << "timing_seconds_Test is NOT OK\n";
    } 

    fout.close(); // закрываем файл
}


void PreSetTest()//��������� ��������� �������
{
    if (!(timing_millis() or timing_msElapsed(0) or timing_seconds() or timing_secElapsed(0))) {
        cout << "PreSetTest is OK" << endl;
         fout << "PreSetTest is OK\n";
    }
    else {
        fout << "PreSetTest is NOT OK\n";
        cout << "PreSetTest is NOT OK" << endl;
    }
}

void timing_processTimer_TEST()//��������� ��� ������� ��������
{
    uint64_t ticks_1 = timing_millis();
    timing_processTimer();
    uint64_t ticks_2 = timing_millis();
    if ((ticks_2 - ticks_1) == 1) {
        cout << "timing_processTimer_TEST is OK" << endl;
        fout << "timing_processTimer_TEST is OK\n";
    }
    else {
        cout << "timing_processTimer_TEST is NOT OK" << endl;
        fout << "timing_processTimer_TEST is NOT OK\n" << endl;
    }
        
}
//===================================================================================
