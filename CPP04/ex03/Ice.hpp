#ifndef ICE_HPP
# define ICE_HPP

# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(std::string const& type);
	Ice(const Ice& other);
	virtual ~Ice();

	Ice&	operator=(const Ice& ohter);

	virtual	Ice*	clone() const;
	virtual void	use(ICharacter& target);

};

#endif