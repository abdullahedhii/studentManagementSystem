#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>


struct class_stats{
	float mid1;
	float mid2;
	float finals;
	float totalavg;
	float maxtotal;
	char maxID[9];
};


void mainmenu(); 
void adminlogin();
void teacherlogin();
void studentlogin();
void adminmenu();
void teachermenu();
void studentmenu();
void newstudent();
int checkdata(char id[]); //checks already exisiting records
void uploadmarks(); 
int checkalreadyuploaded(char id[]); //checks already uploaded marks
float getcourseGPA(float total); //gets per course GPA
void viewcoursemarks();  //for student to view marks of each subject
void sectionstats_subject() ; void overallstats(); //for admin to view stats of each course of each subject
void GPAall(); //to view overall gpa -admin
void particularstudent(); //to view course marks of particular student-teacher
void APstats();
void PFstats();
void ECCstats();
void IRSstats();
void CALstats();
void display(struct class_stats,int studentcount); //display graphical stats of each course
void updateoverallGPAfile();
void displayoverallGPA();
void getoverallGPA(char);
void ViewGPA();
int checkexistingGPArecord(char id[]);
void graphicalanalysis();
void generatehistogram(int failed,int passed);
void displayFEES();
void uploadassignmentDATES();
void viewdeadlines();
void failedoverall();
void deanslistofhonor();
void updateexistingmarks();



struct teacher{
	char name[40];
	char id[9];
	char password[20];
	char course[40];
};

//for overall GPA
struct GPA{
	char id[9];
	float GPA;
};

struct marksinfo{
	char id[9];
	float quizzes;
	float assignments;
	float mid1;
	float mid2;
	float finals;
	float total;
	float gpa;
};

char AdminID[]="AD-29@91m";
char AdminPassword[]="lisAD29@01#m";
char ID[9],Password[20];
char name[40];
char section;


	
struct student{
	char name[40];
	char id[9];
	char password[15];
};

struct deadline{
	char course[40];
	char title[40];
	int day;
	int month;
	int year;
	int hour;
	int minutes;
};

struct coursedrop{
	char ID[9];
	int count;
	char course[5][40];
};

