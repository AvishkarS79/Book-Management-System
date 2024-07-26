#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Book{
    int bookId;
    char bookName[30];
    char authorName[30];
    float price;
    float rating;
    char category[30];
}Book;

void addBook(Book*, int);
void displayBook(Book*);
int searchByBookId(Book*);
void searchByBookName(Book*, char*);
void sortBook(Book* );
void updateBook(Book* );
void deleteData(Book* );
void searchByCategory(Book*, char*);
void hardcodedValues(Book*);

int ctr=3;
int size =3;

int main(){

    Book* b1 = (Book*)malloc(sizeof(Book)*size);
    hardcodedValues(b1);
    
    int choice;
    do{
        printf("\n1.Add The Book\n2.Display The Book\n3.Search The Book By Id\n4.Search The Book By Name\n5.Sort The Book\n6.Update The Book\n7.Delete The Book\n8.Search The Book By Category\n");
          
        printf("Enter the Choice : ");
        scanf("%d", &choice);

        switch (choice){
        case 1:{
            printf("Enter how many Book you want to store : ");
            int numOfBooks;
	        scanf("%d",&numOfBooks);
            addBook(b1, numOfBooks);
            break;
        }
        case 2:{
            displayBook(b1);
            break;
        }
        case 3:{
            int index = searchByBookId(b1);
            if(index != -1){
                printf("%d %s %s %s %f %f\n", b1[index].bookId, b1[index].bookName, b1[index].authorName, b1[index].category, b1[index].price, b1[index].rating);
            }
            break;
        }
        case 4:{
            char searchBook[20];
            printf("Enter the Book Name You Want To Search : ");
            fflush(stdin);
            gets(searchBook);

            searchByBookName(b1, searchBook);
            break;
        }
        case 5:{
            sortBook(b1);
            break;
        }
        case 6:{
            updateBook(b1);
            break;
        }
        case 7:{
            deleteData(b1);
            break;
        }
        case 8:{
            char categoryName[20];
            printf("Enter the Category Name You Want To Search : ");
            fflush(stdin);
            gets(categoryName);

            searchByCategory(b1, categoryName);
            break;
        }
        default :
            printf("Invalid Choice");
            break;
        }
        printf("\nDo you want To Continue?\nPress 1 For Yes\nPress Any Number For Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
    }
    while(choice != -1);
	printf("\nProgram exit succesfully !!!");
}

void hardcodedValues(Book* b1){
    b1[0].bookId = 101;
    strcpy(b1[0].bookName, "The Signalman");
    strcpy(b1[0].authorName, "Charles Dickens");
    strcpy(b1[0].category, "Suspense");
    b1[0].price = 1670;
    b1[0].rating = 9;

    b1[1].bookId = 102;
    strcpy(b1[1].bookName, "The Highler  ");
    strcpy(b1[1].authorName, "A.E.Coppard");
    strcpy(b1[1].category, "Adventure");
    b1[1].price = 1200;
    b1[1].rating = 7;

    b1[2].bookId = 103;
    strcpy(b1[2].bookName, "The Open Boat");
    strcpy(b1[2].authorName, "Stephen Crane");
    strcpy(b1[2].category, "Classic");
    b1[2].price = 1500;
    b1[2].rating = 8;
}

void addBook(Book* b1, int numOfBooks){

    if(numOfBooks>size && ctr==0){
		printf("Realloc\n");
		b1=realloc(b1,sizeof(Book)*(numOfBooks));
		size=numOfBooks;
	}
	else if((ctr+numOfBooks)>size && ctr!=0){
		printf("Realloc\n");
		b1=realloc(b1,sizeof(Book)*(size+numOfBooks));
		size+=numOfBooks;
	}

    for(int i=ctr; i<(ctr+numOfBooks); i++){
        printf("Enter the Book Id : ");
        scanf("%d", &b1[i].bookId);
        
        fflush(stdin);
        printf("Enter the Book Name : ");
        gets(b1[i].bookName);
        
        fflush(stdin);
        printf("Enter the Author Name : ");
        gets(b1[i].authorName);
        
        fflush(stdin);
        printf("Enter the Category Name : ");
        gets(b1[i].category);
        
        printf("Enter the Book Price : ");
        scanf("%f", &b1[i].price);

        printf("Enter the Book Rating Out Of 10 : ");
        scanf("%f", &b1[i].rating);

    } 
    ctr = ctr + numOfBooks;
}

void displayBook(Book* b1){

    printf("                         Book detail\n");
	printf("===========================================================================================\n");
	printf("|Book Id   |    Name     |    Author Name    |    Category     |    Price   |    Rating    \n");
	printf("===========================================================================================\n");

    for(int i=0; i<ctr; i++){
        printf("   %-8d %-12s %-20s %-15s %-13f %-10f\n", b1[i].bookId, b1[i].bookName, b1[i].authorName, b1[i].category, b1[i].price, b1[i].rating);

        /*printf("Book Id-%d\t", b1[i].bookId);
        printf("Book Name-%s\t", b1[i].bookName);
        printf("Author Name-%s\t", b1[i].authorName);
        printf("Category Name-%s\t", b1[i].category);
        printf("Book Price-%f\t", b1[i].price);
        printf("Book Rating-%f/10.00\n", b1[i].rating); */
    }
}

int searchByBookId(Book* b1){
    int searchId;
    printf("Enter the Book Id You Want To Search : ");
    fflush(stdin);
    scanf("%d", &searchId);
    
    for(int i=0; i<ctr; i++){
        if(searchId == b1[i].bookId){
            return i;
        }
    }
    return -1;
}

void searchByBookName(Book* b1, char* searchBook){
    
    int flag = 0;
    for(int i=0; i<ctr; i++){
        if(strcasecmp(b1[i].bookName, searchBook)==0){
            flag =1;
            printf("Book is Found\n");
            printf("%d %s %s %s %f %f\n", b1[i].bookId, b1[i].bookName, b1[i].authorName, b1[i].category, b1[i].price, b1[i].rating);
            break;
        }else{
            printf("Not Found");
        }
    }
}
void searchByCategory(Book* b1, char*categoryName){
    int flag = 0;
    for(int i=0; i<ctr; i++){
        if(strcasecmp(b1[i].category, categoryName)==0){
            flag =1;
            printf("Book is Found\n");
            printf("%d %s %s %s %f %f\n", b1[i].bookId, b1[i].bookName, b1[i].authorName, b1[i].category, b1[i].price, b1[i].rating);
            break;
        }
    }
}

void sortBook(Book* b1){
    int choice;
    printf("Press 1 For Sort by Price\nPress 2 For Sort by Rating\nEnter The choice : ");
    scanf("%d", &choice);

    if(choice == 1){
        for(int i=0; i<ctr; i++){
            for(int j=i+1; j<ctr; j++){
                   if(b1[j].price < b1[i].price){
                   int temp = b1[i].price;
                   b1[i].price = b1[j].price;
                   b1[j].price = temp;
                }
            }
            printf("\nThe Sortng price is : "); 
            printf("%d %s %s %s %f %f\n", b1[i].bookId, b1[i].bookName, b1[i].authorName, b1[i].category, b1[i].price, b1[i].rating); 
        }
   }
    if(choice == 2){
        for(int i=0; i<ctr; i++){
            for(int j=i+1; j<ctr; j++){
                if(b1[j].rating < b1[i].rating){
                int temp = b1[i].rating;
                b1[i].rating = b1[j].rating;
                b1[j].rating = temp;
                }
            }
            printf("\nThe Sortng rating is : ");
            printf("%d %s %s %s %f %f\n", b1[i].bookId, b1[i].bookName, b1[i].authorName, b1[i].category, b1[i].price, b1[i].rating);
        }  
    }
}

void updateBook(Book* b1){

    int index = searchByBookId(b1);
    if(index!=-1) {
		int choice;
		printf("What do you want to update?");
		printf("\nPress 1 For price\nPress 2 for rating : ");
		fflush(stdin);
		scanf("%d",&choice);

		if(choice == 1) {
			printf("Enter The Updated Price : ");
			scanf("%f",&b1[index].price);
            printf("The Updated Book Price is : \n");

		}else if(choice == 2){
			printf("Enter The Updated Rating : ");
			scanf("%f",&b1[index].rating);
            printf("The Updated rating is : \n");
			}
            displayBook(b1);
	}
	else{
		printf("The Book is not Found!");
	}
} 

void deleteData(Book* b1){
    int index = searchByBookId(b1);
	for(int i=index; i<ctr-1; i++) {
		b1[i] = b1[i+1];
	}
	ctr--;
    displayBook(b1);
}
