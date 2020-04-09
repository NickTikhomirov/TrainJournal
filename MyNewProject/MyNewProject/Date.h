#pragma once
#include <string>
#include <vector>
#include <ctime>

int startDate;
int startMon;
std::string weekday[] = { "Воскресенье", "Понедельник", "Вторник", "Среда","Четверг", "Пятница", "Суббота"};

std::vector<time_t> dates;

//Рандом дат, НЕ ТРОГАТЬ 
void RandomDateGenerator(int N, std::time_t curtime) {

    tm * timeinfo = std::localtime(&curtime);
    timeinfo->tm_min = rand() % 59;
    timeinfo->tm_hour = 10 + rand() % 8;
    timeinfo->tm_mday = startDate;
    timeinfo->tm_mon = startMon;
    dates.push_back(std::mktime(timeinfo));

    bool zashel = false;
    tm * somedate = std::localtime(&curtime);
    for(size_t i = 0; i < N-1; i++) {

        somedate->tm_min = rand() % 59;
        somedate->tm_hour = 10 + rand() % 8;
        if(!zashel) {
            somedate->tm_mday = startDate+ 2 + rand() % 3;
            zashel = true;
        }
        somedate->tm_mday = somedate->tm_mday + 2 + rand() % 3;
        std::mktime(somedate);
        dates.push_back(std::mktime(somedate));
    }
}

//функция парсинга, МОЖНО ВИДОИЗМЕНЯТЬ
std::vector<std::string> parseDateToString(std::vector<time_t > datesToParse){
    std::vector<std::string> parsedData;
    std::string str = "";
    for (auto it : datesToParse){
        str =   std::to_string(std::localtime(&it)->tm_mday) + "." +
                std::to_string(std::localtime(&it)->tm_mon) + "." +
                std::to_string(std::localtime(&it)->tm_year + 1900)  + "\t" +
                weekday[std::localtime(&it)->tm_wday] + "\t\t" +
                std::to_string(std::localtime(&it)->tm_hour) + ":" +
                std::to_string(std::localtime(&it)->tm_min) + "\n";
        parsedData.push_back(str);
    }
    return parsedData;
}

int main(){
    srand(time(0));

    std::time_t curtime = std::time(nullptr);

    //ВОТ ТУТ СКОЛЬКО НАМ НУЖНО ЗАНЯТИЙ
    int N = 30;
    
    //ЧИСЛО МЕСЯЦА НАЧАЛА 
    startDate = 30;
    //МЕСЯЦ НАЧАЛА
    startMon = 3;

    //НУ СОБСНА РАБОТА
    RandomDateGenerator(N, curtime);

    //ТУТ ПОЛУЧАЕМ СТРОКУ ЕЕ ПИХАЕМ КУДА УГОДНО
    std::vector<std::string> PD = parseDateToString(dates);

    return 0;
}
