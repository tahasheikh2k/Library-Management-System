#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
ofstream MemIn; 
ofstream BookIn;


//<<<--------------------Member Classes--------------->>>

class Member
{
	private:
		string name;
		string gender;
		int age;
		string book_borrow[100];
		static int count;
		
	public:
		Member()
		{
			name = " ";
			for(int i = 0;i<100;i++)
			{
				book_borrow[i] = " ";
			}
			 
		}
		void Add_Member_info()
		{
			MemIn.open("MembersRecord.txt",ios::app);		
			
			fflush(stdin);
			cout<<"Enter name: ";
			getline(cin,name);
			
			fflush(stdin);
			cout <<"Enter Gender: ";
			getline(cin,gender);
			
			fflush(stdin);
			cout <<"Enter Age: ";
			cin >> age;
			
			MemIn << "<------------Data of the New Member " << count << "------------->" << endl;
			MemIn << "Name " <<  name << endl;
			MemIn << "Gender: " << gender << endl;
			MemIn << "Age: " << age << endl;
			
			count++;
			
			MemIn.close();
		}
		
		void card_register()
		{
			fflush(stdin);
			cout <<"Enter Gender: ";
			getline(cin,gender);
			
			fflush(stdin);
			cout <<"Enter Age: ";
			cin >> age;
			
			MemIn.open("MembersRecord.txt",ios::app);
			
			MemIn << "Gender: " << gender << endl;
			MemIn << "Age: " << age << endl;
			
			count++;
			
			MemIn.close();
			
		}
		string getname()
		{
			return name;
		}
		
	void display_borrow()
		{
			for(int i = 0; i < 100; i++)
			{
				if(book_borrow[i] != " ")
				{
				
				cout << "\nBorrowed books by this member are: " << book_borrow[i] <<endl;
				
				}
			
			}
		}
		
	void display_mem()
	{
		cout << "\nMember name: " << name;
		cout << "\nMember Gender: " << gender;
		cout << "\nMember Age: " << age;
		display_borrow();
	}	
		
			
	void set_name(string temp)
	{
	name = temp;
	
	}
	
	
	
	void Borrow_Book()
	{
		string chk;
		
		cout << "\nDo you want to borrow a book? (Yes/yes/No/no): ";
		getline(cin,chk);
		
		for(int i = 0; i<5;i++)
		{
			if(chk == "yes" || chk == "Yes")
			{
			
			if(book_borrow[i] != " ")
			{
				i++;
			}
			
			
			cout <<"Enter the books you want to borrow: ";
			getline(cin,book_borrow[i]);
			
			if(book_borrow[i] == "No More Books" || book_borrow[i] == "no more books")
			{
				book_borrow[i] = " ";
				i = 6;
			}
			
			if(i == 5)
			{
				cout << "\nYou have reached maximum limit for borrowing a book!" <<endl;
			}
		
		
			}
			
			else 
			{
				break;
			}
		}
	}
	
	
	
	int g_count()
	{
		return count;
	}
		
	
	
};
class Card
{
	private:
	int amount;
		
	public:
		Card()
		{
			amount=0;
			
		}
		
		int get_amount()
		{
			return amount;
		}
		
		int Menu()
		{
			string chk;
			
			{
				int x;
				cout<<"1-Card for 2 years = Rs.500"<<endl;
				cout<<"Enter 1 to register: ";
				cin>>x;
				switch(x)
				{
					case 1:
						amount=500;
						cout<<"\nAmount = "<<amount<<endl;
						cout<<"\nRegistered Successfully"<<endl;
						return amount;
					break;
					
					default:
						cout<<"Invalid input:"<<endl;
						cout<<"Do you want to try again (yes,no): ";
						cin>>chk;
						break;
				}
			}while(chk=="Yes"||chk=="yes");
		}
		
	
		
};


 int Member::count = 1;


//<<<-------------------Book Classes------------------>>>

class Books
{
	private:
	string name_book;
	string category;
	string author;
	
		
	public:
	
