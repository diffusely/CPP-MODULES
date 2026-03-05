#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: m_end(false)
	, m_start(0)
	, m_count(0)
{}

PhoneBook::~PhoneBook()
{}

std::string PhoneBook::addDote(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::add()
{
    std::string input;

    do {
        std::cout << "First name: ";
        std::getline(std::cin, input);
        if (input.empty()) 
			std::cout << "This field cannot be empty!\n";
    } while (input.empty());
    m_contacts[m_start].setFirstName(input);

    do {
        std::cout << "Last name: ";
        std::getline(std::cin, input);
        if (input.empty())
			std::cout << "This field cannot be empty!\n";
    } while (input.empty());
    m_contacts[m_start].setLastName(input);

    do {
        std::cout << "Nick name: ";
        std::getline(std::cin, input);
        if (input.empty())
			std::cout << "This field cannot be empty!\n";
    } while (input.empty());
    m_contacts[m_start].setNickName(input);

    do {
        std::cout << "Phone number: ";
        std::getline(std::cin, input);
        if (input.empty())
			std::cout << "This field cannot be empty!\n";
    } while (input.empty());
    m_contacts[m_start].setPhoneNumber(input);

    do {
        std::cout << "Darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty())
			std::cout << "This field cannot be empty!\n";
    } while (input.empty());
    m_contacts[m_start].setDarkestSecret(input);

    m_start = (m_start + 1) % 8;
	if (m_count < 8)
		++m_count;
}

void PhoneBook::printTable()
{
	std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << "\n";

    for (int i = 0; i < m_count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << addDote(m_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << addDote(m_contacts[i].getLastName()) << "|"
                  << std::setw(10) << addDote(m_contacts[i].getNickName()) << "\n";
    }
}

void PhoneBook::findIndex()
{
	int index;
	do {
		
		std::cout << "input index: ";
		std::cin >> index;

		if (std::cin.eof())
			return ;
		if (std::cin.fail()) {
    	    std::cin.clear();
    	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	    std::cout << "Invalid input. Enter a number.\n";
		} else break;
	
	} while(1);

	if (index < 0 || index >= m_count) {
		std::cout << "Invalid index.\n";
		return ;
	}

	std::cout << "First name: " << m_contacts[index].getFirstName() << "\n";
    std::cout << "Last name: " << m_contacts[index].getLastName() << "\n";
    std::cout << "Nick name: " << m_contacts[index].getNickName() << "\n";
    std::cout << "Phone number: " << m_contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << m_contacts[index].getDarkestSecret() << "\n";
}

void PhoneBook::search()
{
	printTable();
	findIndex();
}

void PhoneBook::exit()
{
	m_end = true;
}

void PhoneBook::run()
{
	std::string input;

	while (!m_end) {

		std::getline(std::cin, input);

		if (std::cin.eof())
			break ;

		if (input == "ADD")
				add();
		else if (input == "SEARCH")
				search();
		else if (input == "EXIT")
				exit();
	}
}
