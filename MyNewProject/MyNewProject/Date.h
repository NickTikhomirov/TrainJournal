#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

// СУКА НЕ СТИРАЙ ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ, А ТО Я УЖЕ САМ НЕ ЕБУ КАК ЭТО РАБОТАЕТ
int startDate;
int startMon;

// ЭТО НА 2020 ГОД КОЛ-ВО ДНЕЙ В МЕСЯЦАХ
int dayInMonths[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
// ВОТ ТУТ ЦИФЕРКИ - ЭТО ДЕНЬ НЕДЕЛИ. ПН - 1, ВТ - 2, ..., ВС-0
int startDayInMonth[12] = {3,6,0,3,5,1,3,6,2,4,0,2};

// ВОТ СЮДА ОНИ ВСЕ ЛЕТЯТ
std::vector<tm> dates;

void RandomDateGenerator(int N, int tm_sec, int tm_yday, int tm_year, int tm_isdst) {

    int tm_min;
    int tm_hour;
    int iday;
    int tm_mon = startMon;
    int tm_mday = startDate;

    //----генерим время (часы и минуты)
    tm_min = rand() % 59;
    tm_hour = 10 + rand() % 8;
    //---------------------------------

    //-------тут определяем день недели, НЕ РЕДАЧИТЬ, А ТО ВСЕ ПОЛЕТИТ
    iday = startDate;
    while (iday > 6 - startDayInMonth[startMon]) {
        iday -= 7;
    }
    iday -= 1;
    int someday = startDayInMonth[startMon] + iday;
    if (someday < 0) {
        someday = 7 + someday;
    }
    //-----Заносим первый день
    const struct tm startDateInTm = {tm_sec, tm_min, tm_hour, startDate, startMon, tm_year, someday, tm_yday, tm_isdst};
    dates.push_back(startDateInTm);
    //-------------------------------------------

    //------Генерим новый день-----------------
    for(int i = 0; i < N - 1; i++) {
        //----------находим новый день в месяце
        tm_mday += 2 + rand() % 3;
        //--------проверяем, а не след ли месяц
        if(tm_mday > dayInMonths[tm_mon]){
            tm_mday = tm_mday - dayInMonths[tm_mon];
            tm_mon++;
        }
        //-------ну тут время делаем
        tm_min = rand() % 59;
        tm_hour = 10 + rand() % 8;

        //--------Тут определяем день недели, НЕ РЕДАЧИТЬ, А ТО ВСЕ ПОЛЕТИТ
        iday = tm_mday;
        while (iday > 6 - startDayInMonth[tm_mon]) {
            iday -= 7;
        }
        iday -= 1;
        int tm_wday = startDayInMonth[tm_mon] + iday;
        if (tm_wday < 0) {
            tm_wday = 7 + tm_wday;
        }
        //---Заносим дни
        const struct tm generatedDate = {tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst};
        dates.push_back(generatedDate);
    }
    //------------------------------------

}

//-------А это для вывода нахуй!--КУДА?????? ДА КУДА ХОЧЕШЬ НАХУЙ НАХУЙ!
std::string DateToString(std::vector<tm> dates){
    std::string str = "";
    return str;
}

int main(){
    srand(time(0));
    /*
     * Изначально есть период отсчета, определяем его в tm
     * после генерим два дня в неделе
     * узнаем для них число и месяц
     * генерим время
     * готово
     */

    //base:
    std::time_t curtime = std::time(nullptr);
    int tm_sec = 0;
    int tm_yday = std::localtime(&curtime)->tm_yday;
    int tm_year= std::localtime(&curtime)->tm_year;
    int tm_isdst = std::localtime(&curtime)->tm_isdst;
    //---


    int N = 30;   // ВОТ ЭТО СКОЛЬКО ДНЕЙ ХОТИМ
    startDate = 23; // ВОТ ЭТО ДАТА КОГДА МЫ НАЧИНАЕМ ЗАНИМАТЬСЯ (ОНА ВХОДИТ В N)
    startMon = 3; // ВОТ ЭТО НАЧАЛЬНЫЙ МЕСЯЦ, КОГДА МЫ ФИГАРИТЬ НАЧИНАЕМ

    RandomDateGenerator(N, tm_sec, tm_yday, tm_year, tm_isdst);
    //-----ВОТ ТАК В КОНСОЛЬ-------
    for(auto it : dates)
        std::cout << std::asctime(&it) << std::endl;
    //---НЕ ЗАБУДЬ ССЫЛКУ ЕБУЧУЮ 
    return 0;
}
