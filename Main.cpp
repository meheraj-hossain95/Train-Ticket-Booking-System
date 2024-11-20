#include<bits/stdc++.h>
#include <windows.h>
#include<fstream>

using namespace std;

const int INF = 999999999;

void load_invalid();
void line();
void load_home();
void load_register();
void load_registered_successfully();

void load_login();
void ticket_booking_from();
void ticket_booking_to();
void load_contact_us();

void date_train();
void print_page();

int division();
int djikstra ();
bool KMP(string S, int x);


vector < pair < int, int > > g[400];
set < pair < int, int > > S;
map<pair<int,int >,int> mp;
int d[400], p[400];

map<pair<int,int>,int> get_vertex;
map<int,pair<string,string>> vertex_data;

int starting,ending,seat_class;

string date,number,name,nid_pass;

void data() {

    get_vertex[{1,1}] = 13;     vertex_data[13] = {"Dhaka" , "Tangail"};
    get_vertex[{1,2}] = 14;     vertex_data[14] = {"Dhaka" , "Narsingdi"};
    get_vertex[{1,3}] = 16;     vertex_data[16] = {"Dhaka" , "Dhaka"};

    //Chattogram 2
    get_vertex[{2,1}] = 15;     vertex_data[15] = {"Chattogram" , "Brahmanbaria"};
    get_vertex[{2,2}] = 17;     vertex_data[17] = {"Chattogram" , "Cumilla"};
    get_vertex[{2,3}] = 18;     vertex_data[18] = {"Chattogram" , "Feni"};
    get_vertex[{2,4}] = 19;     vertex_data[19] = {"Chattogram" , "Noakhali"};
    get_vertex[{2,5}] = 20;     vertex_data[20] = {"Chattogram" , "Chattogram"};
    get_vertex[{2,6}] = 21;     vertex_data[21] = {"Chattogram" , "Hathazari"};
    get_vertex[{2,7}] = 22;     vertex_data[22] = {"Chattogram" , "Cox’s Bazar"};

    //Rajshahi 3
    get_vertex[{3,1}] =  4;     vertex_data[4]  = {"Rajshahi" , "Bogura"};
    get_vertex[{3,2}] =  5;     vertex_data[5]  = {"Rajshahi" , "Sirajgang"};
    get_vertex[{3,3}] = 29;     vertex_data[29] = {"Rajshahi" , "Pabna"};
    get_vertex[{3,4}] = 30;     vertex_data[30] = {"Rajshahi" , "Rajshahi"};

    //Mymensingh 4
     get_vertex[{4,1}] =  6;     vertex_data[6] = {"Mymensingh" , "Jamalpur"};
     get_vertex[{4,2}] =  7;     vertex_data[7] = {"Mymensingh" , "Mymensingh"};
     get_vertex[{4,3}] =  8;     vertex_data[8] = {"Mymensingh" , "Netrokona"};

    //Barisal 5
    get_vertex[{5,1}] =  23;     vertex_data[23] = {"Barisal" , "Barisal"};
    get_vertex[{5,2}] =  24;     vertex_data[24] = {"Barisal" , "Kuakata"};

    //Khulna 6
    get_vertex[{6,1}] = 26;     vertex_data[26] = {"Khulna" , "Khulna"};
    get_vertex[{6,2}] = 25;     vertex_data[25] = {"Khulna" , "Narail"};
    get_vertex[{6,3}] = 27;     vertex_data[27] = {"Khulna" , "Bagerhat"};
    get_vertex[{6,4}] = 28;     vertex_data[28] = {"Khulna" , "Chuadanga"};

    //Rangpur 7
    get_vertex[{7,1}] =  1;     vertex_data[1]  = {"Rangpur" , "Panchagarh"};
    get_vertex[{7,2}] =  2;     vertex_data[2]  = {"Rangpur" , "Dinajpur"};
    get_vertex[{7,3}] =  3;     vertex_data[3]  = {"Rangpur" , "Rangpur"};

    //Sylhet 8
    get_vertex[{8,1}] =  9;     vertex_data[9]  = {"Sylhet" , "Sunamganj"};
    get_vertex[{8,2}] = 10;     vertex_data[10] = {"Sylhet" , "Sylhet"};
    get_vertex[{8,3}] = 11;     vertex_data[11] = {"Sylhet" , "Srimangal"};
    get_vertex[{8,4}] = 12;     vertex_data[12] = {"Sylhet" , "Habiganj"};

}


void load_invalid() {
    system("Color 0C");

    cout << "\n\n\n\t\t\t\t<<-------------------------------------------------------->>\n\n";
    cout << "\t\t\t\t\t\t **   Something Went Wrong **\t\t\n\n";
    cout << "\t\t\t\t<<-------------------------------------------------------->>\n\n";

    cout << "\n\n\n\n\t\t\t\t\t\t>> Press Enter to Try Again << \n\n\n\n\n\n";
    cin.get();
    if(cin.get() == '\n'){
        system("cls");
        load_home();
    }else{
        system("cls");
        load_invalid();
    }
}


void line(){
    cout <<"  -------------------------------------";
    cout <<"---------------------------------------";
    cout <<"---------------------------------------\n";
}


void load_home() {
    system("Color 70");
    cout << "\n\n\n\n\t\t\t\t\t     R a i l w a y   T i c k e t s\t\t\t\t\n\n";
    line();
    cout << "\n\n\n";
    cout << "\t\t\t 1.  Register\n\n";
    cout << "\t\t\t 2.  Login\n\n";
    cout << "\t\t\t 3.  Contact Us\n\n";
    cout << "\t\t\t 4.  Exit\n\n";

    cout << "\n\t\t\tEnter : ";
    int x;  cin >> x;

    if(x == 1){
        system("cls");
        load_register();
    }else if(x == 2) {
        system("cls");
        load_login();
    }else if(x == 3) {
        system("cls");
        load_contact_us();
    }else if(x == 4) {
        system("cls");
        return ;
    }
    else {
        system("cls");
        load_invalid();
    }
}


void load_contact_us() {
    system("Color 0F");
    cout << "\n\n\n\t\t\tContact us for refund of unsuccessful purchases and card charging issues\n\n";

    line();
    cout <<"\t\t\t >>  bKash \t\t\t16247\n\n";
    cout <<"\t\t\t >>  Nagad \t\t\t16167\n\n";
    cout <<"\t\t\t >>  Rocket/DBBL Nexus \t\t16216\n\n";
    cout <<"\t\t\t >>  Upay \t\t\t16268\n\n";
    cout <<"\t\t\t >>  Visa/ Mastercard \t\tN/A\n\n";

    cout << "\n\n\n\t\t\t***********************************";
    cout << "***********************************\n\n";
    cout << "\n \t\t\t\t\t  >> Press Enter To Goto HomePage  << \n\n\n";

    cin.get();
    if(cin.get() == '\n')system("cls");
    load_home();
}


bool KMP(string s,int x){

    bool flag = false;

    int n=s.size();
    vector<int>pi(n);

    for(int i=1,j=0;i<n;i++) {
        if(s[i]==s[j]){pi[i]=++j;}
        else if(j==0){pi[i]=0;}
        else{j=pi[j-1];i--;}
    }

    for(auto e:pi){
        if(e == x) flag = true;
    }
    return flag;

}


void load_registered_successfully() {
    system("Color 0A");
    cout << "\n\n\n\n\t\t\t\t<<-------------------------------------------------------->>\n\n";
    cout << "\t\t\t\t\t\t**  Successfully Registered **\t\t\n\n";
    cout << "\t\t\t\t<<-------------------------------------------------------->>\n\n";

    cout << "\n\n\n \t\t\t\t\t  >> Press Enter To Goto HomePage  << \n\n\n";

    cin.get();
    if(cin.get() == '\n')system("cls");
    else load_invalid();

    load_home();
}


