#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

int curEmpNo=0,reqEmpNo=0,empArrSize=0;

struct employee
{
	int code;

	char name[50];

	float salary;

	float reduction;

	float bonus;
};

struct employee empArr[100];

void drawRect(int st_pos_x,int st_pos_y,int width,int height);

void drawText(int st_pos_x,int st_pos_y,int text_len,char text[],char clor[]);

void drawNoEmpMeg(void);

void actionApp(void);

void drawExit(void);

int iscodeunique(int emp_num,int code);

int getUserCode(int emp_num);

float getUserSalary(void);

float getUserBonus(void);

float getUserReduction(float salary);

void addNewEmp(int emp_num);

void displayEmp(int emp_num);

void runApp(void);

void drawMenuButton(void);

void drawNextButton(void);

void drawPrevButton(void);

void drawNewButton(void);

void drawDisplyButton(void);

void drawExitButton(void);

int main(void)
{
	runApp();

	getch();

	return 0;

}

void runApp(void){

	system("cls");

	//start position x, start position y, width ,height

	drawRect(20,3,40,17);//screen app width=40 height=15

	drawRect(30,7,20,3); // new rectangle width=20, height=3

	drawRect(30,11,20,3);// display rectangle width=20, height=3

	drawRect(30,15,20,3);// exit rectangle width=20, height=3

	drawText(30,4,20,"ITI System","GREEN");

	drawText(30,7,20,"new","GREEN");

	drawText(30,11,20,"display","BLUE");

	drawText(30,15,20,"exit","BLUE");

	gotoxy(40,8); // in the middle of first rect = new

	actionApp();

}

void actionApp (void)
{
	int currentPosY=wherey();

	char arrow;

	while(1)

	{

		if(currentPosY ==8) drawNewButton();

		else if (currentPosY==12) drawDisplyButton();

		else drawExitButton();

		flushall();

		arrow=getch();

		if(arrow==NULL)
		{
			  arrow=getch();

			  if(arrow==72)  //go to up
			  {
				if (currentPosY==8) currentPosY=16;

				else currentPosY -=4;

			  }

			  else if(arrow==80) //go to down
			  {
				 if(currentPosY == 16) currentPosY=8;

				 else currentPosY+=4;

			  }
			  gotoxy(wherex(),currentPosY);
		}

		else if (arrow ==13)
		{

			if(currentPosY==8)   //add new employee

			{

				empArrSize++;

				addNewEmp(empArrSize-1);

			}

			else if(currentPosY==16) drawExit();

			else // display employee

			{
				if (empArrSize<=0) //if there is no employee to disply
				{
					 drawNoEmpMeg();

					 runApp();
				}

				else
				{
					reqEmpNo=curEmpNo; //to print always last employee user disply

					displayEmp(reqEmpNo);
				}
			}

			break;  // when press enter mean another page will disply so break from home page
		}
	}
}

void drawNoEmpMeg()
{
	char arrow;

	system("cls");

	drawRect(10,5,60,15);//screen app width=40 height=15

	drawText(30,6,20,"ITI System","GREEN");

	drawText(25,10,30,"There is no employee yet to disply!","RED");

	drawText(25,12,30,"Please add new employees then you can disply them!","GREEN");

	drawText(25,13,30,"press enter key to back to home","");

	arrow=getch();

	if (arrow==13) return;

}

int iscodeunique(int emp_num,int code)
{
	int i;

	for (i=0;i<=emp_num;i++)//start from first employee to last one entered
	{
		if (code ==(empArr[i].code)) return 1;//duplicated code so refuse it
	}
	return 0;
}

