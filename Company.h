#ifndef COMPANY_H
#define COMPANY_H

#pragma once

class Company{
private:
	int id;
	std::string name;
public:
	Company();
	Company(int id, std::string name);

	void setId(int id);
	int getId();
	void setName(std::string name);
	std::string getName();
};

#endif // !COMPANY_H