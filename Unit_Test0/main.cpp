
//===================================================================================
#include "TimingTest.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()

{
    ofstream fout("report.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    PreSetTest();
    timing_processTimer_TEST();
    timing_msElapsed_Test();
    timing_seconds_Test();
    fout.close(); // закрываем файл
    system("pause");
    
}

