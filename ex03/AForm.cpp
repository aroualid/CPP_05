#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), signGrade(75), execGrade(75)
{

}

AForm::AForm(const std::string name, unsigned int const signGrade, unsigned int const execGrade, std::string target) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade), target(target)
{
	if (signGrade < 1 || execGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm()
{}

AForm::AForm(AForm const & src) : name("Form"), signGrade(75), execGrade(75)
{
	*this = src;
}

AForm& AForm::operator=(AForm const & src)
{
	(void) src;
	return (*this); 

}


std::string AForm::getName() const
{
	return (name);
}

unsigned int AForm::getGrade(int index) const
{
	if (index == 0)
		return (signGrade);
	else 
		return (execGrade);
	
}

std::string AForm::getSign() const
{
	if (isSigned == true)
		return ("is signed");
	else 
		return ("is not signed");
}

std::ostream& operator<< (std::ostream& o, AForm const& i)
{
	o << i.getName() << ", AForm signed grade is : " << i.getGrade(0) << ", AForm exec grade is : " << i.getGrade(1) << " and he " << i.getSign() << "." << std::endl;
	return o;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= signGrade)
	{
		std::cout << "AForm " << this->name << " has been signed by " << b.getName() << std::endl;
		this->isSigned = true;
	}
	else 
		throw AForm::GradeTooLowException();
}


const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !!\n");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low !!\n");
}

