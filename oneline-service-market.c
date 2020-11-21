#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAMESIZE 30
#define PASSSIZE 30
#define ADRSSIZE 50
#define NMBRSIZE 15


typedef struct info
{
    char name[NAMESIZE];
    char pass[PASSSIZE];
    char adrs[ADRSSIZE];
    char nmbr[NMBRSIZE];
} info;

void sign_up();
void sign_in();
void sign_out();

void home_page();

void appliance();

void refrigerator();
void AC();
void washing_machine();
void IPS();
void generator();
void TV();
void oven();

void gadgets();

void desktop();
void laptop();
void smartphone();

void electrical();

void fan();
void light();
void motor();
void switches();
void cable();
void main_board();
void check_up();

void laundry();

void men();
void household();
void kids();
void women();

void clean();

void room_clean();
void bathroom_clean();

void sanitary();

void tap();
void sink();
void basin();
void bathtub();
void plumbing();



void main()
{
    system("cls");
    system("color 3f");
    int a;
    printf("\n\n\n\n\n\n\n\t\t    Welcome To The Largest Online Service Market  ");
    printf("\n\n\n\n\n\n\t\t\t1. Create an account.\n\n\t\t\t2. I already have an account.\n\n\t\t\t3. Exit\n");
    printf("\n\n\n\t\t\tChoose your option: ");
    scanf("%d",&a);
    if (a==1)
    {
        sign_up();
    }
    else if (a==2)
    {
        sign_in();
    }

    else if(a==3)
    {
        exit(0);
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        main();
    }
}

void sign_up()
{
    system("cls");
    system("color 1f");
    info acc;
    info fileacc;
    int usernamefound=0;
    FILE *sign;

    sign = fopen("signing_up.bin", "a+");
    if(sign==NULL)
    {
        sign = fopen("signing_up.bin", "w+");
    }

    fflush(stdin);

    printf("\n\n\n\n\n\n\n\t\t\t    ******  Sign Up  *****");
    printf("\n\n\n\n\t\t\tEnter Your Name : ");
    fgets(acc.name, NAMESIZE, stdin);

    while(fread(&fileacc, sizeof(info), 1, sign))
    {
        if(strncmp(fileacc.name, acc.name, NAMESIZE)==0)
        {
            printf("\n\n\nOops! It seems you have registered once. Press any key to try another name...\n\n");
            usernamefound=500;
            getch();
            sign_up();
        }
    }

    printf("\n\n\t\t\tMake a Password : ");
    fgets(acc.pass, PASSSIZE, stdin);


    printf("\n\n\t\t\tEnter Your Address : ");
    fgets(acc.adrs, ADRSSIZE, stdin);


    printf("\n\n\t\t\tEnter Your Phone Number : ");
    fgets(acc.nmbr, NMBRSIZE, stdin);

    if(usernamefound==0)
    {
        fwrite(&acc, sizeof(info), 1, sign);
    }
    fclose(sign);

    printf("\n\n\n\n\n\t\t------ You have successfully registered ------\n\n\n\t\t\tPress any key to Sign in...\n");
    getch();
    sign_in();
}

void sign_in()
{
    system("cls");
    system("color 2f");
    info acc;
    info fileacc;
    int accountfound=0;


    FILE *sign;

    fflush(stdin);
    printf("\n\n\n\n\n\n\n\t\t\t    ******  Sign In  *****");
    printf("\n\n\n\n\t\t\tEnter Your Name : ");
    fgets(acc.name, NAMESIZE, stdin);
    printf("\n\n\t\t\tEnter Your Password : ");
    fgets(acc.pass, PASSSIZE, stdin);


    sign = fopen("signing_up.bin", "r");
    while(fread(&fileacc, sizeof(info), 1, sign))
    {
        if(strncmp(fileacc.name, acc.name, NAMESIZE)==0 && strncmp(fileacc.pass, acc.pass, PASSSIZE)==0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\t\t------ You have successfully signed in ------");
            printf("\n\n\n\t\t\tPress any key to continue...");
            accountfound=123;
            getch();
            home_page();
            break;
        }
    }
    if(accountfound==0)
    {

        printf("\n\n\n\t\t\tIncorrect Username or Password");
        printf("\n\n\n\tPress 1 to try again or any key to go to the registration page\n");
        fclose(sign);
        int w;
        scanf("%d", &w);
        if(w==1)
        {
            sign_in();
        }
        else
        {
            main();
        }

    }
    fclose(sign);
    getch();

}

