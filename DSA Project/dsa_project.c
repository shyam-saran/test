#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
int count1=0;

struct student_info 
{
    char name[20];               //for student name
    int cnumber;                 // for course number
    char grade[5];               // for assigning grades
} st[55];

struct course_info
{
	int cnumber;       // for course number 
	char cname[20];   // for storing course name 
	int credit;      // number of credit associated with course 
}cr[20];



////////////////////////////////////////////////////Register Student First Time //////////////////////////////////////////////////
register_student()
{
 char flag='y';
 while(flag=='y')
 {
 	printf("enter the student name:  ");
 	scanf("%s",&st[count].name);
 	printf("enter the course number:  ");
 	scanf("%d",&st[count].cnumber);
 	strcpy(st[count].grade,"U");
 	count++;
 	printf("\nDo you want to continue student registration? ");
 	scanf("%s",&flag);
 	
 	if((flag!='y')&(flag!='n'))
		{
			
			while((flag!='y')&(flag!='n'))
			{
				printf("\nenter correct input ");
				printf("\nDo you want to continue?  ");
				scanf("%s",&flag);
			}
		}
 }
}


////////////////////////////////////////////////////Register Courses First Time /////////////////////////////////////////////////////

register_course()
{
	char flag='y';
    while(flag=='y')
		 {
		 	printf("Enter the course number:  ");
		 	scanf("%d",&cr[count1].cnumber);
		 	printf("Enter the course name :  ");
		 	scanf("%s",&cr[count1].cname);
		 	printf("Enter the course credit number : ");
		 	scanf("%d",&cr[count1].credit);
		 	count1++;
		 	printf("\nDo you want to continue course registration? ");
		 	scanf("%s",&flag);
		 	
		 	if((flag!='y')&(flag!='n'))
				{
					
					while((flag!='y')&(flag!='n'))
					{
						printf("\nenter correct input ");
						printf("\nDo you want to continue?  ");
						scanf("%s",&flag);
					}
				}
		 }
}



//////////////////////////////////////////////////////////////Query Number 1///////////////////////////////////////////////
query1()
{
	int cnum;
	printf("Enter course number:  ");
	scanf("%d",&cnum);
	int i;
	for(i=0;i<count;i++)
	{
		if(cnum==st[i].cnumber)
		{
			printf(" %s ",st[i].name);
			printf("\n");
		}
	}
}

//////////////////////////////////////////////////////////////Query Number 2///////////////////////////////////
query2()
{
	char str[20];
	printf("Enter the student name :  ");
	scanf("%s",&str);
	int i;
	for (i=0;i<count;i++)
	{
		if(strcmp(str,st[i].name)==0)
		{

			get_course_info(st[i].cnumber);
		}
	}
}


get_course_info(cnum)
{
	int i;
	for (i=0;i<count1;i++)
	{
		if(cr[i].cnumber==cnum)
		{
			printf("%d , %s , %d ",cr[i].cnumber,cr[i].cname,cr[i].credit);
			printf("\n");
		}
	}
}





//////////////////////////////////////////////////////////////Query Number 3///////////////////////////////////////////////
query3()
{
	int crn1,crn2,i,j;
	printf("Enter course number1 :  ");
	scanf("%d",&crn1);
	printf("Enter course number2 :  ");
	scanf("%d",&crn2);
	
	for(i=0;i<count;i++)
	{   

		if(crn1==st[i].cnumber)
		{

			for(j=i+1;j<count;j++)
			{
				if((strcmp(st[i].name,st[j].name)==0))
				{
					if(st[j].cnumber==crn2)
						printf("%s \n",st[i].name);
				}
			}
		}
	}
}


//////////////////////////////////////////////////////////////Query Number 4///////////////////////////////////////////////

query4()
{
	int crn;
	int i,cnt=0;
	printf("Enter course number:  ");
	scanf("%d",&crn);
	
	for(i=0;i<count;i++)
	{
		if(crn==st[i].cnumber)
		cnt++;
	}
	printf("%d ",cnt);
}




//////////////////////////////////////////////////////////////Query Number 5///////////////////////////////////////////////

query5()
{
	printf("Enter student name :  ");
	scanf("%s",&st[count].name);
	printf("Enter the Course Number : ");
	scanf("%d",&st[count].cnumber);
	strcpy(st[count].grade,"U");
	count++;
}





