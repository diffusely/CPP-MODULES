#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: m_end(false)
	, m_start(0)
{

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add()
{
	if (m_start == 8)
		m_start = 0;

	std::cout << "first name:";
	std::cin >> m_contacts[m_start].firsname;
	std::cout << "last name:";
	std::cin >> m_contacts[m_start].lastName;
	std::cout << "nick name:";
	std::cin >> m_contacts[m_start].nickName;
	std::cout << "phone number:";
	std::cin >> m_contacts[m_start].phoneNumber;

	++m_start;

}
void PhoneBook::search()
{
}

void PhoneBook::exit()
{
	m_end = true;
}

void PhoneBook::run()
{
	while (!m_end) {

		std::string input;
		std::cin >> input;

		if (input == "ADD")
				add();
		else if (input == "SEARCH")
				search();
		else if (input == "EXIT")
				exit();
	}
}
