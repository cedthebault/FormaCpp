#include "Task.h"

class Node

{
    int value;
    public:
    std::shared_ptr<Node> leftPtr;
    std::shared_ptr<Node> rightPtr;
    //std::shared_ptr<Node> parentPtr;
    std::weak_ptr<Node> parentPtr;
    Node(int val) : value(val) {
         std::cout<<"Contructor"<<val<<std::endl;
    }
    ~Node() {
         std::cout<<"Destructor"<<value<<std::endl;
    }
};

uniquePtrExemple(){
	// Empty unique_ptr object
	std::unique_ptr<int> ptr1;

	// Check if unique pointer object is empty
	if(!ptr1)
		std::cout<<"ptr1 is empty"<<std::endl;

	// Check if unique pointer object is empty
	if(ptr1 == nullptr)
		std::cout<<"ptr1 is empty"<<std::endl;

	// can not create unique_ptr object by initializing through assignment
	// std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error

	// Create a unique_ptr object through raw pointer
	std::unique_ptr<Task> taskPtr(new Task(23));

	// Check if taskPtr is empty or it has an associated raw pointer
	if(taskPtr != nullptr)
		std::cout<<"taskPtr is  not empty"<<std::endl;

	//Access the element through unique_ptr
	std::cout<<taskPtr->mId<<std::endl;

	std::cout<<"Reset the taskPtr"<<std::endl;
	// Reseting the unique_ptr will delete the associated
	// raw pointer and make unique_ptr object empty
	taskPtr.reset();

	// Check if taskPtr is empty or it has an associated raw pointer
	if(taskPtr == nullptr)
		std::cout<<"taskPtr is  empty"<<std::endl;


	// Create a unique_ptr object through raw pointer
	std::unique_ptr<Task> taskPtr2(new Task(55));

	if(taskPtr2 != nullptr)
		std::cout<<"taskPtr2 is  not empty"<<std::endl;

	// unique_ptr object is Not copyable
	//taskPtr = taskPtr2; //compile error

	// unique_ptr object is Not copyable
	//std::unique_ptr<Task> taskPtr3 = taskPtr2;

	{
		// Transfer the ownership

		std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);


		if(taskPtr2 == nullptr)
			std::cout<<"taskPtr2 is  empty"<<std::endl;

		// ownership of taskPtr2 is transfered to taskPtr4
		if(taskPtr4 != nullptr)
			std::cout<<"taskPtr4 is not empty"<<std::endl;

		std::cout<<taskPtr4->mId<<std::endl;

		//taskPtr4 goes out of scope and deletes the assocaited raw pointer
	}

	// Create a unique_ptr object through raw pointer
	std::unique_ptr<Task> taskPtr5(new Task(56));

	if(taskPtr5 != nullptr)
		std::cout<<"taskPtr5 is not empty"<<std::endl;

	// Release the ownership of object from raw pointer
	Task * ptr = taskPtr5.release();

	if(taskPtr5 == nullptr)
		std::cout<<"taskPtr5 is empty"<<std::endl;

	std::cout<<ptr->mId<<std::endl;

	delete ptr;

}
sharedPtrExemple(){
    	// Creating a shared_ptr through make_shared
	std::shared_ptr<int> p1 = std::make_shared<int>();
	*p1 = 78;
	std::cout << "p1 = " << *p1 << std::endl;

	// Shows the reference count
	std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

	// Second shared_ptr object will also point to same pointer internally
	// It will make the reference count to 2.
	std::shared_ptr<int> p2(p1);

	// Shows the reference count
	std::cout << "p2 Reference count = " << p2.use_count() << std::endl;
	std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

	// Comparing smart pointers
	if (p1 == p2)
	{
		std::cout << "p1 and p2 are pointing to same pointer\n";
	}

	std::cout<<"Reset p1 "<<std::endl;

	p1.reset();

	// Reset the shared_ptr, in this case it will not point to any Pointer internally
	// hence its reference count will become 0.

	std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
		// Shows the reference count
	std::cout << "p2 Reference count = " << p2.use_count() << std::endl;


	// Reset the shared_ptr, in this case it will point to a new Pointer internally
	// hence its reference count will become 1.

	p1.reset(new int(11));
    std::cout << "p1 = " << *p1 << std::endl;
	std::cout << "p1  Reference Count = " << p1.use_count() << std::endl;

	// Assigning nullptr will de-attach the associated pointer and make it to point null
	p1 = nullptr;

	std::cout << "p1  Reference Count = " << p1.use_count() << std::endl;

	if (!p1)
	{
		std::cout << "p1 is NULL" << std::endl;
	}
}

weakPtrExemple(){
    std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
    ptr->leftPtr = std::make_shared<Node>(2);
    ptr->leftPtr->parentPtr = ptr;
    ptr->rightPtr = std::make_shared<Node>(5);
    ptr->rightPtr->parentPtr = ptr;
    std::cout<<"ptr reference count = "<<ptr.use_count()<<std::endl;
    std::cout<<"ptr->leftPtr reference count = "<<ptr->leftPtr.use_count()<<std::endl;
    std::cout<<"ptr->rightPtr reference count = "<<ptr->rightPtr.use_count()<<std::endl;
    std::cout<<"ptr->rightPtr->parentPtr reference count = "<<ptr->rightPtr->parentPtr.lock().use_count()<<std::endl;
    std::cout<<"ptr->leftPtr->parentPtr reference count = "<<ptr->leftPtr->parentPtr.lock().use_count()<<std::endl;
    std::cout<<"ptr reference count = "<<ptr.use_count()<<std::endl;
}

int main()
{
    weakPtrExemple();
	return 0;
}
