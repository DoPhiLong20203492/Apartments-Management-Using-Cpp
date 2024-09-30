#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class apartment
{
      int apartmentNumber;
      char ownerName[30];
      int type; 
      char ophone[30];
      char tenantName[30];
      int totalTenants;
      char tphone[30];
      float rent;
      float area;
    public:
      void accept();
      void show();
      void update();
      float compressData(float);
      int getApartmentNumber()
      {
          return apartmentNumber;
      }
      int getType()
      {
          return type;
      }
      float getRent()
      {
          return rent;
      }
      float getArea()
      {
          return area;
      }
};

class staff
{
    char staffname[30]; 
    char position[30];
    char identity[30];
    char sphone[30];
    char locate[30];
    float salary;
    public:
      void accept();
      void show();
      void update();
      float compressData(float);
      string getstaffname()
      {
        return staffname;
      }
      char getidentity()
      {
          return identity[30];
      }
      char getsphone()
      {
          return sphone[30];
      }
      float getsalary()
      {
          return salary;
      }
};

//Read new records
void apartment::accept()
{
        cout << "\nApartment Number: ";
        cin >> apartmentNumber;
        cout << "Type (1/2/3 bedrooms): ";
		cin >> type;
        cout << "Owner Name: ";
        fflush(stdin);
		gets(ownerName);
		cout << "Owner Phone Number: ";
		fflush(stdin);
		gets(ophone);
		cout << "Tenant Name ('NA' instead): ";
		fflush(stdin);
		gets(tenantName);
		cout << "Tenant Phone Number ('NA' instead): ";
		fflush(stdin);
		gets(tphone);
        cout << "Total Number of Tenants ('0' instead): ";
		cin >> totalTenants;
		cout << "Rent per month (ex: 24000, '0' instead): ";
		cin >> rent;
		rent = compressData(rent);
		cout << "Flat Area (in square metres): ";
		cin >> area;
}

void staff::accept()
{
        cout << "\nStaff's Name: ";
        fflush(stdin);
		gets(staffname);
		cout << "Staff's Position: ";
		fflush(stdin);
		gets(position);
		cout << "Staff's Identity: ";
		fflush(stdin);
		gets(identity);
		cout << "Staff's Phone Number ('NA' instead): ";
		fflush(stdin);
		gets(sphone);
        cout << "Staff's Location: ";
        fflush(stdin);
		gets(locate);
		cout << "Staff's salary (ex: 24000, '0' instead): ";
		cin >> salary;
		salary = compressData(salary);
}

// declare global object variables
apartment flat;
staff obj_staff;

//Compress rent data
float apartment::compressData(float rent)
{
	float compressedRent = rent/1000;
	return compressedRent;
}

float staff::compressData(float salary)
{
	float compressedsalary = salary/1000;
	return compressedsalary;
}

//Display records

void apartment::show()
{
	    //system("CLS");
        cout << endl << "Apartment Number: ";
        cout << apartmentNumber << endl;
        cout << "Flat Type (1/2/3 bedrooms): ";
		cout << type << endl;
        cout << "Owner Name: ";
        puts(ownerName);
		cout << "Owner Phone Number: ";
		puts(ophone); 
		cout << "Tenant Name: ";
		puts(tenantName);
		cout << "Tenant Phone Number: ";
		puts(tphone);
        cout << "Total Number of Tenants: ";
		cout << totalTenants << endl;
		cout << "Rent (per month): VND.";
		cout << rent << "k" << endl;
		cout << "Flat Area (in square metres): ";
		cout << area << endl << endl; 
		system("PAUSE");
		//system("CLS");
}

void staff::show()
{
	    //system("CLS");
        cout << endl << "Staff's Name: ";
        puts(staffname);
        cout << "Staff's Position: ";
        puts(position);
        cout << "Staff's Identity: ";
		puts(identity); 
		cout << "Staff's Phone Number: ";
		puts(sphone); 
		cout << "Staff's Location: ";
		puts(locate);
		cout << "Salary (per month): VND.";
		cout << salary << "k" << endl << endl;
		system("PAUSE");
		//system("CLS");
}

