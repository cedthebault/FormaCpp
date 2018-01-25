#ifndef TASK_H
#define TASK_H
#include <memory>
#include <iostream>

using namespace std;

class Task
{
    public:
        Task();
        Task(int t);
        virtual ~Task();
        int mId;

    protected:

    private:
};

#endif // TASK_H