void addNewEmp(int emp_num)
{

	char arrow;

	struct employee e;

	e.code=getUserCode(emp_num);

	drawText(10,8,20,"Emplyee_Name: ","BLUE");

	gotoxy(35,9);

	flushall();

	gets(e.name);

	e.salary=getUserSalary();

	e.bonus=getUserBonus();

	e.reduction=getUserReduction(e.salary);

	gotoxy(40,21);

	drawRect(35,20,10,3);

	drawText(35,20,10,"Save","GREEN");

	while (1)
	{

		flushall();

		arrow=getch();

		if(arrow==13)
		{
			empArr[emp_num]=e;//press enter to save data

			runApp();

			break;

		}
	}
}
int getUserCode(int emp_num)
{

	int code;

	while (1)
	{

		system("cls");

		drawRect(5,3,70,21);

		drawText(5,4,70,"ITI System","GREEN");

		drawText(10,6,20,"Emplyee_ID: ","BLUE");

		gotoxy(35,7);

		scanf("%d",&code);

		if(iscodeunique(emp_num,code)==0) return code; //this code is unique

						  //so accept it and break to enter the rest of info


		drawText(15,8,50,"please enter uniqu code! To continue press enter"

		,"RED");

		getch();
	}

}

float getUserSalary()
{
	float salary;

	while(1)
	{

		drawText(10,10,20,"Employee_Salary: ","BLUE");

		gotoxy(35,11);

		printf("                ");

		gotoxy(35,11);

		scanf("%f",&salary);

		if(salary>=5000) return salary;

		drawText(15,13,50,

		"can't enter employee'salary less than 5k! To continue press enter"

		,"RED");

		getch();

		gotoxy(6,14);

		printf("                                                                   ");

	}

}

float getUserBonus()
{
	float bonus;

	while(1)
	{
		drawText(10,12,20,"Employee_Bonus: ","BLUE");

		gotoxy(35,13);

		printf("                ");

		gotoxy(35,13);

		scanf("%f",&bonus);

		if(bonus>=0) return bonus;

		drawText(15,14,50,"can't enter negative bonus! To continue press enter"

		,"RED");

		getch();

		gotoxy(6,15);

		printf("                                                                    ");
	}

}

float getUserReduction(float salary)
{

	float reduction;

	while(1)
	{

		drawText(10,15,20,"Emplyee_Reduction: ","BLUE");

		gotoxy(35,16);

		printf("                ");

		gotoxy(35,16);

		scanf("%f",&reduction);

		if(reduction>0 && reduction<0.5*salary) return reduction;

		drawText(30,16,20,"can't enter reduction negative!"

		,"RED");

		drawText(30,17,20,"or more than the half of employee salary!","RED");

		drawText(30,18,20,"To continue press enter","RED");

		getch();

		gotoxy(6,17);

		printf("			                                            ");

		gotoxy(6,18);

		printf("                                                        ");

		gotoxy(6,19);

		printf("                                                        ");
	}


}

void displayEmp(int emp_num)
{

	int positionX;

	double netSalary;

	char arrow;

	curEmpNo= emp_num;

	//reqEmpNo++;

	//if (reqEmpNo == empArrSize) reqEmpNo=0; //to print first employee

										   //not carbage data


	netSalary=empArr[emp_num].salary+empArr[emp_num].bonus

	-empArr[emp_num].reduction;

	system("cls");


	drawRect(10,4,60,18);

	gotoxy(40-strlen("EmployeeNo    ")/2,6);

	textcolor(GREEN);

	cprintf("EmployeeNo %d",emp_num+1);


	drawText(10,8,25,"Emplyee_Name: ","BLUE");

	gotoxy(40,9);

	textcolor(GREEN);

	cprintf("%s",empArr[emp_num].name);

	drawText(10,10,25,"Emplyee_ID: ","BLUE");

	gotoxy(40,11);

	textcolor(GREEN);

	cprintf("%d",empArr[emp_num].code);

	drawText(10,12,25,"Employee_Net_Salary: ","BLUE");

	gotoxy(40,13);

	textcolor(GREEN);

	cprintf("%f",netSalary);

	gotoxy(40,20);  //go to menu

	positionX=40;

	drawMenuButton();

	while(1)
	{
		flushall();

		arrow=getch();

		if(arrow==NULL)
		{
			arrow=getch();

			if(arrow==77) //go to right
			{
				if(positionX !=60) positionX+=20;

				else positionX=20;

			}
			else if(arrow == 75)//go to left
			{
				if (positionX !=20) positionX-=20;

				else positionX=60;
			}

			if (positionX == 20) drawPrevButton();

			else if (positionX == 40) drawMenuButton();

			else if (positionX == 60) drawNextButton();
		}

		else if (arrow ==13) //press enter
		{

			if(positionX == 20) //press previou button
			{

				reqEmpNo=curEmpNo-1; // get previous employee

				if (reqEmpNo <0) reqEmpNo =empArrSize-1;  //get first employee

				displayEmp(reqEmpNo);

				break;
			}

			else if (positionX == 40)

			{ //press menu button

				runApp();

				break;
			}

			else if (positionX == 60) //press next button
			{
				reqEmpNo=curEmpNo+1;

				if(reqEmpNo >= empArrSize) reqEmpNo=0;//last employee

				displayEmp(reqEmpNo);

				break;

			}
		}

	}
}

