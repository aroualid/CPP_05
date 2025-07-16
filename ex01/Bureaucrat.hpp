
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Form;

class Bureaucrat {

public:
	class GradeTooHighException : public std::exception 
	{	
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{	
		virtual const char *what() const throw();
	};
	Bureaucrat();
	Bureaucrat(unsigned int grade, std::string name);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const & src);
	void setName(std::string name);
	void setGrade(unsigned int grade);
	std::string getName() const;
	unsigned int getGrade() const;
	void incrGrade();
	void decrGrade();
	void signForm (Form & form);
private:
	std::string name;
	unsigned int	grade;
};

std::ostream & operator << (std::ostream & o, Bureaucrat const & i);


#endif
