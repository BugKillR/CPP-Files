#include "./Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _fixedPointVal(0) { std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointVal = number * (1 << _fractionalBits);
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointVal = roundf(number * (float)(1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int		Fixed::getRawBits(void) const { 
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointVal; 
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointVal = raw;
}

int	Fixed::toInt(void) const {
	return (_fixedPointVal / (1 << this->_fractionalBits));
}

float	Fixed::toFloat(void)	const
{
	return ((float)_fixedPointVal / (1 << _fractionalBits));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& ref) {
	os << ref.toFloat();
	return os;
}
