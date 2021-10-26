#include <iostream>
using namespace std;

//Account
class Account
{
protected:
    double Account_balance;
    int Account_Number;

public:
    Account(int Accountnumber, double AccountBalance = 0)
    {
        Account_Number = Accountnumber;
        if (AccountBalance >= 0)
        {
            this->Account_balance = AccountBalance;
        }
        else //if initial balance is less than zero.
        {
            this->Account_balance = 0;
            cout << "initial balance invalid";
        }
    }
    //updates balance
    void credit(double AccountBalance)
    {
        this->Account_balance = this->Account_balance + AccountBalance;
    }
    // debit amount from account
    double debit(double Debit_amount)
    {
        if (Account_balance >= Debit_amount)
        {
            this->Account_balance = this->Account_balance - Debit_amount;
            return (this->Account_balance);
        }
        else
        {
            cout << "withdrawl amount exceeded your Account balance.";
            return -1;
        }
    }
    //to get balance in the Account.
    double getBalance()
    {
        return this->Account_balance;
    }
    int Get_Account_Number()
    {
        return Account_Number;
    }
};

// savings Account class (derived class)
class Savings_Account : public Account
{
private:
    double interest_Rate;

public:
    Savings_Account(int number, double AccountBalance, double rate) : Account(number, AccountBalance)
    {
        this->interest_Rate = rate;
    }
    //to calculate total interest amount
    double calculateInterest()
    {
        return (this->Account_balance * this->interest_Rate) / 100;
    }
    //to calculate interest amount + current Account balance
    double calculateInterest(double temp)
    {
        return this->Account_balance + temp;
    }
    //to set the interset rate
    void setInterest(double rate)
    {
        this->interest_Rate = rate;
    }
};

// checking Account class (derived class)
class Checking_Account : public Account
{
private:
    double feeCharge;

public:
    Checking_Account(int number, double AccountBalance, double charge) : Account(number, AccountBalance)
    {
        this->feeCharge = charge;
    }
    void Credit(double Debit_amount)
    {
        credit(Debit_amount);
    }
    //to debit including function
    void transactionFee(double charge, double Debit_amount)
    {
        double balance = debit(Debit_amount);
        if (balance > feeCharge) //if balance is less than withdraw + Debit transaction fee
        {
            this->Account_balance = balance - this->feeCharge;
        }
        else
        {
            cout << " TRANSACTION FAILURE (INSUFFICIENT TRANSACTION Debit) ";
            this->Account_balance = balance + Debit_amount; // setting amount to the Account
        }
    }
    //setting charging
    void setCharge(double charge)
    {
        this->feeCharge = charge;
    }

    //returning charging
    double getCharge()
    {
        return this->feeCharge;
    }
};

//store the data of the savings Accounts.
class Saving_list
{
private:
    Savings_Account *acc;

public:
    Saving_list *next = NULL;
    Saving_list(Savings_Account *head)
    {
        acc = head;
        next = NULL;
    }
    //to insert Data at last
    void insertData(Savings_Account *head1)
    {
        Saving_list *ptr; //newnode to insert
        ptr = new Saving_list(head1);
        ptr->acc = head1;
        ptr->next = NULL;
        //if the ist is empty
        this->next = ptr; //adding newNode to your choice
    }
    // getting Account number if present
    Savings_Account *GetAccount(int AccountNum)
    {
        Saving_list *temp = this;
        while (temp != NULL)
        {
            if (temp->acc->Get_Account_Number() == AccountNum)
            {
                return temp->Get_Account();
            }
            temp = temp->next;
        }
        cout << "NOT FOUND!!!";
        return NULL;
    }
    //returning Account
    Savings_Account *Get_Account()
    {
        return this->acc;
    }
};
//store the data of the checkings Accounts.
class Checking_list
{
private:
    Checking_Account *acc;

public:
    Checking_list *next = NULL;
    Checking_list(Checking_Account *head)
    {
        acc = head;
        next = NULL;
    }
    //to insert Data at last
    void insertData(Checking_Account *head2)
    {
        Checking_list *ptr; //newnode to insert
        ptr = new Checking_list(head2);
        ptr->acc = head2;
        ptr->next = NULL;
        //if the ist is empty
        this->next = ptr; //adding newNode to your choice
    }
    // getting Account
    Checking_Account *GetAccount(int AccountNum)
    {
        Checking_list *temp = this;
        while (temp)
        {
            if (temp->acc->Get_Account_Number() == AccountNum)
            {
                return temp->Get_Account();
                break;
            }
            temp = temp->next;
        }
        cout << "NOT FOUND!!!";
        return NULL;
    }
    //returning Account
    Checking_Account *Get_Account()
    {
        return this->acc;
    }
};

