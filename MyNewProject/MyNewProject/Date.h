#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <chrono>
#include <ctime>

int startDate;
int startMon;

int dayInMonths[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int startDayInMonth[12] = {3,6,0,3,5,1,3,6,2,4,0,2};

tm RandomDateGenerator(int tm_sec, int tm_yday, int tm_year, int tm_isdst) {

    int tm_min = rand() % 59;
    int tm_hour = 10 + rand() % 8;
    int tm_mon = rand() % 11;

    int days = dayInMonths[tm_mon] - 1;
    int tm_mday = 1 + rand() % days;
    int iday = tm_mday;
    while (iday > 6 - startDayInMonth[tm_mon]) {
        iday -= 7;
    }
    iday -= 1;
    int tm_wday = startDayInMonth[tm_mon] + iday;
    if(tm_wday < 0) {
        tm_wday = 7 + tm_wday;
    }

    const struct tm a = {tm_sec,tm_min,tm_hour,tm_mday,tm_mon,tm_year,tm_wday,tm_yday,tm_isdst};
    return a;
}

std::string DateToString(const struct tm Date){
    std::string str = "";
    return str;
}

int main(){
    srand(time(0));


    //base:
    std::time_t curtime = std::time(nullptr);
    int tm_sec = 0;
    int tm_yday = std::localtime(&curtime)->tm_yday;
    int tm_year= std::localtime(&curtime)->tm_year;
    int tm_isdst = std::localtime(&curtime)->tm_isdst;
    //---

    startDate = 23;
    startMon = 3;
    //int tm_min=23;
    //int tm_hour=12;
    //int tm_mday=9;
    //int tm_mon=3;
    //int tm_wday=4;
    //const struct tm a = {tm_sec,tm_min,tm_hour,tm_mday,tm_mon,tm_year,tm_wday,tm_yday,tm_isdst};
    //std::cout << std::asctime(&a) << std::endl;
    const struct tm b = RandomDateGenerator(tm_sec, tm_yday, tm_year, tm_isdst);
    std::cout << std::asctime(&b) << std::endl;
    return 0;
}