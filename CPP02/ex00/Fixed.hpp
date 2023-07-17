#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

class Fixed
{
private:
	int				 _value;
	static const int _bytes = 8;
public:
	Fixed();
	Fixed(const Fixed &parent);
	~Fixed();
	Fixed& operator=(const Fixed &parent);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};
#endif