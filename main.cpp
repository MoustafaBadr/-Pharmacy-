#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class pharmacy
{
public :

    char drug_id[5];
    char drug_name [30];
    char Drug_Amount [30];
    char Price [30];
    char Type_of_Package [30];
    char Shelf_Number [30];


};

class zpharmacy

{
public :

    double zdrug_id;
    string zdrug_name ;
    double zDrug_Amount ;
    double zPrice ;
    string zType_of_Package ;
    double zShelf_Number;

};

class File
{
    public :
    void validateName(string &name)
    {
        cin.clear();
        cin.sync();
        getline(cin, name);
        while (name.find_first_of("0123456789!@#$%^&*()_+:{}/-+=") != -1)
        {
            cout << "Error ";
            cout << "No digits are allowed in name." << endl;
            cout << "Please re-enter a valid name:" << endl;
            cin.clear();
            cin.sync();
            getline(cin, name);
        }
    }

    void insert()
 {

   pharmacy ph;
   int flag=0;
   ofstream file;
   file.open("pharmacy.txt");
   do{
 	cout<<"   ENTER THE Drug Id :>> ";
	 cin>>ph.drug_id;

	 cout<<"  ENTER THE NAME :>> ";
	 cin>>ph.drug_name;
	 cout<<"  ENTER THE AMOUNT :>> ";
	 cin>>ph.Drug_Amount;
	 cout<<"  ENTER THE PRICE :>> ";
	 cin>>ph.Price;
	 cout<<"  ENTER THE TYPE :>> ";
	 cin>>ph.Type_of_Package;
	 cout<<"  ENTER SHELF NUMBER :>> ";
	 cin>>ph.Shelf_Number;
     file<<ph.drug_id<<"|"<<ph.drug_name<<"|"<<ph.Drug_Amount<<"|"<<ph.Price<<"|"<<ph.Type_of_Package<<"|"<<ph.Shelf_Number<<endl;
	 cout<<"	PRESS (0) TO FINISH INSERT DATA OR PRESS ANY KEY TO COUNTINE \n\n";
     cin>>flag;
     }
     while(flag!=0);

 	file.close();
 }

    void view()
    {   pharmacy mypharmacy;
        system("cls");
        fstream file;
        file.open("pharmacy.txt", ios::in | ios::out | ios::app);
        cout << "|************|************|************|********|***************|\n";
        cout << "|  DRUG ID   | DRUG NAME  | DRUG AMOUNT| PRICE  | TYPE OF ACKAGE|\n";
        while (!file.eof())
        {
        cout << "|------------|------------|------------|--------|---------------|\n";

            file.getline(mypharmacy.drug_id , 100 , '|') ;
            file.getline(mypharmacy.drug_name, 100 , '|');
            file.getline(mypharmacy.Drug_Amount , 100 , '|');
            file.getline(mypharmacy.Price , 100 , '|');
            file.getline(mypharmacy.Type_of_Package , 100 , '\n') ;
            cout <<setw(8)<< mypharmacy.drug_id <<setw(14) << mypharmacy.drug_name <<setw(12)<< mypharmacy.Drug_Amount <<setw(12)<< mypharmacy.Price<<setw(10)<<mypharmacy.Type_of_Package <<endl;

        }
        cout << "|***************************************************************|\n";
        file.close();
    }

