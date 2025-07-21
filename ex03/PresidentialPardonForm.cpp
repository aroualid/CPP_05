
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm()
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	(void) src;
	return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
		std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
	}
}
