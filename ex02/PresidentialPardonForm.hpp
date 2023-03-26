#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
# include <iostream>

class PresidentialPardonForm {
	private:

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm &copy );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &assign );
		~PresidentialPardonForm( void );
};

std::ostream &operator<<( std::ostream &o, PresidentialPardonForm *a );

#endif