int main(){
	printf("\n\n\t\t\t\tFAST NATIONAL UNIVERSITY OF COMPUTER SCIENCES");
		printf("\n\n\t\t\t\t\tSTUDENT MANAGEMENT SYSTEM\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	mainmenu();
}

void mainmenu(){
	char user;
	printf("\tWho should we recognize you as?\n");
	printf("\t\tA.Admin\n\t\tT.Teacher\n\t\tS.Student\n ");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\tEnter here: ");
	scanf(" %c",&user);
	
	switch (user){
		case 'A':
			case 'a':
			    adminlogin();
				break;
		case 'T':
			case 't':
				teacherlogin();
				break;
		case 'S':
			case 's':
				studentlogin();
				break;
						
		default:
			printf("Invalid choice!\n");
			mainmenu();
			break;
			
	}
}
void adminlogin(){
	system("cls");
	printf("\n\t\tEnter your Admin ID: ");
	  fflush(stdin);
    gets(ID);
	printf("\n\t\tEnter your password: ");
	fflush(stdin);
	gets(Password);
	
	Sleep(1000);
	printf("\n\n\t\t\tLoading ");
	for(int i=1;i<=10;i++){
		printf(".");
		Sleep(200);
	}
	  
	    if(strcmp(ID,AdminID)==0 && strcmp(Password,AdminPassword)==0  ){
	    	printf("\n\n\tWelcome Mr.Atif!.Successfully logged in\n");
	    	printf("------------------------------------------------------------------------------------------------------------------------\n");
	    	Sleep(500);
	    	adminmenu();
		}
		else {
		printf("\n\nSorry ! either ID or password was entered incorrectly.Try again!\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		  Sleep(1500);
		adminlogin();
		}
}
void teacherlogin(){
	system("cls");
	printf("\n\n\t\tEnter your teacher ID: ");
	  fflush(stdin);
     	gets(ID);
	printf("\n\t\tEnter your password: ");
	  fflush(stdin);
	    gets(Password);
	    	Sleep(1000);
	printf("\n\t\t\tLoading ");
	for(int i=1;i<=10;i++){
		printf(".");
		Sleep(200);
	}
	FILE*ptr;
	struct teacher record;
	int found=0;
	ptr=fopen("Teacherfile.bin","rb");
	while(fread(&record,sizeof(struct teacher),1,ptr)!=NULL){
		if(strcmp(record.id,ID)==0 && strcmp(record.password,Password)==0){
			strcpy(name,record.name);
			found=1;
			break;
		}
	}
	fclose(ptr);
	if(found==0){
		printf("\n\n\tSorry ! either ID or password was entered incorrectly.Try again!\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
		
		   Sleep(1500);
		teacherlogin();
	}
	else{
		printf("\n\n\tWelcome %s! Successfuly logged in\n",name);
			printf("------------------------------------------------------------------------------------------------------------------------\n");
		  Sleep(500);
		teachermenu();
	}

}

void studentlogin(){
	system("cls");

	printf("\n\n\t\tEnter your section: ");
	scanf(" %c",&section);
	
	printf("\n\t\tEnter your student ID: ");
	  fflush(stdin);
     	gets(ID);
     	
	printf("\n\t\tEnter your password: ");
	  fflush(stdin);
	    gets(Password);
	    
		Sleep(1000);
	printf("\n\t\t\tLoading ");
	for(int i=1;i<=10;i++){
		printf(".");
		Sleep(200);
	}
	    
	FILE*ptr;
	struct student record;
	int found=0;
	
	if(section=='K' || section=='k'){
			ptr=fopen("studentfileK.bin","rb");
	}
	else{
			ptr=fopen("studentfileF.bin","rb");
	}

	while(fread(&record,sizeof(struct student),1,ptr)!=NULL){
		if(strcmp(record.id,ID)==0 && strcmp(record.password,Password)==0){
			strcpy(name,record.name);
			found=1;
			break;
		}
	}
	fclose(ptr);
	if(found==0){
		printf("\n\n\tSorry ! either ID or password was entered incorrectly.Try again!\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
		  Sleep(500);
		studentlogin();
	}
	else{
		printf("\n\n\tWelcome %s! Successfuly logged in\n",name);
			printf("------------------------------------------------------------------------------------------------------------------------\n");
		   Sleep(1500);
		studentmenu();
	}
}

void adminmenu(){
	char task;
	system("cls");
		printf("\n\n\t\t\t\tFAST NATIONAL UNIVERSITY OF COMPUTER SCIENCES");
		printf("\n\n\t\t\t\t\t\tADMIN PORTAL\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\tEnter appropriate letter for your choice of action: ");
	printf("\n\t a. For viewing overall GPA of all students.");	
	printf("\n\t b. For viewing course stats of each Section .");
	printf("\n\t c. For adding a new student record.");
	printf("\n\t d. For finalising semester GPA of all students."); //GPA gets uploaded to files
	printf("\n\t e. To print graphical analysis of each course(passed/failed).");
	printf("\n\t f. To view list of students with overall gpa <2.00 points.");
	printf("\n\t g. To view Deans List Of Honors.")  ;    
	printf("\n\t h. To exit.");
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t Enter here: ");
	
	scanf(" %c",&task);

		
	    switch(task){
	    	
	   	        case 'a':
	   	 	       displayoverallGPA();
	   	 	        break;
	   	 	
	   	        case 'b':
	   	 	        overallstats();
	   	         	break;
	   	 
	   	        case 'c':
	   	         	newstudent();
	   	        	break;
	   	        
	   	        case 'd':
	   	        	updateoverallGPAfile();
	   	        	break;
	   	        
				case 'e':
				    graphicalanalysis();
					break;
				
				case 'f':
				    failedoverall();
					break;
					
	   	 	    case 'g':
	   	 	       	deanslistofhonor();
	   	 	        break;
	   	 	    
									 	
	   	        case 'h':
	   	            exit(1);
	   	            break;
	   	        
	   	        default:
	   	        	printf("\n\tSorry!Invalid choice.Please enter again");
	   	        	adminmenu();
	   	        	break;
	   	        	
	   	 	   
	   }
	   
	   int anothertask;
	   printf("\nDo you wish to perform another task?\n\t1.YES\n\t2.NO\n");
	   printf("\tEnter here: ");
	   scanf("%d",&anothertask);
	   
	   if(anothertask==1){
	   	 adminmenu();
	   }
	   
	   else{
	   	exit(1);
	   } 
	   
	   
}

void teachermenu(){
	char task;
	system("cls");
			printf("\n\n\t\t\t\tFAST NATIONAL UNIVERSITY OF COMPUTER SCIENCES");
		printf("\n\n\t\t\t\t\t\tTEACHER PORTAL\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\tEnter appropriate letter for your choice of action: ");
	printf("\n\t a. For viewing GPA of all students in your course.");
	printf("\n\t b. For viewing class stats of your subject.");
	printf("\n\t c. For uploading student marks .");
	printf("\n\t d. For viewing marks of particular student.");
	printf("\n\t e. To upload assignment deadlines.");
	printf("\n\t f. To update already uploaded marks of a particular student.");
	printf("\n\t g. To exit.");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t Enter here: ");
	scanf(" %c",&task);

	         switch(task){
	            	 case 'a':
	   	            	GPAall();
	   	            	break;
	   	 	
	   	             case 'b':
	   	            	sectionstats_subject();
	   	            	break;
	   	 
	   	             case 'c':
	   	            	uploadmarks();
	   	            	break;
	   	 	         
	   	 	         case 'd':
	   	 	         	particularstudent();
	   	 	         	break;
	   	 	         	
	   	 	         case 'e':
	   	 	         	uploadassignmentDATES();
	   	 	         	break;
	   	 	        
	   	 	         case 'f':
	   	 	         	updateexistingmarks();
	   	 	         	break;
	   	 	         	
	   	 	         case 'g':
	   	                exit(1);
	   	                break;
	   	                
	   	            default:
	   	        	printf("\n\tSorry!Invalid choice.Please enter again");
	   	        	teachermenu();
	   	        	break;
	              }
	
	   int anothertask;
	   printf("\nDo you wish to perform another task?\n\t1.YES\n\t2.NO\n");
	   printf("\tEnter here: ");
	   scanf("%d",&anothertask);
	   
	   if(anothertask==1){
         	teachermenu();
	   }
	   
	   else{
	   	exit(1);
	   } 
	   

         
}

void studentmenu(){
	char task;
	system("cls");
		printf("\n\n\t\t\t\tFAST NATIONAL UNIVERSITY OF COMPUTER SCIENCES");
		printf("\n\n\t\t\t\t\t\tSTUDENT PORTAL\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\tEnter appropriate letter for your choice of action: ");
	printf("\n\t a. For viewing your sessional marks");
	printf("\n\t b. For viewing your semester GPA.");
	printf("\n\t c. To view fees for next semester(scholarship might apply based on semester gpa).");
	printf("\n\t d. View assignment Deadlines.");
	printf("\n\t e. To exit.");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t Enter here: ");
	scanf(" %c",&task);
	
	
		      switch(task){
	                  	 case 'a':
	   	                    	viewcoursemarks();
	   	                       	break;
	   	 	
	   	                 case 'b':
	   	                        ViewGPA();
	   	                     	break;	   	 	
	   	                     	
	   	                 case 'c':
	   	                 	    displayFEES();
	   	                 	    break;
	   	                
	   	                 case 'd':
	   	                 	    viewdeadlines();
	   	                 	    break;
	   	                 
	   	                 case 'e':
	   	                 	   exit(1);
	   	                 	   break;
	   	                 	   
	   	                 default:
	   	            	 printf("\n\tSorry!Invalid choice.Please enter again");
	   	            	 studentmenu();
	   	            	 break;
	   	                 	   
	   	              
	   }
	 
	   	
		int anothertask;
	   printf("\nDo you wish to perform another task?\n\t1.YES\n\t2.NO\n");
	   printf("\tEnter here: ");
	   scanf("%d",&anothertask);
	   
	   if(anothertask==1){
         studentmenu();	
	   }
	   
	   else{
	   	exit(1);
	   } 
	   
	
}

void newstudent(){
	struct student record;
	int n;
	int success=0;
	
	printf("\n\tHow many new student records do you wish to add? ");
	printf("\n\tEnter here: ");
	scanf("%d",&n);
	printf("\n\tIn which section are these records to be added? 'K' or 'F' ");
	printf("\n\tEnter here: ");
	scanf(" %c",&section);
	
	FILE*ptr;
	switch(section){
		    case 'K':
		    	case 'k':
		    		ptr=fopen("studentfileK.bin","ab");
		    		
		    		break;
		    		
		    case 'F':
		    	case 'f':
		    		ptr=fopen("studentfileF.bin","ab");
		    		break;
		    		
		    default:
		    	printf("\n\tSorry!We entertain only two sections as of now.");
	}
	
	
	for(int i=0;i<n;i++){
		
		printf("\nFor Student %d: ",i+1);
		printf("\nEnter name: ");
		fflush(stdin);
		gets(record.name);
		
		printf("\nEnter id: ");
		fflush(stdin);
		gets(record.id);
		
	    int check=checkdata(record.id);
	    if(check==0){
	    	printf("\nRecord with %s id already exists! Please enter data for a new student.",record.id);
	    
			printf("\nEnter id: ");
		    fflush(stdin);
		    gets(record.id);
		    
		    
		}
		printf("\nEnter password: ");
		fflush(stdin);
		gets(record.password);

		fwrite(&record,sizeof(student),1,ptr);
		success=1;
	}
	fclose(ptr);
	
	if(success){
		printf("\nRecords successfully added!\n");
	}

	
	else {
		printf("\nCould not add records.");
	}
}


int checkdata(char id[]){
	
	struct student record;
	FILE*ptr;
    //check section K
	ptr=fopen("studentfileK.bin","rb");
	while(fread(&record,sizeof(student),1,ptr)!=NULL){
		
		if(strcmp(id,record.id)==0){
			    fclose(ptr);
				return 0;
		}
	}
	fclose(ptr);
	
	//check section F
	ptr=fopen("studentfileF.bin","rb");
	while(fread(&record,sizeof(student),1,ptr)!=NULL){
		
		if(strcmp(id,record.id)==0){
			    fclose(ptr);
				return 0;
		}
	}
	fclose(ptr);
	
	return 1;
}

void uploadmarks(){
	
	struct student record;
	struct marksinfo upload;
    int success=0;
	
	printf("\n\tFor which section do you wish to upload marks? 'K' or 'F' ");
	printf("\n\tEnter here: ");
	scanf(" %c",&section);
	
	FILE*ptr1;
	FILE*ptr2;
	
    switch(section){
		    case 'K':
		    	case 'k':
		    		ptr1=fopen("studentfileK.bin","rb");
		    		break;
		    		
		    case 'F':
		    	case 'f':
		    			ptr1=fopen("studentfileF.bin","rb");
		    		break;
		    		
		    default:
		    	printf("\n\tSorry!We entertain only two sections as of now.");
		    	teachermenu();
	}
	system("cls");
	switch (section){
		    case 'K':
		    	case 'k':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr2=fopen("PFKmarks.bin","ab");
    		                printf("\n\t\t\tPROGRAMMING FUNDAMENTALS");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr2=fopen("APKmarks.bin","ab");
	                    	  printf("\n\t\t\tAPPLIED PHYSICS");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr2=fopen("IRSKmarks.bin","ab");
	                    	  printf("\n\t\t\tISLAMIC STUDIES");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr2=fopen("ECCKmarks.bin","ab");
	                    	printf("\n\t\t\tENGLISH COMPOSITION AND COMPREHENSION");
                                  	}
                                  	
	                     else {
			                 ptr2=fopen("CALKmarks.bin","ab");
			                 printf("\n\t\t\tCALCULUS AND ANALYTICAL GEOMETRY");
                                   	}
            break;
            
             case 'F':
		    	case 'f':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr2=fopen("PFFmarks.bin","ab");
    		                  printf("\n\t\t\tPROGRAMMING FUNDAMENTALS");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr2=fopen("APFmarks.bin","ab");
	                    	  printf("\n\t\t\tAPPLIED PHYSICS");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr2=fopen("IRSFmarks.bin","ab");
	                    	  printf("\n\t\t\tISLAMIC STUDIES");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr2=fopen("ECCFmarks.bin","ab");
	                    		printf("\n\t\t\tENGLISH COMPOSITION AND COMPREHENSION");
                                  	}
                                  	
	                     else {
			                 ptr2=fopen("CALFmarks.bin","ab");
			                    printf("\n\t\t\tCALCULUS AND ANALYTICAL GEOMETRY");
                                   	}
            
            
            break;
		    		
	}
   
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    int i=0;
	while(fread(&record,sizeof(struct student),1,ptr1)!=NULL){
		strcpy(upload.id,record.id);
		int check=checkalreadyuploaded(upload.id);
		if(check==1){
			success=1;
			printf("\nMarks for %s have been uploaded already",upload.id);
			continue;
		}
		else{
			uploads:
				printf("\n\n\tFor student ID: %s,Enter Marks Scored in: ",upload.id);
		printf("\n\t Quizzes: ");
		scanf("%f",&upload.quizzes);
		
		printf("\n\t Assignments: ");
		scanf("%f",&upload.assignments);
		
		printf("\n\t Mid1: ");
		scanf("%f",&upload.mid1);
		
		printf("\n\t Mid2: ");
		scanf("%f",&upload.mid2);
		
		printf("\n\t Finals: ");
		scanf("%f",&upload.finals);
		
		upload.total=upload.quizzes+upload.assignments+upload.mid1+upload.mid2+upload.finals;
		if(upload.total>100){
			printf("\nLooks like you entered the marks incorrectly ,the total is supposed to be out of 100 with marks division 10-10-15-15-50.");
			goto uploads;
		}
		upload.gpa=getcourseGPA(upload.total);
		fwrite(&upload,sizeof(marksinfo),1,ptr2);
		success=1;
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
		}
	
	}
	
	fclose(ptr1);
	fclose(ptr2);
	
	if(success){
			printf("\n\t\tMarks uploaded for section %c successfully!",section);
	}

	else {
		printf("\n\t\tError uploading marks");
	}
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}
//check already uploaded marks of a student for teachers
int checkalreadyuploaded(char id[]){
	FILE*ptr;
	struct marksinfo details;
	
		switch (section){
		    case 'K':
		    	case 'k':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr=fopen("PFKmarks.bin","rb");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr=fopen("APKmarks.bin","rb");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr=fopen("IRSKmarks.bin","rb");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr=fopen("ECCKmarks.bin","rb");
                                  	}
                                  	
	                     else {
			                 ptr=fopen("CALKmarks.bin","rb");
                                   	}
            break;
            
             case 'F':
		    	case 'f':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr=fopen("PFFmarks.bin","rb");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr=fopen("APFmarks.bin","rb");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr=fopen("IRSFmarks.bin","rb");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr=fopen("ECCFmarks.bin","rb");
                                  	}
                                  	
	                     else {
			                 ptr=fopen("CALFmarks.bin","rb");
                                   	}
            
            
            break;
	 	    		
	}
	 while( fread(&details,sizeof(marksinfo),1,ptr)!=NULL){
	 	 if(strcmp(details.id,id)==0){
	 	 	 fclose(ptr);
	 	 	 return 1; //record exists
		  }
	 	
	 }
	 fclose(ptr);
	 return 0;
	
}
float getcourseGPA(float total){
	float gpa;
	if(total>=86){
		gpa=4.00;
	}
	else if(total>=82){
		gpa=3.67;
	}
	else if(total>=78){
		gpa=3.33;
	}
	else if(total>=74){
		gpa=3.00;
	}
	else if(total>=70){
		gpa=2.67;
	}
	else if(total>=66){
		gpa=2.33;
	}
	else if(total>=62){
		gpa=2.0;
	}
	else if(total>=58){
		gpa=1.67;
	}
	else if(total>=54){
		gpa=1.33;
	}
	else if(total>=50){
		gpa=1.00;
	}
	else gpa=0.00;
	
	return gpa;
}

