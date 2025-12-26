#pragma once

#include <iostream>
#include <string>

class PhoneBook
{
	struct Contact
	{
		std::string firsname;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
	};

public:
	PhoneBook();
	~PhoneBook();

	void add();
	void search();
	void exit();
	void run();

private:
	// Contacts
	Contact m_contacts[8];

private:
	// Exit and Contact start
	bool m_end;
	int m_start;

};