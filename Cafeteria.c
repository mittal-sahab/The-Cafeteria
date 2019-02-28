#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct dish{
	int id;
	char name[20];
	int price;
	int quant;
};
void ordering(){
	int i,fl=12,su=0,mod,reorder,whattodo,j; long long int studid,checkid; struct dish s1[12];
	modcomplete:
	printf("SELECT YOUR DISHES THAT YOU WANT TO ORDER\n\n");
	printf("DISH ID\t\tDISH NAME\t\tPRICE(IN INR)\n");
	printf("101\t\tMAGGI\t\t\t40\n");
	printf("102\t\tALOO PARANTHA\t\t50\n");
	printf("103\t\tFRENCH FRIES\t\t70\n");
	printf("104\t\tPIZZA\t\t\t90\n");
	printf("105\t\tBURGER\t\t\t40\n");						//printing of menu on screen
	printf("106\t\tTEA\t\t\t20\n");
	printf("107\t\tCOFFEE\t\t\t20\n");
	printf("108\t\tCOKE\t\t\t20\n");
	printf("109\t\tDOSA\t\t\t60\n");
	printf("110\t\tNOODLES\t\t\t80\n");
	printf("111\t\tPUFF\t\t\t40\n");
	printf("112\t\tPASTA\t\t\t80\n");
	printf("\nPLEASE ENTER THE DISH ID(s) OF DISHES YOU WANT TO ORDER.ENTER 999 WHEN YOU ARE DONE\n");
	for(i=0;i<12;i++){
		lab:
		printf("ENTER ORDER ID OF DISH %d\n",i+1);
		scanf("%d",&s1[i].id); //taking input of order id
		for(j=0;j<i;j++){
			if(s1[i].id==s1[j].id){
				MessageBox(0,"YOU HAVE ALREADY ORDERED THIS DISH.YOU MAY INCREASE ITS QUANTITY ON NEXT PAGE.NO NEED TO ORDER IT AGAIN","WARNING",MB_OK);
				goto lab;
			}
		}
		if(s1[i].id==999){
		 printf("\nYOUR ORDERS ARE RECORDED. PRESS ENTER TO CONTINUE TO ENTER QUANTITY.");
		 fl = i;
		 break; 			//breaking the input loop when user enters 999
		 }
		switch(s1[i].id){
			case 101:
			case 102:
			case 103:
			case 104:
			case 105:								//checking if the given input of order ID is present among valid order IDs or not
			case 106:
			case 107:
			case 108:
			case 109:
			case 110:
			case 111:
			case 112:	
			case 999: continue;
				break;
			default : MessageBox(0,"ENTER A VALID ORDER ID","WARNING!!",MB_OK);
						fflush(stdin);
			 		goto lab;			//going back to input in case the previous entered order id is not valid
		}
	}
	for(i=fl;i<12;i++){
		s1[i].id = 0;			//the id entries in structure array other than the entered values will become 0 
	}
	for(i=0;i<12;i++){
		switch(s1[i].id){
			case 101: strcpy(s1[i].name,"MAGGI		");
						s1[i].price =40;
						break;
			case 102: strcpy(s1[i].name,"ALOO PARANTHA	");
						s1[i].price = 50;
						break;
			case 103: strcpy(s1[i].name,"FRENCH FRIES	");
						s1[i].price = 70;
						break;
			case 104: strcpy(s1[i].name,"PIZZA		");                            
						s1[i].price = 90;
						break;
			case 105: strcpy(s1[i].name,"BURGER		");				//assigning the names and price to the respective dish IDs and assigning NO DISH 
						s1[i].price = 40;
						break;
			case 106: strcpy(s1[i].name,"TEA		");
						s1[i].price = 20;
						break;
			case 107: strcpy(s1[i].name,"COFFEE		");
						s1[i].price = 20;
						break;
			case 108: strcpy(s1[i].name,"COKE		");
						s1[i].price = 20;
						break;
			case 109: strcpy(s1[i].name,"DOSA		");
						s1[i].price = 60;
						break;
			case 110: strcpy(s1[i].name,"NOODLES		");
						s1[i].price = 80;
						break;
			case 111: strcpy(s1[i].name,"PUFF		");
						s1[i].price = 40;
						break;
			case 112: strcpy(s1[i].name,"PASTA		");
						s1[i].price = 80;
						break;
			case 0:	strcpy(s1[i].name,"NO DISH");
						s1[i].price = 0;
						break;
		}
	}
	getch();
	modquant:
	system("cls");
	printf("\n\t\t\tYOUR ORDER LOOKS DELICIOUS.ENTER THE QUANTITY OF DISHES.\n\n");
	for(i=0;i<fl;i++){																					//taking quantity inputs of the dishes
		printf("\nENTER QUANTITY OF %s\n",s1[i].name);
		scanf("%d",&s1[i].quant);
		printf("YOUR EXPENSE ON %s = Rs. %d\n",s1[i].name,s1[i].price*s1[i].quant);
		su = su+s1[i].price*s1[i].quant;
		printf("YOUR TOTAL EXPENDITURE TILL NOW = Rs. %d\n",su);
	}
	printf("YOUR QUANTITIES ARE RECORDED. PRESS ENTER TO REVIEW YOUR ORDER.");
	getch();
	system("cls");
	printf("\n\t\t\tYOUR ORDER REVIEW.\n\n");
	printf("YOUR DISH\t\t|\tQUANTITY\t|\tEXPENSE\n");
	for(i=0;i<fl;i++){
		printf("%s\t|\t%d\t\t|\tRs. %d\n",s1[i].name,s1[i].quant,s1[i].price*s1[i].quant);
	}
	printf("\n\t\tTOTAL = Rs. %d\n\n",su);
	validcommand:
	printf("PRESS 1 TO CONFIRM YOUR ORDER.\n");
	printf("PRESS 2 TO MODIFY TO YOUR ORDER.\n");						//some user friendly commands provided
	printf("PRESS 3 TO CANCEL YOUR ORDER AND EXIT.\n");
	scanf("%d",&mod);
	if(mod==1){														//#### CASE 1 that is confirmation of order  
		idagain:
		system("cls");
		printf("\n\t\tENTER YOUR INSTITUTE ID\n\t\t");
		scanf("%lld",&studid);										//taking institute ID in before confirming of order
		FILE *check;
		check = fopen("CHECK.txt","r");
		while(1){
			fscanf(check,"%lld",&checkid);					//file code to check validity of student id
			if(studid==checkid) break;
			if(feof(check)){
				MessageBox(0,"YOUR INSTITUTE ID IS INVALID.PLEASE ENTER VALID INSTITUTE ID OR CONTACT CAFETERIA ADMINISTRATION FOR ENQUIRY.","WARNING",MB_OK);
				goto idagain;
			}
		}
		fclose(check);
		system("cls");
		FILE *fptr;
		fptr = fopen("CAFETERIA.txt","a+");
		fprintf(fptr,"ID : %lld\n",studid);
		for(i=0;i<fl;i++){
		fprintf(fptr,"%d\t%s\t%d\t%d\t%d\n",s1[i].id,s1[i].name,s1[i].price,s1[i].quant,s1[i].price*s1[i].quant);		//printing every order to file i.e. appending
		}
		fprintf(fptr,"TOTAL = %d\n",su);
		fclose(fptr);
		printf("\n\n\t\t\tYOUR ORDER HAS BEEN CONFIRMED. PAY RS. %d TO THE CAFETERIA INCHARGE AT THE COUNTER.\n\n\t\t\tENJOY YOUR FOOD! HAVE A NICE DAY.",su);
		printf("\nYOUR BILL :\n\n");
		printf("ID : %lld\n",studid);
		printf("SR. NO.\t|\tORDER ID\t|\tYOUR DISH\t\t|\tQUANTITY\t|\tPRICE\t|\tTOTAL\n");
		for(i=0;i<fl;i++){
			printf("%d\t|\t%d\t\t|\t%s\t|\t%d\t\t|\t%d\t|\t%d\n",i+1,s1[i].id,s1[i].name,s1[i].quant,s1[i].price,s1[i].quant*s1[i].price); //printing bill on screen
		}
		printf("TOTAL AMOUNT TO BE PAID : RS. %d\n",su);
		FILE *bill;
		bill = fopen("BILL.txt","w");
		fprintf(bill,"ID : %lld",studid);
		fprintf(bill,"\nSR. NO.\t|\tORDER ID\t|\tYOUR DISH\t\t|\tQUANTITY\t|\tPRICE\t|\tTOTAL\n");
		for(i=0;i<fl;i++){
			fprintf(bill,"%d\t|\t%d\t\t|\t%s\t|\t%d\t\t|\t%d\t|\t%d\n",i+1,s1[i].id,s1[i].name,s1[i].quant,s1[i].price,s1[i].quant*s1[i].price);   //printing bill in BILL.txt file
		}
		fprintf(bill,"TOTAL AMOUNT TO BE PAID : RS. %d\n",su);
		fclose(bill);
		valid:
		printf("\nPRESS 0 TO PRINT YOUR BILL.\n");
		printf("PRESS 1 TO EXIT.\n");
		scanf("%d",&whattodo);
		if(whattodo==0){
		 MessageBox(0,"YOU NEED TO SAVE THE BILL AS PDF BEFORE PRINTING IT.PRESS OK TO CONTINUE TO PRINT.","SAVE BEFORE YOU PRINT",MB_OK);
		 system("NOTEPAD /P BILL.txt");										//lead to printing of bill
		}
		else if(whattodo==1) exit(0);
		else {
			MessageBox(0,"ENTER A VALID COMMAND","WARNING!!",MB_OK);
			system("cls");
			goto valid;
		}
	}
	else if(mod==2){											//#### CASE 2 that is modification of order
		mod2:
		system("cls");
		printf("\n\n\t\tPRESS 0 TO MODFIFY QUANTITY OF YOUR ORDERED DISHES.\n");				//know what user wants to do with his order
		printf("\t\tPRESS 1 TO BEGIN ORDERING DISHES AGAIN.THIS WILL REMOVE YOUR CURRENT ORDERED DISHES.\n");
		scanf("%d",&reorder);
		if(reorder==0){
			su = 0;															//in case he wants to change only quantity
			goto modquant;
		}
		else if(reorder==1){
			for(i=0;i<fl;i++){
				s1[i].id = 0;
				s1[i].quant = 0;
				s1[i].price = 0;								//in case he wants to order again from beginning
				strcpy(s1[i].name,"NO DISH");
			}
			su = 0;
			goto modcomplete;
		}
		else{
			MessageBox(0,"ENTER A VALID COMMAND","WARNING!!",MB_OK);				//in case he enters an invalid command
			goto mod2;
		}
	}
	else if(mod==3){																//#### CASE 3 that is cancellation of order
		system("cls");
		printf("\n\n\t\t\tYOUR ORDER HAS BEEN CANCELLED.\n\n\t\t\t HOPE TO SEE YOU SOON !! ");
	}
	else{																						//#### CASE 4 that is an invalid command
		system("cls");
		MessageBox(0,"ENTER A VALID COMMAND","WARNING!!",MB_OK);
		goto validcommand;
	}
}
int main(){
	system("COLOR A0");																	//changing BG and text colour 
	printf("\n\n\t\t\tWELCOME TO THE UNIQUE BREW CAFETERIA\n\n"); 
	ordering();																			//this step is everything and self exlanatory
}