void viewcoursemarks(){
	struct marksinfo details;
	int course;


	FILE*ptr;
	system("cls");
	printf("\n\t\tFor which course do you wish to view your marks?");
	printf("\n\t1.Applied Physics");
	printf("\n\t2.Programming Fundamentals");
	printf("\n\t3.English Composition and Comprehension");
	printf("\n\t4.Islamic Studies");
	printf("\n\t5.Calculus And Analytical Geometry");
    printf("\n\tEnter here:");
    scanf("%d",&course);
    
    if(section=='K' || section=='k'){
    	    
			if(course==1){
    	    	ptr=fopen("APKmarks.bin","rb");
			}
			
			else if(course==2){
				ptr=fopen("PFKmarks.bin","rb");
			}
			
			else if(course==3){
				ptr=fopen("ECCKmarks.bin","rb");
			}
			
			else if(course==4){
				ptr=fopen("IRSKmarks.bin","rb");
			}
			
			else if(course==5){
				ptr=fopen("CALKmarks.bin","rb");
			}
			
			else{
				printf("\n\tInvalid course choice.");
			}
			
	}
	
	else if(section=='F' || section=='f'){
		
			if(course==1){
    	    	ptr=fopen("APFmarks.bin","rb");
			}
			
			else if(course==2){
				ptr=fopen("PFFmarks.bin","rb");
			}
			
			else if(course==3){
				ptr=fopen("ECCFmarks.bin","rb");
			}
			
			else if(course==4){
				ptr=fopen("IRSFmarks.bin","rb");
			}
			
			else if(course==5){
				ptr=fopen("CALFmarks.bin","rb");
			}
			else{
				printf("\n\tInvalid course choice.");
			}
	}
	else{
		printf("\n\tInvalid section !");
		studentmenu();
	}
   
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	int success=0;
	while(fread(&details,sizeof(struct marksinfo),1,ptr)!=NULL){
		if(strcmp(ID,details.id)==0){
			printf("\n\tQuizzes: %.2f",details.quizzes);
			printf("\n\tAssignments: %.2f",details.assignments);
			printf("\n\tMid 1: %.2f",details.mid1);
			printf("\n\tMid 2: %.2f",details.mid2);
			printf("\n\tFinals: %.2f",details.finals);
			printf("\n\tTotal: %.2f",details.total);
			printf("\n\tCourse GPA:%.2f points\n",details.gpa);
			if(details.gpa<1){
				printf("\n\tCourse Improvement Required.\n");
			}
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
			success=1;
			break;
		}
	}
	fclose(ptr);
	if(success==0){
		printf("\n\tNo record for student with ID %s exists!\n",ID);
	}
	
}

void particularstudent(){
	system("cls");
	struct marksinfo details;
	char studentID[9];
	
	printf("\n\t\tEnter the ID of student you wish to view marks of: ");
	fflush(stdin);
	gets(studentID);
	
	printf("\n\t\tEnter the section of student you wish to view marks of: ");
	scanf(" %c",&section);
	
	FILE*ptr;
	int success=0;
    switch (section){
		    case 'K':
		    	case 'k':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr=fopen("PFKmarks.bin","rb");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr=fopen("APKmarks.bin","rb");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr=fopen("IRSKmarks.bin","rb");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr=fopen("ECCKmarks.bin","rb");
                                  	}
                                  	
	                     else {
			                 ptr=fopen("CALKmarks.bin","rb");
                                   	}
            break;
            
             case 'F':
		    	case 'f':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr=fopen("PFFmarks.bin","rb");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr=fopen("APFmarks.bin","rb");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr=fopen("IRSFmarks.bin","rb");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr=fopen("ECCFmarks.bin","rb");
                                  	}
                                  	
	                     else {
			                 ptr=fopen("CALFmarks.bin","rb");
                                   	}
            ;
            
            break;
            
            default:
            	printf("\n\tInvalid section!");
		    		
	}
          	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
          while(fread(&details,sizeof(marksinfo),1,ptr)!=NULL){
          	      if(strcmp(studentID,details.id)==0){
          	      	success=1;
          	      	printf("\n\t\tID:%s",details.id);
          	      	printf("\n\t\tQuizzes: %.2f",details.quizzes);
          	      	printf("\n\t\tAssignments: %.2f",details.assignments);
          	      	printf("\n\t\tMid1: %.2f",details.mid1);
          	      	printf("\n\t\tMid2: %.2f",details.mid2);
          	      	printf("\n\t\tFinals: %.2f",details.finals);
          	      	printf("\n\t\tTotal: %.2f",details.total);
          	      	printf("\n\t\tGPA: %.2f\n",details.gpa);
          	      		printf("-----------------------------------------------------------------------------------------------------------------------\n");
          	      	break;
					}
					
		  }
	
	fclose(ptr);
	if(success==0){
		printf("\n\tSorry,No record for %s id exists in your entered section!\n",studentID);
	}
	

}

