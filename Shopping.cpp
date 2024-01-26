#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <string>
using namespace std;
int Answer, Step, result, installment;
float TotalAmount = 0;
bool Con = false;
int MainPage();
void line();
void About();
void Shopping();
void Recete(int result, int installment,int TotalAmount, bool Con);
void installmentOP(int TotalAmount,bool Con);
int main() {
	

	MainPage();
	do {
		if (Answer == 1) {
			char Answer;
			About();
			cout << "Would you like to continue1(Y/N): \n"; cin >> Answer;
			if (Answer == 'n' || Answer == 'N') {
				break;
			}
			else {
				MainPage();
			}
		}
		else if (Answer == 2) {
			Shopping();
		}
		else if (Answer == 3) {
			break;
		}
		else {
			cout << "please enter number between (1 - 3): "; cin >> Answer;
		}
	} while (true);
	return 0;
}
int MainPage() {
	Step = 1;
	line();
	cout << '\t' << "MGD FIRMASINA HOS GELDINIZ\n";
	cout << '\t' << "SLOGANIMIZ: ISTEDIGINIZI SATIN ALIN\n";
	cout << "Lutfen bir islem seciniz: \n" << "1- Firma Hakkinda\n" << "2- Alis Veris\n" << "3- Cikis\n";
	cin >> Answer;
	return Answer;
}
void line() {
	for (int i = 0; i <= 39; i++) {
		cout << " -";
	}cout << '\n';
}
void About() {
	Step = 2;
	cout << "MGD informatin 2024 yilinda kurlumus olup en yeni  teknolojileri hizmete sunar." << endl;
	cout << "Firma sahibi:" << left << setw(5) << "      Mohammad MOHAMMName" << endl;
	cout << "Magaza Muduru:" << setw(5) << left << "      Damin, Mohammed Geabel" << endl;
	cout << "Satis Elemenlari" << setw(5) << left << "      Saeed, Lansa" << endl;
}
void Shoppingstart();
void Return();
void Shopping() {
	Step = 2;
	int cev;
	line();
	cout << "1- Shopping start\n" << "2- installmentOP\n" << "3- Recete\n" << "0- Return\n";
	cout << "Tercihinizi giriniz: "; cin >> cev;
	if (cev == 1) {
		Shoppingstart();
	}
	else if (cev == 2) {
		installmentOP(TotalAmount,Con);
		Con=true;
	}
	else if (cev == 3) {
		Recete(result,installment,TotalAmount,Con);
	}
	else {
		Return();
	}
}
void Shoppingstart() {
	Step = 3;
	struct product {
		string productName;
		float productPrice;
		int productNU;
	};

		product product1{ "Telephon", 24009, 1 };
		product product2{ "Computer" , 78756, 2 };
		product product3{ "Screen " , 6756, 3 };

		char continue1;

		do {
			int productnumbers1 = 0;
			int productnumbers2 = 0;
			int productnumbers3 = 0;

			cout << product1.productNU << "-  " << product1.productName << setw(35) << right << product1.productPrice << " $" << endl;
			cout << product2.productNU << "-  " << product2.productName<< setw(32) << right << product2.productPrice << " $" << endl;
			cout << product3.productNU << "-  " << product3.productName << setw(35) << right << product3.productPrice << " $" << endl;
			cout << "4- make the basket empty " << endl;
			cout << "5- Return " << endl;

			cout << '\n' << '\n';
			int productsec;
			cout << "Select your product : ";
			cin >> productsec;
			cout << '\n' << '\n';

			if (productsec == 4) {
				// Sepeti sıfırla
				productnumbers1 = 0;
				productnumbers2 = 0;
				productnumbers3 = 0;
				cout << "The basket is empty." << endl;
			}
			else if (productsec == 5) {
				Return();
			}
			else {
				int numbers;
				cout << "How many do you want from them : ";
				cin >> numbers;
				cout << '\n' << '\n';

				// Kullanıcı seçimine göre sepetteki numbersı güncelleyin
				switch (productsec) {
				case 1:
					productnumbers1 += numbers;
					TotalAmount += product1.productPrice * numbers;
					break;
				case 2:
					productnumbers2 += numbers;
					TotalAmount += product2.productPrice * numbers;
					break;
				case 3:
					productnumbers3 += numbers;
					TotalAmount += product3.productPrice * numbers;
					break;
				default:
					cout << "Geçersiz seçim. Program tamamlandi." << endl;
				}

				
				cout << "Total price is  : " << TotalAmount << " $" << endl;
				cout << '\n' << '\n';
			}

			cout << "Do you want to continue1? (Y/N): ";
			cin >> continue1;

		} while (continue1 == 'Y' || continue1 == 'y');

}
void installmentOP(int TotalAmount,bool Con) {
	Step = 3;
	Con= true;
	string month[12] = { "Jun","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	line();
	do {
		cout << "How many month would you like to pay? [1-36]" << endl;
		cin >> installment;
	} while (installment < 1 || installment>36);
	result = TotalAmount / installment;
	for (int i = 0; i < installment; i++)
	{
		cout << month[i] << "     " << result << endl;
	}
}
void Recete(int result, int installment, int TotalAmount, bool Con) 
{
	ofstream outputFile("Recete.txt");

			if (!outputFile.is_open()) 
			{
			cerr << "Error opening the file." << endl;
			}
	    Step = 3;
	if (Con==true)
	{
		void Recete(int result, int installment); 
		{
			string month[12] = { "Jun","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"  };
			for (int i = 0; i < installment; i++) {
			outputFile << month[i] << "    " << result << endl;
			}
			
		}
	}
	else
	{
		void Recete(int TotalAmount);
		{
			string month[12] = { "Ocak","subat","Mart","Nisan","Mayis","Haziran","Temmuz","Ağustos","Eylul","Ekim","Kasim","Aralik" };
			ofstream outputFile("Recete.txt");
			outputFile << TotalAmount << endl;
		}
		}
		outputFile.close();
		cout << "Recete is ready\n";
}

void Return() {
	if (Step == 2) {
		MainPage();
	}
	else if (Step == 3) {
		Shopping();
	}
}
