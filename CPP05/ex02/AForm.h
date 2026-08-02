#ifndef _AFORM_HPP_
# define _AFORM_HPP_

# include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm(void);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& copy);
		virtual				~AForm();
		AForm&				operator=(const AForm& other);
		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(Bureaucrat& b);
		virtual void		execute(const Bureaucrat& e) const = 0;
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
		class NotSignedExeption : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif