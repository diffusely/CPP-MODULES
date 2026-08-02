#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

# include <iostream>

# define HIGH_GRADE 1
# define LOW_GRADE 150

# include "AForm.h"

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		Bureaucrat(void);
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat&			operator=(const Bureaucrat& other);
		int					getGrade(void) const;
		void				setGrade(int grade);
		const std::string&	getName(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm& form);
		void				executeForm(const AForm& form) const;
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
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif