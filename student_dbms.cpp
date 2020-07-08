//including the required libraries
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//creating a structure to store info
struct student{
	
	int roll;
	char name[50];
	int phy, chem, math, eng, cs; //marks
	float per;
	char grade;
	int std;
}s;

//pointer to the file which stores student data
FILE *fp;

//function to enter student data
void student_write(){

	fp = fopen("students.dat","ab"); //open file in append mode
	//enter student details
	cout << "\n\t\tPlease enter the details of the student: ";
	cout << "\n\t\tEnter the Roll Number: ";
	cin >> s.roll;
	fflush(stdin);
	cout << "\n\t\tEnter the Name: ";
	gets(s.name);
	cout << "\n\t\tEnter the Marks in Physics (out of 100): ";
	cin >> s.phy;
	cout << "\n\t\tEnter the Marks in Chemistry (out of 100): ";
	cin >> s.chem;
	cout << "\n\t\tEnter the Marks in Maths (out of 100): ";
	cin >> s.math;
	cout << "\n\t\tEnter the Marks in English (out of 100): ";
	cin >> s.eng;
	cout << "\n\t\tEnter the Marks in Computer Science (out of 100): ";
	cin >> s.cs;
	
	//calculate percentage
	s.per = (s.phy + s.chem + s.eng + s.cs + s.math)/5.0;

	//code for grade calculation
	if (s.per>=80)
	{
		s.grade = 'A';
	}
	else if (s.per>=50 && s.per<80)
	{
		s.grade = 'B';
	}
	else if (s.per>=25 && s.per<50)
	{
		s.grade = 'C';
	}
	else
	{
		s.grade = 'F';
	}
	
	//wrrite it to the file
	fwrite(&s, sizeof(s), 1, fp);
	fclose(fp);
	cout << "\n\t\tRECORD CREATED SUCCESSFULLY!";
	getch();
}

//function to display all records
void display_all(){

	system("cls");
	cout << "\n\t\tDISPLAYING ALL RECORDS!";
	fp = fopen("students.dat","rb"); //open file in read mode
	
	//base condition
	if(fp==NULL){

		cout << "\n\t\tNO RECORDS EXIST!";
		getch();
	}
	//reading the file and displaying the data
	//using a loop to display all records
	while((fread(&s, sizeof(s), 1, fp))>0){

		cout << "\n\t\tRoll Number of student: " << s.roll;
		cout << "\n\t\tName of student: " << s.name;
		cout << "\n\t\tMarks in Physics (out of 100): " << s.phy;
		cout << "\n\t\tMarks in Chemistry (out of 100): " << s.chem;
		cout << "\n\t\tMarks in Maths (out of 100): " << s.math;
		cout << "\n\t\tMarks in English (out of 100): " << s.eng;
		cout << "\n\t\tMarks in Computer Science (out of 100): " << s.cs;
		cout << "\n\t\tPercentage of student: " << s.per;
		cout << "\n\t\tGrade of student: " << s.grade;
		cout << "\n\n====================================\n";
		
	}
	fclose(fp);
	getch();
}

//function to display individual student data
void display_student(int n){

	int flag=0;
	fp = fopen("students.dat", "rb"); //open file in read mode
	//reading the file and displaying the student data
	while((fread(&s, sizeof(s), 1, fp))>0){
		//compare entered roll number with existing records
		if(s.roll==n){

			cout << "\n\t\tRoll Number of student: " << s.roll;
			cout << "\n\t\tName of student: " << s.name;
			cout << "\n\t\tMarks in Physics (out of 100): " << s.phy;
			cout << "\n\t\tMarks in Chemistry (out of 100): " << s.chem;
			cout << "\n\t\tMarks in Maths (out of 100): " << s.math;
			cout << "\n\t\tMarks in English (out of 100): " << s.eng;
			cout << "\n\t\tMarks in Computer Science (out of 100): " << s.cs;
			cout << "\n\t\tPercentage of student: " << s.per;
			cout << "\n\t\tGrade of student: " << s.grade;
			flag = 1;
		}
	}
	fclose(fp);
	if (flag==0)
	{
		cout << "\n\t\tRECORD DOES NOT EXIST!"; //no record exists
	}
	getch();
}