void GPAall(){;
	struct student record;
	struct marksinfo details;
  
    
	printf("\n\tWhich section do you wish to view GPA of? 'K' or 'F' ");
	printf("\n\tEnter here: ");
	scanf(" %c",&section);
	
	FILE*ptr1;
	FILE*ptr2;
	
    switch(section){
		    case 'K':
		    	case 'k':
		    		ptr1=fopen("studentfileK.bin","rb");
		    		break;
		    		
		    case 'F':
		    	case 'f':
		    		ptr1=fopen("studentfileF.bin","rb");
		    		break;
		    		
		    default:
		    	printf("\n\tInvalid choice.");
	}
	
	switch (section){
		    case 'K':
		    	case 'k':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr2=fopen("PFKmarks.bin","rb");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr2=fopen("APKmarks.bin","rb");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr2=fopen("IRSKmarks.bin","rb");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr2=fopen("ECCKmarks.bin","rb");
                                  	}
                                  	
	                     else {
			                 ptr2=fopen("CALKmarks.bin","rb");
                                   	}
            break;
            
             case 'F':
		    	case 'f':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr2=fopen("PFFmarks.bin","rb");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr2=fopen("APFmarks.bin","rb");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr2=fopen("IRSFmarks.bin","rb");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr2=fopen("ECCFmarks.bin","rb");
                                  	}
                                  	
	                     else {
			                 ptr2=fopen("CALFmarks.bin","rb");
                                   	}
           
            
             break;
		    		
	}
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t ID\t\t\tNAME\t\t\tGPA\n");
	
	while( (fread(&record,sizeof(student),1,ptr1)!=NULL ) && (fread(&details,sizeof(marksinfo),1,ptr2)!=NULL )){
	       printf("\t%9s",record.id);
	       printf("\t%20s",record.name);
	       printf("\t\t%.2f points\n",details.gpa);
	}
	fclose(ptr1);
	fclose(ptr2);
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
}
void sectionstats_subject(){
	
	printf("\n\t\tWhich section do you wish to view course statistics of?");
	scanf(" %c",&section);

	if(Password[0]=='A' && Password[1]=='P'){
		APstats();
	}
	else if(Password[0]=='P' && Password[1]=='F'){
		PFstats();
	}
	else if(Password[0]=='E' && Password[1]=='C' && Password[2]=='C'){
		ECCstats();
	}
	else if(Password[0]=='I' && Password[1]=='R' && Password[2]=='S'){
		IRSstats();
	}
	else {
		CALstats();
	}
	
}
void overallstats(){
	   
	printf("\n\t\tWhich section do you wish to view course statistics of?");
	scanf(" %c",&section);
	
	printf("\n\nApplied physics statistics of section %c",section);
	   	APstats();
	
	printf("\n\nProgramming Fundamentals statistics of section %c",section);
	   	PFstats();
	
	printf("\n\nEnglish Composition and Comprehension statistics of section %c",section);
	   	ECCstats();
	   	
	printf("\n\nIslamic studies statistics of section %c",section);
	   	IRSstats();
	
	printf("\n\nCalculus and Analytical Geometry statistics of section %c",section);
	   	CALstats();
	
	Sleep(200);
}

void APstats(){
	  
	FILE*ptr;
	struct marksinfo details;
	struct class_stats stats;
	int failcnt=0;
	int studentcount=0;
	
    switch(section){
	       	 
	       	case 'K':
	       	 	case 'k':
	       	 		ptr=fopen("APKmarks.bin","rb");
	       	 		break;
	       	
			case 'F':
	       	 	case 'f':
	       	 		ptr=fopen("APFmarks.bin","rb");
	       	 		break;		
	       	
	       	default:
				printf("\n\tInvalid section choice.");	
			
		   }
	
	stats.mid1=0,stats.mid2=0,stats.finals=0,stats.maxtotal=0,stats.totalavg=0;
	while(fread(&details,sizeof(marksinfo),1,ptr)!=NULL){
		 stats.mid1+=details.mid1;
		 stats.mid2+=details.mid2;
		 stats.finals+=details.finals;
		 stats.totalavg+= details.total;
		 if(details.total>stats.maxtotal){
		 	stats.maxtotal=details.total;
		 	strcpy(stats.maxID,details.id);
		 }
		 if(details.total<50){
		 	failcnt++;
		 }
		 studentcount++;
	}
	fclose(ptr);
    
    display(stats,studentcount);
	printf("Number of students who failed: %d\n",failcnt);
}
 
void PFstats(){
	  FILE*ptr;
	struct marksinfo details;
	struct class_stats stats;
	int failcnt=0;
	int studentcount=0;
	
    switch(section){
	       	 
	       	case 'K':
	       	 	case 'k':
	       	 		ptr=fopen("PFKmarks.bin","rb");
	       	 		break;
	       	
			case 'F':
	       	 	case 'f':
	       	 		ptr=fopen("PFFmarks.bin","rb");
	       	 		break;	
						
			default:
				printf("\n\tInvalid section choice.");		
	       	 
		   }
	
	stats.mid1=0,stats.mid2=0,stats.finals=0,stats.maxtotal=0,stats.totalavg=0;
    while(fread(&details,sizeof(marksinfo),1,ptr)!=NULL){
		 stats.mid1+=details.mid1;
		 stats.mid2+=details.mid2;
		 stats.finals+=details.finals;
		 stats.totalavg+= details.total;
		 if(details.total>stats.maxtotal){
		 	stats.maxtotal=details.total;
		 	strcpy(stats.maxID,details.id);
		 }
		 if(details.total<50){
		 	failcnt++;
		 }
		 studentcount++;
	}
	fclose(ptr);
    
    display(stats,studentcount);
	printf("Number of students who failed: %d\n",failcnt);
}

void IRSstats(){
	  FILE*ptr;
	struct marksinfo details;
	struct class_stats stats;
	int failcnt=0;
	int studentcount=0;
	
    switch(section){
	       	 
	       	case 'K':
	       	 	case 'k':
	       	 		ptr=fopen("IRSKmarks.bin","rb");
	       	 		break;
	       	
			case 'F':
	       	 	case 'f':
	       	 		ptr=fopen("IRSFmarks.bin","rb");
	       	 		break;	
						
			default:
				printf("\n\tInvalid section choice.");	
	       	 
		   }
	
	stats.mid1=0,stats.mid2=0,stats.finals=0,stats.maxtotal=0,stats.totalavg=0;
	while(fread(&details,sizeof(marksinfo),1,ptr)!=NULL){
		 stats.mid1+=details.mid1;
		 stats.mid2+=details.mid2;
		 stats.finals+=details.finals;
		 stats.totalavg+= details.total;
		 if(details.total>stats.maxtotal){
		 	stats.maxtotal=details.total;
		 	strcpy(stats.maxID,details.id);
		 }
		 if(details.total<50){
		 	failcnt++;
		 }
		 studentcount++;
	}
	fclose(ptr);
    
    display(stats,studentcount);
	printf("Number of students who failed: %d\n",failcnt);
}

void ECCstats(){
	  FILE*ptr;
	struct marksinfo details;
	struct class_stats stats;
	int failcnt=0;
	int studentcount=0;
	
    switch(section){
	       	 
	       	case 'K':
	       	 	case 'k':
	       	 		ptr=fopen("ECCKmarks.bin","rb");
	       	 		break;
	       	
			case 'F':
	       	 	case 'f':
	       	 		ptr=fopen("ECCFmarks.bin","rb");
	       	 		break;		
	       	 		
	       	default:
				printf("\n\tInvalid section choice.");	
	       	 
		   }
	
	stats.mid1=0,stats.mid2=0,stats.finals=0,stats.maxtotal=0,stats.totalavg=0;
    while(fread(&details,sizeof(marksinfo),1,ptr)!=NULL){
		 stats.mid1+=details.mid1;
		 stats.mid2+=details.mid2;
		 stats.finals+=details.finals;
		 stats.totalavg+= details.total;
		 if(details.total>stats.maxtotal){
		 	stats.maxtotal=details.total;
		 	strcpy(stats.maxID,details.id);
		 }
		 if(details.total<50){
		 	failcnt++;
		 }
		 studentcount++;
	}
	fclose(ptr);
    
    display(stats,studentcount);
	printf("Number of students who failed: %d\n",failcnt);
}