void drawMenuButton(void)
{
	drawRect(35,18,10,3);

	drawText(35,18,10,"Home","GREEN");

	drawRect(15,18,10,3);

	drawText(15,18,10,"Prev","BLUE");

	drawRect(55,18,10,3);

	drawText(55,18,10,"Next","BLUE");
}
void drawNextButton(void)
{
	drawRect(35,18,10,3);

	drawText(35,18,10,"Home","BLUE");

	drawRect(15,18,10,3);

	drawText(15,18,10,"Prev","BLUE");

	drawRect(55,18,10,3);

	drawText(55,18,10,"Next","GREEN");
}
void drawPrevButton(void)
{
	drawRect(35,18,10,3);

	drawText(35,18,10,"Home","BLUE");

	drawRect(15,18,10,3);

	drawText(15,18,10,"Prev","GREEN");

	drawRect(55,18,10,3);

	drawText(55,18,10,"Next","BLUE");
}

void drawExit(void)
{
	system("cls");

	drawRect(20,5,40,15);

	drawRect(30,9,20,9);

	drawText(20,6,40,"ITI System","GREEN");

	drawText(30,10,20,"Thank you! ","BLUE");

	drawText(30,13,20," For your time ","BLUE");

}

void drawRect(int st_pos_x,int st_pos_y,int width,int height)
{
	int i=0,j=0,startX=st_pos_x;

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			gotoxy(st_pos_x ++,st_pos_y);


			if(i==0 || i==height-1) printf("* ");

			else if(j==0||j==width-1) printf("* ");

		}
		st_pos_y++;

		st_pos_x=startX;
	}
}

void drawText(int st_pos_x,int st_pos_y,int text_len,char text[],char clor[])
{
	int strLen=strlen(text);

	int startPosX=(text_len-strLen)/2;

	gotoxy(st_pos_x+startPosX,st_pos_y+1);


	if(strcmp(clor,"BLUE")==0) textcolor(BLUE);

	else if(strcmp(clor,"GREEN")==0) textcolor(GREEN);

	else if (strcmp(clor,"RED")==0) textcolor(RED);

	cprintf("%s",text);

}

void drawNewButton(void)
{
	drawText(30,7,20,"New","GREEN");

	drawText(30,11,20,"Display","BLUE");

	drawText(30,15,20,"Exit","BLUE");

}

void drawDisplyButton(void)
{
	drawText(30,7,20,"New","BLUE");

	drawText(30,11,20,"Display","GREEN");

	drawText(30,15,20,"Exit","BLUE");
}

void drawExitButton(void)
{
	drawText(30,7,20,"New","BLUE");

	drawText(30,11,20,"Display","BLUE");

	drawText(30,15,20,"Exit","GREEN");
}