	void add_books()
	{
	
	fflush(stdin);
	cout << "Enter the Book name: ";
	getline(cin,name_book);

	cout << "Enter the Author: ";
	getline(cin,author);
	
	cout << "Enter the Category: ";
	getline(cin,category);
	
	
	BookIn.open("BooksRecord.txt",ios::app);
	BookIn << "<<---------- New Book has been registered ---------->> " << endl << endl;
	
	BookIn << "Book name: " << name_book << endl;
	BookIn << "Book Author: " << author << endl;
	BookIn << "Book Category: " << category << endl;
	
	BookIn.close();
	
	}

	void display()
	{
		cout << "\nBook name: " << name_book;
		cout << "\nCategory: " << category;
		cout << "\nAuthor: " << author;
	}
	
	string get_name()
	{
		return name_book;
	}	
	
	string get_category()
	{
		return category;
	}
	
	string get_author()
	{
		return author;
	}
	
	void set_books(string name, string categ, string auth)
	{
		name_book = name;
		category = categ;
		author = auth;
		
	}
	
};

// <<--------------------Library Classes-------------------------->>

class Library
{
	private:
		Books b;
		Member obj;
		Card c1;
		
	public:
	


//  <-----------------------Member Section----------------------->
	
	void Member_info()
		{
			obj.Add_Member_info();
		}
		
		void card_reg()
		{
			obj.card_register();
		}
	
	Member get_mem()
	{
		return obj; 
	}
	
	void get_borrow()
	{
		obj.Borrow_Book();
	}
	
	int get_count()
	{
		 obj.g_count();
	}
	
	void set_data_l(string temp)
	{
		obj.set_name(temp);
		
	}	
		
	bool SearchByMemName(string temp)
	{
		string chk;
		
		if(temp == obj.getname())
		{
			cout << "\nYou can borrow book!" <<endl;
			get_borrow();
			return true;
		
		}
		
		else 
		{
			return false;
			
		}
	
}
	
		
	Card get_card()
	{
		return c1;
		}	
		
	
	
		int check(string temp)
		{
			int amount1 = 0;
			if(obj.getname()!= temp || obj.getname() == " ")
			{
				string check;
				cout<<"\nYou have to buy card if you want to issue book"<<endl;
				cout<<"\nIf you want to register, please enter (Yes/yes): ";
				getline(cin,check);
				if(check=="Yes"||check=="yes")
				{
				amount1 = c1.Menu();
					return amount1;
				}	
			}
			
		}
		
		string get_mem_name()
		{
			return obj.getname();
		}
		
	
	bool SearchByMember(string temp)
	{
		if(temp == obj.getname())
		{
			
			return true;
 		}
		
		else 
		{
			return false;
		}
	
	}
	
	
	
//	<-------------------------BOOK SECTION----------------------->
	
	
	void set_books(string n,string c,string cat)
	{
		b.set_books(n,c,cat);
	}
	
	
	
	void get_books()
	{
		
		b.add_books();
		
	}	
	
	void show()
	{
		b.display();
	}
	
	Books get_book()
	{
		return b;
	}
	
	bool SearchByName(string temp)
	{
		
		if(temp == b.get_name())
		{
			cout << "\nThe book is available in the Library!" <<endl;
			return true;
		}
		
		else 
		{
			return false;
		}
		
	}
	
	bool SearchByAuthor(string temp)
	{
		if(temp == b.get_author())
		{
			
			return true;
		}
		
		else 
		{
			return false;
		}
	
	}
	
	bool SearchByCategory(string temp)
	{
		if(temp == b.get_category())
		{
			
			return true;
 		}
		
		else 
		{
			return false;
		}
	
	}
		
	
};

//<<-------------Outside Class Functions of Member Class ---------------->>

int Checker(Library l[],string temp,int j)
{
	Member m1;
	int count = 0;
	string check;
	
	for(int i = 0; i<100;i++)
	{
		if(l[i].SearchByMemName(temp) == true)
		{
			count++;
		}
	
	}
	
	
	
	if(count != 1)
	{
		
		if(l[count].check(temp) == 500 || l[count].get_mem_name() == " ")
			{
				
			l[j].set_data_l(temp);
			MemIn.open("MembersRecord.txt",ios::app);
			MemIn << "<------------Data of the New Member " << l[j].get_count() 	<< "------------->" << endl;
			MemIn << "Name " <<  temp << endl;
			MemIn.close(); 
			
			l[j].card_reg();
			
			
			
			 j++;
		
			}
						
		
	}
	

	return j;
}