void load_register() {
    system("Color 70");

    string nam = "" , nid, num, pass;

    cout << "\n\n\n\t\t\t\t\t    >> Please Verify Your Number  << \n\n";
    line();
    cout << "\n\n\n";
    cout << "\n\t\t\tEnter Your Name : ";
    char c;
    cin >> c;
    nam += c;
    while (cin.get(c) and c != '\n') {
        nam += c;
    }
    cout << "\n\t\t\tEnter NID Number : ";  cin >> nid; cin.get();
    cout << "\n\t\t\tEnter Mobile Number : ";  cin >> num; cin.get();
    cout << "\n\t\t\tEnter a Password : ";   cin >> pass; cin.get();

    // Checking the uniqueness..

    ifstream file_1("passenger_data.txt");

    bool flag = true;

    string getting = "//number=" + num + "//";

    if(file_1.is_open()) {

        string data;

        while(getline(file_1, data)){

            string searching = getting + '#' + data;
            if(KMP(searching,getting.size())) {
              flag = false;
            }
    }
        file_1.close();
    }

    cout << "\n\n\t\t\tChecking ";
        for(int i = 0; i <= 2000; i+=80){
            Sleep(100);
            cout << ". ";
        }cout <<"\n\n\n";

    if(flag) {
        ofstream file;
        file.open("passenger_data.txt", ios_base::app);

        if(file.is_open()) {
            string register_it = "//passenger_registration_data//nid=" + nid + "//name=" + nam + "//number=" + num + "//password=" + pass + "//\n";
            file << register_it;
            file.close();
            }
            system("cls");
            load_registered_successfully();
        }else {
            system("cls");
            load_invalid();
        }

    return;
}


void load_login() {

        system("Color 70");

        cout << "\n\n\n\t\t\t\t   > > > Login With Your Number And Password < < < \n\n";
        line();
        string num, pass;
        cout << "\n\n\n\t\t\t\t Enter Mobile Number : ";  cin >> num;
        cout << "\n\n\t\t\t\t Enter a Password : ";   cin >> pass;

        ifstream file_1("passenger_data.txt");

        string getting =  "//number=" + num + "//password=" + pass + "//";

        bool flag = false;
        string data;

        if(file_1.is_open()) {
            while(getline(file_1, data)){
                string searching = getting + '#' + data;
                if(KMP(searching,getting.size())) {
                    flag = true;
                    break;
            }
        }
        file_1.close();
    }

        cout << "\n\n\t\t\tChecking ";
        for(int i = 0; i <= 2000; i+=80){
            Sleep(100);
            cout << ". ";
        }cout <<"\n\n\n";

        cout << "\n\n";
        line();
        cout << "\n\n";

        if(flag){
            int k = 1;
            for(int i = 0; i < data.size(); i++) {
                if(data[i] == '=') {
                    i++;
                    string s = "";
                    while(data[i]!='/') {
                        s += data[i];
                        i++;
                    }
                    if(k == 1) nid_pass = s;
                    else if(k == 2) name = s;
                    else if(k == 3) number = s;
                    else break;
                    k++;
                }
            }
            system("Color 0A");
            cout << "\t\t\t\t\t\t   Login successful\n";
            cout << "\n\n \t\t\t\t\t  >> Press Enter To Ticket Booking << \n\n\n";
            cin.get();
            if(cin.get() == '\n')system("cls");
            ticket_booking_from();
        }
        else{
            system("Color 0C");
            cout << "\t\t\t\t\t\t  Wrong Information !!\n";
            cout << "\n\n\n \t\t\t\t\t  >> Press Enter To Goto HomePage  << \n\n\n";
            cin.get();
            if(cin.get() == '\n')system("cls");
            load_home();
        }
}


