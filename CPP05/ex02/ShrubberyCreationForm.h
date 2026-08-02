#ifndef _SCF_HPP_
# define _SCF_HPP_

# include "AForm.h"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		const std::string&		getTarget(void) const;
		void					execute(const Bureaucrat& e) const;
};

#endif