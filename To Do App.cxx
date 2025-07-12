#include <iostream>
#include <vector>
using namespace std;
/* <--------- To Do App --------->
 Author: Ankit
 Date: 11-7-2025
 Project: To Do app
 Description: A simple console       based To do list app. 
*/

// ---> UI
void menu()
{
	cout << " ____________________ TO DO APP ____________________\n"
		 << endl;
	cout << "       🙏WELCOME TO YOUR PERSONAL TO DO LIST🙏\n      ▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️\n\n"
		 << endl;
	cout << "   1. =>View Tasks                 2. =>Add Task\n\n   3. =>Delete Task                4. =>Mark Task\n\n   5. =>Exit\n\n"
		 << endl;
	cout << " ---------------------------------------------------- \n"
		 << endl;
}
// ---> Back button
void back_button()
{
	char yes;
	do
	{
		cout << "\n   Type (y) to back: ";
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
		{
			break;
		}
	} while (yes != 'y' || yes != 'Y');
}
// ---> struct to get task from user
struct task
{
	string name;
	bool completed = false;
};
vector<task> todo; // vector to store data

// ---> 1.View Task
void view_task()
{
	if (!todo.empty())
	{
		cout << "                📝List Of Your Tasks🖋\n                ______________________\n"
			 << endl;
		cout << "   S.NO.   Task status   Task\n   -----   -----------   ----\n";
		for (int i = 0; i < todo.size(); i++)
		{
			cout << "    " << (i + 1) << ".         [" << (todo[i].completed ? "✅" : "  ") << "]      " << todo[i].name << endl
				 << endl;
		}
	}
	else
	{
		cout << "   Task doesn't exist❗❕\n"
			 << endl;
	}
	back_button();
}

// ---> 2.Add Task
void add_task()
{
	string newtask;
	cout << "       🙏WELCOME TO YOUR PERSONAL TO DO LIST🙏\n      ▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️▫️\n\n"
		 << endl;
	cout << "     📝Start adding tasks:-\n"
		 << endl;
	cout << "   Enter Task: ";
	cin.ignore();
	getline(cin, newtask);
	todo.push_back({newtask, false});
	char yes1;
	do
	{
		cout << "\n   Do you want to add more tasks(y/n): ";
		cin >> yes1;
		if (yes1 == 'y' || yes1 == 'Y')
		{
			cout << "\n   Enter Task: ";
			cin.ignore();
			getline(cin, newtask);
			todo.push_back({newtask, false});
		}
		else if (yes1 == 'n' || yes1 == 'N')
		{
			break;
		}
	} while (yes1 != 'n' || yes1 != 'N');
	back_button();
}

// ---> 3.Delete Task
void delete_task()
{
	if (!todo.empty())
	{
		cout << "                📝List Of Your Tasks🖋\n                ______________________\n"
			 << endl;
		cout << "   S.NO.   Task status   Task\n   -----   -----------   ----\n";
		for (int i = 0; i < todo.size(); i++)
		{
			cout << "    " << (i + 1) << ".         [" << (todo[i].completed ? "✅" : "  ") << "]      " << todo[i].name << endl
				 << endl;
		}
		int num;
		cout << "   Enter Task number to delete: ";
		cin >> num;
		if (num > 0 && num <= todo.size())
		{
			todo.erase(todo.begin() + num - 1);
			cout << "   deleting task... \n   deleting task... \n   Your task deleted successfully 👍\n"
				 << endl;
		}
		else
		{
			cout << "   Invalid Number\n"
				 << endl;
		}
	}
	else
	{
		cout << "   Task doesn't exist❗❕\n"
			 << endl;
	}
	back_button();
}
// ---> 4.Mark Task
void mark_task()
{
	if (!todo.empty())
	{
		cout << "                📝List Of Your Tasks🖋\n                ______________________\n"
			 << endl;
		cout << "   S.NO.   Task status   Task\n   -----   -----------   ----\n";
		for (int i = 0; i < todo.size(); i++)
		{
			cout << "    " << (i + 1) << ".         [" << (todo[i].completed ? "✅" : "  ") << "]      " << todo[i].name << endl
				 << endl;
		}
		int num;
		cout << "   Enter Task number to mark as done[✅]: ";
		cin >> num;
		if (num > 0 && num <= todo.size())
		{
			todo[num - 1].completed = true;
			cout << "\n   Your task marked successfully ✅\n"
				 << endl;
		}
		else
		{
			cout << "   Invalid number\n"
				 << endl;
		}
	}
	else
	{
		cout << "   Task doesn't exist❗❕\n"
			 << endl;
	}
	back_button();
}

// ---> Main function
int main()
{
	int input;
	do
	{
		menu();
		do
		{ // this loop print a message if user give input that are not available.
			cout << "   Your Input: ";
			cin >> input;
			cout << endl;
			if (input <= 0 || input > 5)
			{
				cout << " Please give available input\n"
					 << endl;
			}
		} while (input <= 0 || input > 5); // -----> switch cases
		switch (input)
		{
		case 1:
			view_task();
			break;
		case 2:
			add_task();
			break;
		case 3:
			delete_task();
			break;
		case 4:
			mark_task();
			break;
		case 5:
			cout << "                  🙏THANKS FOR VISIT🙏\n\n   Exiting To Do App...\n"
				 << endl;
			break;
		default:
			cout << " Please give available input\n"
				 << endl;
		}
	} while (input != 5);
	return 0;
}