int division() {

    cout << "\t\t\tSelect Division : \n";
    cout << "\t\t\t-----------------------------------------------------\n";
    cout << "\t\t\t1. Dhaka \t\t 5. Barisal\n";
    cout << "\t\t\t2. Chattogram \t\t 6. Khulna\n";
    cout << "\t\t\t3. Rajshahi \t\t 7. Rangpur\n";
    cout << "\t\t\t4. Mymensingh \t\t 8. Sylhet\n";

    cout << "\n\t\t\tEnter Division: ";

    int x = 0;
    cin >> x;

    if(x) {
        cout << "\n\n\t\t\tSelect City : \n";
        cout << "\t\t\t-----------------------------------------------------\n";
        if(x == 1) {
            cout << "\t\t\t1. Tangail\n";
            cout << "\t\t\t2. Narsingdi\n";
            cout << "\t\t\t3. Dhaka\n";
        }else if(x == 2) {
            cout << "\t\t\t1. Brahmanbaria\n";
            cout << "\t\t\t2. Cumilla\n";
            cout << "\t\t\t3. Feni\n";
            cout << "\t\t\t4. Noakhali\n";
            cout << "\t\t\t5. Chattogram\n";
            cout << "\t\t\t6. Hathazari\n";
            cout << "\t\t\t7. Cox's Bazar\n";
        }else if(x == 3){
            cout << "\t\t\t1. Bogura\n";
            cout << "\t\t\t2. Sirajgang\n";
            cout << "\t\t\t3. Pabna\n";
            cout << "\t\t\t4. Rajshahi\n";
        }else if(x == 4){
            cout << "\t\t\t1. Jamalpur\n";
            cout << "\t\t\t2. Mymensingh\n";
            cout << "\t\t\t3. Netrokona\n";
        }else if(x == 5){
            cout << "\t\t\t1. Barisal\n";
            cout << "\t\t\t2. Kuakat\n";
        }else if(x == 6){
            cout << "\t\t\t1. Khulna\n";
            cout << "\t\t\t2. Narail\n";
            cout << "\t\t\t3. Bagerhat\n";
            cout << "\t\t\t4. Chuadangayz\n";
        }else if(x == 7){
            cout << "\t\t\t1. Panchagarh\n";
            cout << "\t\t\t2. Dinajpur\n";
            cout << "\t\t\t3. Rangpur\n";
        }else if(x == 8){
            cout << "\t\t\t1. Sunamganj\n";
            cout << "\t\t\t2. Sylhet\n";
            cout << "\t\t\t3. Srimangal\n";
            cout << "\t\t\t4. Habiganj\n";
        }else{
            load_invalid();
        }
    }
    cout << "\n\t\t\tEnter city: ";
    int y; cin >>y;

    return get_vertex[{x,y}];
}


void ticket_booking_from() {
    system("Color 70");
    cout << "\n\n";
    line();
    cout << "\t\t\t\t\t\t**  F R O M  **\n";
    line();
    cout << "\n";

    starting = division();
    system("cls");
    ticket_booking_to();
}


void ticket_booking_to() {
    system("Color 70");
    cout << "\n\n";
    line();
    cout << "\t\t\t\t\t\t\t**  T O **\n";
    line();
    cout << "\n";
    ending = division();
    cout << ending;
    system("cls");
    date_train();
}