void CALstats(){
	  FILE*ptr;
	struct marksinfo details;
	struct class_stats stats;
	int failcnt=0;
	int studentcount=0;
	
    switch(section){
	       	 
	       	case 'K':
	       	 	case 'k':
	       	 		ptr=fopen("CALKmarks.bin","rb");
	       	 		break;
	       	
			case 'F':
	       	 	case 'f':
	       	 		ptr=fopen("CALFmarks.bin","rb");
	       	 		break;	
						
			default:
				printf("\n\tInvalid section choice.");		
	       	 
		   }
	
	stats.mid1=0,stats.mid2=0,stats.finals=0,stats.maxtotal=0,stats.totalavg=0;
	while(fread(&details,sizeof(marksinfo),1,ptr)!=NULL){
		 stats.mid1+=details.mid1;
		 stats.mid2+=details.mid2;
		 stats.finals+=details.finals;
		 stats.totalavg+= details.total;
		 if(details.total>stats.maxtotal){
		 	stats.maxtotal=details.total;
		 	strcpy(stats.maxID,details.id);
		 }
		 if(details.total<50){
		 	failcnt++;
		 }
		 studentcount++;
	}
	fclose(ptr);
    
    display(stats,studentcount);
	printf("Number of students who failed: %d\n",failcnt);
}

void display(struct class_stats stats,int studentcount){
	        stats.mid1/=studentcount;
	    	stats.mid2/=studentcount;
	    	stats.finals/=studentcount;
	    	stats.totalavg/=studentcount;
	    	printf("\n\nTotal student count is: %d\n",studentcount);
	    	printf("Average score mid 1 is: %.2f\n",stats.mid1);
	    	printf("Average score mid 2 is: %.2f\n",stats.mid2);
	    	printf("Average score finals is: %.2f\n",stats.finals);
	    	printf("Average total score is: %.2f\n",stats.totalavg);
	    	printf("Student ID %s has max score of %.2f\n",stats.maxID,stats.maxtotal); 
	    	printf("-----------------------------------------------------------------------------------------------------------------------\n");
}

void updateoverallGPAfile(){
	
	//GPAs of all sections get finalised together and are written in the same file
	//once for section K 
	getoverallGPA('K');
	//once for section F;
	getoverallGPA('F');
	
}

