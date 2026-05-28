#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	static const int	_fractionalBits;
    int					_fixedPointVal;

public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed&	operator=(const Fixed& ref);
	Fixed	operator+(const Fixed& ref) const;
	Fixed	operator-(const Fixed& ref) const;
	Fixed	operator*(const Fixed& ref) const;
	Fixed	operator/(const Fixed& ref) const;

	bool	operator>(const Fixed& ref) const;
	bool	operator<(const Fixed& ref) const;
	bool	operator>=(const Fixed& ref) const;
	bool	operator<=(const Fixed& ref) const;
	bool	operator==(const Fixed& ref) const;
	bool	operator!=(const Fixed& ref) const;
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int  const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed&	min(Fixed& f1, Fixed& f2);
	static Fixed&	max(Fixed& f1, Fixed& f2);

	static const Fixed&	min(const Fixed& f1, const Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& ref);

#endif