       void Search ()
    {   fstream file;
        system("cls");
        cout << "CHOOSE ONE OF THE THREE OPTIONS :"<<endl;
        cout << "1- DRUG ID.\n2- DRUG NAME\n3- back.\n";
        int i;
        cin >>i;
        while (true)
        {
            if (cin.fail() ||  !(i<=7 && i>0))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid choice :" << endl;
                cin >> i ;
            }
            else break;
        }
        switch (i)
        {

        case 1 :
        {

            pharmacy mypharmacy;
            system("cls");
            file.open("pharmacy.txt" , ios::in | ios::out | ios::app);
            cout << "ENTER DRUG ID :\n";
            double ID ;
            bool flag = 0;
            cin>> ID ;
            while (true)
            {
                if (cin.fail() ||  ID <= 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "please Enter a Valid ID :" << endl;
                    cin >> ID ;
                }
                else break;
            }
            while (!file.eof())
            {
            file.getline(mypharmacy.drug_id , 100 , '|') ;
            file.getline(mypharmacy.drug_name, 100 , '|');
            file.getline(mypharmacy.Drug_Amount , 100 , '|');
            file.getline(mypharmacy.Price , 100 , '|');
            file.getline(mypharmacy.Type_of_Package , 100 , '\n') ;
                if (ID == strtod(mypharmacy.drug_id , NULL))
                {
                    flag = 1 ;
                    cout <<"=============================================\n";
                    cout <<"DRUG ID : "<< mypharmacy.drug_id << "\nDRUG NAME : " << mypharmacy.drug_name << "\nDRUG AMOUNT : "<< mypharmacy.Drug_Amount <<"\nPRICE : " << mypharmacy.Price <<"\nTYPE OF PACKAGE : "<<mypharmacy.Type_of_Package <<endl;
                    cout <<"=============================================\n";
                }
            }
            if (flag == 0) cout <<"************** - Not found - ***********"<<endl;
        }

        file.close();
        break;

        case 2 :
        {
             pharmacy mypharmacy;
            system("cls");
            cout << "ENTER DRUG NAME :\n";
            string name ;
            bool flag2 = 0;
            validateName( name );
            file.open("pharmacy.txt" , ios::in);
            while (!file.eof())
            {
            file.getline(mypharmacy.drug_id , 100 , '|') ;
            file.getline(mypharmacy.drug_name, 100 , '|');
            file.getline(mypharmacy.Drug_Amount , 100 , '|');
            file.getline(mypharmacy.Price , 100 , '|');
            file.getline(mypharmacy.Type_of_Package , 100 , '\n') ;
                if (mypharmacy.drug_name == name )
                {
                    flag2 = 1;
                    cout <<"=============================================\n";
                    cout <<"DRUG ID : "<< mypharmacy.drug_id << "\nDRUG NAME : " << mypharmacy.drug_name << "\nDRUG AMOUNT : "<< mypharmacy.Drug_Amount <<"\nPRICE : " << mypharmacy.Price <<"\nTYPE OF PACKAGE : "<<mypharmacy.Type_of_Package <<endl;
                    cout <<"=============================================\n";
                }
            }
            if (flag2 == 0) cout <<"###############- Not found - #############"<<endl;
        }
        file.close();
        break;


        case 3 :
            return;
        }
    }

    void binarySearchForPK ()
    {   fstream file;

        double IDs [100];
        string DNs [100];
        string DAs [100];
        string DPs [100];
        string TPs [100];
        pharmacy mypharmacy;
        int counter = 1;
        file.open("pharmacy.txt" , ios::in);
        while (true)
        {

            file.getline(mypharmacy.drug_id , 100 , '|') ;
            file.getline(mypharmacy.drug_name, 100 , '|');
            file.getline(mypharmacy.Drug_Amount , 100 , '|');
            file.getline(mypharmacy.Price , 100 , '|');
            file.getline(mypharmacy.Type_of_Package , 100 , '\n') ;

            IDs [counter] = strtod(mypharmacy.drug_id , NULL);
            DNs [counter] = mypharmacy.drug_name;
            DAs [counter] = mypharmacy.Drug_Amount;
            DPs [counter] = mypharmacy.Price;
            TPs [counter] = mypharmacy.Type_of_Package;
            if (file.eof())
                break;
            else
                counter++;
        }
        file.close();
        ///////////////////////// Sorting ///////////////
        int i , j , temp , tempx;
        for(i=1; i<=counter; ++i)
        {
            for(j=0; j <= (counter-i) ; ++j)
                if(IDs[j]>IDs[j+1])
                {
                    temp=IDs[j];
                    IDs[j]=IDs[j+1];
                    IDs[j+1]=temp;

                }
        }

        cout << "Enter the drug ID to search with Binary Search Method :" <<endl;
        double id;
        cin >> id ;
        while (true)
        {
            if (cin.fail() ||  id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid ID :" << endl;
                cin >> id ;
            }
            else break;
        }
        int posetion = binarySearch(IDs , 0 , counter , id) ;
        if ( posetion != -1 )
        {

            cout << "##################_Found _###############"<<'\n'<< endl;
            cout <<"DRUG ID : "<< IDs[posetion] << endl;
            cout <<"DRUG NAME : "<< DNs[posetion] << endl;
            cout <<"DRUG AMOUNT : " << DAs[posetion] << endl;
            cout <<"PRICE : " << DPs [posetion] << endl;
            cout <<"TYPE OF PACKAGE : "<< TPs [posetion] << endl;

        }
        else cout << "***************** Not Found ******************"<<endl;
        return;
    }
