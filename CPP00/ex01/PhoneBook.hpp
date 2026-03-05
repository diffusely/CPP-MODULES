#pragma once

#include "Contact.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void run();

private:
	// Private functions
	void add();
	void search();
	void exit();

	std::string addDote(const std::string &str);
	void printTable();
	void findIndex();

private:
	// Contacts
	Contact m_contacts[8];

private:
	// Exit and Contact start
	bool m_end;
	int m_start;
	int m_count;
};