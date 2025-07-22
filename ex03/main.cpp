#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	Bureaucrat numero1(131,"numero1");
	Bureaucrat numero2(2, "numero2");
	Bureaucrat numero3(1, "numero3");
	ShrubberyCreationForm papier1("home");
	RobotomyRequestForm papier2("timmy");
	PresidentialPardonForm papier3("stan");
	numero1.signAForm(papier3);
	numero1.executeForm(papier1);
	numero2.signAForm(papier2);
	numero2.executeForm(papier2);
	numero3.signAForm(papier3);
	numero3.executeForm(papier3);
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("RobotomdsdssdsyRequestForm", "Bender");
	delete rrf;
	AForm *abs;
	abs = someRandomIntern.makeForm("PresidentialPardonForm", "Michel");
	delete abs;
}
