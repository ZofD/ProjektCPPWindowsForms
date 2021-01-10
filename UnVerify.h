#ifndef UNFERIFY_H
#define UNFERIFY_H

#pragma once
class UnVerify{
public:
	static User logIn(std::string login, std::string password);
	static bool registration(std::string login, std::string password);
};

#endif // !UNFERIFY_H