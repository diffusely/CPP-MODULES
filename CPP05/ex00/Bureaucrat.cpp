#include "Bureaucrat.h"

// Bureaucrat::Bureaucrat()
// {}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
	: _name(copy._name)
{
	if (copy._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (copy._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = copy._grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other) {
		const_cast<std::string&>(this->_name) = other._name;
		if (other._grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (other._grade < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade = other._grade;
	}
	return (*this);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += 1;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low!");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	std::cout << b.getName() << " bureaucrat grade " << b.getGrade() << "\n";
	return (os);
}