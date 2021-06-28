
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <sstream>
bool tc;
void f1() {
    std::cout << "Hello World!\n";
}
void f2() {
    int age; std::string firstname; std::string lastname;
    std::cout << "Enter your first name:" << std::endl;
    std::cin >> firstname;
    std::cout << "Enter your last name:" << std::endl;
    std::cin >> lastname;
    std::cout << "Enter your age:" << std::endl;
    std::cin >> age;
    while (std::cin.fail() || age<0)
    {
        std::cout << "Invalid Entry! Please enter a positive number!" << std::endl;
        std::cout << "Enter your age:" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> age;
    }
    std::cout << firstname << " " << lastname<< ", "<<age<<std::endl;
}
void f4() {
    time_t result=time(NULL);
    char str[26];
    ctime_s(str, sizeof str, &result);

    int countr = 4;
    while (countr < 11) {
        std::cout << str[countr];
        countr++;
    }
    countr = 20;
    while (countr < 24) {
        std::cout << str[countr];
        countr++;
    }
    std::cout<<std::endl;
}
void f5() {
    int numbers[]={ 0,0 };
    std::cout << "Enter a number:" << std::endl;
    std::cin >> numbers[0];
    while (std::cin.fail() )
    {
        std::cout << "Invalid Entry! Please enter a  number!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> numbers[0];
    }
    
    std::cout << "Enter another number:" << std::endl;
    std::cin >> numbers[1];
    while (std::cin.fail())
    {
        std::cout << "Invalid Entry! Please enter a  number!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> numbers[0];
    }
    if (numbers[0] > numbers[1]) {
        std::cout << numbers[0] << " was the bigger number" << std::endl;
    }
    else {
        std::cout << numbers[1] << " was the bigger number" << std::endl;
    }
    
}
void f6() {

    int iSecret, iGuess;

    /* initialize random seed: */
    srand(time(NULL));

    /* generate secret number between 1 and 10: */
    iSecret = rand() % 100 + 1;

    do {
        std::cout << "Guess the number (1 to 100): " << std::endl;
        std::cin >> iGuess;
        while (std::cin.fail() || iGuess>100 || iGuess<0)
        {
            std::cout << "Invalid Entry! Please enter a  number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> iGuess;
        }
        if (iSecret < iGuess) std::cout<<"The secret number is LOWER"<<std::endl;
        else if (iSecret > iGuess) std::cout << "The secret number is HIGHER" << std::endl;
    } while (iSecret != iGuess);

   std::cout<<"Congratulations!"<<std::endl;
}
void f7() {
    std::string message;
    std::ofstream myfile;
    myfile.open("text7.txt", std::ofstream::out | std::ofstream::trunc);
    std::cout << "enter the text you want on your file test7.txt" <<std::endl;
    std::cin >> message;
    myfile << message;
    myfile.close();
}
void f8() {
    std::string x;
    std::ifstream inFile;

    inFile.open("text7.txt");
    if (!inFile) {
        std::cout << "Unable to open file"<<std::endl;
        exit(1); // terminate with error
    }

    while (inFile >> x) {
        std::cout << x << std::endl;
    }

    inFile.close();
}
void f10() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i * j < 10) std::cout << "  ";
            if (i * j < 100 && i*j >=10) std::cout << " ";
            std::cout << i * j <<"  ";
            
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
void f9() {
    double inp;
    std::cout <<"Enter a decimal number"<< std::endl;
    std::cin >> inp;
    std::cout << inp << "^0.5  = " << pow(inp, 0.5) << std::endl;
    std::cout << inp << "^2.0  = " << pow(inp,2.0) << std::endl;
    std::cout << inp << "^10.0 = " << pow(inp, 10.0) << std::endl;

}
void f11() {
    std::vector<int> list1;
    std::vector<int> list2;
    srand(time(NULL));
    int mynum;
    for (int i = 0; i < 10; i++) {        
        mynum = rand() % 100;
        list1.push_back(mynum);
        std::cout << list1[i] << " ";
    }
    std::cout << std::endl;
    list2 = list1;
    std::sort(list2.begin(), list2.end());
    for (int i = 0; i < list2.size(); i++) {
        std::cout << list2[i] << " ";
    }
}
void f12() {
    std::string input;

    std::cout << "Please enter a word: ";
    std::cin >> input;

    if (input == std::string(input.rbegin(), input.rend())) {
        std::cout << input << " is a palindrome"<<std::endl;
    }
    else {
        std::cout << input << " is NOT a palindrome"<<std::endl;
    }
}
void f13() {
    int a[2];
    for (int i = 0; i < 2; i++) {
        std::cout << "Enter a number:"<<std::endl;
        std::cin >> a[i];
        while (std::cin.fail())
        {
            std::cout << "Invalid Entry! Please enter a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> a[i];
        }
    }
    if (a[1] > a[0]+1) {
        for (int i = 1; i < a[1] - a[0]; i++) {
            std::cout << a[0]+i<<" ";
        }
        std::cout<<std::endl;
    }
    else if (a[0] > a[1] + 1) {
        for (int i = 1; i < a[0] - a[1]; i++) {
            std::cout << a[1] + i << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "No numbers in between the two input numbers" << std::endl;
    }
}
void f14() {
    std::string str;
    std::vector<int> vect;

    std::cout << "Enter a bunch of numbers separated by comma:" << std::endl;
    std::cin >> str;
    std::stringstream ss(str);
    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
        
    }

    for (std::size_t i = 0; i < vect.size(); i++)
        if (vect[i] % 2 == 0) {
            std::cout << vect[i] << " is even" << std::endl;
        }
        else {
            std::cout << vect[i] << " is odd" << std::endl;
        }
}
void f15() {
    std::string str;
    std::vector<int> vect;

    std::cout << "Enter a bunch of numbers separated by comma:" << std::endl;
    std::cin >> str;
    std::stringstream ss(str);
    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();

    }
    int sum = 0;
    for (std::size_t i = 0; i < vect.size(); i++) {
        sum += vect[i];
    }
    std::cout << "Sum of the numbers: "<< sum << std::endl;

}
void f16() {
    struct aCharacter {
       std::string mname;
       int mhealth;
       int mpower;
       int mluck;
    };
    aCharacter player;
    aCharacter opponent;
    std::cout << "Input Player name:" << std::endl;
    std::cin >> player.mname;
    std::cout << "Input Opponent name:" << std::endl;
    std::cin >> opponent.mname;
    srand(time(NULL));
    player.mhealth = rand() % 101;
    opponent.mhealth = rand() % 101;
    player.mpower = rand() % 101;
    opponent.mpower = rand() % 101;
    player.mluck = rand() % 101;
    opponent.mluck = rand() % 101;
    std::cout << player.mname << " health: " << player.mhealth << "%" << std::endl;
    std::cout << player.mname << " power: " << player.mpower << "%" << std::endl;
    std::cout << player.mname << " luck: " << player.mluck <<"%"<< std::endl;
    std::cout << opponent.mname << " health: " << opponent.mhealth << "%" << std::endl;
    std::cout << opponent.mname << " power: " << opponent.mpower << "%" << std::endl;
    std::cout << opponent.mname << " luck: " << opponent.mluck << "%" << std::endl;
}
void f3() {
    if (tc) {
        system("Color 1A");
        tc = false;
    }
    else {
        system("Color 1B");
        tc = true;
    }
    std::cout << "CHANGING COLOR" << std::endl;
}
void functionpick(int fu) {
    switch (fu) {
    case 1: f1(); 
        break;       
    case 2: f2();
        break;
    case 3: f3(); 
        break;      
    case 4: f4();
        break;
    case 5: f5();
        break;
    case 6: f6();
        break;
    case 7: f7();
        break;
    case 8: f8();
        break;
    case 9: f9();
        break;
    case 10: f10();
        break;
    case 11: f11();
        break;
    case 12: f12();
        break;
    case 13: f13();
        break;
    case 14: f14();
        break;
    case 15: f15();
        break;
    case 16: f16();
        break;
    
    }


}

const int NUMBER_OF_QUESTIONS = 16;
int main()
{
    tc = true;
    system("Color 1B");
    int function_number=1; 
    while (function_number != 0) {
        
        std::cout << "Pick a function to execute by entering a number (1-16), to quit input number 0\n";
        std::cin >> function_number;
        while (std::cin.fail() || function_number > NUMBER_OF_QUESTIONS || function_number < 0)
        {
            std::cout << "Invalid Entry! Please enter a number 0-16" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> function_number;
        }
        if (function_number == 0) {
            break;
        }
        
        functionpick(function_number);
    }
}