///////////////////////////////////////////////////////////////////////////////////////////////
    int binarySearch(double ID[], int lowerbound, int upperbound, double key)
    {
        int curr;
        curr = ( lowerbound + upperbound) / 2;

        while((ID[curr] != key) && (lowerbound <= upperbound))
        {
            if (ID[curr] > key)
            {
                upperbound = curr- 1;
            }
            else
            {
                lowerbound = curr+ 1;
            }
            curr = (lowerbound + upperbound) / 2;
        }
        if (lowerbound <= upperbound)
            return curr;

        else
            return -1;
    }

    void deleteing ()
    {
        fstream file;
        system("cls");
        fstream file1;
        file.open("pharmacy.txt" , ios::in | ios::out | ios::app);
        file1.open("delete.txt" ,  ios::out);
        int flag = 0;
        int deleted = 0;
        cout << "ENTER DRUG ID YOU WANT TO DELETE :"<<endl;
        double id ;
        cin >> id ;
        while (true)
        {
            if (cin.fail() ||  id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid ID :" << endl;
                cin >> id ;
            }
            else break;
        }
        pharmacy mypharmacy;
        while (!file.eof())
        {

            file.getline(mypharmacy.drug_id , 100 , '|') ;
            file.getline(mypharmacy.drug_name, 100 , '|');
            file.getline(mypharmacy.Drug_Amount , 100 , '|');
            file.getline(mypharmacy.Price , 100 , '|');
            file.getline(mypharmacy.Type_of_Package , 100 , '\n') ;
            file1.seekg(0 , ios::end);
            if (strtod(mypharmacy.drug_id,NULL) != id)
            {
                if(file1.tellp() == 0)
                    file1  << mypharmacy.drug_id<< "|" <<mypharmacy.drug_name<< "|" << mypharmacy.Drug_Amount << "|" << mypharmacy.Price << "|" << mypharmacy.Type_of_Package;
                else
                    file1 << "\n" <<mypharmacy.drug_id<< "|" <<mypharmacy.drug_name << "|" << mypharmacy.Drug_Amount<< "|" << mypharmacy.Price << "|" << mypharmacy.Type_of_Package;

            }
            else
            {
                flag = 1;
                deleted = 1;
            }
        }
        file.close();
        file1.close();
        remove("pharmacy.txt");
        rename("delete.txt" , "pharmacy.txt" );
        if (flag)
            cout << "==> Deleted <==" <<endl;
        else cout <<" ==> Not Found <==" <<endl;

    }

    void updating ()
    {
        fstream file;
        system("cls");
        fstream file1;
        file.open("pharmacy.txt" , ios::in | ios::out | ios::app);
        file1.open("Update.txt" ,  ios::out);
        int flag = 0;
        cout << "ENTER DRUG ID YOU WANT TO  UPDATE :"<<endl;
        double id ;
        cin >> id ;
        while (true)
        {
            if (cin.fail() ||  id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid ID :" << endl;
                cin >> id ;
            }
            else break;
        }
        pharmacy mypharmacy;
        while (!file.eof())
        {
             file.getline(mypharmacy.drug_id , 100 , '|') ;
            file.getline(mypharmacy.drug_name, 100 , '|');
            file.getline(mypharmacy.Drug_Amount , 100 , '|');
            file.getline(mypharmacy.Price , 100 , '|');
            file.getline(mypharmacy.Type_of_Package , 100 , '\n') ;
            file1.seekg(0 , ios::end);
            if (strtod(mypharmacy.drug_id,NULL) != id)
            {
                if(file1.tellp() == 0)
                    file1  << mypharmacy.drug_id<< "|" <<mypharmacy.drug_name<< "|" << mypharmacy.Drug_Amount << "|" << mypharmacy.Price << "|" << mypharmacy.Type_of_Package;
                else
                    file1 << "\n" <<mypharmacy.drug_id<< "|" <<mypharmacy.drug_name << "|" << mypharmacy.Drug_Amount<< "|" << mypharmacy.Price << "|" << mypharmacy.Type_of_Package;

            }
            else
            {
                cout << "==> Found <==" << endl;
                cout << "ID : " << mypharmacy.drug_id<<endl;
                cout << "First Name : " << mypharmacy.drug_name<<endl;
                cout << "Last Name : " << mypharmacy.Drug_Amount<<endl;
                cout << "City : " << mypharmacy.Price<<endl;
                cout << "Grade : " << mypharmacy.Type_of_Package<<endl;
                cout << " Now you will Update this Data"<<endl;
                zpharmacy xpharmacy ;
tt :
                xpharmacy.zdrug_id;
                fstream file;
                file.open( "pharmacy.txt" , ios::in | ios::out | ios::app );
                int i = 0 ;
                while (true)
                {
                    cout << "ENTER THE NEW DRUG ID :"<<endl;
                    cin >> xpharmacy.zdrug_id;
                    while (true)
                    {
                        if (cin.fail() ||  xpharmacy.zdrug_id<= 0)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "please Enter a Valid ID :" << endl;
                            cin >> xpharmacy.zdrug_id ;
                        }
                        else break;
                    }
                     if (xpharmacy.zdrug_id != strtod(mypharmacy.drug_id, NULL)){
                    pharmacy mypharmacy;

                    while (!file.eof())
                    {
            file.getline(mypharmacy.drug_id , 100 , '|') ;
            file.getline(mypharmacy.drug_name, 100 , '|');
            file.getline(mypharmacy.Drug_Amount , 100 , '|');
            file.getline(mypharmacy.Price , 100 , '|');
            file.getline(mypharmacy.Type_of_Package , 100 , '\n') ;

                        if ( xpharmacy.zdrug_id == strtod(mypharmacy.drug_id , NULL))
                            i = 1;

                    }

                    }
                    if (i == 1 )
                    {
                        cout <<"THIS DRUG ID IS ALREADY EXIST .... \n";
                        goto tt;
                    }
                    else break;

                }
                cin.ignore();

        cout << "Enter NEW DRUG NAME : ";
        validateName(xpharmacy.zdrug_name);
        cout << "Enter NEW DRUG AMOUNT : ";
        cin>>xpharmacy.zDrug_Amount;
        cout << "Enter NEW PRICE : ";
        cin>>xpharmacy.zPrice;
        cout << "Enter NEW TYPE OF PACKAGE : ";
        cin >> xpharmacy.zType_of_Package;

                if(file1.tellp() == 0)
                {
                    file1 << xpharmacy.zdrug_id<< "|" << xpharmacy.zdrug_name << "|" << xpharmacy.zDrug_Amount << "|" << xpharmacy.zPrice << "|" << xpharmacy.zType_of_Package;
                }
                else
                {
                    file1 << "\n"  << xpharmacy.zdrug_id<< "|" << xpharmacy.zdrug_name << "|" << xpharmacy.zDrug_Amount << "|" << xpharmacy.zPrice << "|" << xpharmacy.zType_of_Package;
                }
                system("cls");
                cout << "==> Updated Successfuly <=="<<endl;
                flag = 1;
            }
        }
        file.close();
        file1.close();
        remove("pharmacy.txt");
        rename("Update.txt" , "pharmacy.txt");
        if (!flag)
            cout <<" ==> Not Found <== " <<endl;
        cout << "\n \n \n \n \n "<<endl;
        cout << "press (Y/y) if you want to update another drug id \nany thing else if you want to continue.   ";
                char ch;
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    updating();

    }
};
int main()
{   File file;
zz:
    string pass;
    cout<<"\t\t\t$Welcome to our project pharmacy $\t"<<endl;
    cout<<"\t\t\t\t***************\n"<<endl;
    cout<<"\t\t\t$=====Hello my dear user======$\t"<<endl;
    cout<<"\t\t\t        ENTER YOUR PASSWORD "<<endl;
     cout<<"\t\t\t$============Welcome=========$\t"<<endl;
 cin>>pass;
    if(pass=="sec12"){
    system("cls");
gg:
    cout<<"\n\n";

    cin.clear();
    int i;


    cout<<" \t\t\t ENTER '1' TO INSERT DRUG .\n \t\t\t ENTER '2' TO VIEW CONTENT.\n \t\t\t ENTER '3' TO SEARCH DRUG. \n \t\t\t ENTER '4' TO BINARY SEARCH. \n \t\t\t ENTER '5' TO DELETE DRUG .\n \t\t\t ENTER '6' TO UPDATE DATA. \n \n   \t\t\t   OR PRESS '0' TO (EXITE) "<<'\n'<<endl;

     cout<<"YOUR CHOICE IS : ";
     cin>>i;
aa:
    switch (i){
    case 1:
            file.insert();
            goto gg;
break;
case 2:
                file.view();
goto gg;
break;
case 3:
                file.Search();
goto gg;
break;
case 4:
                file.binarySearchForPK();
goto gg;
break;
case 5:
               file.deleteing ();
goto gg;
break;
case 6:
               file.updating();
goto gg;
break;
case 0:
           return 0;
break;
default :
cout<<"enter a valied choice : ";
cin>>i;
goto aa;
    }

    }
    else
        goto zz;

    return 0;
}
