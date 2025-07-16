
#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {

public:	
	class GradeTooHighException : public std::exception 
	{	
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{	
		virtual const char *what() const throw();
	};
	Form(const std::string name, unsigned int const signGrade, unsigned int const execGrade);
	Form(Form const & src);
	~Form();
	Form &operator=(Form const & src);
	std::string getName() const;
	unsigned int getGrade(int index) const;
	std::string getSign() const;
	void beSigned (Bureaucrat &b);
private:
	Form();
	const std::string name;
	bool isSigned;
	unsigned int const signGrade;
	unsigned int const execGrade;
};

std::ostream& operator<< (std::ostream& o, Form const& i);

#endif 