int MemberNotFound(bool chk[])
{
	int count = 0;
	
	for(int i = 0; i<100;i++)
	{
	
	if(chk[i] == true)
	{
		count++;
	}


	
}
	if(count >= 2)
	{
		count = 1;
	}

	return count;
	
}


void DisplaySearchByMemName(Library l[],string temp)
{

	int c;
	int f;
	
	bool chk[100] = {false};
	
	
	for(int i = 0;i<100;i++)
	{	
		
	chk[i] = l[i].SearchByMember(temp);	
	if(chk[i] == true)
	{
	l[i].get_mem().display_mem();
		cout <<endl;
	
	}
	
	
	}
	
	
	c = MemberNotFound(chk);
	if(c != 1)
	{
		cout << "\nThere is no member of such name!" <<endl;
	}
		
	
}



//<<---------------------Outside Functions for Book Class-------------------->>

//<---------False Condtions Functions For Books----------->


int NameNotFound(bool chk[])
{
	int count = 0;
	
	for(int i = 0; i<100;i++)
	{
	
	if(chk[i] == true)
	{
		count++;
	}


	
}
	
	return count;
	
}

int AuthorNotFound(bool chk[])
{
	int count = 0;
	
	for(int i = 0; i<100;i++)
	{
	
	if(chk[i] == true)
	{
		count++;
	}


	
}

	if(count >= 2)
	{
		count = 1;
	}

	
	return count;
	
}



int CategoryNotFound(bool chk[])
{
	int count = 0;
	
	for(int i = 0; i<100;i++)
	{
	
	if(chk[i] == true)
	{
		count++;
	}


	
}
	if(count >= 2)
	{
		count = 1;
	}

	return count;
	
}





//<<<<---- Normal Functions for displaying Search -----> 

void DisplaySearchByName(Library l[], string temp)
{
	int c;
	
	bool chk[100] = {false};
	
	for(int i = 0;i<100;i++)
	{
		
	chk[i] = l[i].SearchByName(temp);	
	
	
	}
	
	c = NameNotFound(chk);
	if(c != 1)
	{
		cout << "\nThere is no book with such name!" <<endl;
	}
	
	
	
	
}

void DisplaySearchByAuthor(Library l[], string temp)
{
	
	int c;
	
	bool chk[100] = {false};
	
	for(int i = 0;i<100;i++)
	{
		
	chk[i] = l[i].SearchByAuthor(temp);	
	
	if(chk[i] == true)
	
	{
	l[i].get_book().display();
	cout <<endl;
	}
	
	
	
	}
	
	
	c = AuthorNotFound(chk);
	if(c != 1)
	{
		cout << "\nThere is no author with such name!" <<endl;
	}
	
	
}

void DisplaySearchByCategory(Library l[], string temp)
{
	
	int c;
	int f;
	
	bool chk[100] = {false};
	
	
	for(int i = 0;i<100;i++)
	{	
		
	chk[i] = l[i].SearchByCategory(temp);	
	if(chk[i] == true)
	{
	l[i].get_book().display();
		cout <<endl;
	
	}
	
	
	}
	
	
	c = CategoryNotFound(chk);
	if(c != 1)
	{
		cout << "\nThere are no books of this Category!" <<endl;
	}
	
	
	
}



void box()
{
	int key,length,width;
	length = 0;
	width = 0;
	

	
	
	while(length < 65)
	{
		cout << "=";
	length++;
	
	}
	cout <<endl;
while(width < 7)
	{
		cout << "|                                                               |" <<endl;
	width++;
	}
	
	cout << "| \t     Library Management System                          |" << endl;
	cout << "| \t  Enter 1 for Member Registration!                      |" <<endl;
	cout << "| \t  When pressed '1' Enter 'A' to Add member info         |" <<endl;
	cout << "| \t  When pressed '1' Enter 'B' to check and issue a book  |" <<endl;
	cout << "| \t  When pressed '1' Enter 'C' to display members info    |" <<endl;
	cout << "| \t  When pressed '1' Enter 'E' to return back to main     |" <<endl;
	cout << "| \t  Enter 2 for Book Collection!                          |" <<endl;
	cout << "| \t  When pressed '2' Enter 'A' to Add books               |" <<endl;
	cout << "| \t  When pressed '2' Enter 'B' to check books             |" <<endl;
	cout << "| \t  When pressed '2' Enter 'C' to check Author            |" <<endl;
	cout << "| \t  When pressed '2' Enter 'D' to check category          |" <<endl;
	cout << "| \t  When pressed '2' Enter 'E' to return back to main     |" <<endl;
	cout << "| \t  Enter 'E' when in Main menu to Exit the program       |" <<endl;
	
	while(width < 15)
	{
		cout << "|                                                               |" <<endl;
	width++;
	}
	


while(length < 130)
	{
		cout << "=";
	length++;
	
	}

	
	
}

