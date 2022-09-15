//
// Created by anil on 21.05.2021.
//



//about the txt files: ı have created txt files according to given project pdf
//so if you create these 3 txt files according to project and if you
//place them to correct place(ı mean project folder) there wont be problem

// second note: this note is about the inside of txt. ın project discussion some people said that there
//are weird symbols and we dont understand it. ı will explain why it is like this.
//there are weird symbols because the ones who writes structs to txt files could see this.
//and it is not a problem because instead of writing every attribute of a struct object, writing struct directly
//is easier than other things and we dont need to read txt files because if you use the code that ı submitted,
//you can see what a txt file contains.



//third note: in order to decrease the amount of time that you will spent to understand the code that ı wrote
//ı added comments in important parts and ı tried to write in a clear way.
//also ı assure you ı tested all functionalities of this code according to given project pdf file,
//and all of them works perfectly.




//additional note, normally ı was taking system date as rented date,
//you can see the code below which is in comment format, then ı thought if ı take system date,
//how you can test the features of my code while trying because for example yo will test my code in 5 or
//10 minutes but,if ı take system date,you wont be able to test features. so ı did like this,
//you will enter the day that wou will rent a book,when it comes to deliver this book,program will take
//todays date. ı think it is clear.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



struct Customer { // customer data stored in this struct

    int C_ID ;
    char name[30] ;
    char surname[30];
    int age ;
    int wallet ;
} ;

struct Books {//book data stored in this struct
    int B_ID;
    char name[50];
    char author[50];
    int age_limit;
    int price_per_week;
    int rented; // 1 for true,0 for false
};

struct Rented {//rent information stored in this struct
    int R_ID;
    int C_ID;
    int B_ID;
    char rented_date[50];
    int week;
};



void writeCustomers(struct Customer *emps, int *ptr){// this method saves customer data to customers.txt file


    FILE *filep = fopen("customers.txt","w");//txt file name important

    int y ;
    for(y=0 ; y<*ptr;y++){
        if(emps[y].C_ID != 0) {
            fwrite (&emps[y], sizeof(struct Customer), 1, filep);
        }
    }
    fclose(filep);
}



void writeBooks(struct Books *books, int *ptr2){// this method saves book data to books.txt file


    FILE *filBook = fopen("books.txt","w");//txt file name important

    int y ;
    for(y=0 ; y<*ptr2;y++){

        if(books[y].B_ID != 0) {
            fwrite (&books[y], sizeof(struct Books), 1, filBook);
        }

    }
    fclose(filBook);
}




void writeRented(struct Rented *rented, int *ptr3){// this method saves rent data to rented.txt file


    FILE *filRented = fopen("rented.txt","w");//txt file name important
    int y ;
    for(y=0 ; y<*ptr3;y++){

        if(rented[y].R_ID != 0) {

            fwrite (&rented[y], sizeof(struct Rented), 1, filRented);

        }

    }
    fclose(filRented);
}


void addCustomer(struct Customer *emps, int *ptr){

    struct Customer cust; // temp customer


    cust.C_ID = *ptr + 1;//auto increment
    char name [30];
    char surname [30];

    while(1==1){
        int check=1; // one means no problem
        printf("NAME: ");// taking name and surname
        scanf("%s",name);
        printf("SURNAME: ");
        scanf("%s",surname);
        int i;
        for (i=0; i<*ptr;i++){
            if(strcmp(name, emps[i].name)==0  && strcmp(surname, emps[i].surname)==0){//checking if someone has same name and surname
                printf("there is already person with same name and surname.Try another name and surname.\n");
                check = 0;
                break;
            }
        }
        if(check==1){
            break;
        }
    }
    strcpy(cust.name, name);
    strcpy(cust.surname, surname);

    printf("AGE:");//taking age and wallet info
    scanf("%d",&cust.age);
    printf("WALLET:");
    scanf("%d",&cust.wallet);
    int x ;
    int counter = 0 ;
    for(x = 0 ; x<*ptr ; x++){
        if(emps[x].C_ID == cust.C_ID) counter++ ;
    }

    if(counter==1 || cust.C_ID == 0) printf("INVALID ID\n");

    else {

        emps[*ptr] = cust ;//person is added
        *ptr = *ptr + 1 ;
        printf("CUSTOMER ADDED\n");

    }

}



