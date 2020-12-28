#include "pch.h"
#include "Helper.h"

static std::string YEAR_NULL = "0000";
static std::string MONTH_NULL = "00";
static std::string DAY_NULL = "00";

std::vector<std::string> Helper::split(std::string string, char delim) {
    std::vector<std::string> split;
    std::size_t current, previous = 0;
    try {
        current = string.find(delim);
        while (current != std::string::npos) {
            split.push_back(string.substr(previous, current - previous));
            previous = current + 1;
            current = string.find(delim, previous);
        }
        split.push_back(string.substr(previous, current - previous));
    } catch (std::exception) {
        split = std::vector<std::string>{ YEAR_NULL, MONTH_NULL, DAY_NULL };
    }
    return split;
}
time_t Helper::stringToTime_t(std::string date) {
    try {
        std::vector<std::string> cont = Helper::split(date, '-');
        if (cont[0] == "1970") {
            return (time_t)(-1);
        }
        struct tm tm_ = { 0 };
        tm_.tm_year = atoi(cont[0].c_str()) - 1900;
        tm_.tm_mon = atoi(cont[1].c_str()) - 1;
        tm_.tm_mday = atoi(cont[2].c_str());
        return mktime(&tm_);
    } catch (std::exception){}
    return (time_t)(-1);
}
std::string Helper::time_tToString(time_t time) {
    std::tm* ptm = localtime(&time);
    char buffer[32];
    strftime(buffer, 32, "%Y-%m-%d", ptm);
    return buffer;
}
std::string Helper::time_tToString(time_t time, std::string format) {
    std::tm* ptm = localtime(&time);
    char buffer[32];
    strftime(buffer, 32, format.c_str(), ptm);
    return buffer;
}