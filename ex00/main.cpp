#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat stan(0, "stan");
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat steve(200, "stan");
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat bobby(12, "bobby");
		std::cout << bobby;
		bobby.incrGrade();
		std::cout << bobby;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat willy(1, "willy");
		std::cout << willy;
		willy.incrGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat timmy(150, "timmy");
		std::cout << timmy;
		timmy.decrGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
}
