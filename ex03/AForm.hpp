
#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm {

public:	
	class GradeTooHighException : public std::exception 
	{	
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{	
		virtual const char *what() const throw();
	};
	AForm(const std::string name, unsigned int const signGrade, unsigned int const execGrade, std::string target);
	AForm(AForm const & src);
	virtual ~AForm();
	AForm &operator=(AForm const & src);
	std::string getName() const;
	unsigned int getGrade(int index) const;
	std::string getSign() const;
	void beSigned (Bureaucrat &b);
	virtual void execute(Bureaucrat const & executor) const = 0;
protected:
	AForm();
	const std::string name;
	bool isSigned;
	unsigned int const signGrade;
	unsigned int const execGrade;
	std::string target;
};

std::ostream& operator<< (std::ostream& o, AForm const& i);

#endif 