void addBook(struct Books *books, int *ptr2){

    struct Books bk; // temp book

    bk.B_ID = *ptr2 + 1;//auto increment feature
    char name [30];
    char author [30];

    while(1==1){
        int check=1; // one means no problem
        printf("NAME: ");// taking name and author
        scanf("%s",name);
        printf("AUTHOR: ");
        scanf("%s",author);
        int i;
        for (i=0; i<*ptr2;i++){
            if(strcmp(name, books[i].name)==0  && strcmp(author, books[i].author)==0){//cehcking if a book has same name and author
                printf("there is already book with same name and author.Try another name and author.\n");
                check = 0;
                break;
            }
        }
        if(check==1){
            break;
        }
    }

    strcpy(bk.name,name);
    strcpy(bk.author,author);

    printf("AGE LIMIT:");// taking additional data about book
    scanf("%d",&bk.age_limit);
    printf("PRICE PER WEEK:");
    scanf("%d",&bk.price_per_week);
    bk.rented=0;

    int x ;
    int counter = 0 ;
    for(x = 0 ; x<*ptr2 ; x++){
        if(books[x].B_ID == bk.B_ID) counter++ ;
    }

    if(counter==1 || bk.B_ID == 0) printf("INVALID ID\n");

    else {
        books[*ptr2] = bk ;// book is added
        *ptr2 = *ptr2 + 1 ;
        printf("BOOK ADDED\n");
    }
}



void listCustomer(struct Customer *emps, int *ptr){//this method lists all customers


    int y ;
    printf("\nCustomers:\n");
    for(y=0 ; y<*ptr;y++){

            printf("ID:%d\n",emps[y].C_ID);
            printf("NAME:%s\n",emps[y].name);
            printf("SURNAME:%s\n",emps[y].surname);
            printf("AGE:%d\n",emps[y].age);
            printf("WALLET:%d\n",emps[y].wallet);
            printf("\n");


    }
}



void listBook(struct Books *books, int *ptr2){//this method lists all books

    int y ;
    printf("\nBOOKS:\n");
    for(y=0 ; y<*ptr2;y++){
        if(0!=strcmp(books[y].name,"")){
            printf("ID:%d\n",books[y].B_ID);
            printf("NAME:%s\n",books[y].name);
            printf("AUTHOR:%s\n",books[y].author);
            printf("AGE LIMIT:%d\n",books[y].age_limit);
            printf("PRICE PER WEEK:%d\n",books[y].price_per_week);
            printf("IS RENTED(1 means yes,0 means no):%d\n",books[y].rented);
            printf("\n");
        }

    }
}


void listRented(struct Rented *rented, int *ptr3){// this method lists all rented data


    int y ;
    printf("\nRENTS:\n");
    for(y=0 ; y<*ptr3;y++){

        printf("RENTED ID:%d\n",rented[y].R_ID);
        printf("BOOK ID:%d\n",rented[y].B_ID);
        printf("CUSTOMER ID:%d\n",rented[y].C_ID);
        printf("TAKEN DATE:%s\n",rented[y].rented_date);
        printf("WEEKS WANTED:%d\n",rented[y].week);
        printf("\n");
    }
}



void updateCustomer(struct Customer *emps, int *ptr){// this method updates customer info

    printf("ENTER ID FOR UPDATING:");// taking C_ID

    int idforupdate;
    scanf("%d",&idforupdate);

    if(idforupdate==0) {
        printf("WRONG ID\n");//id is wrong
        return ;
    }

    int x ;
    int counter = 0;
    for (  x = 0 ; x<*(ptr); x++){//trying to find a match

        if(emps[x].C_ID == idforupdate) {//customer found

            printf("NAME: ");//set new data
            scanf("%s",emps[x].name);
            printf("SURNAME: ");
            scanf("%s",emps[x].surname);
            printf("AGE:");
            scanf("%d",&emps[x].age);
            printf("CUSTOMER UPDATED\n");
            counter++;
        }
    }
    if(counter==0) printf("WRONG ID\n");
}



