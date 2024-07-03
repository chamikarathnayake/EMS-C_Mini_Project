#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float Managers[5] = {150000, 180000, 120000, 150000, 130000};
float Executive_Officer[5] = {75000, 80000, 100000, 95000, 85000};
float junior_Executive_Officer[5] = {50000, 65000, 55000, 75000, 60000};
float Assistant[5] = {35000, 48000, 40000, 37000, 42000};  // Basic, Special Bonus, Loans, Other Allowances, WNOP

int choice;
int EmpId[10];
char Eno;
int OT;
float OTPayment;
float MSalary;
float Bonus;
float Loan;
char yesno;
float Total_earnings;
float Total_DEDUCTION;
float NET_PAY;
float EPF_8;
float ETF;


// Function prototypes
void addEmployee();
void calculateOT();
void monthlySalaryinBrief();
void specialBonus();
void loans();
void viewPayslip();
void showAllEmployees();
void gobackTomainmenu();
void applyanotherEmployee();

int main(){
    do {
        printf("\n\t\t\t\t\t\t\tEmployee Management System");
        printf("\n\t\t\t\t\t\t------------------------------------------\n\n");
        printf("\t\t\t\t\t1. Add Employee\n\n");
        printf("\t\t\t\t\t2. Calculate OT\n\n");
        printf("\t\t\t\t\t3. Monthly Salary in Brief\n\n");
        printf("\t\t\t\t\t4. Special Bonus\n\n");
        printf("\t\t\t\t\t5. Loans\n\n");
        printf("\t\t\t\t\t6. View Payslip\n\n");
        printf("\t\t\t\t\t7. Show All Employees\n\n");

        printf("\n \tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                choice = 0;
                break;
            case 2:
                calculateOT();
                choice = 0;
                break;
            case 3:
                monthlySalaryinBrief();
                choice = 0;
                break;
            case 4:
                specialBonus();
                choice = 0;
                break;
            case 5:
                loans();
                choice = 0;
                break;
            case 6:
                viewPayslip();
                choice = 0;
                break;
            case 7:
                showAllEmployees();
                choice = 0;
                break;
            default:
                printf("\n\n\t.......................Invalid choice Please try again.......................\n");
                gobackTomainmenu();
                choice = 0;
        }

    } while (choice != 0);

return 0;
}

void addEmployee() {
    FILE *file;
    char EmpId[10];
    char empName[50];
    char designation[10];
    char dateOfJoining[15];
    char existingEmpID[30];

    printf("\n \tEnter Employee No: ");
    scanf(" %s", EmpId);

    file = fopen("employees.txt", "r");
    while (fscanf(file, "%s", existingEmpID) != EOF) {
        if (strcmp(existingEmpID, EmpId) == 0) {
            fclose(file);
            printf("\n\tEmployee ID already exists. Try again with a different ID.\n");
            gobackTomainmenu();
            return;
        }
    }
    fclose(file);

    file = fopen("employees.txt", "a");
    if (file == NULL) {
        printf("\n\tError opening file for writing employee information.\n");
        return;
    }

    printf("\n \tEnter Employee Name (S_I_DISSANAYAKE): ");
    scanf(" %s", empName);

    printf("\n \tEnter Employee Designation: ");
    scanf(" %s", designation);

    printf("\n \tEnter Date of Joining (YYYY-MM-DD): ");
    scanf(" %s", dateOfJoining);

    fprintf(file, "%s %s %s %s \n",EmpId, empName, designation, dateOfJoining);

    fclose(file);

    printf("\n\tEmployee added successfully.\n");

    applyanotherEmployee();
}

void calculateOT() {

    printf("\n \tEnter Employee No: ");
    scanf(" %d", &EmpId);

    printf("\n\t\t * Designation Codes\n\n");
    printf("\t\t\tM. Manager\n\n");
    printf("\t\t\tE. Executive Officer\n\n");
    printf("\t\t\tJ. junior Executive Officer\n\n");
    printf("\t\t\tA. Assistant\n");

    printf("\n \tEnter Designation Code(M,E,J,A): ");
    scanf(" %s", &Eno);

    printf("\n \tEnter OT hours: ");
    scanf("%d", &OT);

    switch (Eno) {
        case 'M': case 'm':
            OTPayment = OT * 50;
            printf("\n\t................................................\n");
            printf("\n\t\tYour OT Rate is 50 per hour");
            printf("\n\t\tYour OT Payment = Rs %.2f\n", OTPayment);
            printf("\n\t................................................\n");
            break;
        case 'E': case 'e':
            OTPayment = OT * 30;
            printf("\n\t................................................\n");
            printf("\n\t\tYour OT Rate is 30 per hour");
            printf("\n\t\tYour OT Payment = Rs %.2f\n", OTPayment);
            printf("\n\t................................................\n");
            break;
        case 'J': case 'j':
            OTPayment = OT * 20;
            printf("\n\t................................................\n");
            printf("\n\t\tYour OT Rate is 20 per hour");
            printf("\n\t\tYour OT Payment = Rs %.2f\n", OTPayment);
            printf("\n\t................................................\n");
            break;
        case 'A': case 'a':
            OTPayment = OT * 10;
            printf("\n\t................................................\n");
            printf("\n\t\tYour OT Rate is 10 per hour");
            printf("\n\t\tYour OT Payment = Rs %.2f\n", OTPayment);
            printf("\n\t................................................\n");
            break;
        default:
            printf("\n\n\t.......................Invalid input.......................\n");
    }
    gobackTomainmenu();
}