//Update records with new values
void apartment::update()
{
	char tenantNewName[30], tphoneNew[30];
    float newRent;
    int newNumberOfTenants;
    cout << "\nEnter the new Details...";
    cout << "\nNew Tenant Name (Enter '1' to retain old one): ";
    fflush(stdin);   gets(tenantNewName);
    cout<< "\nNew Tenant Phone Number (Enter '1' to retain old one): ";
    fflush(stdin);   gets(tphoneNew);
	cout<< "\nNew Flat Rent/month (Enter 1 to retain old one, ex: 24000): ";
    cin >> newRent;
    newRent = compressData(newRent);
    cout << "\nNew Number of Tenants (Enter 1 to retain old one): ";
    cin >> newNumberOfTenants;
	if(strcmp(tenantNewName,"1") != 0)
	   strcpy(tenantName, tenantNewName);
	if(strcmp(tphoneNew, "1")!=0)
	   strcpy(tphone, tphoneNew);
	if(newRent != 1)
	   rent = newRent;
	if(newNumberOfTenants != 1)
	   totalTenants = newNumberOfTenants;
}

void staff::update()
{
	char sphoneNew[30], newposition[30], newlocation[30];
    float newsalary;
    cout << "\nEnter the new Details...";
    cout << "\nNew staff's Phone Number (Enter '1' to retain old one): ";
    fflush(stdin);   gets(sphoneNew);
    cout<< "\nNew staff's Position (Enter '1' to retain old one): ";
    fflush(stdin);   gets(newposition);
    cout<< "\nNew staff's Location (Enter '1' to retain old one): ";
    fflush(stdin);   gets(newlocation);
	cout<< "\nNew Salary/month (Enter 1 to retain old one, ex: 24000): ";
    cin >> newsalary;
    newsalary = compressData(newsalary);
	if(strcmp(sphoneNew,"1") != 0)
	   strcpy(sphone, sphoneNew);
	if(strcmp(newposition, "1")!=0)
	   strcpy(position, newposition);
    if(strcmp(newlocation, "1")!=0)
	   strcpy(locate, newlocation);
	if(newsalary != 1)
	   salary = newsalary;
}


//Search for records based on multiple conditions
void Search_condition()
{
    int stype;
    float srent;
    char found = 'n';
    ifstream file("apartment.dat", ios::in|ios::binary);    
    cout << "\nEnter the values for the Search...\n";
    cout << "\n1.Type (1/2/3 bedrooms, specify 1/2/3): ";
	cin >> stype;
    cout << "\n2.Rent per month(for <=x, specify x like 24000): ";
	cin >> srent;
	srent = srent/1000;
    file.seekg(0, ios::beg);
    while(1)               
    {
        file.read((char*)&flat, sizeof(flat));
        if(!file)
            break;
        if((flat.getType() == stype) && (flat.getRent() <= srent))
        {
                flat.show();
                found = 'y';
        }
    }
    if(found == 'n')
       cout << "\nNO RECORD FOUND !!!\n\n";
    file.close();
    system("PAUSE");
}

//Search for record based on primary key (apartment number)
void Search_apartment()
{
	int apNumber;
	char found = 'n';
    ifstream file("apartment.dat", ios::in|ios::binary);    
    cout << "\nEnter the apartment number to search: ";
    cin >> apNumber;
    file.seekg(0, ios::beg);
    while(1)               
    {
        file.read((char*)&flat, sizeof(flat));
        if(!file)
            break;
        if(apNumber == flat.getApartmentNumber())
        {
                flat.show();
                found = 'y';
        }
    }
    if(found == 'n')
       cout << "\nNO RECORD FOUND !!!\n";
    file.close();
    system("PAUSE"); 
}

void Search_staffname()
{
	string staffname;
	char found = 'n';
    ifstream file("staff.dat", ios::in|ios::binary);    
    cout << "\nEnter the staff name to search: ";
    fflush(stdin);   
    getline(cin, staffname);
    cout << "Searching ... " << staffname << "\n";
    file.seekg(0, ios::beg);
    while(1)               
    {
        file.read((char*)&obj_staff, sizeof(obj_staff));
        if(!file)
            break;
        if(staffname == obj_staff.getstaffname())
        {
            obj_staff.show();
            found = 'y';
        }
    }
    if(found == 'n')
       cout << "\nNO RECORD FOUND !!!\n";
    file.close();
    system("PAUSE"); 
}

