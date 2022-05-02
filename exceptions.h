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
    class BadInput : public Exception {
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

    class NegativeIncreaseValue : public Exception {
    };

    class NegativeSalaryIncrease : public Exception {
    };

    class EmployeeNegativeId : public Exception {
    };

    class NullInput : public Exception {
    };

    class CompanyHasEmployeesAntCanNotBeDeleted : public Exception{
    };

     class InvalidInput : public  Exception{
};

     class NoEmployeesInMarket : public Exception{
     };

#endif //EMPLOYEE_H_EXCEPTIONS_H
}