//////////////////////////////////////////////////////////////Query Number 6///////////////////////////////////////////////

query6()
{
	char str[20];
	char s[20];
	int crn;
	int i,j;
	
	printf("Enter the student name :  ");
	scanf("%s",&str);
	printf("Enter course number :  ");
	scanf("%d",&crn);
	for(i=0;i<count;i++)
	{
		if((strcmp(str,st[i].name)==0)&&(st[i].cnumber==crn))
		{
//			printf("hello");
			break;
		}
		
	}
	if(i!=count-1)
	{
//		printf("i is %d",i);
		for (j=i;j<count-1;j++)
		{ 
	        strcpy(st[j].name,st[j+1].name);
	   		st[j].cnumber=st[j+1].cnumber;
			strcpy(st[j].grade,st[j+1].grade);
		}
	}
	
	count--;
}




//////////////////////////////////////////////////////////////Query Number 7///////////////////////////////////////////////

query7()
{
	char name[20];
	int cnum,i;
	printf("Enter name of student :  ");
	scanf("%s",&name);
	printf("Enter the course numer :  ");
	scanf("%d",&cnum);
	for (i=0;i<count;i++)
	{
		if((strcmp(st[i].name,name)==0)&(st[i].cnumber==cnum))
		{
			printf("Yes");
			return;
		}
	}
	printf("NO");
	return ;
}

printall()
{
	int i;
	for(i=0;i<count;i++)
	{
		printf(" %s , %d , %s \n ",st[i].name,st[i].cnumber,st[i].grade);
	}
}





//////////////////////////////////////////////////////////////Query Number 8///////////////////////////////////////////////

query8()
{
	int num;
	printf("Enter the number : ");
	scanf("%d",&num);
    int visit[count];
    
    
    int i,j,cnt;
    
	for(i=0;i<count;i++)
    {
       visit[i]=0;	
	}
    
    
    for(i=0;i<count;i++)
    {
    	cnt=1;
    	if(visit[i]==0)
    	{
    		for(j=i+1;j<count;j++)
    		{
    			if(strcmp(st[i].name,st[j].name)==0)
    			{
    				cnt++;
    				visit[j]=1;
				}
			}
		}
//		printf("\n name is %s cnt is %d",st[i].name,cnt);
	   if(cnt>num)
	   	printf("%s \n",st[i].name);
	}
}





//////////////////////////////////////////////////////////////Query Number 9///////////////////////////////////////////////

query9()
{
	int visit[count];
	int i,j;
	
	for(i=0;i<count;i++)
    {
       visit[i]=0;	
	}
	
	
	for(i=0;i<count;i++)
    {
    	if(visit[i]==0)
    	{
    		for(j=i+1;j<count;j++)
    		{
    			if(strcmp(st[i].name,st[j].name)==0)
    			{
    				visit[j]=1;
				}
			}
			printf("%s \n",st[i].name);
		}

	}
	
}






//////////////////////////////////////////////////////////////Query Number 10///////////////////////////////////////////////

query10()
{
	int i;
	for(i=0;i<count1;i++)
	{
		printf("%d ,%s , %d \n",cr[i].cnumber,cr[i].cname,cr[i].credit);
	}
}






//////////////////////////////////////////////////////////////Query Number 11///////////////////////////////////////////////
query11()
{
	int num;
	printf("Enter the number :  ");
	scanf("%d",&num);
	int visit[count];
	int i,j,cnt;
	
    
	for(i=0;i<count;i++)
    {
       visit[i]=0;	
	}
    
    
    for(i=0;i<count;i++)
    {
    	cnt=1;
    	if(visit[i]==0)
    	{
    		for(j=i+1;j<count;j++)
    		{
    			if(st[i].cnumber==st[j].cnumber)
    			{
    				cnt++;
    				visit[j]=1;
				}
			}
		}
//		printf("\n name is %s cnt is %d",st[i].name,cnt);
	   if(cnt>num)
	   	get_course_info(st[i].cnumber);
	}
	
}