//Read records from file
void Read_flatRecords()
{ 
      ifstream f1("apartment.dat", ios::in|ios::binary);
      if(!f1)
      {
             cerr << "\nFile Open Error !!!";
             return;
      }
      while(f1.read((char*)&flat, sizeof(flat)))
      {  
              flat.show();
      } 
      f1.close();
}

void Read_staffRecords()
{ 
      ifstream f1("staff.dat", ios::in|ios::binary);
      if(!f1)
      {
             cerr << "\nFile Open Error !!!";
             return;
      }
      while(f1.read((char*)&obj_staff, sizeof(obj_staff)))
      {  
              obj_staff.show();
      } 
      f1.close();
}

//Write record to file according to flat number
void Insert_flatrecord()
{
     ifstream fi("apartment.dat", ios::in|ios::binary);
     ofstream fo("temp.dat", ios::out|ios::binary);
     char last = 'y', duplicate = 'n';
     apartment snew; // create new object
	 cout << "\nEnter the details of the new Record: \n";
	 snew.accept();
	 while(fi.read((char*)&flat, sizeof(flat)))
	 {	         
         if(snew.getApartmentNumber() == flat.getApartmentNumber())
		 {
		 	cout << "\nApartment details for " << flat.getApartmentNumber() << " ALREADY EXISTS\n\n";
		 	duplicate = 'y';
			goto label;		        	
		 }   
         if(snew.getApartmentNumber() <= flat.getApartmentNumber())
         {
             fo.write((char*)&snew, sizeof(snew));
             last = 'n';
             break;
         }
         else
         	 fo.write((char*)&flat, sizeof(flat));
     }
     if(last == 'y')
         fo.write((char*)&snew, sizeof(snew));
     else if(!fi.eof())
     {
        while(1)
        {     
           if(!fi)
              break;
           fi.read((char*)&flat, sizeof(flat));              
           fo.write((char*)&flat, sizeof(flat));
           if(!fi)
              break;
        }
     }
     fi.close();
     fo.close();
     remove("apartment.dat");
     rename("temp.dat", "apartment.dat");
     cout<<"\nApartment Added Successfully !!!\n";
     label:
     if(duplicate == 'y')
     {
     	remove("temp.dat");
	 }
	 system("PAUSE");  
}     

void Insert_staffrecord()
{
     ifstream fi("staff.dat", ios::in|ios::binary);
     ofstream fo("temp.dat", ios::out|ios::binary);
     char last = 'y', duplicate = 'n';
     staff snew;
	 cout << "\nEnter the details of the new Record: \n";
	 snew.accept();
	 while(fi.read((char*)&obj_staff, sizeof(obj_staff)))
	 {	         
         if(snew.getstaffname() == obj_staff.getstaffname())
		 {
		 	cout << "\nStaff information for " << snew.getstaffname() << " ALREADY EXISTS\n\n";
		 	duplicate = 'y';
			goto label;		        	
		 }   
         if(snew.getstaffname() <= obj_staff.getstaffname())
         {
             fo.write((char*)&snew, sizeof(snew));
             last = 'n';
             break;
         }
         else
         	 fo.write((char*)&obj_staff, sizeof(obj_staff));
     }
     if(last == 'y')
         fo.write((char*)&snew, sizeof(snew));
     else if(!fi.eof())
     {
        while(1)
        {     
           if(!fi)
              break;
           fi.read((char*)&obj_staff, sizeof(obj_staff));              
           fo.write((char*)&obj_staff, sizeof(obj_staff));
           if(!fi)
              break;
        }
     }
     fi.close();
     fo.close();
     remove("staff.dat");
     rename("temp.dat", "staff.dat");
     cout<<"\nStaff Added Successfully !!!\n";
     label:
     if(duplicate == 'y')
     {
     	remove("temp.dat");
	 }
	 system("PAUSE");  
}     

