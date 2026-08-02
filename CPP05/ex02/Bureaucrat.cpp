#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGH_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
{
	if (copy._grade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (copy._grade < HIGH_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = copy._grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		const_cast<std::string&>(this->_name) = other._name;
		if (other._grade > LOW_GRADE)
			throw Bureaucrat::GradeTooLowException();
		else if (other._grade < HIGH_GRADE)
			throw Bureaucrat::GradeTooHighException();
		this->_grade = other._grade;
	}
	return (*this);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGH_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < HIGH_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low!");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high!");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	std::cout << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}