void monthlySalaryinBrief() {

    printf("\n \tEnter Employee No: ");
    scanf(" %d", &EmpId);

    printf("\n\t\t * Designation Codes\n\n");
    printf("\t\t\tM. Manager\n\n");
    printf("\t\t\tE. Executive Officer\n\n");
    printf("\t\t\tJ. junior Executive Officer\n\n");
    printf("\t\t\tA. Assistant\n");

    printf("\n \tEnter Designation Code(M,E,J,A): ");
    scanf(" %s", &Eno);

    printf("\n \tEnter OT hours: ");
    scanf("%d", &OT);

    switch (Eno) {
        case 'M': case 'm':
            MSalary = Managers[0] + Managers[1] + (OT * 50);                    // Basic,  Special Bonus
            printf("\n\t...........................................\n");
            printf("\n\t\tYour Monthly Salary = %.2f\n", MSalary);
            printf("\n\t...........................................\n");
            break;
        case 'E': case 'e':
            MSalary = Executive_Officer[0] + Executive_Officer[1] + (OT * 40);
            printf("\n\t...........................................\n");
            printf("\n\t\tYour Monthly Salary = %.2f\n", MSalary);
            printf("\n\t...........................................\n");
            break;
        case 'J': case 'j':
            MSalary = junior_Executive_Officer[0] + junior_Executive_Officer[1] + (OT * 30);
            printf("\n\t...........................................\n");
            printf("\n\t\tYour Monthly Salary = %.2f\n", MSalary);
            printf("\n\t...........................................\n");
            break;
        case 'A': case 'a':
            MSalary = Assistant[0] + Assistant[1] + (OT * 10);
            printf("\n\t...........................................\n");
            printf("\n\t\tYour Monthly Salary = %.2f\n", MSalary);
            printf("\n\t...........................................\n");
            break;
        default:
            printf("\n\n\t.......................Invalid input.......................\n");
    }
    gobackTomainmenu();
}

void specialBonus() {

    printf("\n \tEnter Employee No: ");
    scanf(" %d", &EmpId);

    printf("\n\t\t * Designation Codes\n\n");
    printf("\t\t\tM. Manager\n\n");
    printf("\t\t\tE. Executive Officer\n\n");
    printf("\t\t\tJ. junior Executive Officer\n\n");
    printf("\t\t\tA. Assistant\n");

    printf("\n \tEnter Designation Code(M,E,J,A): ");
    scanf(" %s", &Eno);

    switch (Eno) {
        case 'M': case 'm':
            Bonus = Managers[1];
            printf("\n\t........................................\n");
            printf("\n\t\tYou have %.2f of Bonus\n", Bonus);
            printf("\n\t........................................\n");
            break;
        case 'E': case 'e':
            Bonus = Executive_Officer[1];
            printf("\n\t........................................\n");
            printf("\n\t\tYou have %.2f of Bonus\n", Bonus);
            printf("\n\t........................................\n");
            break;
        case 'J': case 'j':
            Bonus = junior_Executive_Officer[1];
            printf("\n\t........................................\n");
            printf("\n\t\tYou have %.2f of Bonus\n", Bonus);
            printf("\n\t........................................\n");
            break;
        case 'A': case 'a':
            Bonus = Assistant[1];
            printf("\n\t........................................\n");
            printf("\n\t\tYou have %.2f of Bonus\n", Bonus);
            printf("\n\t........................................\n");
            break;
        default:
            printf("\n\n\t.......................Invalid input.......................\n");
    }
    gobackTomainmenu();
}