//////////////////////////////////////////////////////////////Query Number 12///////////////////////////////////////////////
query12()
{
	int credn;
	char str[20];
	printf("enter credit number :  ");
	scanf("%d",&credn);
	printf("enter student name :  ");
	scanf("%s",&str);
	
	
	int i,j,cnum;
	
	for(i=0;i<count;i++)
	{
		if((strcmp(st[i].name,str)==0))
		{ 
//		    printf("hello");
			cnum=st[i].cnumber;
			for(j=0;j<count1;j++)
			{
				if((cr[j].cnumber==cnum)&(cr[j].credit==credn))
				{
					get_course_info(st[i].cnumber);
				}
			}
		}
		
	}
	
}




//////////////////////////////////////////////////////////////Query Number 13///////////////////////////////////////////////

query13()
{
	int credn,i;
	printf("Enter the number : ");
	scanf("%d",&credn);
	for(i=0;i<count1;i++)
	{
		if(credn==cr[i].credit)
			{
				get_course_info(cr[i].cnumber);
			}
	}
}





//////////////////////////////////////////////////////////////Query Number 14///////////////////////////////////////////////

query14()
{
	char str[20];
	int i,j,total_credit=0;
	printf("Enter student name :  ");
	scanf("%s",&str);
	for(i=0;i<count;i++)
	{
		if(strcmp(str,st[i].name)==0)
		{
			for(j=0;j<count1;j++)
			{
				if(cr[j].cnumber==st[i].cnumber)
				  total_credit=total_credit+cr[j].credit;
			}
		}
	}
	printf(" %d ",total_credit);
}



//////////////////////////////////////////////////////////////Query Number 15///////////////////////////////////////////////

query15()
{
	int credn;
	printf("Enter the Number :  ");
	scanf("%d",&credn);
	int visit[count];
	int i,j,k,total_credit;
	
	for(i=0;i<count;i++)
	{
		visit[i]=0;
	}
	
	for(i=0;i<count;i++)
	{
		if(visit[i]==0)
		{    
		    total_credit=0;
			for(j=i;j<count;j++)
			{
				if(strcmp(st[i].name,st[j].name)==0)
				{
					visit[j]=1;
					for(k=0;k<count1;k++)
						{
							if(cr[k].cnumber==st[j].cnumber)
							  total_credit=total_credit+cr[k].credit;
						}
				}
			}
		if (total_credit>=credn)
			{
				printf(st[i].name);
				printf("\n");
			}
		}
		
	}
	
	
}



//////////////////////////////////////////////////////////////Query Number 16///////////////////////////////////////////////

query16()
{
	int i,j;
	float m,crn,total_gd=0,total_crn=0;
	char str[20];
	printf("enter the student name :  ");
	scanf("%s",&str);
	for(i=0;i<count;i++)
	{

		if(strcmp(st[i].name,str)==0)
		{
			printf("Course number= %d , grade %s \n",st[i].cnumber,st[i].grade);
			
			for(j=0;j<count1;j++)
			{
				if(cr[j].cnumber==st[i].cnumber)
					crn=cr[j].credit;
			}
			m=find_gd(st[i].grade);
			
			total_gd=total_gd+(m*crn);
			total_crn=total_crn+crn;
		}
		
	}
	printf(" CGPA IS %f  \n",(1.0*total_gd)/(1.0*total_crn));
}


//////////////////////////////////////////////////////////////Query Number 17///////////////////////////////////////////////

query17()
{
	int i,j,k;
	float m,crn,total_gd=0,total_crn=0,num,gpa;
	char str[20];
	int visit[count];
	
	for(i=0;i<count;i++)
	{
		visit[i]=0;
	}
	
	printf("Enter the number :  ");
	scanf("%f",&num);
	
	for(i=0;i<count;i++)
	{	
	    total_gd=0;
		total_crn=0;
        if(visit[i]==0)
        {
        	for(j=i;j<count;j++)
        	{
			
	        	if(strcmp(st[i].name,st[j].name)==0)
				{

					
					for(k=0;k<count1;k++)
					{
						if(cr[k].cnumber==st[j].cnumber)
							crn=cr[k].credit;
					}
					m=find_gd(st[j].grade);
					
					total_gd=total_gd+(m*crn);
					total_crn=total_crn+crn;
					
					visit[j]=1;
				}
			}
			
			gpa=(1.0*total_gd)/(1.0*total_crn);
			
	if(gpa<num)
				printf("%s \n",st[i].name);
		}
		
		
	}
}


