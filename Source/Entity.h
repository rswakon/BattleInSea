#ifndef ENTITY_H
#define ENTITY_H
#include "math.h"
#include "Globals.h"




	template <class T>
	class Vector2D
	{
	public:
		T X;
		T Y;
		Vector2D();
		Vector2D(T _x, T _y);
		void Set(T _x, T _y);
		void operator=(const Vector2D<T> & _v);
		void operator+=(const Vector2D<T> & _v);
		void operator-=(const Vector2D<T> & _v);
		Vector2D<T> operator+(const Vector2D<T> & _v) const;
		Vector2D<T> operator-(const Vector2D<T> & _v) const;
		Vector2D<T> operator-() const;
		void operator*=(float _value);
		Vector2D<T> operator*(float _value) const; // vector * float	
		void operator/=(float _value);
		Vector2D<T> operator/(float _value) const;	
		Vector2D<T> sub( Vector2D<T> v1,  Vector2D<T> v2);
		float Distance(const Vector2D<T> & _a, const Vector2D<T> & _b);
		float Length() const;
		void Normalize();
		T Sqr(const T & _value);
		void limit(float max);
		float magnitude();
		void mult(float n);
		float DistanceFrom(const Vector2D<T> & _v) ;
	};

	template <class T>
	void Vector2D<T>::Set(T _x, T _y)
	{
		X = _x;
		Y = _y;
	}
	template <class T>
	Vector2D<T>::Vector2D()
	{
		 
	}
	template <class T>
	Vector2D<T>::Vector2D(T _x, T _y):X(_x),Y(_y)
	{

	}

	template <class T>
	void Vector2D<T>::operator=(const Vector2D<T> & _v)
	{
		X = _v.X;
		Y = _v.Y;
	}
	template <class T>
	void Vector2D<T>::operator+=(const Vector2D<T> & _v)
	{
		X += _v.X;
		Y += _v.Y;
	}
	template <class T>
	void Vector2D<T>::operator-=(const Vector2D<T> & _v)
	{
		X -= _v.X;
		Y -= _v.Y;
	}
	template <class T>
	Vector2D<T> Vector2D<T>::operator+(const Vector2D<T> & _v) const
	{
		return Vector2D<T>( X + _v.X, Y + _v.y);
	}
	template <class T>
	Vector2D<T> Vector2D<T>::operator-(const Vector2D<T> & _v) const
	{
		return Vector2D<T> ( X - _v.X, Y - _v.Y);
	}
	template <class T>
	Vector2D<T>Vector2D<T>::operator-() const
	{
		return Vector2 ( -X, -Y);
	}

	template <class T>
	void Vector2D<T>::operator*=(float _value)
	{
		X *= _value;
		Y *= _value;
	}
	template <class T>
	Vector2D<T> Vector2D<T>::operator*(float _value) const // vector * float
	{
		return Vector2D<T>(X * _value, Y * _value);
	}

	template <class T>
	void Vector2D<T>::operator/=(float _value)
	{
		X /= _value;
		Y /= _value;
	}

	template <class T>
	Vector2D<T> Vector2D<T>::operator/(float _value) const
	{
		return Vector2(X / _value, Y / _value);
	}

	template <class T>
	Vector2D<T> Vector2D<T>::sub( Vector2D<T> v1,  Vector2D<T> v2)
	{
		Vector2D<T> v =   Vector2D<T>(v1.X - v2.X,v1.Y - v2.Y);
		return v;
	}

	template <class T>
	float Vector2D<T>::Length() const
	{
		return sqrt(X*X + Y*Y);
	} 


	template <class T>
	void Vector2D<T>::Normalize()
	{
		float length = Length();
		X /= length;
		Y /= length;     
	}

	template <class T>
	T Vector2D<T>::Sqr(const T & _value)
	{ 
		return (_value * _value);
	}

	template <class T>
	bool operator==( const Vector2D<T> & A, const Vector2D<T> & B) // strict comparing of floats for ie std::algorithm
	{
		return (A.X == B.X) && (A.Y == B.Y);
	}

	template <class T>
	bool operator!=( const Vector2D<T> & A, const Vector2D<T> & B) // strict comparing of floats 
	{
		return (A.X != B.X) || (A.Y != B.Y);
	}

	template <class T>
	Vector2D<T> operator*(float _value, const Vector2D<T> & _vector) // float * vector
	{
		return Vector2D<T>(_vector.x * _value, _vector.y * _value);
	}

	template <class T>
	float Vector2D<T>::Distance(const Vector2D<T> & _a, const Vector2D<T> & _b)
	{
		return sqrt( Sqr( _a.X - _b.X ) + Sqr( _a.Y - _b.Y ) );
	}

	template <class T>
	void Vector2D<T>::limit(float max)
	{
		if (magnitude() > max) {
			Normalize();
			mult(max);
		}
	}
	template <class T>
	float Vector2D<T>::magnitude() 
	{
		return (float) sqrt(X*X + Y*Y);
	}
	template <class T>
	void Vector2D<T>::mult(float n) 
	{
		X *= n;
		Y *= n;
	}

	template <class T>
   float Vector2D<T>::DistanceFrom(const Vector2D<T> & _v) 
    {
     return sqrt( Sqr( X - _v.X ) + Sqr( Y - _v.Y ) );
    }

typedef Vector2D<int> VectorI;
typedef Vector2D<float> VectorF;



class Entity
{
public:
	Entity()
	{
	}

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual void HandleCollision( Entity * entity ) = 0;
	 

public:
	 
	int animationFrame;			// aktualna klatak
	int frameCount;				// iloœæ klatek animacji
	int frameRate;				// prêdkoœæ odtwarzania animacji (klatek animacji na sekunde - FPS)
	int tick;
 
	 


};




#endif