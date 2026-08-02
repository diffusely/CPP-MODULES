#ifndef _PPF_HPP_
# define _PPF_HPP_

# include "AForm.h"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		const std::string&		getTarget(void) const;
		void					execute(const Bureaucrat& e) const;
};

#endif