/************************************************************************************
                  ** C **
Module: ���������� ��������.
Author: ������ ������ <a2.zaytsev@neroelectronics.by>
************************************************************************************/

#include "timing.h"
#include "supplyMonitor.h"

//===================================================================================

#pragma pack(4)
typedef struct
{
    const uint32_t sentinelBottom;      // ���������� ��� ����������� ������ ������
    volatile uint64_t millisCounter;    // ������� ���������� �� �� ������ ���������
    const uint32_t sentinelTop;
                                        // ���������� ��� ����������� ������ ������
} LocalVariables_s;

static LocalVariables_s timing_var =
{
    .sentinelBottom = SENTINEL_BOTTOM,
    .millisCounter = 0,
    .sentinelTop = SENTINEL_TOP,
};

//===================================================================================

void timing_processTimer()
{
    timing_var.millisCounter += supply_getSysTickPeriod();
}

uint64_t timing_millis()
{
    return timing_var.millisCounter;
}

uint64_t timing_msElapsed(
    uint64_t millis)
{
    return (timing_var.millisCounter - millis);
}

uint64_t timing_seconds()
{
    return (timing_var.millisCounter / 1000);
}

uint64_t timing_secElapsed(
    uint64_t seconds)
{
    return (timing_seconds() - seconds);
}

//===================================================================================