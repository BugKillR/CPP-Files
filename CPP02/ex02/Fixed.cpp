#include "./Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _fixedPointVal(0) { }

Fixed::Fixed(const int number) {
	_fixedPointVal = number * (1 << _fractionalBits);
}

Fixed::Fixed(const float number) {
	_fixedPointVal = roundf(number * (float)(1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	setRawBits(other.getRawBits());
}

Fixed::~Fixed() { }

int		Fixed::getRawBits(void) const {
	return _fixedPointVal; 
}

Fixed& Fixed::operator=(const Fixed& other) {
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& ref) const {
	Fixed	res;

	res.setRawBits(getRawBits() + ref.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed& ref) const {
	Fixed	res;

	res.setRawBits(getRawBits() - ref.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed& ref) const {
	Fixed	res;

	res.setRawBits((getRawBits() * ref.getRawBits()) / (1 <<_fractionalBits));
	return (res);
}

Fixed	Fixed::operator/(const Fixed& ref) const {
	Fixed	res;

	res.setRawBits((getRawBits() * (1 << _fractionalBits)) / ref.getRawBits());
	return (res);
}

bool	Fixed::operator>(const Fixed& ref) const {
	return getRawBits() > ref.getRawBits() ? true : false;
}

bool	Fixed::operator<(const Fixed& ref) const {
	return getRawBits() < ref.getRawBits() ? true : false;
}

bool	Fixed::operator>=(const Fixed& ref) const {
	return getRawBits() >= ref.getRawBits() ? true : false;
}

bool	Fixed::operator<=(const Fixed& ref) const {
	return getRawBits() <= ref.getRawBits() ? true : false;
}

bool	Fixed::operator==(const Fixed& ref) const {
	return getRawBits() == ref.getRawBits() ? true : false;
}

bool	Fixed::operator!=(const Fixed& ref) const {
	return getRawBits() != ref.getRawBits() ? true : false;
}

Fixed&	Fixed::operator++() {
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed&	Fixed::operator--() {
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)  {
	Fixed	old(*this);
	setRawBits(getRawBits() + 1);
	return (old);
}

Fixed	Fixed::operator--(int) {
	Fixed	old(*this);
	setRawBits(getRawBits() - 1);
	return (old);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	return f1 < f2 ? f1 : f2; 
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	return f1 > f2 ? f1 : f2;
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	return f1 < f2 ? f1 : f2;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	return f1 > f2 ? f1 : f2;
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