//Delete a record given the apartment number
void Delete_flatrecord()
{
     ifstream fi("apartment.dat", ios::in|ios::binary); 
     ofstream fo("temp.dat", ios::out|ios::binary); 
     int aID=0;
     char found='f'; 
     cout << "\nEnter the apartment number to be deleted: ";
	 cin >> aID;
     while(fi.read((char*)&flat, sizeof(flat))) 
     {              
              if(aID == flat.getApartmentNumber())
              { 
                   cout << "\nDetails of the apartment to be deleted\n";
                   flat.show();
                   found = 't'; 
                   continue; 
              } 
              else 
                   fo.write((char*)&flat, sizeof(flat));
              
      } 
      if(found == 'f') 
        cout << "\n\n\t\tRECORD NOT FOUND !!!\n\n";
      else
        cout << "\n\n\t\tRecord Deleted Successfully !!!\n\n"; 
      fi.close(); 
      fo.close();       
      remove("apartment.dat"); 
      rename("temp.dat", "apartment.dat");
      system("PAUSE");  
}

void Delete_staffrecord()
{
     ifstream fi("staff.dat", ios::in|ios::binary); 
     ofstream fo("temp.dat", ios::out|ios::binary); 
     string sname;
     char found='f'; 
     cout << "\nEnter staff name to be deleted: ";
	 fflush(stdin);   
     getline(cin, sname);
     while(fi.read((char*)&obj_staff, sizeof(obj_staff))) 
     {      
            if(sname == obj_staff.getstaffname())
            { 
                cout << "\nInfomation of the staff to be deleted\n";
                obj_staff.show(); 
                found = 't'; 
                continue; 
            } 
            else 
                fo.write((char*)&obj_staff, sizeof(obj_staff));
              
      } 
      if(found == 'f') 
        cout << "\n\n\t\tRECORD NOT FOUND !!!\n\n";
      else
        cout << "\n\n\t\tRecord Deleted Successfully !!!\n\n"; 
      fi.close(); 
      fo.close();       
      remove("staff.dat"); 
      rename("temp.dat", "staff.dat");
      system("PAUSE");  
}

//Update the record given the updated values
void Update_flatrecord()
{
     fstream f1("apartment.dat", ios::in|ios::out|ios::binary); 
     int aID; 
     long pos; 
     char found='f'; 
     cout << "\nEnter the apartment number to be Updated: ";
	 cin >> aID;
	 if(!f1)
	 {
		cout << "File not Found";
		exit(0);
	 } 
	 else
	 {
		f1.read((char*)&flat, sizeof(flat));
		while(!f1.eof())
		{
			if(aID == flat.getApartmentNumber())
			{
				f1.seekg(0, ios::cur);
				flat.update();
				f1.seekp(f1.tellg() - sizeof(flat));
				f1.write((char*)&flat, sizeof(flat));
				found = 't';
				cout << "\n\n\t\tRECORD UPDATED !!!\n\n";
			}
			f1.read((char*)&flat, sizeof(flat));
		}
	 }

     if(found == 'f') 
        cout<<"\n\n\t\tRECORD NOT FOUND !!!\n\n";
     f1.close();
     system("PAUSE"); 
}

void Update_staffrecord()
{
     fstream f1("staff.dat", ios::in|ios::out|ios::binary); 
     string sname; 
     long pos; 
     char found='f'; 
     cout << "\nEnter the staff name to be Updated: ";
	 fflush(stdin);   
     getline(cin, sname);
	 if(!f1)
	 {
		cout << "File not Found";
		exit(0);
	 } 
	 else
	 {
		f1.read((char*)&obj_staff, sizeof(obj_staff));
		while(!f1.eof())
		{
            char *p = &obj_staff.getstaffname()[0];
			if(sname == obj_staff.getstaffname())
			{
				f1.seekg(0, ios::cur);
				obj_staff.update();
				f1.seekp(f1.tellg() - sizeof(obj_staff));
				f1.write((char*)&obj_staff, sizeof(obj_staff));
				found = 't';
				cout << "\n\n\t\tRECORD UPDATED !!!\n\n";
			}
			f1.read((char*)&obj_staff, sizeof(obj_staff));
		}
	 }

     if(found == 'f') 
        cout<<"\n\n\t\tRECORD NOT FOUND !!!\n\n";
     f1.close();
     system("PAUSE"); 
}

