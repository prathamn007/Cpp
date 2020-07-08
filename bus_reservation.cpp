/*including the required libraries*/
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include<iomanip>
using namespace std;

static int m = 0;/*variable which counts the number of buses*/

/*creating the required class*/
class b{
	
	/*decalring required variables*/
  	char busnum[5], driver[10], arrival[10], depart[10], from[20], to[20], seat[8][4][10];

/*decalring required functions*/	
public:
  	void install();
	void allotment();
  	void empty();
  	void show();
  	void avail();
  	void position(int i);
}

bus[10]; /*object for class b*/

/*function for formatting reasons*/
void vline(char ch){

  for (int i=80;i>0;i--)

  cout<<ch;

}

/*function for installing the information about a bus in the system*/
void b::install(){

	cout<<"Enter bus no: ";

  	cin>>bus[m].busnum;

  	cout<<"\nEnter Driver's name: ";

  	cin>>bus[m].driver;

  	cout<<"\nArrival time: \t";

  	cin>>bus[m].arrival;

  	cout<<"\nDeparture: \t";

  	cin>>bus[m].depart;

  	cout<<"\nFrom: \t";

  	cin>>bus[m].from;

  	cout<<"\nTo: \t";

  	cin>>bus[m].to;

  	bus[m].empty();

  	m++; /*this variable counts the number of buses*/

}

/*function for allotting the seat in a bus*/
void b::allotment(){

  	int seat;
	
  	char number[5];

  	top: /*label to ensure if bus number isn't correct
  			we come back to this point*/

  	cout<<"Bus number: ";

  	cin>>number;

	int n;

	/*checking if the bus number entered matches the database*/	
  for(n=0;n<=m;n++){

    if(strcmp(bus[n].busnum, number)==0)

    break;

	}
	
	/*code to allot a seat*/
	while(n<=m){

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32){

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else{

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0){

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

    }

    else

      cout<<"The seat no. is already reserved.\n";

    }

    }

	/*If bus number is greater than number of buses then it asks to enter the correct bus number*/
    if(n>m){

      	cout<<"Enter correct bus no.\n";

      	goto top;

    }

}

/*function to print "empty" for unallotted seats*/
void b::empty(){

  	for(int i=0; i<8;i++)
	{

    	for(int j=0;j<4;j++)
    	{

      		strcpy(bus[m].seat[i][j], "Empty");

    	}

  	}

}

/*function to display available buses*/
void b::show(){

  	int k;

  	char number[5];

  	cout<<"Enter bus no: ";

  	cin>>number;

  	for(k=0;k<=m;k++)

  	{

    	if(strcmp(bus[k].busnum, number)==0)

    	break;

  	}

while(k<=m)

{

  	vline('*');

  	cout<<"Bus no: \t"<<bus[k].busnum

  	<<"\nDriver: \t"<<bus[k].driver<<"\t\tArrival time: \t"

  	<<bus[k].arrival<<"\tDeparture time:"<<bus[k].depart

  	<<"\nFrom: \t\t"<<bus[k].from<<"\t\tTo: \t\t"<<

  	bus[k].to<<"\n";

  	vline('*');

  	bus[0].position(k);

  	int a=1;

  	for (int i=0; i<8; i++){

    	for(int j=0;j<4;j++){

      		a++;

      		if(strcmp(bus[k].seat[i][j],"Empty")!=0)

      		cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[k].seat[i][j]<<".";

    	}	

  }

  break;

  }

  if(k>m)

    cout<<"Enter correct bus no! ";

}

/*function to show the seat wise view of the bus*/
void b::position(int l){

  	int s=0;m=0;

  	for (int i =0; i<8;i++){

    	cout<<"\n";

    	for (int j = 0;j<4; j++){

      		s++;

      		if(strcmp(bus[l].seat[i][j], "Empty")==0){

          		cout.width(5);

          		cout.fill(' ');

          		cout<<s<<".";

          		cout.width(10);

          		cout.fill(' ');

          		cout<<bus[l].seat[i][j];

          		m++;

        }

        else{

        	cout.width(5);

        	cout.fill(' ');

        	cout<<s<<".";

        	cout.width(10);

        	cout.fill(' ');

        	cout<<bus[l].seat[i][j];

        }

    }

}

  cout<<"\n\nThere are "<<m<<" seats empty in Bus No: "<<bus[l].busnum;

}

/*function to display the buses available*/
void b::avail(){


  	for(int n=0;n<m;n++){

    	vline('*');

    	cout<<"\nBus no: \t"<<bus[n].busnum<<"\nDriver: \t"<<bus[n].driver

    	<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    	<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"

    	<<bus[n].to<<"\n";

    	vline('*');
    	
    }

}

/*Driver function*/
int main(){

	system("cls");

	int option;

	while(1)

	{

   		cout << setw(72) << "---------------------------------------" << endl;
    	cout << setw(72) << "|      WELCOME TO PRATHAM EXPRESS     |" << endl;
    	cout << setw(72) << "---------------------------------------" << endl;
    	cout << setw(74) << "***************************************" << endl;
    	cout << setw(74) << "*           1.INSTALL                 *" << endl;
    	cout << setw(74) << "*           2.TICKET RESERVATION      *" << endl;
    	cout << setw(74) << "*           3.SHOW                    *" << endl;
	    cout << setw(74) << "*           4.BUSES AVAILABLE         *" << endl;
	    cout << setw(74) << "*           5.EXIT                    *" << endl;
	    cout << setw(74) << "***************************************" << endl;
	    cout << setw(70) << "PLEASE CHOOSE YOUR PREFERENCE: ";

  		cin>>option;

		/*switch case for various operations*/
  		switch(option){

    		case 1:  bus[m].install();
			break;
    		
    		case 2:  bus[m].allotment();
			break;
      
    		case 3:  bus[0].show();
			break;
      
    		case 4:  bus[0].avail();
			break;
      
    		case 5:  exit(0);

  		}

	}	

return 0;

}
