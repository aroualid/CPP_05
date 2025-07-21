#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	Bureaucrat numero1(131, "numero1");
	Bureaucrat numero2(2, "numero2");
	Bureaucrat numero3(1, "numero3");
	ShrubberyCreationForm papier1("home");
	RobotomyRequestForm papier2("timmy");
	PresidentialPardonForm papier3("stan");
	numero1.signAForm(papier1);
	numero1.executeForm(papier1);
	numero2.signAForm(papier2);
	numero2.executeForm(papier2);
	numero3.signAForm(papier3);
	numero3.executeForm(papier3);
}
