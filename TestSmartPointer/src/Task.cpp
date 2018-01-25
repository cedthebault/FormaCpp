#include "Task.h"

Task::Task()
{
	cout<<"Task::Constructor par defaut"<<endl;
}
Task::Task(int id ) :mId(id)
{
	cout<<"Task::Constructor"<<endl;
}
Task::~Task()
{
	cout<<"Task::Destructor"<<endl;
}