void updateBook(struct Books *books, int *ptr2){// update book informations

    printf("ENTER BOOK ID FOR UPDATING:");//take B_ID info

    int idforupdate;
    scanf("%d",&idforupdate);

    if(idforupdate==0) {
        printf("WRONG ID\n");
        return ;
    }

    int x ;
    int counter = 0;
    for (  x = 0 ; x<*(ptr2); x++){//trying to match correct book

        if(books[x].B_ID == idforupdate) {//book matched

            printf("NAME: ");//setting new values
            scanf("%s",books[x].name);
            printf("AUTHOR: ");
            scanf("%s",books[x].author);
            printf("AGE LIMIT:");
            scanf("%d",&books[x].age_limit);
            printf("PRICE PER WEEK:");
            scanf("%d",&books[x].price_per_week);
            printf("BOOK UPDATED\n");
            counter++;
        }
    }
    if(counter==0) printf("WRONG ID\n");
}



void deposit(struct Customer *emps, int *ptr){//adding money to customers wallet

    printf("ENTER CUSTOMER ID FOR DEPOSIT:");//customer ıd taken

    int idforupdate;
    scanf("%d",&idforupdate);

    if(idforupdate==0) {
        printf("WRONG ID\n");
        return ;
    }

    int x ;
    int counter = 0;
    for (  x = 0 ; x<*(ptr); x++){

        if(emps[x].C_ID == idforupdate) {//customer found

            int money;
            printf("Deposit Amount:");// take amount of deposit
            scanf("%d",&money);
            emps[x].wallet += money;//money deposited
            printf("MONEY DEPOSITED\n");
            counter++;
        }

    }

    if(counter==0) printf("WRONG ID\n");
}



void rentBook(struct Customer *emps , int *ptr ,struct Books *books, int *ptr2,struct Rented *rented,int *ptr3){// this method is for renting book


    struct Books bk;// temporary objects
    struct Customer cust;
    struct Rented rent;


    printf("ENTER BOOK ID:");// taking book id
    int idforupdate;
    scanf("%d",&idforupdate);

    if(idforupdate==0) {
        printf("WRONG ID\n");
        return ;
    }

    int x ;

    for (  x = 0 ; x<*(ptr2); x++){

        if(books[x].B_ID == idforupdate) {


            if(books[x].rented == 1){//checking if the wanted book is rented or not
                printf("this book is rented.\n");//book rented, return main page
                return;

            }else{//continue

                bk = books[x];
                printf("ENTER YOUR C_ID:");//taking customer id

                int idforupdate;
                scanf("%d",&idforupdate);

                if(idforupdate==0) {
                    printf("INVALID ID\n");
                    return ;
                }

                int y ;

                for (  y = 0 ; y<*(ptr); y++){

                    if(emps[y].C_ID == idforupdate) {//finding given user
                        cust=emps[y];

                    }

                }


                if(cust.age<bk.age_limit){// checking if that person's age is greater than age limit
                    printf("Your age is not enough to hire this book.\n");// it is noot, return main page
                    return;
                }

                printf("ENTER HOW MANY WEEKS YOU WILL HIRE BOOK:");// how many week it will be hired
                int weekWanted;
                scanf("%d",&weekWanted);


                if (  weekWanted  * bk.price_per_week  > cust.wallet ){// if persons money is not enough
                    printf("You dont have enough money.\n");//warn user and return to main page
                    return;
                }
                else {// person have enough money
                    cust.wallet = cust.wallet - (weekWanted * bk.price_per_week);// update balance of that person
                    int z ;

                    for (  z = 0 ; z<*(ptr); z++){

                        if(emps[z].C_ID == cust.C_ID) {//update money info
                            emps[z]=cust;
                            break;
                        }

                    }
                    bk.rented = 1;
                    int k ;

                    for (  k = 0 ; k<*(ptr2); k++){

                        if(books[k].B_ID == bk.B_ID) {//update book info as rented
                            books[k]=bk;
                            break;
                        }
                    }

                    rent.R_ID = *ptr3 + 1;// auto increment feature for rent system
                    rent.B_ID = bk.B_ID;//setting rent info
                    rent.C_ID = cust.C_ID;
                    rent.week = weekWanted;


                    //short note if you start from to comment
                    printf("ENTER TODAYS DATE: (ex:'24/04/2021')\n");//taking rent date
                    printf("important note! date format should be dd/mm/yyyy\n");
                    scanf("%s",rent.rented_date);
                    //and finish to comeent here



                    //and if you use the code below,system date will be taken
                    /*
                    char  timee[100];
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);
                    sprintf(timee, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
                    printf("%s\n",timee);

                    //strcpy(rent.rented_date,timee);
                    */


                    int xx ;
                    int counterx = 0 ;
                    for(xx = 0 ; xx<*ptr3 ; xx++){
                        if(rented[xx].R_ID == rent.R_ID) counterx++ ;
                    }

                    if(counterx==1 || rent.R_ID == 0) printf("INVALID ID ***TRY AGAIN***\n");

                    else {

                        rented[*ptr3] = rent ;//adding rent information
                        *ptr3 = *ptr3 + 1 ;
                        printf("BOOK RENTED\n");
                        return;
                    }
                }
            }
        }
    }
}