//function to modify the student record
void student_modify(){

	int num, flag=0;
	system("cls");
	cout << "\n\t\tMODIFY SCREEN";
	cout << "\n\t\tPlease enter the Roll Number of the student to modify: ";
	cin >> num; //input roll number of the student to modify
	fp = fopen("students.dat","rb+"); //open file in rb+ mode
	//read the file
	while(((fread(&s, sizeof(s), 1, fp))>0)&&flag==0){
		//compare the enetered roll number with existing records
		if (s.roll==num){
			
			//print existing records
			cout << "\n\t\tRoll Number of student: " << s.roll;
			cout << "\n\t\tName of student: " << s.name;
			cout << "\n\t\tMarks in Physics (out of 100): " << s.phy;
			cout << "\n\t\tMarks in Chemistry (out of 100): " << s.chem;
			cout << "\n\t\tMarks in Maths (out of 100): " << s.math;
			cout << "\n\t\tMarks in English (out of 100): " << s.eng;
			cout << "\n\t\tMarks in Computer Science (out of 100): " << s.cs;
			cout << "\n\t\tPercentage of student: " << s.per;
			cout << "\n\t\tGrade of student: " << s.grade;
			
			//enter new student details
			cout << "\n\n\t\tPlease enter the new details of the student: ";
			cout << "\n\t\tEnter the Roll Number: ";
			cin >> s.roll;
			fflush(stdin);
			cout << "\n\t\tEnter the Name: ";
			gets(s.name);
			cout << "\n\t\tEnter the Marks in Physics (out of 100): ";
			cin >> s.phy;
			cout << "\n\t\tEnter the Marks in Chemistry (out of 100): ";
			cin >> s.chem;
			cout << "\n\t\tEnter the Marks in Maths (out of 100): ";
			cin >> s.math;
			cout << "\n\t\tEnter the Marks in English (out of 100): ";
			cin >> s.eng;
			cout << "\n\t\tEnter the Marks in Computer Science (out of 100): ";
			cin >> s.cs;
			
			//calculate percentage
			s.per = (s.phy + s.chem + s.eng + s.cs + s.math)/5.0;

			//code for grade calculation
			if (s.per>=80)
			{
				s.grade = 'A';
			}
			else if (s.per>=50 && s.per<80)
			{
				s.grade = 'B';
			}
			else if (s.per>=25 && s.per<50)
			{
				s.grade = 'C';
			}
			else
			{
				s.grade = 'F';
			}
			
			//moving file pointer to the required position
			fseek(fp, -(long)sizeof(s), 1);
			//write new data to the file
			fwrite(&s, sizeof(s), 1, fp);
			cout << "\n\t\tRECORD UPDATED!";
			flag=1;
		}
	}

	fclose(fp);
	if(flag==0){

		cout << "\n\t\tRECORD NOT FOUND!"; //if record does not exist
	}
	getch();
}