//////////////////////////////////////////////////////////////Query Number 18///////////////////////////////////////////////

query18()
{
	int i,j,k;
	float m,crn,total_gd=0,total_crn=0,num,gpa;
	char str[20];
	int visit[count];
	
	for(i=0;i<count;i++)
	{
		visit[i]=0;
	}
	
	printf("Enter the number :  ");
	scanf("%f",&num);
	
	for(i=0;i<count;i++)
	{	
	    total_gd=0;
		total_crn=0;
        if(visit[i]==0)
        {
        	for(j=i;j<count;j++)
        	{
			
	        	if(strcmp(st[i].name,st[j].name)==0)
				{
					
					for(k=0;k<count1;k++)
					{
						if(cr[k].cnumber==st[j].cnumber)
							crn=cr[k].credit;
					}
					m=find_gd(st[j].grade);
					
					total_gd=total_gd+(m*crn);
					total_crn=total_crn+crn;
					
					visit[j]=1;
				}
			}
			
			gpa=(1.0*total_gd)/(1.0*total_crn);
			

			if(gpa>num)
				printf(" %s \n",st[i].name);
		}
		
		
	}

}





find_gd(char gd[10])
{
	if(strcmp(gd,"A+")==0)
	   return 10;
	else if(strcmp(gd,"A")==0)
	    return 9;
	else if(strcmp(gd,"B+")==0)
	    return 8;
	else if(strcmp(gd,"B")==0)
	    return 7;
	else if(strcmp(gd,"C")==0)
	    return 6;
	else if(strcmp(gd,"D")==0)
	    return 5;
	else if(strcmp(gd,"E")==0)
	    return 4;  
	else if(strcmp(gd,"F")==0)
	    return 0;
	else
		printf("Please enter correct value");    
	
}



//////////////////////////////////////////////////////////////Query Number 19///////////////////////////////////////////////
query19()
{
	char gd[10];
	int i,m,n,coursen;
	printf("Enter the grade :  ");
	scanf("%s",&gd);
	printf("Enter the course number :  ");
	scanf("%d",&coursen);
	m=find_gd(gd);
	for(i=0;i<count;i++)
	{
		if(st[i].cnumber==coursen)
		{
			n=find_gd(st[i].grade);
			if(n>=m)
			printf("%s \n ",st[i].name,m,n);
		}
	}
}




//////////////////////////////////////////////////////////////Query Number 20///////////////////////////////////////////////
query20()
{
	char gd[10];
	int i,m,n,coursen;
	printf("Enter the grade :  ");
	scanf("%s",&gd);
	printf("Enter the course number :  ");
	scanf("%d",&coursen);
	m=find_gd(gd);
	for(i=0;i<count;i++)
	{
		if(st[i].cnumber==coursen)
		{
			n=find_gd(st[i].grade);
			if(n<m)
			printf("%s \n ",st[i].name,m,n);
		}
	}
}




//////////////////////////////////////////////////////////////Query Number 21///////////////////////////////////////////////
query21()
{
	int cnum,i;
	char str[20];
	printf("Enter student name :  ");
	scanf("%s",&str);
	printf("Enter course number :  ");
	scanf("%d",&cnum);
	for(i=0;i<count;i++)
	{
		if((strcmp(str,st[i].name)==0)&(st[i].cnumber==cnum))
		{
			printf("Enter the grade :  ");
			scanf("%s",st[i].grade);
		}
	}
}



////////////////////////////////////////////////////////////// Query Number 22 ///////////////////////////////////////////////
query22()
{
	int crnum;
	printf("Enter Course Number :  ");
	scanf("%d",&crnum);
	int i;
	
	for(i=0;i<count;i++)
	{
		if(st[i].cnumber==crnum)
		{    
//		    printf("cnumber %d name %s grade %s",st[i].cnumber,st[i].name,st[i].grade);
			if(strcmp(st[i].grade,"U")==0)
			{
				printf("Assign grade to %s :  ",st[i].name);
				scanf("%s",&st[i].grade);
			}
		}
	}
}