void deliverBook(struct Customer *emps , int *ptr ,struct Books *books, int *ptr2,struct Rented *rented,int *ptr3){


    struct Books bk;
    struct Customer cust;
    struct Rented rent;
    struct Rented tempR;
    int custId;


    printf("ENTER BOOK ID THAT YOU WILL DELIVER:");//taking book id for to deliver

    int idforupdate;
    scanf("%d",&idforupdate);

    if(idforupdate==0) {
        printf("WRONG ID\n");
        return ;
    }

    int x ;
    int count=0;
    for (  x = 0 ; x<*(ptr2); x++){

        if(books[x].B_ID == idforupdate) {// find the book


            if(books[x].rented == 1){// check if really that book is rented
                count++;//status check
                bk = books[x];// so it is rented, take book data
                books[x].rented=0;// now book is not rented

                int y ;

                for (  y = 0 ; y<*(ptr3); y++){// find the user who borrowed that book via checking rent informations

                    if(rented[y].B_ID == idforupdate) {

                        custId = rented[y].C_ID;//customer id found
                        tempR = rented[y];

                    }
                }

                int z ;
                for (  z = 0 ; z<*(ptr); z++){
                    if(emps[z].C_ID == custId) {// customer is found by using customer id
                        cust=emps[z];

                    }
                }


                char  todaysT[100];

                int remDay;//remaining days
                int remWeek;//remaining week info

                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                sprintf(todaysT, "%02d/%02d/%d",  tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900 );
                //todays date is taken in string format



                char *str = todaysT;


                int year, month, day;
                sscanf(str, "%02d/%02d/%d",  &day,&month,&year);//encoding todays date string




                char *str2 = tempR.rented_date;

                int yearR, monthR, dayR;
                sscanf(str2, "%02d/%02d/%d",  &dayR,&monthR,&yearR);//encoding rented date string




                    remDay = ((month-monthR)*30) + (day-dayR);//this is math part,take difference between months and multiply it with 30
                    //and add the difference between days
                    remWeek = (tempR.week*7 -remDay)/7 ;//calculate the remaining week


                if(day==dayR && monthR==month && year==yearR){//if you took today and delicer today,run this
                    remWeek=tempR.week;}



                    remWeek=floor(remWeek);//here is the thing,if you can rent book weekly,if you spend 8 days,it menas 2 weeks because,
                    //in every system, for example netflix, if you spent 31 days, it takes two month payment and book renting system works
                    //like this too. if you rent for 3 weeks and you deliver it 9 days later, you used two weeks this book
                    //only one week money will be refunded

                    cust.wallet = cust.wallet + (remWeek * bk.price_per_week);// refund the money

                    int k ;
                    for (  k = 0 ; k<*(ptr); k++){

                        if(emps[k].C_ID == cust.C_ID) {//find the customer
                            emps[k]=cust;
                            break;
                        }

                    }


                    int xx ;
                    int counterx = 0;
                    for(xx = 0 ; xx<*ptr ; xx++){
                        if(emps[xx].C_ID == cust.C_ID) counterx++ ;
                    }

                        emps[*ptr] = cust ;//customer info updated
                        printf("BOOK DELIVERED\n");
                        return;

            }
        }
    }
    if (count==0){printf("THIS BOOK IS NOT RENTED!\n");}
}