//function to delete student details
void student_delete(){

	int num;
	FILE *fp2;
	system("cls");
	cout << "\n\t\tDELETE RECORD";
	cout << "\n\t\tEnter Roll Number of student to delete: ";
	cin >> num; //input roll number to delete
	fp = fopen("students.dat", "rb");
	//open a temporary file
	fp2 = fopen("temp.dat", "wb");
	//move file pointer to required position
	rewind(fp);
	//read the file
	while((fread(&s, sizeof(s), 1, fp))>0){
		
		//compare the roll number to the existing records
		if(s.roll!=num){

			fwrite(&s, sizeof(s), 1, fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	remove("students.dat"); //remove the temporary file
	rename("temp.dat", "students.dat"); //rename the temp file to students
	cout << "\n\t\tRECORD DELETED!";
	getch();
}

//function to display entire class result
void class_result(){

	system("cls");
	fp = fopen("students.dat", "rb");  //open file in read mode
	if(fp==NULL){
		
		//if file could not be opened
		cout << "\n\t\tERROR! FILE COULD NOT BE OPENED! RETURN TO THE ENTRY MENU TO CREATE AN ENTRY";
		cout << "\n\t\tSoftware is closing...";
		getch();
		exit(0);
	}
	//format for output
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    	cout << "====================================================\n";
    	cout << "R.No.  Name       P   C   M   E   CS  Perc   Grade\n";
    	cout << "====================================================\n";
	
	//read the file for displaying required data
    	while((fread(&s, sizeof(s), 1, fp))>0){

    		printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n", s.roll, s.name, s.phy, s.chem, s.math, s.eng, s.cs, s.per, s.grade);
    	}
    	fclose(fp);
    	getch();
}

//function for result menu
void result(){

	int ans, roll;
	char ch;
	cout << "\n\t\tRESULT MENU";
	cout << "\n\t\t1. CLASS RESULT\n\t\t2. STUDENT REPORT CARD\n\t\t3. EXIT"; //components of the menu
	cout << "\n\t\tPlease enter your choice (1-3): ";
	cin >> ans; //input the choice
	switch(ans){
		
		//display entire class result
		case 1: class_result();
				break;
		//display individual records
		case 2: do
		{
			system("cls");
			cout << "\n\t\tEnter the Roll Number of the Student: ";
			cin >> roll;
			display_student(roll);
			cout << "\n\t\tDo you want another record? (y/n)";
			cin >> ch;
		} while (ch=='Y'||ch=='y');

		//exit the menu
		case 3: break;

		default: cout << "\a";
	}
	
}

//function for intro
void introduction(){
	
	cout << "\n\n\t\tSTUDENT DBMS PROJECT";
	cout << "\n\n\t\tBY: PRATHAM N";
	getch();
}

//function for entry menu
void entry_menu(){

	char ch2;
	system("cls");
	//components of the menu
	cout << "\n\t\tENTRY MENU";
	cout << "\n\t\t1. CREATE STUDENT RECORD";
	cout << "\n\t\t2. DISPLAY ALL STUDENT RECORDS";
	cout << "\n\t\t3. SEARCH STUDENT RECORD";
	cout << "\n\t\t4. MODIFY STUDENT RECORD";
	cout << "\n\t\t5. DELETE STUDENT RECORD";
	cout << "\n\t\t6. EXIT";
	cout << "\n\t\tPlease enter your choice (1-6): ";
	cin >> ch2; //input your choice
	
	//switch case for choices
	switch(ch2){
		
		//creating a record
		case '1': system("cls");
				student_write();
				break;

		//display all records
		case '2': display_all();
				break;

		//search the record based on roll number
		case '3': {

			int num;
			system("cls");
			cout << "\n\t\tPlease enter Roll Number: ";
			cin >> num;
			display_student(num);
		}
		break;

		//modifying a record
		case '4': student_modify();
				  break;

		//deleting a record
		case '5': student_delete();
				  break;

		//exit the menu
		case '6': break;

		default: cout << "\a";
				 entry_menu();
	}
}

//driver function
int main(){
	
	char ch;
	introduction();
	do{
		//a menu
		system("cls");
		cout << "\n\t\tMAIN MENU";
		cout << "\n\t\t1.RESULT MENU";
		cout << "\n\t\t2.ENTRY/EDIT MENU";
		cout << "\n\t\t3.EXIT";
		cout << "\n\n\t\tPlease enter your option (1-3): ";
		ch = getche(); //enter the option
		//switch case for the menu
		switch(ch){
			
			//opens the result menu
			case '1':	system("cls");
						result();
						break;
			
			//opens the entry menu
			case '2':	entry_menu();
						break;
			//exits the DBMS			
			case '3':	exit(0);
			
			default:	cout << "\a";
		}
	}while(ch!='3');
	
	return 0;
	
}
