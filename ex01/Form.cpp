#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), signGrade(75), execGrade(75)
{

}

Form::Form(const std::string name, unsigned int const signGrade, unsigned int const execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::~Form()
{}

Form::Form(Form const & src) : name("Form"), signGrade(75), execGrade(75)
{
	*this = src;
}

Form& Form::operator=(Form const & src)
{
	(void) src;
	return (*this); 

}


std::string Form::getName() const
{
	return (name);
}

unsigned int Form::getGrade(int index) const
{
	if (index == 0)
		return (signGrade);
	else 
		return (execGrade);
	
}

std::string Form::getSign() const
{
	if (isSigned == true)
		return ("is signed");
	else 
		return ("is not signed");
}

std::ostream& operator<< (std::ostream& o, Form const& i)
{
	o << i.getName() << ", Form signed grade is : " << i.getGrade(0) << ", Form exec grade is : " << i.getGrade(1) << " and he " << i.getSign() << "." << std::endl;
	return o;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= signGrade)
	{
		std::cout << "Form " << this->name << " has been signed by " << b.getName() << std::endl;
		this->isSigned = true;
	}
	else 
		throw Form::GradeTooLowException();
}


const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !!\n");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low !!\n");
}

