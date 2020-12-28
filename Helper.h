#ifndef HELPER_H
#define HELPER_H

#pragma once
class Helper{
public:
	static std::vector<std::string> split(std::string string, char delim = ' ');
	static time_t stringToTime_t(std::string date);
	static std::string time_tToString(time_t time);
	static std::string time_tToString(time_t time, std::string format);
};

#endif // !HELPER_H