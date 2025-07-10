
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string name)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	this->grade = grade;
	this->name = name;
	std::cout << "A new Bureaucrat " << name << " is ready to work and his grade is " << grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;

}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src)
{	
	name = src.getName();
	grade = src.getGrade();
	return (*this);

}

void Bureaucrat::setName(std::string name)
{
	this->name = name;
}

void Bureaucrat::setGrade(unsigned int grade)
{
	this->grade = grade;
}

std::string Bureaucrat::getName() const
{
	return (name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (grade);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High !!\n");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low !!\n");
}

void Bureaucrat::incrGrade()
{
	if (this->grade -1 < 1)
		throw GradeTooHighException();
	else
	{
		this->grade--;
		std::cout << this->name << " got promoted " << std::endl;
	}
}

void Bureaucrat::decrGrade()
{
	if (this->grade +1 > 150)
		throw GradeTooLowException();
	else
	{
		this->grade++;
		std::cout << this->name << " got degrade " << std::endl;
	}
}


std::ostream& operator<< (std::ostream& o, Bureaucrat const& i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}
