 #include <iostream>
#include <fstream>
using namespace std;
double o1[5], o2[5], o3[5], o4[5];          // creating array of 5 integer to store rating .
int r1[1000], r2[1000], r3[1000], r4[1000]; // creating this array  to store how many  users rate

class user
{
public:
    string name;
    string pass;

    void signup()
    {
        cout << "Enter the username: ";
        cin >> name;
        cout << "Enter the password: ";
        cin >> pass;
        cout << "Signup Successful\n";
    }

    bool login()
    {
        string inputName, inputPass;
        cout << "Enter the username: ";
        cin >> inputName;
        cout << "Enter the password: ";
        cin >> inputPass;
        if (inputName == name && inputPass == pass)
        {
            cout << "Login Successful\n";
            return true;
        }
        else
        {
            cout << "Login Failed. Incorrect username or password.\n";
            return false;
        }
    }
};

class movie
{
public:
    int a, v;
    double z;

    int rating;

    int ratemovie(int category, double *ratings, int *ratingsCount) // creating function to rate the movie
    {
        cout << "Select the movie by entering its index number to rate the movie\n";
        cin >> v;

        if (v >= 1 && v <= 5)
        {
            cout << "Rate the movie from 1-10\n";
            cin >> z;

            if (z <= 10)
            {
                cout << "Rating added successfully!\n";
                ratingsCount[v]++;
                ratings[v] += z;
            }
            else
            {
                cout << "Invalid Choice!\n";
            }
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
    int displaymovie() // creating display function to show movies.
    {
        string st;
        ifstream in;
        in.open("movies.txt"); // this you have to create by your own and you can write the movies name which have to be rate.
        while (in.eof() == 0)
        {
            getline(in, st);
            cout << st << endl;
        }
    }
    int displaymovie1()
    {
        string st1;
        ifstream in;
        in.open("movies1.txt"); // this you have to create by your own and you can write the movies name which have to be rate.
        while (in.eof() == 0)
        {
            getline(in, st1);
            cout << st1 << endl;
        }
    }
    int displaymovie2()
    {
        string st2;
        ifstream in;
        in.open("movies2.txt"); // this you have to create by your own and you can write the movies name which have to be rate.
        while (in.eof() == 0)
        {
            getline(in, st2);
            cout << st2 << endl;
        }
    }
    int displaymovie3()
    {
        string st3;
        ifstream in;
        in.open("movies3.txt"); // this you have to create by your own and you can write the movies name which have to rate.
        while (in.eof() == 0)
        {
            getline(in, st3);
            cout << st3 << endl;
        }
    }
    void displayrating(double *ratings, int *ratingsCount, const string movieNames[])
    {
        for (int i = 1; i <= 5; i++)
        {
            if (ratingsCount[i] > 0)
            {
                cout << movieNames[i] << " = " << ratings[i] / ratingsCount[i] << endl;
            }
            else
            {
                cout << movieNames[i] << " = No ratings yet.\n";
            }
        }
        cout << endl;
    }
};

int main()
{

    char zx;
    user Me;
    const string comedyMovies[6] = {"", "Barfi", "Chennai Express", "Golmaal", "Here Pheri", "PK"};
    const string actionMovies[6] = {"", "Bloody Daddy", "Extraction", "Vikram Vedha", "URI", "WAR"};
    const string romanticMovies[6] = {"", "Sanam Teri Kasam", "Dilwale Dulhania Le Jayenge", "Goliyon ki Raasleela Ram-Leela", "Dil Bechara", "Rockstar"};
    const string horrorMovies[6] = {"", "Pari", "Bhool Bhulaiya", "The Nun", "The Devil Inside", "Conjuring"};

    while (1)
    {
    start:
        printf("Enter Choice\nL.Login\nS.Signup\nE.Exit\n");
        scanf("%s", &zx);
        switch (zx)
        {
        case 'S':
            Me.signup();
            break;
        case 'L':
            if (Me.login())
            {
                cout << endl;
                cout << "------------------------------------------------------WELCOME TO MOVIE RATING SYSTEM--------------------------------------------------------" << endl;
                movie a;
                char n;
                char c;
                int m;

                while (1)
                {
                    cout << "\nEnter\nD.Display movies Categories\nR.Display rating\nE.Exit\n\n"; // here you can select the task you want to perform.
                    cin >> n;
                    switch (n) // switch case was used to select specific task

                    {
                    case 'D':
                        cout << "Enter the index number to rate movie categories at which they are being displayed\n1.Comedy\n2.Action\n3.Romantic\n4.Horror\n";
                        cin >> m;
                        switch (m) // nested switch case was used to rate  particular  movies they want to rate.

                        {
                        case 1:
                            a.displaymovie();
                            a.ratemovie(1, o1, r1);
                            break;
                        case 2:
                            a.displaymovie1();
                            a.ratemovie(2, o2, r2);
                            break;
                        case 3:
                            a.displaymovie2();
                            a.ratemovie(3, o3, r3);
                            break;
                        case 4:
                            a.displaymovie3();
                            a.ratemovie(4, o4, r4);
                            break;
                        }
                        break;
                    case 'R':
                        cout << "---------------------------------------------------Here are the movies ratings-------------------------------------------------\n";
                        cout << "COMEDY\n";
                        a.displayrating(o1, r1, comedyMovies);
                        cout << "ACTION\n";
                        a.displayrating(o2, r2, actionMovies);
                        cout << "ROMANTIC\n";
                        a.displayrating(o3, r3, romanticMovies);
                        cout << "HORROR\n";
                        a.displayrating(o4, r4, horrorMovies);

                        break;
                    case 'E':
                        cout << "Exiting the Movie Rating System. Goodbye!\n";
                        goto start;
                    default:
                        cout << "Invalid choice !" << endl;
                    }
                }
            }
            break;
        case 'E':
            return 0;
        }
    }
    return 0;
}
