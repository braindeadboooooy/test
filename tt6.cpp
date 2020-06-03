#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#define MAX_MENU_NUMBER 8
using namespace std;
class ciz_information
{
private:
    string ciz_name;
    unsigned int data;

public:
    string &Getciz_name()
    {
        return ciz_name;
    }
    unsigned int &Getciz_data()
    {
        return data;
    }
    ciz_information(string c, unsigned int d);
    ciz_information();
    friend ostream &operator<<(ostream &out, const ciz_information &obj);
    friend istream &operator>>(istream &in, ciz_information &obj);
};
ciz_information::ciz_information()
{
    ciz_name = "";
    data = 0;
}
ciz_information::ciz_information(string c, unsigned int d)
{
    ciz_name = c;
    data = d;
}
class sotrudnik_information
{
private:
    string name;
    string surname;
    string middle_name;

public:
    string &Getsotrudnik_name()
    {
        return name;
    }
    string &Getsotrudnik_surname()
    {
        return surname;
    }
    string &Getsotrudnik_middlename()
    {
        return middle_name;
    }
    sotrudnik_information();
    sotrudnik_information(string n, string s, string m);
    friend ostream &operator<<(ostream &out, const sotrudnik_information &obj);
    friend istream &operator>>(istream &in, sotrudnik_information &obj);
};
sotrudnik_information::sotrudnik_information()
{
    name = "";
    surname = "";
    middle_name = "";
}
sotrudnik_information::sotrudnik_information(string n, string s, string m)
{
    name = n;
    surname = s;
    middle_name = m;
}
ostream &operator<<(ostream &out, const sotrudnik_information &obj)
{
    out << "name: " << obj.name << endl;
    out << "surname: " << obj.surname << endl;
    out << "middle name: " << obj.middle_name << endl;
    out << "------------------------------------------------------------" << endl;
    return out;
}
istream &operator>>(istream &in, sotrudnik_information &obj)
{
    in >> obj.name;
    in >> obj.surname;
    in >> obj.middle_name;
    return in;
}
class shop_information
{
private:
    int shop_count;
    int sotrudnik_count;
    int mas_size;
    int ciz_size;
    int sotrudnik_size;
    sotrudnik_information *mas_sotrudnik;
    ciz_information *mas_ciz;
    string shop_name;

public:
    int Getshop_count()
    {
        return shop_count;
    }
    void setshop_count(int tmp_shop_count)
    {
        shop_count = tmp_shop_count;
    }
    int Getsotrudnik_count()
    {
        return sotrudnik_count;
    }
    void setsotrudnik_count(int tmp_sotrudnik_count)
    {
        sotrudnik_count = tmp_sotrudnik_count;
    }
    int Getmas_size()
    {
        return mas_size;
    }
    void setmas_size(int tmp_mas_size)
    {
        mas_size = tmp_mas_size;
    }
    string &Getshop_name()
    {
        return shop_name;
    }
    void setshop_name(string tmp_shop_name)
    {
        shop_name = tmp_shop_name;
    }
    int Getciz_size()
    {
        return ciz_size;
    }
    void setciz_size(int tmp_ciz_size)
    {
        ciz_size = tmp_ciz_size;
    }
    int Getsotrudnik_size()
    {
        return sotrudnik_size;
    }
    void setsotrudnik_size(int tmp_sotrudnik_size)
    {
        sotrudnik_size = tmp_sotrudnik_size;
    }
    sotrudnik_information **Getmas_sotrudnik()
    {
        return &mas_sotrudnik;
    }
    ciz_information **Getmas_ciz()
    {
        return &mas_ciz;
    }
    shop_information(string sn);
    shop_information();
    friend ostream &operator<<(ostream &out, const shop_information &obj);
    friend istream &operator>>(istream &in, shop_information &obj);
};
shop_information::shop_information()
{

    sotrudnik_count = 0;
    mas_size = 0;
    ciz_size = 0;
    sotrudnik_size = 0;
    shop_name = "";
}
shop_information::shop_information(string sn)
{
    shop_name = sn;
}
ostream &operator<<(ostream &out, const shop_information &obj)
{

    out << "shop name: " << obj.shop_name << endl;
    out << "------------------------------------------------------------" << endl;
    return out;
}
istream &operator>>(istream &in, shop_information &obj)
{
    in >> obj.shop_name;
    return in;
}
class help
{
public:
    void helpon(int choice);
    void showmenu();
    bool isvalid(int ch);
};
void help::showmenu()
{
    cout << "Информация о предприятии" << endl;
    cout << "1. Добавить сотрудника" << endl;
    cout << "2. Информация о сотрудниках" << endl;
    cout << "3. Добавить СИЗ" << endl;
    cout << "4. Информация о СИЗ" << endl;
    cout << "5. Добавить цех" << endl;
    cout << "6. Информация о цехах" << endl;
    cout << "7. Удалить сотрудника" << endl;
    cout << "8. Выход" << endl;
    cout << ">";
}
bool help::isvalid(int ch)
{
    if ((ch < 1) || (ch > MAX_MENU_NUMBER))
    {
        cout << "Неверное значение" << endl;
        cout << "Введите еще раз" << endl;
        return false;
    }
    else
        return true;
}
int main(int argc, char *argv[])
{
    string shopname_adding;
    string name_adding;
    string surname_adding;
    string middlename_adding;
    
    string surname_search;
    string name_search;
    string middlename_search;
    
    int i=0;
    int j=0;
    int k=0;
    int size_ciz;
    int size_sotrudnik;
    int count_sotr;
    int count_shop;
    shop_information *mas_shop;
    string file_name;
    ifstream rf;
    int choice;
    string poisk_shop_name;
    string answer;
    help hlpob;
    if (argc >= 2)
    {
        file_name = string(argv[1]);
        rf.open(argv[1], ios::binary | ios::in);
    }
    else
    {
        cout << "Введите имя файла\n";
        cin >> file_name;
        rf.open(file_name, ios::binary | ios::in);
    }
    if (!rf)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    int size_shop = 1;
    rf.read((char *)&size_shop, sizeof(size_shop));
    if (!rf.gcount())
    {
        size_shop = 1;
    }
    mas_shop = new shop_information[size_shop];
    while (!rf.eof())
    {
        if (rf.gcount())
        {
            for (int i = 0; i < size_shop; i++)
            {
                size_t size1;
                rf.read((char *)&size1, sizeof(size1));
                mas_shop[i].Getshop_name().resize(size1);
                rf.read((char *)(mas_shop[i].Getshop_name().c_str()), size1);
                sotrudnik_information **mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
                ciz_information **mas_ciz = mas_shop[i].Getmas_ciz();
                rf.read((char *)&size_sotrudnik, sizeof(size_sotrudnik));
                mas_shop[i].setmas_size(size_sotrudnik);
                rf.read((char *)&size_ciz, sizeof(size_ciz));
                mas_shop[i].setciz_size(size_ciz);
                mas_shop[i].setsotrudnik_size(size_sotrudnik);
                *mas_sotrudnik = new sotrudnik_information[size_sotrudnik];
                *mas_ciz = new ciz_information[size_ciz];
                for (int j = 0; j < size_sotrudnik; j++)
                {
                    size_t size2;
                    rf.read((char *)&size2, sizeof(size2));
                    (*mas_sotrudnik)[j].Getsotrudnik_name().resize(size2);
                    rf.read((char *)((*mas_sotrudnik)[j].Getsotrudnik_name().c_str()), size2);
                    size_t size3;
                    rf.read((char *)&size3, sizeof(size3));
                    (*mas_sotrudnik)[j].Getsotrudnik_surname().resize(size3);
                    rf.read((char *)((*mas_sotrudnik)[j].Getsotrudnik_surname().c_str()), size3);
                    size_t size4;
                    rf.read((char *)&size4, sizeof(size4));
                    (*mas_sotrudnik)[j].Getsotrudnik_middlename().resize(size4);
                    rf.read((char *)((*mas_sotrudnik)[j].Getsotrudnik_middlename().c_str()), size4);
                    for (int k = 0; k < size_ciz; k++)
                    {
                        rf.read((char *)&(*mas_ciz)[k].Getciz_data(), sizeof(unsigned int));
                        size_t size5;
                        rf.read((char *)&size5, sizeof(size5));
                        (*mas_ciz)[k].Getciz_name().resize(size5);
                        rf.read((char *)((*mas_ciz)[k].Getciz_name().c_str()), size5);
                    }
                }
            }
        }
    }
    mas_shop[i].setsotrudnik_count(j);
    count_sotr = mas_shop[i].Getsotrudnik_count();
    mas_shop[i].setshop_count(i);
    count_shop = mas_shop[i].Getshop_count();
    rf.close();
    for (;;)
    {
        hlpob.showmenu();
        do
        {
            cin >> choice;
        } while (!hlpob.isvalid(choice));
        if (choice == MAX_MENU_NUMBER)
            break;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            int flag_name = 0;
            cout << "Введите имя цеха" << endl;
            cin >> poisk_shop_name;
            for (int i = 0; i < size_shop; i++)
            {
                if (poisk_shop_name == mas_shop[i].Getshop_name())
                {
                    cout << "Введите имя сотрудника" << endl;
                    cin >> name_adding;
                    cout << "Введите фамилию сотрудника" << endl;
                    cin >> surname_adding;
                    cout << "Введите отчество сотрудника" << endl;
                    cin >> middlename_adding;
                    sotrudnik_information a(name_adding, surname_adding, middlename_adding);
                    flag_name = 1;
                    sotrudnik_information **mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
                    if (mas_shop[i].Getmas_size() <= mas_shop[i].Getsotrudnik_count())
                    {
                        sotrudnik_information *new_mas_sotrudnik = new sotrudnik_information[2 * size_sotrudnik];
                        copy_n(*mas_sotrudnik, size_sotrudnik, new_mas_sotrudnik);
                        delete[] * mas_sotrudnik;
                        *mas_sotrudnik = new_mas_sotrudnik;
                        size_sotrudnik *= 2;
                    }
                    (*mas_sotrudnik)[count_sotr++]=a;
                }
            }
            if (flag_name == 0)
            {
                cout << "Введенного цеха не существует" << endl;
            }
        }
        break;
        case 2:
        {
            for (int i = 0; i < count_shop; ++i)
            {
                cout << "Shop #" << i + 1 << endl;
                cout << mas_shop[i] << endl;
                sotrudnik_information **mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
                for (int j = 0; j < count_sotr; j++)
                {
                    cout<<"Sotrudnik: "<<j+1<<endl;
                    cout<<(*mas_sotrudnik)[j]<<endl;
                }
            }
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        case 5:
        {
            cout << "Введите название цеха" << endl;
            cin >> shopname_adding;
            shop_information b(shopname_adding);
            mas_shop[count_shop++] = b;
            size_sotrudnik=10;
            sotrudnik_information **mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
            *mas_sotrudnik = new sotrudnik_information[size_sotrudnik];
            count_sotr=0;
        }
        break;
        case 6:
        {
            for (int i = 0; i < count_shop; ++i)
            {
                cout << "Shop #" << i + 1 << endl;
                cout << mas_shop[i] << endl;
            }
        }
        break;
        case 7:
        { 
            cout << "Введите фамилию сотрудника: " << endl;
            cin >> surname_search;
            cout << "Введите имя сотрудника: " << endl;
            cin >> name_search;
            cout << "Введите отчество сотрудника: " << endl;
            cin >> middlename_search;
            int check = 0;
            sotrudnik_information** mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
            for (int i = 0; i < count_sotr; ++i){
                if ((surname_search == (*mas_sotrudnik)[i].Getsotrudnik_surname()) && (name_search == (*mas_sotrudnik)[i].Getsotrudnik_name()) && (middlename_search == (*mas_sotrudnik)[i].Getsotrudnik_middlename())) {
                    for (int j = i; j < count_sotr - 1; ++j) {
                        (*mas_sotrudnik)[j].Getsotrudnik_surname() = (*mas_sotrudnik)[j + 1].Getsotrudnik_surname();
                        (*mas_sotrudnik)[j].Getsotrudnik_name() = (*mas_sotrudnik)[j + 1].Getsotrudnik_name();
                        (*mas_sotrudnik)[j].Getsotrudnik_middlename() = (*mas_sotrudnik)[j + 1].Getsotrudnik_middlename();
                    }
                count_sotr = count_sotr - 1;
                check = check + 1;
                }
            }
            if (check == 0) {
                cout << "Сотрудник не найден!" << endl;
            } 
        }
        break;
        }
    }
    ofstream wf;
    wf.open(file_name, ios::binary | ios::out);
    wf.write((char *)&size_shop, sizeof(size_shop));
    wf.write((char *)&size_sotrudnik, sizeof(size_sotrudnik));
    wf.write((char *)&size_ciz, sizeof(size_ciz));
    for (int i = 0; i < size_shop; i++)
    {
        size_t size1;
        wf.write((char *)&size1, sizeof(size1));
        mas_shop[i].Getshop_name().resize(size1);
        wf.write((char *)(mas_shop[i].Getshop_name().c_str()), size1);
        wf.write((char *)&size_sotrudnik, sizeof(size_sotrudnik));
        wf.write((char *)&size_ciz, sizeof(size_ciz));
        sotrudnik_information **mas_sotrudnik = mas_shop[i].Getmas_sotrudnik();
        ciz_information **mas_ciz = mas_shop[i].Getmas_ciz();
        for (int j = 0; j < size_sotrudnik; j++)
        {
            size_t size2;
            wf.write((char *)&size2, sizeof(size2));
            (*mas_sotrudnik)[j].Getsotrudnik_name().resize(size2);
            wf.write((char *)((*mas_sotrudnik)[j].Getsotrudnik_name().c_str()), size2);
            size_t size3;
            wf.write((char *)&size3, sizeof(size3));
            (*mas_sotrudnik)[j].Getsotrudnik_surname().resize(size3);
            wf.write((char *)((*mas_sotrudnik)[j].Getsotrudnik_surname().c_str()), size3);
            size_t size4;
            wf.write((char *)&size4, sizeof(size4));
            (*mas_sotrudnik)[j].Getsotrudnik_middlename().resize(size4);
            wf.write((char *)((*mas_sotrudnik)[j].Getsotrudnik_middlename().c_str()), size4);
            for (int k = 0; k < size_ciz; k++)
            {
                wf.write((char *)&(*mas_ciz)[k].Getciz_data(), sizeof(unsigned int));
                size_t size5;
                wf.write((char *)&size5, sizeof(size5));
                (*mas_ciz)[k].Getciz_name().resize(size5);
                wf.write((char *)((*mas_ciz)[k].Getciz_name().c_str()), size5);
            }
        }
    }
    wf.close();
    return 0;
}
