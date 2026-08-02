#include "AForm.h"

AForm::AForm(void): _name("Unknown"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {}

AForm::~AForm() {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign > LOW_GRADE || this->_gradeToExecute > LOW_GRADE)
		throw AForm::GradeTooLowException();
	else if (this->_gradeToSign < HIGH_GRADE || this->_gradeToExecute < HIGH_GRADE)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& copy): _name(copy._name), _isSigned(false), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	if (copy._gradeToSign > LOW_GRADE || copy._gradeToExecute > LOW_GRADE)
		throw AForm::GradeTooLowException();
	else if (copy._gradeToSign < HIGH_GRADE || copy._gradeToExecute < HIGH_GRADE)
		throw AForm::GradeTooHighException();
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		if (other._gradeToSign > LOW_GRADE || other._gradeToExecute > LOW_GRADE)
			throw AForm::GradeTooLowException();
		else if (other._gradeToSign < HIGH_GRADE || other._gradeToExecute < HIGH_GRADE)
			throw AForm::GradeTooHighException();
		const_cast<std::string&>(this->_name) = other._name;
		const_cast<int&>(this->_gradeToSign) = other._gradeToSign;
		const_cast<int&>(this->_gradeToExecute) = other._gradeToExecute;
	}
	return (*this);
}

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw Bureaucrat::GradeTooLowException();
	this->_isSigned = true;
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade is too low!");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade is too high!");
}

const char*	AForm::NotSignedExeption::what() const throw()
{
	return ("AForm: Form is not signed!");
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << "Name: " << f.getName() << "\n"
		<< "Signed: " << (f.getSigned() == true ? "yes" : "no") << "\n"
		<< "Grade to sign: " << f.getGradeToSign() << "\n"
		<< "Grade to execute: " << f.getGradeToExecute() << "\n"
		<< std::endl;
	return (os);
}