//Calculate rent of the flat including per sq. ft. maintenance
void Calculate_rent()
{
	int aptNumber;
	float maintenanceAmount, rentPlusMaintenance = 0.0;
	char found = 'n';
    ifstream file("apartment.dat", ios::in|ios::binary);    
    cout << "\nEnter the maintenance amount for this month (amount in VND. per square metre): ";
    cin >> maintenanceAmount;
    cout << "\nEnter the apartment number for which the rent is to be calculated: ";
    cin >> aptNumber;
    file.seekg(0, ios::beg);
    while(1)               
    {
            file.read((char*)&flat, sizeof(flat));
            if(!file)
               break;
            if(aptNumber == flat.getApartmentNumber())
            {
            	  rentPlusMaintenance = flat.getArea() * maintenanceAmount + flat.getRent() * 1000;
            	  cout << "\n\nThe total monthly rent to be paid: VND. " << rentPlusMaintenance << endl << endl;
                  found = 'y';
            }
    }
    if(found == 'n')
       cout << "\nNO RECORD FOUND !!!\n\n";
    file.close();
    system("PAUSE");
}

void Calculate_salary()
{
	string sname;
	float salary = 0.0;
    float numofmonth = 0;
	char found = 'n';
    ifstream file("staff.dat", ios::in|ios::binary);    
    cout << "\nEnter the number of working months: ";
    cin >> numofmonth;
    cout << "\nEnter the staff name for which the salary is to be calculated: ";
    fflush(stdin);   
    getline(cin, sname);
    file.seekg(0, ios::beg);
    while(1)               
    {
        file.read((char*)&obj_staff, sizeof(obj_staff));
        if(!file)
            break;
        if(sname == obj_staff.getstaffname())
        {
                salary = obj_staff.getsalary() * numofmonth * 1000;
                cout << "\n\nThe salary of this staff: VND. " << salary << endl << endl;
                found = 'y';
        }
    }
    if(found == 'n')
       cout << "\nNO RECORD FOUND !!!\n\n";
    file.close();
    system("PAUSE");
}


//Supported operations menu
void main_menu()
{
    int choice;
    while (true)
    {
        system("CLS");
        cout << "*******************************************************************************";
        cout << "\n\t     \tApartment (Owner & Tenant) Management System\t\t      \n";
        cout << "*******************************************************************************";
        cout << "\n\n\t\t\t    <<<<<:: MENU ::>>>>>\n";
        cout << "\n\t\t\t    1. Add Apartment";
        cout << "\n\t\t\t    2. Delete Apartment";
        cout << "\n\t\t\t    3. Update Apartment";
        cout << "\n\t\t\t    4. Display All Apartments";
        cout << "\n\t\t\t    5. Search Apartment (Based on apartment)";
        cout << "\n\t\t\t    6. Search Apartment (Based on conditions)";
        cout << "\n\t\t\t    7. Calculate monthly rent (Included maintenance)";
        cout << "\n\t\t\t    8. Add Staff";
        cout << "\n\t\t\t    9. Delete Staff";
        cout << "\n\t\t\t    10. Update Staff Infomation";
        cout << "\n\t\t\t    11. Display All Staffs";
        cout << "\n\t\t\t    12. Search Staff Name";
        cout << "\n\t\t\t    13. Calculate salary";
        cout << "\n\t\t\t    14. Exit";
        cout << "\n\t\t\t    Enter your choice: ";
        cin >> choice;
        switch(choice)
        {                   
            case 1: Insert_flatrecord();
                   break;
                   
           case 2: Delete_flatrecord();
                   break;
                   
           case 3: Update_flatrecord();
                   break;
                   
           case 4: Read_flatRecords();
                   break;
                   
           case 5: Search_apartment();
                   break;
                   
           case 6: Search_condition();
                   break;
                   
           case 7: Calculate_rent();
		           break;

           case 8: Insert_staffrecord();
                   break;

           case 9: Delete_staffrecord();
                   break;

           case 10: Update_staffrecord();
                   break;

           case 11: Read_staffRecords();
                   break;

           case 12: Search_staffname();
                   break;

           case 13: Calculate_salary();
                   break;

           case 14: exit(0);
           
           default: 
                cout << "\nNo such option...\n\n";
                system("PAUSE");
                char s;
                cout << "Do you want to continue? ...(Y/N)";
                cin >> s;
                if (s == 'Y' || s == 'y')
                    continue;
                else
                    exit(0);
        } 
    }
}

int main()
{   
    main_menu();
    getch();
    return 0;
}
