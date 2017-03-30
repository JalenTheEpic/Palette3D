#ifndef _DEBUG_EXCEPTION_H_
#define _DEBUG_EXCEPTION_H_
#include <string>
#include <sstream>

#define THROW_EXCEPTION(msg, type) throw Palette3D::Exception(__FILE__, __LINE__, (msg), (type))

namespace Palette3D
{

	enum class ExceptionType {
		InvalidOperation, ArgumentException, ArgumentNull,
		ArgumentOutOfRange, NullReference, IndexOutOfRange, AccessViolation,
		StackOverflow, OutOfMemory, OutOfVRam, FileNotFound
	};
	/// A general purpose exception class to indicate ssurge-related errors
	class Exception
	{
		

		/***** ATTRIBUTES *****/
	protected:
		/// The error description
		std::string mDescription;

		/// The file in which the error occurred
		std::string mFile;

		ExceptionType mType;

		/// The line number on which the error occurred
		unsigned int mLine;


		/***** CONSTRUCTORS / DESTRUCTORS *****/
	public:
		/// The only constructor
		Exception(std::string file, unsigned int line, std::string desc, ExceptionType type) :
			mDescription(desc), mFile(file), mLine(line), mType(type){}

		/***** METHODS *****/
	public:
		/// Returns an error string
		std::string getString()
		{
			std::stringstream ss;
			ss << "'" << mDescription << "' [" << mFile << "@" << mLine << "]";
			return ss.str();
		}
	};
}

#endif