void home_page()
{
    int c;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\tLargest Online Service Market");
    printf("\n\n\n\n\t\tOur services : \n");
    printf("\n\n\t\t\t\t1. Appliance Repair\n\n\t\t\t\t2. Gadgets Repair\n\n\t\t\t\t3. Electrical Services \n\n\t\t\t\t4. Laundry Home Services\n\n\t\t\t\t5. Cleaning Services\n\n\t\t\t\t6. Pluming and Sanitary Services\n\n\n\n\n\t\t\t\t0. Sign Out\n");
    printf("\n\n\n\t\t\tChoose your option : ");
    scanf("%d",&c);
    if(c==1)
    {
        appliance();
    }
    else if(c==2)
    {
        gadgets();
    }
    else if(c==3)
    {
        electrical();
    }
    else if(c==4)
    {
        laundry();
    }
    else if(c==5)
    {
        clean();
    }
    else if(c==6)
    {
        sanitary();
    }
    else if(c==0)
    {
        sign_out();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        home_page();
    }
}

void sign_out()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\tSigning Out....Press Enter to continue....");
    getch();
    main();
}

void appliance()
{
    system("cls");
    int c;
    printf("\n\n\n\n\n\n\t\t\tLargest Online Service Market");
    printf("\n\n\n\n\t\tAppliance Repair : \n");
    printf("\n\n\t\t\t\t1. Refrigerator Servicing\n\n\t\t\t\t2. AC Repair\n\n\t\t\t\t3. Washing machine Servicing\n\n\t\t\t\t4. IPS Servicing\n\n\t\t\t\t5. Generator Servicing\n\n\t\t\t\t6.TV Servicing\n\n\t\t\t\t7.Microwave Oven Services\n\n\n\n\n\t\t\t\t0. Go back\n");
    printf("\n\n\n\t\t\tChoose your option : ");
    scanf("%d",&c);
    if(c==1)
    {
        refrigerator();
    }
    else if(c==2)
    {
        AC();
    }
    else if(c==3)
    {
        washing_machine();
    }
    else if(c==4)
    {
        IPS();
    }
    else if(c==5)
    {
        generator();
    }
    else if(c==6)
    {
        TV();
    }
    else if(c==7)
    {
        oven();
    }
    else if(c==0)
    {
        home_page();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        appliance();
    }
}

void gadgets()
{
    system("cls");
    int c;
    printf("\n\n\n\n\n\n\t\t\tLargest Online Service Market");
    printf("\n\n\n\n\t\tGadgets Repair : \n");
    printf("\n\n\t\t\t\t1. Desktop Services\n\n\t\t\t\t2. Laptop Servicing\n\n\t\t\t\t3. Smartphone Repair\n\n\n\n\n\t\t\t\t0. Go back\n");
    printf("\n\n\n\t\t\tChoose your option : ");
    scanf("%d",&c);
    if(c==1)
    {
        desktop();
    }
    else if(c==2)
    {
        laptop();
    }
    else if(c==3)
    {
        smartphone();
    }
    else if(c==0)
    {
        home_page();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        gadgets();
    }
}