int main()
{
    Account *head = NULL;
    int choice, List_Number, AccountNumber;
    double Balance, Interest_Rate, charge, Debit;
    double sample;
    Savings_Account *head1 = NULL;
    Checking_Account *head2 = NULL;
    Saving_list *savingSaving_list = NULL;
    Checking_list *checkingSaving_list = NULL;
    while (1)
    {
        cout << "\n\n1. Open Account (Savings or Checking Account) \n2. Credit (Savings or Checking Account)\n3. Debit (Savings or Checking Account)\n4. Change/Update Interest rate (Savings Account)\n5. Calculate Interest (Savings Account - Print)\n6. Calculate and Update Interest (Savings Account - Credit)\n7. Change/Update Fee Amount (Checking Account)\n8. Print Checking Fee (Checking Account)\n9. Transact and Update (Checking Account - Debit)\n10. Exit\n";
        cout << "Enter the choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n\n Which Account do you want to create ";
            cout << "\n 1. savings Account \n 2. checking list \n";
            cout << "Enter your choice number\n";
            cin >> List_Number;

            while (1)
            {
                cout << "Enter the Account Number :";
                cin >> AccountNumber;
                if (AccountNumber > 0)
                {
                    break;
                }
                else
                {
                    cout << "***********Account number should be differnt***********\n";
                }
            }

            while (1)
            {
                cout << "Enter Account Balance : ";
                cin >> Balance;
                if (Balance >= 0.0)
                {
                    break;
                }
                else
                {
                    cout << "*********Account Balance should be positive******\n";
                }
            }

            if (List_Number == 1)
            {
                while (1)
                {
                    cout << "Enter the interest rate : ";
                    cin >> Interest_Rate;
                    if (Interest_Rate >= 0.0 && Interest_Rate <= 100.0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "*********interest rate be in the range of [1-100] including 0 and 100 ******\n";
                    }
                }
                //creating first savings Account
                if (head1 == NULL)
                {
                    head1 = new Savings_Account(AccountNumber, Balance, Interest_Rate);
                    savingSaving_list = new Saving_list(head1);
                }
                else
                {
                    Savings_Account *node = new Savings_Account(AccountNumber, Balance, Interest_Rate);
                    Saving_list *temp = savingSaving_list;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->insertData(node);
                }
            }
            else if (List_Number == 2)
            {
                while (1)
                {
                    cout << "Enter the fee charge : ";
                    cin >> charge;
                    if (charge > 0.0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "**********fee charge should be positive********\n";
                    }
                }
                if (head2 == NULL)
                {
                    head2 = new Checking_Account(AccountNumber, Balance, charge);
                    checkingSaving_list = new Checking_list(head2);
                }
                else
                {
                    Checking_Account *node = new Checking_Account(AccountNumber, Balance, Interest_Rate);
                    Checking_list *temp = checkingSaving_list;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->insertData(node);
                }
            }
            break;
        }
        case 2:
        {
            cout << "\n\n Which Account do you want to credit ";
            cout << "\n 1. savings Account \n 2. checking list \n";
            cout << "Enter your choice number\n";
            cin >> List_Number;

            cout << "Enter the Account number you want to credit: "; //asking for Account number.
            cin >> AccountNumber;
            while (1) //until the vakue is greater than 0
            {
                cout << "Enter the Debit to credit : ";
                cin >> Debit;
                if (Debit >= 0.0)
                {
                    break;
                }
                else
                {
                    cout << "**********amount should be positive******\n";
                }
            }
            if (List_Number == 1) //if the head type savings Account
            {
                Savings_Account *Data = savingSaving_list->GetAccount(AccountNumber);
                if (Data != NULL)
                {
                    Data->credit(Debit);
                    cout << "Your total balance is " << Data->getBalance() << "\n";
                }
            }
            else if (List_Number == 2) //if the head type checkings Account
            {
                Checking_Account *Data = checkingSaving_list->GetAccount(AccountNumber);
                if (Data != NULL)
                {
                    Data->Credit(Debit);
                    cout << "Your total balance is " << Data->getBalance() << "\n";
                }
            }
            break;
        }
        case 3:
        {
            cout << "\n\n Which Account do you want to debit ";
            cout << "\n 1. savings Account \n 2. checking list \n";
            cout << "Enter your choice number\n";
            cin >> List_Number;

            cout << "Enter the Account number you want to withdraw/debit: ";
            cin >> AccountNumber;
            while (1) //head value greater than 0
            {
                cout << "Enter the amount to debit : ";
                cin >> Debit;
                if (Debit > 0.0)
                {
                    break;
                }
                else
                {
                    cout << "debit amount should be positive !!!\n";
                    cin.clear();
                }
            }
            if (List_Number == 1) //if the head savings Account
            {
                Savings_Account *Data = savingSaving_list->GetAccount(AccountNumber);
                if (Data != NULL)
                {
                    Data->debit(Debit);
                    cout << "Your total balance is " << Data->getBalance() << "\n";
                }
            }
            else if (List_Number == 2) //if the head checkings Account
            {
                Checking_Account *Data = checkingSaving_list->GetAccount(AccountNumber);
                if (Data != NULL)
                {
                    Data->transactionFee(Data->getCharge(), Debit);
                    cout << "Your total balance is " << Data->getBalance() << "\n";
                }
            }
            break;
        }
        case 4:
        {
            cout << "Enter the Account number to change/update the interest rate : ";
            cin >> AccountNumber;
            while (1) //head interset rate in between 1-100
            {
                cout << "Enter the interest rate : ";
                cin >> Interest_Rate;
                if (Interest_Rate > 0.0 && Interest_Rate < 100.0)
                {
                    break;
                }
                else
                {
                    cout << "enter interest rate 1-100 !!!\n";
                }
            }
            Savings_Account *Data = savingSaving_list->GetAccount(AccountNumber);
            if (Data != NULL)
                Data->setInterest(Interest_Rate); //interest
            break;
        }
        case 5:
        {
            cout << "Enter the Account number to change/update the interest rate : ";
            cin >> AccountNumber;
            Savings_Account *Data = savingSaving_list->GetAccount(AccountNumber);
            if (Data != NULL)
            {
                sample = Data->calculateInterest(); //interest
                cout << "Interest of the Account " << AccountNumber << " is " << sample << " per year \n";
            }
            break;
        }
        case 6:
        {
            cout << "Enter the Account number to change/update the interest rate : ";
            cin >> AccountNumber;
            Savings_Account *Data = savingSaving_list->GetAccount(AccountNumber);
            if (Data != NULL)
            {
                sample = Data->calculateInterest();
                cout << "Sum of Account balance Interest of the Account " << AccountNumber << " is " << Data->calculateInterest(sample) << "\n";
            }
            break;
        }
        case 7:
        {
            cout << "Enter the Account number to change/update the fee charge : ";
            cin >> AccountNumber;
            while (1) //head value greater than 0
            {
                cout << "Enter the fee charge : ";
                cin >> charge;
                if (charge > 0.0)
                {
                    break;
                }
                else
                {
                    cout << "********fee charge amount is positive*******\n";
                }
            }
            Checking_Account *Data = checkingSaving_list->GetAccount(AccountNumber);
            if (Data != NULL)
                Data->setCharge(charge); //new charge
            break;
        }
        case 8:
        {
            cout << "Enter the Account number to check fee charge : ";
            cin >> AccountNumber;
            Checking_Account *Data = checkingSaving_list->GetAccount(AccountNumber);
            if (Data != NULL)
                cout << "Fee charge of the Account " << AccountNumber << " is " << Data->getCharge() << "\n";
            break;
        }
        case 9:
        {
            cout << "Enter the Account number to withdraw: ";
            cin >> AccountNumber;
            while (1) //head value greater than 0
            {
                cout << "Enter the Debit to debit : ";
                cin >> Debit;
                if (Debit > 0.0)
                {
                    break;
                }
                else
                {
                    cout << "debit amount should be positive !!!\n";
                }
            }
            Checking_Account *Data = checkingSaving_list->GetAccount(AccountNumber);
            if (Data != NULL)
                Data->transactionFee(Data->getCharge(), Debit); //transact amount
            break;
        }
        default:
            exit(0);
        }
    }
    return 0;
}
