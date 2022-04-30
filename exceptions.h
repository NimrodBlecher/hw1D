#ifndef EMPLOYEE_H_EXCEPTIONS_H
#define EMPLOYEE_H_EXCEPTIONS_H
using std::exception;
namespace hw1 {

    class Exception : public std::exception {
    };

    class WorkerDoesNotExist : public Exception {
    };

    class WorkerAlreadyExist : public Exception {
    };

    class CompanyHasNoWorkers : public Exception {
    };

    class CompanyValueNotSufficient : public Exception {
    };

    class CompanyAlreadyExist : public Exception {
    };

    class CompanyDoesntExist : public Exception {
    };


#endif //EMPLOYEE_H_EXCEPTIONS_H
}