void getoverallGPA(char section){
	
	struct marksinfo details[5];
	struct GPA update;
	FILE*ptr1;
	FILE*ptr2;
	FILE*ptr3;
	FILE*ptr4;
	FILE*ptr5;
	FILE*ptr6;
	
	int success=0;
	
	ptr1=fopen("overallGPA.bin","ab");
	
	if(section=='K' || section=='k'){
		ptr2=fopen("APKmarks.bin","rb");
		ptr3=fopen("PFKmarks.bin","rb");
		ptr4=fopen("ECCKmarks.bin","rb");
		ptr5=fopen("IRSKmarks.bin","rb");
		ptr6=fopen("CALKmarks.bin","rb");
	}
	else if(section=='F' || section=='f'){
		ptr2=fopen("APFmarks.bin","rb");
		ptr3=fopen("PFFmarks.bin","rb");
		ptr4=fopen("ECCFmarks.bin","rb");
		ptr5=fopen("IRSFmarks.bin","rb");
		ptr6=fopen("CALFmarks.bin","rb");
	}
	else{
		printf("\n\tInvalid section choice!");
	}
	
	while( (fread(&details[0],sizeof(marksinfo),1,ptr2)!=NULL)  &&  (fread(&details[1],sizeof(marksinfo),1,ptr3)!=NULL)  &&
	 (fread(&details[2],sizeof(marksinfo),1,ptr4)!=NULL) && (fread(&details[3],sizeof(marksinfo),1,ptr5)!=NULL) &&
	 (fread(&details[4],sizeof(marksinfo),1,ptr6)!=NULL)) {
	 	    strcpy(update.id,details[0].id);
	 	    int check=checkexistingGPArecord(update.id);
	 	    
		if(check==1){
			success=1;
			   printf("GPA has already been finalised for %s\n",update.id);
	 	     continue;	
			 }
	 	   
	 	else{
	 	    	update.GPA= (details[0].gpa * 3/17) + (details[1].gpa * 3/17) + (details[2].gpa * 3/17) + (details[3].gpa * 3/17) +(details[4].gpa * 3/17);
	 	    fwrite(&update,sizeof(GPA),1,ptr1);
	 	    printf("GPA finalised for %s\n",update.id);
	 	    success=1;
			 }
	 	    
	 }
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");	 
	 fclose(ptr1);
	 fclose(ptr2);
	 fclose(ptr3);
	 fclose(ptr4);
	 fclose(ptr5);
	 fclose(ptr6);
	 
	 if(success){
	 	printf("\n\tOverall GPAs finalised for section %c\n",section);
	 }
	 else{
	 	printf("\n\tError finalising GPAs for section %c,or marks haven't been uploaded yet.",section);
	 }
	 
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

int checkexistingGPArecord(char id[]){
	struct GPA check;
	FILE*ptr;
	ptr=fopen("overallGPA.bin","rb");
	
	while(fread(&check,sizeof(GPA),1,ptr)!=NULL){
		if(strcmp(id,check.id)==0){
			
		    fclose(ptr);
		    return 1;
		}
	
	}
	
	fclose(ptr);
	return 0;
}

void displayoverallGPA(){
	FILE*ptr;
	ptr=fopen("overallGPA.bin","rb");

    struct GPA display;
    
    printf("\n\t\tID\t\tSGPA");
   while(fread(&display,sizeof(GPA),1,ptr)!=NULL){
   	    printf("\n\t\t%s\t%.2fpoints",display.id,display.GPA);
   }
   fclose(ptr);
   	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

void ViewGPA(){
	FILE*ptr;
	ptr=fopen("overallGPA.bin","rb");

    struct GPA display;
    printf("\n\t\tID\t\tSGPA");
    while(fread(&display,sizeof(GPA),1,ptr)!=NULL){
    	if(strcmp(display.id,ID)==0){
    		printf("\n\t\t%s\t%.2fpoints",display.id,display.GPA);
    		if(display.GPA<2){
   	    	printf("\n\t\tAcademic Warning!");
		   }
    		break;
		}
   }
   fclose(ptr);
   	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

void graphicalanalysis(){
	printf("\nEnter section you wish to view graphical analysis of: ");
	scanf(" %c",&section);
	FILE*ptr;
	struct marksinfo details;
	int failed,passed;
	switch(section){
		
		 case'K':
		   case'k':
		   	//Applied physics;
		   	ptr=fopen("APKmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
			printf("\n\nApplied Physics\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
				printf("\n------------------------------------------------------------------------------------------------------------------------\n");
				
		   	
		   	//Programming Fundamentals;
		   	ptr=fopen("PFKmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
			printf("\n\nProgramming Fundamentals\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
				printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
			//English composition and comprehension;
		   	ptr=fopen("ECCKmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
			printf("\n\nEnglish composition and comprehension\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
				printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
			//Islamic Studies;
		   	ptr=fopen("IRSKmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
			printf("\n\nIslamic Studies\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
				printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
			//Calculus;
		   	ptr=fopen("CALKmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
			printf("\n\nCalculus And Analytical Geometry\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
				printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
	    break;
			
			
		case'F':
		   case'f':
		   	//Applied physics;
		   	ptr=fopen("APFmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
			printf("\n\nApplied physics\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
				printf("\n------------------------------------------------------------------------------------------------------------------------\n");
		   	
		   	//Programming Fundamentals;
		   	ptr=fopen("PFFmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
				printf("\n\nProgramming Fundamentals\n");
					printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
			//English composition and comprehension;
		   	ptr=fopen("ECCFmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
				printf("\n\nEnglish composition and comprehension\n");
					printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
			//Islamic Studies;
		   	ptr=fopen("IRSFmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
			printf("\n\nIslamic Studies\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
			//Calculus;
		   	ptr=fopen("CALFmarks.bin","rb");
		   	failed=0,passed=0;
		   	while( fread((&details),sizeof(marksinfo),1,ptr)!=NULL){
		   		   if(details.gpa<1){
		   		     	failed++;
					  }
		   		   else {
		   		   	    passed++;
					  }
			   }
			fclose(ptr);
				printf("\n\nCalculus And Analytical Geometry\n");
				printf("-----------------------------------------------------------------------------------------------------------------------\n");
			generatehistogram(failed,passed);
			printf("\n------------------------------------------------------------------------------------------------------------------------\n");
			
	    break;
	}
}

void generatehistogram(int failed,int passed){
	
	printf("Passed: ");
	for(int i=0;i<passed;i++){
		printf("*");
	}
	
	printf("\nFailed: ");
	for(int i=0;i<failed;i++){
		printf("*");
	}
	
}

void displayFEES(){
	float fees=145000;
	struct GPA check;
	FILE*ptr;
	ptr=fopen("overallGPA.bin","rb");
	while(fread(&check,sizeof(struct GPA),1,ptr)!=NULL){
		if(strcmp(ID,check.id)==0){
			  //scholarship criteria
			  if(check.GPA==4){
			  	printf("\n\t\tCongratulations!75 percent scholarship is available for your next semester.");
			  	fees*= 0.25;
			  }
			  else if(check.GPA>=3.5){
			  	printf("\n\t\tCongratulations!50 percent scholarship is available for your next semester.");
			  	fees*= 0.5;
			  }
			   else if(check.GPA>=3){
			  	printf("\n\t\tCongratulations!25 percent scholarship is available for your next semester.");
			  	fees*= 0.75;
			  }
			  else if(check.GPA>=2.5){
			  	printf("\n\t\tCongratulations! 15 percent scholarship is available for your next semester.");
			  	fees*= 0.85;
			  }
			  break;
		}
	}
	fclose(ptr);
	printf("\n------------------------------------------------------------------------------------------------------------------------");
	    printf("\n\t\tID: %s",ID);
		  	printf("\n\t\tAmount due: %.2f rupees",fees);
			  	printf("\n\t\tDue data: 29th January,2023");
			  		printf("\n------------------------------------------------------------------------------------------------------------------------");
}

void uploadassignmentDATES(){
	FILE*ptr;
	struct deadline date;
	
	if(Password[0]=='A' && Password[1]=='P'){
			strcpy(date.course,"Applied Physics");
	}
	else if(Password[0]=='P' && Password[1]=='F'){
		strcpy(date.course,"Programming Fundamentals");
	}
	else if(Password[0]=='E' && Password[1]=='C' && Password[2]=='C'){
		strcpy(date.course,"English Composition And Comprehension");
	}
	else if(Password[0]=='I' && Password[1]=='R' && Password[2]=='S'){
		strcpy(date.course,"Islamic Studies");
	}
	else if(Password[0]=='C' && Password[1]=='A' && Password[2]=='L'){
		strcpy(date.course,"Calculus And Analytical Geometry");
	}
    printf("\n\t\tEnter assignment title: ");
    fflush(stdin);
    gets(date.title);
    printf("\n\t\tEnter due data (dd mm yy): ");
    scanf("%d %d %d",&date.day,&date.month,&date.year);
    printf("\n\t\tEnter time of deadline (11 59):");
    scanf("%d %d",&date.hour,&date.minutes);
    ptr=fopen("assignmentsdeadline.bin","ab");
    fwrite(&date,sizeof(deadline),1,ptr);
    fclose(ptr);
    printf("\n------------------------------------------------------------------------------------------------------------------------");
}

void viewdeadlines(){
	int due=0,count=0;
	//get current date:
	time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n\t\t\t\t\t\t\t\t\t\tCurrent Date: %d-%d-%d %d:%d:%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900,tm.tm_hour,tm.tm_min,tm.tm_sec);
	
	
	FILE*ptr;
	struct deadline date;
	ptr=fopen("assignmentsdeadline.bin","rb");
		printf("\n------------------------------------------------------------------------------------------------------------------------");
	printf("\n\n\t\t\t\t\tAssignments Due");
	printf("\n------------------------------------------------------------------------------------------------------------------------");
	while(fread(&date,sizeof(deadline),1,ptr)!=NULL){
	    due=0;
		 if( date.month>=tm.tm_mon+1 && date.day>tm.tm_mday){
		 	due=1;
		 }
		 else if ( date.month==tm.tm_mon+1 && date.day<tm.tm_mday){
		 	due=1;
		 }
		 else if(date.day>=tm.tm_mday && date.month==tm.tm_mon+1){
		 	due=1;
		 }
		 else if(date.year>tm.tm_year+1900){
		 	due=1;
		 }
		 if(due){
		 	count++;
		 	printf("\n\n\t\tCourse:%s\n\t\tTitle: %s",date.course,date.title);
		 	printf("\n\t\tDue date: %d/%d/%d\t%d:%d",date.day,date.month,date.year,date.hour,date.minutes);
		 }
		 
		 	}
	fclose(ptr);
	if(count==0){
		printf("\n\t\t\t\tWohoo! no assignments due as of now");
	}
	else printf("\n\nNote:Submission After deadline may result in zero marks");
		printf("\n------------------------------------------------------------------------------------------------------------------------");
}

void failedoverall(){
	 struct GPA record;
	 FILE*ptr;
	 ptr=fopen("overallGPA.bin","rb");
	 	printf("\n------------------------------------------------------------------------------------------------------------------------");
	 printf("\n\n\t\tList of students under acadmeic warning this semester:\n");
	 printf("\n\t\t\t\tID\t\tGPA");
	 while(fread(&record,sizeof(struct GPA),1,ptr)!=NULL){
	 	if(record.GPA<2.0){
	 		printf("\n\t\t\t\t%s\t%.2f",record.id,record.GPA);
		 }
	 }
	 fclose(ptr);
	 	printf("\n------------------------------------------------------------------------------------------------------------------------");
}

void deanslistofhonor(){
	struct GPA record;
	 FILE*ptr;
	 ptr=fopen("overallGPA.bin","rb");
	 	printf("\n------------------------------------------------------------------------------------------------------------------------");
	 printf("\n\n\t\tDEANS LIST OF HONORS:\n");
	 printf("\n\t\t\t\tID\t\tGPA");
	 while(fread(&record,sizeof(struct GPA),1,ptr)!=NULL){
	 	if(record.GPA>=3.5){
	 		printf("\n\t\t\t\t%s\t%.2f",record.id,record.GPA);
		 }
	 }
	 fclose(ptr);
	 	printf("\n------------------------------------------------------------------------------------------------------------------------");
}

void updateexistingmarks(){

	struct marksinfo details;
    char id[9];
    
	printf("\n\tEnter the section of student you wish to update marks of? 'K' or 'F' ");
	printf("\n\tEnter here: ");
	scanf(" %c",&section);
	printf("\n\tEnter the ID of student: ");
	fflush(stdin);
	gets(id);
	char file1[20],file2[20];
	FILE*ptr1;
	FILE*ptr2;
		int success=0;
	switch (section){
		    case 'K':
		    	case 'k':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr1=fopen("PFKmarks.bin","rb");
    		                ptr2=fopen("PFKmarks2.bin","wb");
    		                strcpy(file1,"PFKmarks.bin");
    		                strcpy(file2,"PFKmarks2.bin");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr1=fopen("APKmarks.bin","rb");
	                    	  ptr2=fopen("APKmarks2.bin","wb");
	                    	   strcpy(file1,"APKmarks.bin");
    		                strcpy(file2,"APKmarks2.bin");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr1=fopen("IRSKmarks.bin","rb");
	                    	  ptr2=fopen("IRSKmarks2.bin","wb");
	                    	   strcpy(file1,"IRSKmarks.bin");
    		                strcpy(file2,"IRSKmarks2.bin");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr1=fopen("ECCKmarks.bin","rb");
	                    	ptr2=fopen("ECCKmarks2.bin","wb");
	                    	 strcpy(file1,"ECCKmarks.bin");
    		                strcpy(file2,"ECCKmarks2.bin");
                                  	}
                                  	
	                     else {
			                 ptr1=fopen("CALKmarks.bin","rb");
			                 ptr2=fopen("CALKmarks2.bin","wb");
			                  strcpy(file1,"CALKmarks.bin");
    		                strcpy(file2,"CALKmarks2.bin");
                                   	}
            break;
            
             case 'F':
		    	case 'f':
		    		    if(Password[0]=='P' && Password[1]=='F'){
    		                ptr1=fopen("PFFmarks.bin","rb");
    		                  ptr2=fopen("PFFmarks2.bin","wb");
    		                   strcpy(file1,"PFFmarks.bin");
    		                strcpy(file2,"PFFmarks2.bin");
                              	}
                              	
                    	else if (Password[0]=='A' && Password[1]=='P'){
	                    	ptr1=fopen("APFmarks.bin","rb");
	                    	 ptr2=fopen("APFmarks2.bin","wb");
	                    	  strcpy(file1,"APFmarks.bin");
    		                strcpy(file2,"APFmarks2.bin");
                              	}
                              	
	                    else if( Password[0]=='I' && Password[1]=='R' && Password[2]=='S' ){
	                    	ptr1=fopen("IRSFmarks.bin","rb");
	                    	 ptr2=fopen("IRSFmarks2.bin","wb");
	                    	  strcpy(file1,"IRSFmarks.bin");
    		                strcpy(file2,"IRSFmarks2.bin");
                                 	}
                                 	
	                    else if ( Password[0]=='E' && Password[1]=='C' && Password[2]=='C' ) {
	                    	ptr1=fopen("ECCFmarks.bin","rb");
	                    	 ptr2=fopen("ECCFmarks2.bin","wb");
	                    	  strcpy(file1,"ECCFmarks.bin");
    		                strcpy(file2,"ECCFmarks2.bin");
                                  	}
                                  	
	                     else {
			                 ptr1=fopen("CALFmarks.bin","rb");
			                  ptr2=fopen("CALFmarks2.bin","wb");
			                   strcpy(file1,"CALFmarks.bin");
    		                strcpy(file2,"CALFmarks2.bin");
                                   	}
           
            
             break;
		    		
	}
	while(fread(&details,sizeof(struct marksinfo),1,ptr1)!=NULL){
		
		      if(strcmp(id,details.id)==0 && success!=1){
		      	success=1;
		      	   	printf("\n\n\tFor student ID: %s,Enter updated Marks Scored in: ",details.id);
	             	printf("\n\t Quizzes: ");
		              scanf("%f",&details.quizzes);
		
		            printf("\n\t Assignments: ");
		                   scanf("%f",&details.assignments);
		
		            printf("\n\t Mid1: ");
		                    scanf("%f",&details.mid1);
		
	              	printf("\n\t Mid2: ");
		              scanf("%f",&details.mid2);
		
		               printf("\n\t Finals: ");
		               scanf("%f",&details.finals);
		
		details.total=details.quizzes+details.assignments+details.mid1+details.mid2+details.finals;
		details.gpa=getcourseGPA(details.total);
			fwrite(&details,sizeof(struct marksinfo),1,ptr2);
			printf("\n\tMarks for %s updated succesffuly!\n",id);;
			  }
			  
			  else{
			  	fwrite(&details,sizeof(struct marksinfo),1,ptr2);
			  	continue;
			  }
			  
	}
	fclose(ptr1);
	fclose(ptr2);	
	remove(file1);
	rename(file2,file1);
	if(success==0){
		printf("\n\tMarks for %s have not been uploaded!",id);
	}
		printf("\n------------------------------------------------------------------------------------------------------------------------");

}