void burnBook(struct Books *books, int *ptr2){// deleting book from system


    printf("ENTER BOOK ID THAT YOU WILL BURN:");// taking book id

    int idforDelete;
    scanf("%d",&idforDelete);

    if(idforDelete==0) {
        printf("WRONG ID FOR DELETING\n");
        return ;
    }

    int x ;
    for (  x = 0 ; x<*(ptr2); x++){

        if(books[x].B_ID == idforDelete) {// find book


            if(books[x].rented == 0){// check if book is rented
                // it is not rented so, we can delete it
                strcpy(books[x].name ,"");
                strcpy(books[x].author ,"");
                books[x].price_per_week =0;
                books[x].age_limit =0;
                books[x].rented =0;
                printf("BOOK BURNED.");
                return;
            }
            else {
                printf("BOOK CANNOT BE BURNED.");
                printf("BECAUSE IT IS RENTED.");
                return;
            }
        }
    }
}







int main(){


    struct Customer *emps = malloc(100 * sizeof(struct Customer));// create necessary struct arrays
    int numberofCustomer = 0 ;


    struct Books *books = malloc(100 * sizeof(struct Books));
    int numberofBooks = 0 ;


    struct Rented *rented = malloc(100 * sizeof(struct Rented));
    int numberofRented = 0 ;


    FILE *in;//load customer info from txt
    struct Customer inp3;
    in = fopen ("customers.txt", "r");//txt file name important
    if (in == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        exit (1);
    }
    int count =0;
    while(fread(&inp3, sizeof(struct Customer), 1, in)) {
        emps[count] = inp3;
        count++;
    }
    fclose (in);
    numberofCustomer=count;



    FILE *inB;//load book info from txt
    struct Books inpBook;
    inB = fopen ("books.txt", "r");//txt file name important
    if (inB == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        exit (1);
    }
    int countB =0;
    while(fread(&inpBook, sizeof(struct Books), 1, inB)) {
        books[countB] = inpBook;
        countB++;
    }
    fclose (inB);
    numberofBooks=countB;



    FILE *inR;//load rent info from txt
    struct Rented inpRented;
    inR = fopen ("rented.txt", "r");//txt file name important
    if (inR == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        exit (1);
    }
    int countR =0;
    while(fread(&inpRented, sizeof(struct Rented), 1, inR)) {
        rented[countR] = inpRented;
        countR++;
    }
    fclose (inR);
    numberofRented=countR;



    int *ptr = &numberofCustomer;
    int *ptr2 = &numberofBooks;
    int *ptr3 = &numberofRented;



    while(1){
        //interface, it is clear ı think

        printf("\n\nCHOOSE OPTION \n"
               "(0) save and exit\n"//important note,saving is important,please do not stop app without pressing zero
               "(1) add Customer\n"
               "(2) list Customer\n"
               "(3) update Customer\n"
               "(4) deposit Money\n"
               "(5) add Book\n"
               "(6) list Book\n"
               "(7) update Book\n"
               "(8) rent Book\n"
               "(9) list Rented\n"
               "(10) deliver Book\n"
               "(11) burn Book\n"
               "YOUR CHOICE:");

        int choice;
        scanf("%d", &choice);//choosing operations


        if(choice == 0)
        {

            break;
        }


            if(choice == 1) {
                addCustomer(emps, &numberofCustomer);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
            if(choice == 2) {
                listCustomer(emps, &numberofCustomer);

            }
            if(choice == 3) {
                updateCustomer(emps, &numberofCustomer);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
            if(choice == 4) {
                deposit(emps, &numberofCustomer);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
            if(choice == 5) {
                addBook(books, &numberofBooks);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
            if(choice == 6) {
                listBook(books, &numberofBooks);

            }
            if(choice == 7) {
            updateBook(books, &numberofBooks);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
            if(choice == 8) {
            rentBook(emps, &numberofCustomer, books, &numberofBooks, rented, &numberofRented);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
            if(choice == 9) {
            listRented(rented,&numberofRented);

            }
            if(choice == 10) {
            deliverBook(emps, &numberofCustomer, books, &numberofBooks, rented, &numberofRented);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
            if(choice == 11) {
            burnBook(books, &numberofBooks);
                writeCustomers(emps, &numberofCustomer);
                writeBooks(books,&numberofBooks);
                writeRented(rented,&numberofRented);
            }
        }
    return 0 ;
    }