int djikstra () {

    ifstream file_1("track.txt");
    string data;
    if(file_1.is_open()) {

        while(getline(file_1, data)){
            string s = "";
            vector<int>v;
            for(int i = 0; i < data.size(); i++) {
                if(data[i] != ' ') {
                    s+=data[i];
                }else{
                    v.push_back(stoi(s));
                    s="";
                }
            }
            v.push_back(stoi(s));
            //cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
            g[v[0]].push_back(make_pair(v[1], v[2]));
            g[v[1]].push_back(make_pair(v[0], v[2]));
            mp[{v[0], v[1]}] = v[2];
            mp[{v[1], v[0]}] = v[2];
        }
        file_1.close();
    }

     for (int i = 1; i <= 60; i ++){
        d[i] = INF;
    }

    int x = starting;
    int v = ending;
    d[x] = 0;
    S.insert(make_pair(d[x], x));
    while (!S.empty()){
        int v = S.begin()->second;
        S.erase(S.begin());

        for (int i = 0; i < g[v].size(); i ++){
            long long u = g[v][i].first;
            long long int l = g[v][i].second;
            if (d[u] > d[v] + l){
                S.erase(make_pair(d[u], u));
                d[u] = d[v] + l;
                p[u] = v;
                S.insert(make_pair(d[u], u));
            }
        }
    }

    vector<int>ans;
    int weight = 0;
    while (v != x){
        weight += mp[{v,p[v]}];
        v = p[v];
    }
    return weight;
}

void print_page() {
    cout << "\t\n\n\t\t\t\t\t\t   E - T i c k e t \n";
    cout <<'\n';
    line();
    cout << "\n\n";
    cout << "\t\t\t\tName  : " << name << '\n';
    cout << "\t\t\t\tNID  : " << nid_pass << '\n';
    cout << "\t\t\t\tNumber  : " << number << '\n';
    cout << "\n\t\t\t\tFrom\n";
    cout << "\t\t\t\tDivision : " << vertex_data[starting].first << '\n';
    cout << "\t\t\t\tCity     : " << vertex_data[starting].second << '\n';
    cout << "\n\t\t\t\tTo\n";
    cout << "\t\t\t\tDivision  : " << vertex_data[ending].first << '\n';
    cout << "\t\t\t\tCity      : " << vertex_data[ending].second << '\n';
    cout << "\n\t\t\t\tDate  : " << date << '\n';
    cout << "\t\t\t\tSeat Class  : ";
    if(seat_class == 1) cout << "S_CHAIR\n";
    else if(seat_class == 2) cout << "SNIGDHA\n";
    else if(seat_class == 3) cout << "AC_S\n";
    else if(seat_class == 4) cout << "AC_B\n";
    cout << "\t\t\t\tFare  : ";
    double money = djikstra();

    if(seat_class == 1) money *= (double)1.5;
    else if(seat_class == 2) money *= (double)2.5;
    else if(seat_class == 3) money *= (double)2.8;
    else if(seat_class == 4) money *= (double)4.2;
    cout << int(money) << " Taka"<< '\n';
    cout << '\n';
    line();
    cout << '\n';
    cout << "\t\t\t\t------------------------|| Book Now ||------------------------\n";
    cin.get();
    if(cin.get() == '\n'){return;}

}


void date_train() {
    system("Color 70");
    cout << "\n\n";
    line();
    cout << "\t\t\t\t\t\t||  Train Ticket ||\n";
    line();
    cout << "\n\n";
    cout << "\t\t\t\tFrom\n";
    cout << "\t\t\t\tDivision : " << vertex_data[starting].first << '\n';
    cout << "\t\t\t\tCity     : " << vertex_data[starting].second << '\n';
    cout << "\n\t\t\t\tTo\n";
    cout << "\t\t\t\tDivision  : " << vertex_data[ending].first << '\n';
    cout << "\t\t\t\tCity      : " << vertex_data[ending].second << '\n';
    cout << "\n\t\t\t\tDate      : " ; cin >> date;
    cout << "\n\t\t\t\tChoose a Class :\n";
    cout << "\t\t\t\t 1. S_CHAIR              3. AC_S\n";
    cout << "  \t\t\t\t 2. SNIGDHA              4. AC_B\n";
    cout << "\n\t\t\t\tEnter Class : ";
    cin >> seat_class;

    line();

    cout << "\n\t\t\t\t\t Processing ";
        for(int i = 0; i <= 2000; i+=500){
            Sleep(500);
            cout << ". ";
    }cout <<"\n\n\n";

     system("Color 0A");
     system("cls");
     print_page();
}


int main( ){
    data();
    load_home();
    return 0;
}