void electrical()
{
    system("cls");
    int c;
    printf("\n\n\n\n\n\n\t\t\tLargest Online Service Market");
    printf("\n\n\n\n\t\tElectric Services : \n");
    printf("\n\n\t\t\t\t1. Fan Service\n\n\t\t\t\t2. Tube light/Bulb Service\n\n\t\t\t\t3. Water Motor/Pump Servicing\n\n\t\t\t\t4. Switch Board Servicing \n\n\t\t\t\t5. Electrical Cable Fitting\n\n\t\t\t\t6.Main Distribution board Servicing\n\n\t\t\t\t7.Electrical Check Up\n\n\n\n\n\t\t\t\t0. Go back\n");
    printf("\n\n\n\t\t\tChoose your option : ");
    scanf("%d",&c);
    if(c==1)
    {
        fan();
    }
    else if(c==2)
    {
        light();
    }
    else if(c==3)
    {
        motor();
    }
    else if(c==4)
    {
        switches();
    }
    else if(c==5)
    {
        cable();
    }
    else if(c==6)
    {
        main_board();
    }
    else if(c==7)
    {
        check_up();
    }
    else if(c==0)
    {
        home_page();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        electrical();
    }
}

void laundry()
{
    system("cls");
    int c;
    printf("\n\n\n\n\n\n\t\t\tLargest Online Service Market");
    printf("\n\n\n\n\t\tLaundry Home Services : \n");
    printf("\n\n\t\t\t\t1. Men's Wear\n\n\t\t\t\t2. Household and Accessories\n\n\t\t\t\t3. Kid's Wear\n\n\t\t\t\t4. Women's Wear\n\n\n\n\n\t\t\t\t0. Go back\n");
    printf("\n\n\n\t\t\tChoose your option : ");
    scanf("%d",&c);
    if(c==1)
    {
        men();
    }
    else if(c==2)
    {
        household();
    }
    else if(c==3)
    {
        kids();
    }
    else if(c==4)
    {
        women();
    }
    else if(c==0)
    {
        home_page();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        laundry();
    }
}

void clean()
{
    system("cls");
    int c;
    printf("\n\n\n\n\n\n\t\t\tLargest Online Service Market");
    printf("\n\n\n\n\t\tCleaning Services : \n");
    printf("\n\n\t\t\t\t1. Room Basic Cleaning\n\n\t\t\t\t2. Bathroom Cleaning\n\n\n\n\n\t\t\t\t0. Go back\n");
    printf("\n\n\n\t\t\tChoose your option : ");
    scanf("%d",&c);
    if(c==1)
    {
        room_clean();
    }
    else if(c==2)
    {
        bathroom_clean();
    }
    else if(c==0)
    {
        home_page();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        clean();
    }
}

void sanitary()
{
    system("cls");
    int c;
    printf("\n\n\n\n\n\n\t\t\tLargest Online Service Market");
    printf("\n\n\n\n\t\tPlumbing and Sanitary Services : \n");
    printf("\n\n\t\t\t\t1. Water Tap Servicing\n\n\t\t\t\t2. Kitchen Sink Servicing\n\n\t\t\t\t3. Basin Servicing\n\n\t\t\t\t4. Bathtub Servicing\n\n\t\t\t\t5. Plumbing Check Up\n\n\n\n\n\t\t\t\t0. Go back\n");
    printf("\n\n\n\t\t\tChoose your option : ");
    scanf("%d",&c);
    if(c==1)
    {
        printf("tap");
    }
    else if(c==2)
    {
        printf("sink");
    }
    else if(c==3)
    {
        printf("basin");
    }
    else if(c==4)
    {
        printf("bathtub");
    }
    else if(c==5)
    {
        printf("plumbing");
    }
    else if(c==0)
    {
        home_page();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tWrong Input!!!\n");
        printf("\n\n\t\t\tPress 'Enter' to continue...\n");
        getch();
        system("cls");
        sanitary();
    }
}

