#ifndef EMPLOYEE_H_EXCEPTIONS_H
#define EMPLOYEE_H_EXCEPTIONS_H
using std::exception;
namespace hw1 {

    class Exception : public std::exception {
    };

    class WorkerDoesNotExist : public Exception {
    };

    class CompanyHasNoWorkers : public Exception {
    };

    class CompanyValueNotSufficient : public Exception {
    };

    class CompanyAlreadyExists : public Exception {
    };


}



#endif //EMPLOYEE_H_EXCEPTIONS_H