void loans() {

    printf("\n \tEnter Employee No: ");
    scanf(" %d", &EmpId);

    printf("\n\t\t * Designation Codes\n\n");
    printf("\t\t\tM. Manager\n\n");
    printf("\t\t\tE. Executive Officer\n\n");
    printf("\t\t\tJ. junior Executive Officer\n\n");
    printf("\t\t\tA. Assistant\n");

    printf("\n \tDesignation Code(M,E,J,A): ");
    scanf(" %s", &Eno);

    switch (Eno) {
        case 'M': case 'm':
            Loan = Managers[2];
            printf("\n\t..............................................\n");
            printf("\n\t\tYou can get a %.2f of Loan\n", Loan);
            printf("\n\t..............................................\n");
            break;
        case 'E': case 'e':
            Loan = Executive_Officer[2];
            printf("\n\t..............................................\n");
            printf("\n\t\tYou can get a %.2f of Loan\n", Loan);
            printf("\n\t..............................................\n");
            break;
        case 'J': case 'j':
            Loan = junior_Executive_Officer[2];
            printf("\n\t..............................................\n");
            printf("\n\t\tYou can get a %.2f of Loan\n", Loan);
            printf("\n\t..............................................\n");
            break;
        case 'A': case 'a':
            Loan = Assistant[2];
            printf("\n\t..............................................\n");
            printf("\n\t\tYou can get a %.2f of Loan\n", Loan);
            printf("\n\t..............................................\n");
            break;
        default:
            printf("\n\n\t.......................Invalid input.......................\n");
    }
    gobackTomainmenu();
}