void refrigerator()
{
    system("cls");
    int quantity,rate=500,total;
    char name[50]= {"Refrigerator Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void AC()
{
    system("cls");
    int quantity,rate=400,total;
    char name[50]= {"AC Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void washing_machine()
{
    system("cls");
    int quantity,rate=450,total;
    char name[50]= {"Washing Machine Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void IPS()
{
    system("cls");
    int quantity,rate=300,total;
    char name[50]= {"IPS Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void generator()
{
    system("cls");
    int quantity,rate=1000,total;
    char name[50]= {"Generator Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void TV()
{
    system("cls");
    int quantity,rate=350,total;
    char name[50]= {"TV Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void oven()
{
    system("cls");
    int quantity,rate=250,total;
    char name[50]= {"Microwave Oven Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void desktop()
{
    system("cls");
    int quantity,rate=250,total;
    char name[50]= {"Desktop Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void laptop()
{
    system("cls");
    int quantity,rate=500,total;
    char name[50]= {"Laptop Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void smartphone()
{
    system("cls");
    int quantity,rate=150,total;
    char name[50]= {"Smartphone Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void fan()
{
    system("cls");
    int quantity,rate=50,total;
    char name[50]= {"Electric Fan Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void light()
{
    system("cls");
    int quantity,rate=30,total;
    char name[50]= {"Tube Light/Bulb Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void motor()
{
    system("cls");
    int quantity,rate=100,total;
    char name[50]= {"Water Motor/Pump Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void switches()
{
    system("cls");
    int quantity,rate=25,total;
    char name[50]= {"Switch Board Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void cable()
{
    system("cls");
    int quantity,rate=100,total;
    char name[50]= {"Electrical Cable Fitting"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void main_board()
{
    system("cls");
    int quantity,rate=150,total;
    char name[50]= {"Main Distribution Board Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void check_up()
{
    system("cls");
    int quantity,rate=100,total;
    char name[50]= {"Electrical Check up"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void men()
{
    system("cls");
    int quantity,rate=25,total;
    char name[50]= {"Laundry -> Men's Wear"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void household()
{
    system("cls");
    int quantity,rate=30,total;
    char name[50]= {"Laundry -> Household Clothings"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void kids()
{
    system("cls");
    int quantity,rate=15,total;
    char name[50]= {"Laundry -> Kid's Wear"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void women()
{
    system("cls");
    int quantity,rate=20,total;
    char name[50]= {"Laundry -> Women's Wear"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void room_clean()
{
    system("cls");
    int quantity,rate=100,total;
    char name[50]= {"Room Basic Cleaning"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void bathroom_clean()
{
    system("cls");
    int quantity,rate=100,total;
    char name[50]= {"Bathroom Cleaning"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}

void tap()
{
    system("cls");
    int quantity,rate=25,total;
    char name[50]= {"Water Tap Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void sink()
{
    system("cls");
    int quantity,rate=50,total;
    char name[50]= {"Kitchen Sink Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void basin()
{
    system("cls");
    int quantity,rate=100,total;
    char name[50]= {"Basin Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void bathtub()
{
    system("cls");
    int quantity,rate=150,total;
    char name[50]= {"Bathtub Servicing"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
void plumbing()
{
    system("cls");
    int quantity,rate=200,total;
    char name[50]= {"Plumbing Check Up"};

    FILE* fp;
    fp=fopen("bill.txt","a+");

    printf("\n\n\n\n\n\n\n\n\n\t\tType of service : %s",name);

    printf("\n\n\t\tRate : %d/=",rate);
    printf("\n\n\t\tQuantity : ");
    scanf("%d",&quantity);
    total=quantity*rate;
    printf("\n\t\t\t\t  Total Bill : %d/=",total);
    fprintf(fp,"\n %s %d %d",name,rate,quantity);
    fclose(fp);
    printf("\n\n\n\t\tOur representative will contact you within one hour.");
    printf("\n\t\tPlease pay him/her the total bill.\n\n\n\t\t\t\t  Thank You.");

    printf("\n\n\n\n\t\tPress 'Enter' to go to the Home Page...\n");
    getch();
    system("cls");
    home_page();
}
