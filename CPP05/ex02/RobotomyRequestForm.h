#ifndef _RRF_HPP_
# define _RRF_HPP_

# include "AForm.h"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		const std::string&		getTarget(void) const;
		void					execute(const Bureaucrat& e) const;
};

#endif