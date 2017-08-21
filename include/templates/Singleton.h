/*
Palette3D
Licensed under the terms of the MIT License (see LICENSE.txt)
*/


#ifndef _TEMPLATES_SINGLETON_H_
#define _TEMPLATES_SINGLETON_H_

#include <debugging\Exception.h>

namespace Palette3D {
	/// Any class that wished to be a Singleton should derive itself
	/// from this class.  Warning: the derived class must provide a 
	/// template specialization of msSingleton (to set it to nullptr) -- 
	/// usually in their derived_class.cpp file.
	template <class T>
	class Singleton {
		// @@@@@ ATTRIBUTES @@@@@ //
	protected:
		/// The pointer to the singleton
		static T * mspInstance;

		// @@@@@ CONSTRUCTOR / DESTRUCTOR @@@@@ //
	public:
		/// The default constructor
		explicit Singleton() {
			if (mspInstance != nullptr)
				THROW_EXCEPTION("Singleton already exists!", ExceptionType::InvalidOperation);
			mspInstance = static_cast<T*>(this);
		}

		/// The destructor.  
		virtual ~Singleton() {
			mspInstance = nullptr;
		}

		// @@@@@ METHODS @@@@@ //
	public:
		/// Returns a pointer to the one-and-only singleton (throws a ssurge::Exception if no singleton).
		static T * getInstance() {
			if (mspInstance == nullptr)
				THROW_EXCEPTION("Singleton does not exist!", ExceptionType::NullReference);
			return mspInstance;
		}

	};

}

#endif