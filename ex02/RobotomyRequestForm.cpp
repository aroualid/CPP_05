
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm()
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	(void) src;
	return (*this);
}

int rand_perso()
{
	return (std::rand() % 100);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
	{	
		std::cout << "can't execute Form not signed\n";
		return ;
	}
	if (executor.getGrade() > this->execGrade)
		throw GradeTooLowException();
	else
	{
		std::cout << "*drilling noise*\n";
		int i = rand_perso();
		if (i < 50)
			std::cout << target << " has been robotomized \n";
		else
			std::cout << "robotomization failed for " << target << "\n";
	}		
}
