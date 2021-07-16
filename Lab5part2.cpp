#include <iostream>
using namespace std;
const int Max_Size=2;
class Application 
{  //Two variables are declared in class having ID and name 
	int ID = 0;
	string name;
    public:
	//method to return name
	string getname()
	{
		return name;
	}
	//method to return ID
	int getID() 
	{
	  return ID;
	}
	//method to set Name
	void setname(string name1)
	{
		name = name1;
	}
	//method to set ID
	void setID()
	{//everytime ID is incremented
			ID++;
	}
    
};
class Implement 
{public:
	//An array of objects is created
	Application* array[Max_Size];
	//Two variables for mantaining queue
	int rear = -1;
	int front = 0;
	//Method to return if a queue is full or not
	bool isFull() 
	{//return if queue insertion is reached at en array(container)
		return(rear == Max_Size-1);}
    //Method to return if a queue is empty or not
	bool isEmpty()
	{//as an element is added rear is incremented,so if rear is at initial pos means no insertion has been made
		return (rear==-1);}
	//Method to register a patient 
	void RegisterPatient(string name)
	{//An object of class Application is created
		Application* sp= new Application();
		//for insertion,rear is incremented
		rear++;
	    //to set ID of object sp
		sp->setID();
		//to set name of object sp
		sp->setname(name);
		//object of app is stored in array
		array[rear]=sp;
		
		
	
	}
	//Method to serve a patient
	void ServePatient()
	{   //If list is empty no patient is here for serving
		if (isEmpty())
		{
			cout << "All Patients for today are served.No more patients" << endl;
		}
		//If queue contains pateint,first pateint who camed should be served
		else
		{
			cout << "call for patient " << array[front]->getID() << "having name  "<< array[front]->getname()<<endl;
			//for deletion, front is incremented
			front++;
		}
	}
	//Method to show All the record for patients who came today
	void ShowAll()
	{
		for (int i = 0; i <= rear; i++)
		{
			cout <<array[i]->getname();
		}
	
	}
	//This method to return if there are no more patient so doctor can go home
	bool CanDoctorGo()
	{
		if (front==rear+1)
		{
			cout << "Yes doctor can go home"<<endl;
			return true;
		}
		else 
		{
			cout << "have some patients left" << endl;
			return false;
		}
	}
	//This method cancels all the appointment so doctor can go to lunch
	void CancelAll() 
	{
		if (!isEmpty()) {
			while(front!=rear+1)
			{
				ServePatient();
			}
			cout << "Yes,now he can go for lunch";
		}
		else { cout << "no one is here. Yes he can go"; }
	}
};
int main()
{//Object of class Implement is created
	Implement* I = new Implement();
	//int variable option and string name is declared
	int option;
	string name;
//A loop for continuing management system
	while (true) {
		cout << "what u need to check" << endl << "1 for registering patient " <<
			endl << "2 for serving patient" << endl << "3 for doctor can go home" << endl << "4 for show all record"<<endl<< "5 for can doctor go for lunch" << endl<< "6 for shut down the hospital management system"<<endl;
		//input from user in option variable
		cin >> option;
		//option passed to switch to select whether register partient,serve patient,cancel all
		switch (option)
		{
		case 1:
		{//if queue is not full
			if (!I->isFull())
			{
				cout << "please enter the name of patient" << endl;
				cin >> name;
				//take name of patient from user
			    //passed to registerpatient method 
				I->RegisterPatient(name);
			}
			// queue is full prompts message
			else {
				cout << "Already enough patients for today.Doctor cannot treat more patients today" << endl;
			}
			//break statement to break from cases
			break;
		}
		case 2:
			//case 2 for serving the patient
			I->ServePatient();
			break;

		case 3:
			//case 3 for checking doctor can go or not
			I->CanDoctorGo();
			break;

		case 4://case 4 show all the records for todays patient
			I->ShowAll();
			break;
		case 5:
			I->CancelAll();
			break;
		case 6:
		{//to exit out o0f the loop
			return 0;

		}

		}
	}
}