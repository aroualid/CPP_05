#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat numero1(10, "numero1");
	Bureaucrat numero2(2, "numero2");
	Bureaucrat numero3(7, "numero3");
	Form papier1("papier1", 2, 2);
	Form papier2("papier2", 6, 11);
	numero1.signForm(papier1);
	numero2.signForm(papier1);
	numero3.signForm(papier2);
	numero2.signForm(papier2);
}
