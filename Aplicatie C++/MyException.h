#pragma once
#include <string>

using std::string;

class MyException {

public:

	MyException() = default;
	virtual const char* what() const throw() = 0;
};

//-----------------------------------------------------------------------------------

class OfertaException : public MyException {

public:

	OfertaException() = default;
	virtual const char* what() const throw() = 0;
};

class ValidateException : public OfertaException {

	string msg;

public:

	ValidateException(const string& msg);
	const char* what() const throw();
};

//-----------------------------------------------------------------------------------

class RepoException : public MyException {

public:

	RepoException() = default;
	virtual const char* what() const throw() = 0;
};

class FileNotOpen : public RepoException {

	string msg;

public:

	FileNotOpen(const string& filepath);
	const char* what() const throw();

};

//-----------------------------------------------------------------------------------

class CosException : public MyException {

public:

	CosException() = default;
	virtual const char* what() const throw() = 0;
};

class OfertaExistaInCos : public CosException {

public:

	OfertaExistaInCos() = default;
	const char* what() const throw();
};

//-----------------------------------------------------------------------------------

class ServiceException : public MyException {

public:

	ServiceException() = default;
	virtual const char* what() const throw() = 0;
};

class PozitieInvalida : public ServiceException {

public:

	PozitieInvalida() = default;
	const char* what() const throw();
};

class OfertaIdentica : public ServiceException {

public:

	OfertaIdentica() = default;
	const char* what() const throw();
};

class OptiuneSort : public ServiceException {

public:

	OptiuneSort() = default;
	const char* what() const throw();
};

class OfertaNuExista : public ServiceException {

public:

	OfertaNuExista() = default;
	const char* what() const throw();
};

class RepositoryGol : public ServiceException {

public:

	RepositoryGol() = default;
	const char* what() const throw();
};

class NuMaiSuntOperatiiUndo : public ServiceException {

public:

	NuMaiSuntOperatiiUndo() = default;
	const char* what() const throw();
};

//-----------------------------------------------------------------------------------

class UiException : public MyException {

public:

	UiException() = default;
	virtual const char* what() const throw() = 0;
};

class NuExistaOptiune : public UiException {

public:

	NuExistaOptiune() = default;
	const char* what() const throw();
};