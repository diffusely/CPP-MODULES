#pragma once

#include <string>

class Contact
{
public:

    void setFirstName(std::string str);
    void setLastName(std::string str);
    void setNickName(std::string str);
    void setPhoneNumber(std::string str);
    void setDarkestSecret(std::string str);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
};