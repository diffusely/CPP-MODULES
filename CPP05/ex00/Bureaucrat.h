#pragma once

#include <iostream>
#include <exception>
#include <string>

# define HIGH_GRADE 1
# define LOW_GRADE 150

class Bureaucrat
{
public:

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);
	int getGrade() const;
	void setGrade(int grade);
	const std::string& getName() const;
	void incrementGrade();
	void decrementGrade();


	class GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

private:
	const std::string _name;
	int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