void viewPayslip() {
    int EmpId;

    printf("\n \tEnter Employee No: ");
    scanf(" %d", &EmpId);

    printf("\n\t\t * Designation Codes\n\n");
    printf("\t\t\tM. Manager\n\n");
    printf("\t\t\tE. Executive Officer\n\n");
    printf("\t\t\tJ. junior Executive Officer\n\n");
    printf("\t\t\tA. Assistant\n");

    printf("\n \tEnter Employee Designation Code(M,E,J,A): ");
    scanf(" %s", &Eno);

        switch (Eno) {
        case 'M': case 'm':
            Total_earnings = Managers[0]+Managers[1]+Managers[3];
            EPF_8 = (Managers[0]*0.08);
            ETF = (50000*0.03);
            Total_DEDUCTION = (EPF_8+ETF+Managers[4]);
            NET_PAY = Total_earnings - Total_DEDUCTION;

            printf("\n\t____________________________________________________________\n\n");
            printf("\n\t.......................PAY SLIP.............................\n");
            printf("\n\tEmployee ID : %d", EmpId);
            printf("\n\tDesignation : Manager\n");
            printf("\n\tEARNINGS                                              AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tBasic                                               %.2f", Managers[0]);
            printf("\n\tBonus                                               %.2f", Managers[1]);
            printf("\n\tOther Allowances                                    %.2f", Managers[3]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total earnings   %.2f", Total_earnings);
            printf("\n\t                                                    ________\n");
            printf("\n\tDEDUCTIONS                                            AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tEPF                                                  %.2f", EPF_8);
            printf("\n\tETF                                                  %.2f", ETF);
            printf("\n\tWNOP                                                 %.2f", Managers[4]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total DEDUCTION   %.2f", Total_DEDUCTION);
            printf("\n\t                                                    ________\n");
            printf("\n\t                                          NET PAY   %.2f", NET_PAY);
            printf("\n\t____________________________________________________________\n\n");
            break;

        case 'E': case 'e':
            Total_earnings = Executive_Officer[0]+Executive_Officer[1]+Executive_Officer[3];
            EPF_8 = (Executive_Officer[0]*0.08);
            ETF = (35000*0.03);
            Total_DEDUCTION = (EPF_8+ETF+Executive_Officer[4]);
            NET_PAY = Total_earnings - Total_DEDUCTION;

            printf("\n\t____________________________________________________________\n\n");
            printf("\n\t.......................PAY SLIP.............................\n");
            printf("\n\tEmployee ID : %d", EmpId);
            printf("\n\tDesignation : Executive Officer\n");
            printf("\n\tEARNINGS                                              AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tBasic                                               %.2f", Executive_Officer[0]);
            printf("\n\tBonus                                                %.2f", Executive_Officer[1]);
            printf("\n\tOther Allowances                                    %.2f", Executive_Officer[3]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total earnings   %.2f", Total_earnings);
            printf("\n\t                                                    ________\n");
            printf("\n\tDEDUCTIONS                                            AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tEPF                                                  %.2f", EPF_8);
            printf("\n\tETF                                                  %.2f", ETF);
            printf("\n\tWNOP                                                 %.2f", Executive_Officer[4]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total DEDUCTION   %.2f", Total_DEDUCTION);
            printf("\n\t                                                    ________\n");
            printf("\n\t                                          NET PAY   %.2f", NET_PAY);
            printf("\n\t____________________________________________________________\n\n");
            break;
        case 'J': case 'j':
            Total_earnings = junior_Executive_Officer[0]+junior_Executive_Officer[1]+junior_Executive_Officer[3];
            EPF_8 = (junior_Executive_Officer[0]*0.08);
            ETF = (25000*0.03);
            Total_DEDUCTION = (EPF_8+ETF+junior_Executive_Officer[4]);
            NET_PAY = Total_earnings - Total_DEDUCTION;

            printf("\n\t____________________________________________________________\n\n");
            printf("\n\t.......................PAY SLIP.............................\n");
            printf("\n\tEmployee ID : %d", EmpId);
            printf("\n\tDesignation : Junior Executive Officer\n");
            printf("\n\tEARNINGS                                              AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tBasic                                               %.2f", junior_Executive_Officer[0]);
            printf("\n\tBonus                                                %.2f", junior_Executive_Officer[1]);
            printf("\n\tOther Allowances                                    %.2f", junior_Executive_Officer[3]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total earnings   %.2f", Total_earnings);
            printf("\n\t                                                    ________\n");
            printf("\n\tDEDUCTIONS                                            AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tEPF                                                  %.2f", EPF_8);
            printf("\n\tETF                                                   %.2f", ETF);
            printf("\n\tWNOP                                                 %.2f", junior_Executive_Officer[4]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total DEDUCTION   %.2f", Total_DEDUCTION);
            printf("\n\t                                                    ________\n");
            printf("\n\t                                          NET PAY   %.2f", NET_PAY);
            printf("\n\t____________________________________________________________\n\n");
            break;
        case 'A': case 'a':
            Total_earnings = Assistant[0]+Assistant[1]+Assistant[3];
            EPF_8 = (Assistant[0]*0.08);
            ETF = (15000*0.03);
            Total_DEDUCTION = (EPF_8+ETF+Assistant[4]);
            NET_PAY = Total_earnings - Total_DEDUCTION;

            printf("\n\t____________________________________________________________\n\n");
            printf("\n\t.......................PAY SLIP.............................\n");
            printf("\n\tEmployee ID : %d", EmpId);
            printf("\n\tDesignation : Assistant\n");
            printf("\n\tEARNINGS                                              AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tBasic                                               %.2f", Assistant[0]);
            printf("\n\tBonus                                                %.2f", Assistant[1]);
            printf("\n\tOther Allowances                                     %.2f", Assistant[3]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total earnings   %.2f", Total_earnings);
            printf("\n\t                                                    ________\n");
            printf("\n\tDEDUCTIONS                                            AMOUNT");
            printf("\n\t____________________________________________________________");
            printf("\n\tEPF                                                  %.2f", EPF_8);
            printf("\n\tETF                                                   %.2f", ETF);
            printf("\n\tWNOP                                                 %.2f", Assistant[4]);
            printf("\n\t                                                    ________");
            printf("\n\t                                   Total DEDUCTION   %.2f", Total_DEDUCTION);
            printf("\n\t                                                    ________\n");
            printf("\n\t                                          NET PAY   %.2f", NET_PAY);
            printf("\n\t____________________________________________________________\n\n");
            break;
        default:
            printf("\n\n\t.......................Invalid input.......................\n");
    }
    gobackTomainmenu();
}

void showAllEmployees() {
    FILE *file;
    char EmpId[10];
    char empName[20];
    char designation[30];
    char dateOfJoining[15];

    file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("\n\tError opening file for reading employee information.\n");
        return;
    }

    printf("\n\n\n\t\t\t   -------------------- Employee Details --------------------\n\n");
    printf("\n\t%-10s\t%-20s \t\t%-30s %-15s", "EmployeeID", "EmployeeName", "Designation", "Date Of Joining");
    printf("\n\t______________________________________________________________________________________________\n");

    while (fscanf(file, "%s %s %s %s", EmpId, empName, designation, dateOfJoining) != EOF) {
        printf("\n\t%-10s \t%-20s \t\t%-30s %-15s", EmpId, empName, designation, dateOfJoining);
    }
    printf("\n\t______________________________________________________________________________________________\n");

    fclose(file);

    gobackTomainmenu();
}

void applyanotherEmployee() {
    printf("\n\n\tDo you want apply another Employee (Y/N): ");
    scanf(" %c", &yesno);

    if (yesno == 'Y' || yesno == 'y') {
        system("cls");
        addEmployee();
    } else if (yesno == 'N' || yesno == 'n') {
        system("cls");
        main();

    } else {
        printf("\n\nInvalid Input");
    }
}

void gobackTomainmenu() {
    printf("\n\n\tGo back to main menu (Y/N): ");
    scanf(" %c", &yesno);

    if (yesno == 'Y' || yesno == 'y') {
        system("cls");
        main();
    } else if (yesno == 'N' || yesno == 'n') {
        system("cls");
        printf("\n\n\n\n\t\t\t\t\t\t--------------------   Thank You   ----------------------\n\n\n");

    } else {
        printf("\n\nInvalid Input");
        system("cls");
        main();
    }
}
