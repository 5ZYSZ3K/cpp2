#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    bool flag = true;
    ifstream read_file_dealer("dealer.txt", std::ofstream::out);
    //wczytywanie danych z pliku i zapisywanie do obiektu vector
    if(read_file_dealer.is_open()){
        char row[20];
        while(read_file_dealer.getline(row, 20)){
            stringstream ss;
            ss << row;
            string s = ss.str();
        }
    }
    ifstream read_file_client1("client1.txt", std::ofstream::out);
    //wczytywanie danych z pliku i zapisywanie do obiektu vector
    if(read_file_client1.is_open()){
        char row[20];
        while(read_file_client1.getline(row, 20)){
            stringstream ss;
            ss << row;
            string s = ss.str();
        }
    }
    ifstream read_file_client2("client2.txt", std::ofstream::out);
    //wczytywanie danych z pliku i zapisywanie do obiektu vector
    if(read_file_client2.is_open()){
        char row[20];
        while(read_file_client2.getline(row, 20)){
            stringstream ss;
            ss << row;
            string s = ss.str();
        }
    }
    ifstream read_file_factory("factory.txt", std::ofstream::out);
    //wczytywanie danych z pliku i zapisywanie do obiektu vector
    if(read_file_factory.is_open()){
        char row[20];
        while(read_file_factory.getline(row, 20)){
            stringstream ss;
            ss << row;
            string s = ss.str();
        }
    }
    //pętla wykonująca się dopóki użytkownik chce
    while(flag){
        string a;
        //wybór opcji w menu
        cout << "What would you like to manage?\n1.Client\n2.Dealer\n3.Factory:";
        cin >> a;
        if(a == "1"){
            //wypisywanie wszystkich klientów i wybór jednego
            //cout << "1." << client[0] << "2." << client[1] << endl;
            string sclient;
            int iclient;
            cout << "Type the number of a client:";
            cin >> sclient;
            iclient = stoi(sclient)-1;
            //sprawdzanie poprawności numeru oraz wyświetlanie opcji
            if(iclient == 1 || iclient == 0){
                string option;
                cout << "Pick an option" <<"1." << "Buy new car" << "2." << "Buy used car" << "3." << "Sell a car" << "4." << "Do something with your car" <<endl;
                cin >> option;
                if(option == "1"){
                    //listuje samochody z fabryki, pyta który no i procedura
                }
                else if(option == "2"){
                    //listuje samochody z komisu, pyta który no i procedura
                }
                else if(option == "3"){
                    //listuje własne samochody, pyta który no i procedura
                }
                else if(option == "4"){
                    //listuje własne samochody, pyta który no i procedura
                }
                else {
                    cout << "Wrong number!" << endl;
                }
            }
            else cout << "Wrong number!" << endl;
        }
        //zarządzanie komisem
        else if(a == "2"){
            string option;
            cout << "Pick an option" <<"1." << "Buy a car" << "2." << "Sell a car" <<endl;
            cin >> option;
            if(option == "1"){
                //wypisywanie wszystkich klientów i wybór jednego
                //cout << "1." << client[0] << "2." << client[1] << endl;
                string sclient;
                int iclient;
                cout << "Type the number of a client:";
                cin >> sclient;
                iclient = stoi(sclient)-1;
                //sprawdzanie poprawności numeru oraz wyświetlanie opcji
                if(iclient == 1 || iclient == 0){
                    //listuje samochody konkretnego klienta, puta który no i procedura
                }
                else cout << "Wrong number!" << endl;
            }
            else if(option == "2"){
                //listuje samochody z komisu, pyta który no i procedura
            }
            else {
                cout << "Wrong number!" << endl;
            }
        }
        else if(a == "3"){
            /*cout << "Type car name: " << endl;
            cin >> brand;
            if(brand == "BMW" || brand == "Lamborghini" || brand == "Mercedes"){
                array.push_back(new Client(get_type(brand)));
                cout << "Produced!\n" << endl;
            }
            else cout << "We don't produce such cars! \n";*/
        }
        else cout <<"Wrong number!" << endl;
        string exit;
        //funkcja pozwalająca wyjść z nieskończonej pętli
        cout << "Do you want to keep on?\n1.Yes\n2.No\nPick a number:";
        cin >> exit;
        if(exit == "2"){
            string option;
            cout << "Do you want to save your changes?\n1.Yes\n2.No\n";
            cin >> option;
            //zapisywanie danych do pliku, jeśli użytkownik chce
            if(option == "1"){
                /*ofstream save_file("baza.txt");
                for(Client * i : array)
                    save_file << *i->getVehicle() << "\n";
                save_file.close();
                cout << "Data saved!\n";*/
            }
            else cout << "Ok, discarding all changes";
            flag = false;
        }
    }
    cout << "Goodbye!";
    return 0;
}
