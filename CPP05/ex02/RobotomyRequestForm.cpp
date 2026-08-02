#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("def") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	this->_target = other._target;
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& e) const
{
	if (!getSigned())
		throw AForm::NotSignedExeption();
	if (e.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	static int	i;
	if (i % 2 == 0)
	{
		std::cout << "Bzzzzzzzzzzzzzzz" << std::endl;
		std::cout << this->_target << " has been robotomized successfully🤖" << std::endl;
	}
	else
		std::cout << "Robotomy failed ❌" << std::endl;

}