void hardcode_books(Library l[])
{
	

	l[0].set_books("Alchemist","Fantasy","Paulo Coelho");
	l[1].set_books("Adventures of Sherlock Holmes","Mystery","Sir Arthur Conan Doyle");
	l[2].set_books("Alice in the Wonderland","Fantasy","Lewis Carroll");
	l[3].set_books("In the Heart of the Sea","History","Nathaniel Philbrick");
	l[4].set_books("The Hobbit","Fantasy","J. R. R. Tolkien");
	
}



int main()
{
	Library l[100];
	

	ofstream MemIn;
	ofstream BookIn;
	hardcode_books(l);
	
	int j = 0;
	string chk_name;
	string search_member;
	

	
	
	int i = 5;
	char opt;
	bool terminator = true; 
	char sub;
	string search_book,search_author,search_category;
	
	
	box();
	
	cout << "\nSelect any one of the option given below: ";
	cin >> opt;
	
	do 
	{
	
	switch(opt)
	{
	
	case '1': 
	cout << "\nEnter the sub-option: ";
	cin >> sub;
	
	switch(sub)
	{
	
	case 'A':
		
	if(j == 0)
	{
	MemIn.open("MembersRecord.txt",ios::trunc);	
	}
		
	l[j].Member_info();
	j++;
	
	
	break;
	
	case 'B':
	fflush(stdin);
	cout<<"Enter the name to check: ";
	getline(cin,chk_name);
	
	j = Checker(l,chk_name,j);
	

	
	break;
	
	case 'C':
	fflush(stdin);
	cout << "\nEnter the name of member you want information about: ";
	getline(cin,search_member);
	fflush(stdin);
	DisplaySearchByMemName(l,search_member);	
		
	break;	
		
	case 'D':
	break;
	
	case 'E':
	cout <<"\nWelcome back to Main Menu! "<<endl;
	box();
	cout << "\nSelect any of options such as 1,2,3,4: ";
	cin >> opt; 
	
}

	
	break; 
	
	
	break; 
	
	case '2':
	

	cout << "\nEnter the sub-option: ";
	cin >> sub;
	
	
	switch(sub)
	{
	
	case 'A':
		
	if(i == 5)
	 
	{
		BookIn.open("BooksRecord.txt",ios::trunc);
	}	
	
	l[i].get_books();
	i++;
	break;
	
	case 'B':
	fflush(stdin);
	cout << "\nEnter the name of the book you want to search: ";
	getline(cin,search_book);
	fflush(stdin);
	DisplaySearchByName(l,search_book);	
	break;
	
	case 'C':
	fflush(stdin);
	cout << "\nEnter the name of the Author you want to search: ";
	getline(cin,search_author);
	fflush(stdin);
	DisplaySearchByAuthor(l,search_author);	
	break;	
		
	case 'D':
	fflush(stdin);	
	cout << "\nEnter the name of the Category you want to search: ";	
	getline(cin,search_category);
	fflush(stdin);
	DisplaySearchByCategory(l,search_category);
	break;
	
	case 'E':
	cout <<"\nWelcome back to Main Menu! "<<endl;
	box();
	cout << "\nSelect any of options such as 1,2,3,4: ";
	cin >> opt; 
		
		
	}
	
	break;
	case 'E':
	terminator = false;	
	break;	
			
	default:
		
	cout <<"\nInvalid option! Please enter the appropriate number: ";
	cin >> opt;
	
	break;
	
	} //switch bracket
	
	
	} //Loop bracket
	
	
	
	while(terminator);
	
	return 0;
}
