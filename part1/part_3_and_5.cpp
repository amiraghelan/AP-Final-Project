#include <iostream>
#include <stdexcept>
#include <ctime>
#include <vector>
#include "VectorDoublePointer.h"
#include "Vector.h"

#include <chrono>

#define SAMPLING_NO 10
using namespace std;

class TimerUtil
{

    std::chrono::high_resolution_clock::time_point start;
    clock_t cstart;
    std::chrono::high_resolution_clock::time_point end;
    clock_t cend;

public:
    void startRecord()
    {
        start = std::chrono::high_resolution_clock::now();
        cstart = std::clock();
    }
    void stopRecord()
    {
        end = std::chrono::high_resolution_clock::now();
        cend = std::clock();
    }
    auto timeDif()
    {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        return duration.count();
    }

    double diffInCpuClocks()
    {
        return cend - cstart;
    }
};

class Data
{

public:
    std::vector<char> d;
    int sizeInMb;
    Data() {}
    Data(int size) : d(size * 1024 * 1024)
    {
        sizeInMb = size;
    }
    Data(const Data &data) : d(data.sizeInMb * 1024 * 1024)
    {
        sizeInMb = data.sizeInMb;
    }
};

int main()
{
    TimerUtil t;

    double customVectorTime = 0;
    double customVectorClock = 0;

    double customVectorPointerTime = 0;
    double customVectorPointerClock = 0;

    double VectorTime = 0;
    double VectorClock = 0;


    //testing part one

    // for (int i = 0; i < SAMPLING_NO; i++)
    // {
    //     CustomVectorPointer<Data> v;
    //     t.startRecord();
    //     cout << "Test number " << i << endl;
    //     for (int j = 0; j < 250; j++)
    //     {
    //         v.pushBack(Data(4));
    //         cout << "number added " << j << endl;
    //     }
    //     t.stopRecord();
    //     customVectorPointerTime += t.timeDif();
    //     customVectorPointerClock += t.diffInCpuClocks();
    // }
    // cout << "============================================" << endl;
    // for (int i = 0; i < SAMPLING_NO; i++)
    // {
    //     CustomVector<Data> v;
    //     t.startRecord();
    //     cout << "Test number " << i << endl;
    //     for (int j = 0; j < 250; j++)
    //     {
    //         v.pushBack(Data(4));
    //         cout << "number added " << j << endl;
    //     }
    //     t.stopRecord();
    //     customVectorTime += t.timeDif();
    //     customVectorClock += t.diffInCpuClocks();
    // }
    // cout << "============================================" << endl;

    // for (int i = 0; i < SAMPLING_NO; i++)
    // {
    //     vector<Data> v;
    //     t.startRecord();
    //     cout << "Test number " << i << endl;
    //     for (int j = 0; j < 250; j++)
    //     {
    //         v.push_back(Data(4));
    //         cout << "number added " << j << endl;
    //     }
    //     t.stopRecord();
    //     VectorTime += t.timeDif();
    //     VectorClock += t.diffInCpuClocks();
    // }

    // cout << "average info for inserting 4Mb data 300 time: " << endl;
    // cout << "CustomVector:        Time in(sec): " << customVectorTime / (SAMPLING_NO * 1000) << "  CLOCKS: " << customVectorClock / SAMPLING_NO << endl;
    // cout << "CustomVectorPointer: Time in(sec):" << customVectorPointerTime / (1000 * SAMPLING_NO) << "  CLOCKS: " << customVectorPointerClock / SAMPLING_NO << endl;
    // cout << "vector:              Time in(sec): " << VectorTime / (SAMPLING_NO * 1000) << "  CLOCKS: " << VectorClock / SAMPLING_NO << endl;


    //testing part 2
    for (int i = 0; i < SAMPLING_NO; i++)
    {
        cout << "Test number " << i << endl;
        CustomVectorPointer<Data> v;

        t.startRecord();
        v.pushBack(Data(1000));
        t.stopRecord();
        customVectorPointerTime += t.timeDif();
        customVectorPointerClock += t.diffInCpuClocks();
    }
    for (int i = 0; i < SAMPLING_NO; i++)
    {
        cout << "Test number " << i << endl;
        CustomVector<Data> v;

        t.startRecord();
        v.pushBack(Data(1000));
        t.stopRecord();

        customVectorTime += t.timeDif();
        customVectorClock += t.diffInCpuClocks();
    }
    // for (int i = 0; i < SAMPLING_NO; i++)
    // {
    //     cout << "Test number " << i << endl;
    //     vector<Data> v;

    //     t.startRecord();
    //     v.push_back(Data(1000));
    //     t.stopRecord();

    //     VectorTime += t.timeDif();
    //     VectorClock += t.diffInCpuClocks();
    // }

    cout << "average info for inserting 4Mb data 300 time: " << endl;
    cout << "CustomVector:        Time in(sec): " << customVectorTime / (SAMPLING_NO * 1000) << "  CLOCKS: " << customVectorClock / SAMPLING_NO << endl;
    cout << "CustomVectorPointer: Time in(sec):" << customVectorPointerTime / (1000 * SAMPLING_NO) << "  CLOCKS: " << customVectorPointerClock / SAMPLING_NO << endl;
    // cout << "vector:              Time in(sec): " << VectorTime / (SAMPLING_NO * 1000) << "  CLOCKS: " << VectorClock / SAMPLING_NO << endl;

    return 0;
}