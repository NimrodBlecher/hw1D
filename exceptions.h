#ifndef EMPLOYEE_H_EXCEPTIONS_H
#define EMPLOYEE_H_EXCEPTIONS_H
using std::exception;
namespace hw1 {

    class Exception : public std::exception {
    };

    class EmployeeDoesNotExist : public Exception {
    };

    class EmployeeAlreadyExist : public Exception {
    };

    class CompanyHasNoEmployees : public Exception {
    };

    class CompanyValueNotSufficient : public Exception {
    };

    class CompanyAlreadyExist : public Exception {
    };

    class CompanyDoesntExist : public Exception {
    };

    class CompanyNegativeId : public Exception {
    };

    class NullInput : public Exception {
    };

#endif //EMPLOYEE_H_EXCEPTIONS_H
}