printallquery()
{   printf("\n");
    printf("\n");
	printf("---------------------------------------All Query are as follow--------------------- ");
	printf("\n 1. GET ALL STUDENTS REGISTERED FOR THE COURSE <course number> ");
	printf("\n 2. GET ALL COURSES <student name> HAS REGISTERED FOR   ");
	printf("\n 3. GET ALL STUDENTS REGISTERED FOR BOTH THE COURSES <course number> AND <course number> ");
	printf("\n 4. GET NUMBER OF STUDENTS REGISTERED FOR <course number> ");
	printf("\n 5. REGISTER STUDENT <student name> FOR THE COURSE <course number> ");
	printf("\n 6. UNREGISTER STUDENT <student name> FOR THE COURSE <course number> ");
	printf("\n 7. HAS STUDENT <student name> REGISTERED FOR THE COURSE <course number> ? ");
	printf("\n 8. GET ALL STUDENTS WHO HAVE REGISTERED FOR MORE THAN <number> COURSES ");
	printf("\n 9. GET A LIST OF ALL STUDENTS ");
	printf("\n 10. GET A LIST OF ALL COURSES");
	printf("\n 11. GET ALL COURSES WHICH HAVE MORE THAN <number> STUDENTS");
	printf("\n 12. GET ALL <number> CREDIT COURSES <student name> HAS REGISTERED FOR");
	printf("\n 13. GET ALL <number> CREDIT COURSES ");
	printf("\n 14. GET THE TOTAL NUMBER OF CREDITS <student name> REGISTERED FOR ");
	printf("\n 15. GET ALL STUDENTS WHO REGISTERED FOR AT LEAST <number> CREDITS");
	printf("\n 16. GET A LIST OF GRADES AND THE GPA OF STUDENT <student name> ");
	printf("\n 17. GET A LIST OF ALL STUDENTS WHO HAS A GPA BELOW <number>");
	printf("\n 18. GET A LIST OF ALL STUDENTS WHO HAS A GPA ABOVE <number>");
	printf("\n 19. GET A LIST OF ALL STUDENTS WHOSE GRADE IS <grade> AND ABOVE IN <course number>");
	printf("\n 20. GET A LIST OF ALL STUDENTS WHOSE GRADE IS BELOW <grade> IN <course number>");
	printf("\n 21. ASSIGN GRADE <grade> TO STUDENT <student name> FOR THE COURSE <course number>");
	printf("\n 22. ASSIGN GRADES FOR THE COURSE <course number>");
	
	printf("\n");
	printf("\n");
}






main()
{
	int query_number;
	char flag;
	printf("--------------------------------------------------Student Management System--------------------------------------------");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
	printf("\nStudent Registration \n");
	register_student();
	
	
	printf("-----------------------------------------------------------------------------------------------------------------------");
	printf("\nCourse registration \n");
	register_course();
	
	
	printf("------------------------------------------------------------------------------------------------------------------------");
	flag='y';
	
	printallquery();
	
	while(flag=='y')
	{
		printf("\nEnter your query number: ");
		scanf("%d",&query_number);
		switch(query_number)
		{
			case 1:
					query1();
					break;
			case 2:
					query2();
					break;
			case 3:
					query3();
					break;
			case 4:
					query4();
					break;
			case 5:
					query5();
					break;
			case 6:
					query6();
					break;
			case 7:
					query7();
					break;
			case 8:
					query8();
					break;
			case 9:
					query9();
					break;
			case 10:
					query10();
					break;
			case 11:
					query11();
					break;
			case 12:
					query12();
					break;
			case 13:
					query13();
					break;
			case 14:
					query14();
					break;
			case 15 :
					query15();
					break;
			case 16:
					query16();
					break;
			case 17:
					query17();
					break;
			case 18:
					query18();
					break;
			case 19:
					query19();
					break;
			case 20:
					query20();
					break;
			case 21:
					query21();
					break;
			case 22:
					query22();
					break;
			case 23:
					printall();
					break;
			default:
					printf("Kindly enter the correct Query Number");
					break;				
		}
		
		printf("\nDo you want to continue?  ");
		scanf("%s",&flag);
		
		

		
		if((flag!='y')&(flag!='n'))
		{
			
			while((flag!='y')&(flag!='n'))
			{
				printf("\nenter correct input ");
				printf("\nDo you want to continue?  ");
				scanf("%s",&flag);
			}
		}
	}
     
}





