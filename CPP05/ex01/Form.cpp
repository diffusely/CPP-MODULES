#include "Form.h"

Form::Form()
	: _name("Unknown")
	, _isSigned(false)
	, _gradeToSign(1)
	, _gradeToExecute(1)
{}

Form::~Form() {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name)
	, _isSigned(false)
	, _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > LOW_GRADE || _gradeToExecute > LOW_GRADE)
		throw Form::GradeTooLowException();
	else if (_gradeToSign < HIGH_GRADE || _gradeToExecute < HIGH_GRADE)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& copy)
	: _name(copy._name)
	, _isSigned(false)
	, _gradeToSign(copy._gradeToSign)
	, _gradeToExecute(copy._gradeToExecute)
{
	if (copy._gradeToSign > LOW_GRADE || copy._gradeToExecute > LOW_GRADE)
		throw Form::GradeTooLowException();
	else if (copy._gradeToSign < HIGH_GRADE || copy._gradeToExecute < HIGH_GRADE)
		throw Form::GradeTooHighException();
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other) {
		if (other._gradeToSign > LOW_GRADE || other._gradeToExecute > LOW_GRADE)
			throw Form::GradeTooLowException();
		else if (other._gradeToSign < HIGH_GRADE || other._gradeToExecute < HIGH_GRADE)
			throw Form::GradeTooHighException();
		const_cast<std::string&>(_name) = other._name;
		const_cast<int&>(_gradeToSign) = other._gradeToSign;
		const_cast<int&>(_gradeToExecute) = other._gradeToExecute;
	}
	return (*this);
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getGradeToSign())
		throw Bureaucrat::GradeTooLowException();
	_isSigned = true;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low!");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high!");
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << "Name: " << f.getName() << "\n"
		<< "Signed: " << (f.getSigned() == true ? "yes" : "no") << "\n"
		<< "Grade to sign: " << f.getGradeToSign() << "\n"
		<< "Grade to execute: " << f.getGradeToExecute() << "\n"
		<< "\n";
	return (os);
}