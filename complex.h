/*
This is a pure C++ class that implements a "Complex<T>" type.  It's fully compatible with fftwX_Complex<T>, where X can be '', 'f', 'l', etc...
*/

#define _USE_MATH_DEFINES
#include <math.h>

template <typename T>
class Complex {
private:
    // These are the actual real and imaginary parts of this Complex<T> type
    T re, im;
    
public:
    // Initialize this Complex<T> with explicit real and imaginary values
    Complex<T>( T re, T im ) {
        this->re = re;
        this->im = im;
    }

    // Returns the magnitude squared of this complex number
    const T& magsq( void ) {
        return this->re*this->re + this->im*this->im;
    }
    
    // Returns the magnitude of this complex number
    const T& mag( void ) {
        return sqrt(this->mag())
    }
    
    // Returns the phase of this complex number
    const T& phase( void ) {
        if( this->re > 0 )
			return atan(this->re/this->im);
		if( this->re < 0 ) {
			if( this->im >= 0 )
				return atan(this->re/this->im) + M_PI;
			return atan(this->re/this->im) - M_PI;
		}
		if( this->im > 0 )
			return M_PI_2;
		if( this->im < 0 )
			return -M_PI_2;

		// If re == 0 and im == 0, we'll just return zero. :P
		return 0;
    }
    
    // Return the real and imaginary parts
    const T& real( void ) {
        return re;
    }
    
    const T& imag( void ) {
        return im;
    }


////////////////////////////////////////////////////////////////
// OPERATOR OVERLOADING
////////////////////////////////////////////////////////////////
        
    // Initialize this Complex<T> from another Complex<T> object
    Complex<T>( const Complex<T> & other ) {
        this->re = other.re;
        this->im = other.im;
    }
    
    // Overload = operator to allow assignment:
    Complex<T> & operator =( const Complex<T> & other ) {
        this->re = other.re;
        this->im = other.im;
        return *this;
    }

    //Overload - operator to allow negation:
    const Complex<T> &operator -() {
        return Complex<T>(-this->re, -this->im);
    }
    
    // Overload +=, -=, *=, /=
    Complex<T> & operator +=( const Complex<T> & other ) {
        this->re += other.re;
        this->im += other.im;
        return *this;
    }
    
    Complex<T> & operator -=( const Complex<T> & other ) {
        this->re -= other.re;
        this->im -= other.im;
        return *this;
    }

	Complex<T> & operator *=(const Complex<T> & other ) {
        this->re = (this->re * other.re - this->im * other.im);
        this->im = (this->im * other.re + this->re * other.im);
        return *this;
    }
    
    Complex<T> & operator /=( const Complex<T> & other ) {
        T mag = other.magsq();
        this->re = (this->re * other.re + this->im * other.im)/mag;
        this->im = (this->im * other.re - this->re * other.im)/mag;
        return *this;
    }
    
    
    // Overload +, -, *, /
    const Complex<T> & operator +( const Complex<T> & other ) {
        return Complex(*this) += other;
    }
    
    const Complex<T> & operator -( const Complex<T> & other ) {
        return Complex(*this) -= other;
    }
    
    const Complex<T> & operator *( const Complex<T> & other ) {
        return Complex(*this) *= other;
    }
    
    const Complex<T> & operator /( const Complex<T> & other ) {
        return Complex(*this) /= other;
    }

	const bool operator ==(const Complex<T> & other) {
		return this->re == other.re && this->im == other.im;
	}
};