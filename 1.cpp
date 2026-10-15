#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#define max 1000
#include <iomanip>

//菜单界面
void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}
//通讯录结构体
struct person
{
    //姓名
    string name;
    //年龄
    int age;
    //性别 1男 2女
    int gender;
    //电话
    string phone;
    //住址
    string adress;

};
struct personbook
{
    struct person PerArray[max];
    int size;
};
//通讯录结构体
//1.添加通讯录成员
void addperson(personbook *addrBook){
    //判断通讯录是不是满了
    if(addrBook->size==max){
        cout<<"通讯录已经满了"<<endl;
        return ;
    }
    else{
        //添加具体联系人

        //姓名
        string name;
        cout<<"请输入姓名:";
        cin>>name;
        addrBook->PerArray[addrBook->size].name=name;

        //年龄
        int age;
        cout<<"请输入年龄:";
        cin>>age;
        addrBook->PerArray[addrBook->size].age=age;
        //性别 1男 2女
        int gender;
        
       
        while(true){
            cout<<"1---男"<<endl;
            cout<<"2---女"<<endl;
            cout<<"请输入性别:";
             cin>>gender; 
             //如果输入1或者2，则退出。否则继续
            if(gender==1||gender==2){
            addrBook->PerArray[addrBook->size].gender=gender;  
            break;
            }   
            else{
                cout<<"输入错误"<<endl;
                cout<<"请重新输入:";
            }
        }
        //电话
        string phone;
        cout<<"请输入电话号码:";
        cin>>phone;
        addrBook->PerArray[addrBook->size].phone=phone;
        //住址
        string adress;
        cout<<"请输入住址:";
        cin>>adress;
        addrBook->PerArray[addrBook->size].adress=adress;
        //更新通讯录人数
        addrBook->size++;

        cout<<"添加成功"<<endl;
        cout << "按回车键继续..." << endl;
         cin.ignore();
        cin.get();
        system("clear"); //Mac清屏
       
    }

}
//2.显示联系人
void showperson(personbook *addrBook){
    //判断通讯录中人数是否为0
    if(addrBook->size==0){
        cout<<"当前通讯录中人数为0"<<endl;
    }
    else{
        cout<<"当前通讯录人数为："<<addrBook->size<<endl;
        cout << left; //设置左对齐
        for(int i=0;i<addrBook->size;i++){
        cout
        <<"姓名 "<<setw(8)<<addrBook->PerArray[i].name
        <<"年龄 "<<setw(4)<<addrBook->PerArray[i].age
        <<"性别 "<<setw(4)<<(addrBook->PerArray[i].gender==1? "男" : "女")
        <<"电话 "<<setw(13)<<addrBook->PerArray[i].phone
        <<"地址 "<<addrBook->PerArray[i].adress
        <<endl;
        }

    }
    cout << "按回车键继续..." << endl;
         cin.ignore();
        cin.get();
        system("clear"); //Mac清屏

}
//检测联系人是否存在，如果存在就返回联系人所在的位置。否则返回-1。
//参数1 通讯录 参数2 对比的姓名
int isExist(personbook *addrbook,string name){//
    for(int i=0;i<addrbook->size;i++){
        if(addrbook->PerArray[i].name==name){
            return i;//找到了，返回下标编号
        }
    }
    return -1;//没有找到，返回-1
}
//3.删除联系人
void delperson(personbook *addrbook){
    cout<<"请输入你想要删除的联系人";
    string name;
    cin>>name;
    //ret==-1没有查到这个人，不等于-1，找到这个人
    int ret=isExist(addrbook,name);
    if(ret !=-1){
        //查找到这个人，可以进行删除
        for(int i=ret;i<addrbook->size;i++){
            //数据前移
            addrbook->PerArray[i]= addrbook->PerArray[i+1];
            //删除的操作就是直接用后一个数据来覆盖要删除的数据
        }
        addrbook->size--;//更新通讯录中的人员数
        cout<<"删除成功"<<endl;
    }
    else{
        cout<<"没有查到这个人"<<endl;
    }
    cout << "按回车键继续..." << endl;
         cin.ignore();
        cin.get();
        system("clear"); //Mac清屏

}
//4.查询指定的人
void findperson(personbook *addrbook){
    string name;
    cout<<"请输入你要查找的人：";
    cin>>name;
    //判断联系人是否在通讯录中
    int ret=isExist(addrbook,name);
    if(ret!=-1){
        cout << left; //设置左对齐
        cout
        <<"姓名 "<<setw(8)<<addrbook->PerArray[ret].name
        <<"年龄 "<<setw(4)<<addrbook->PerArray[ret].age
        <<"性别 "<<setw(4)<<(addrbook->PerArray[ret].gender==1? "男" : "女")
        <<"电话 "<<setw(13)<<addrbook->PerArray[ret].phone
        <<"地址 "<<addrbook->PerArray[ret].adress
        <<endl;
        
    }
    else{//未找到联系人
        cout<<"没有找到该联系人"<<endl;

    }
    cout << "按回车键继续..." << endl;
         cin.ignore();
        cin.get();
        system("clear"); //Mac清屏
}
//5.修改制定联系人信息
void modifyperson(personbook *addrbook){
    string name;
    cout<<"请输入你要修改的联系人";
    cin>>name;
    //判断是否存在
    int ret=isExist(addrbook,name);
    if(ret!=-1){
        //显示原本联系人信息
        cout<<"原本联系人信息"<<endl;
        cout << left; //设置左对齐
        cout
        <<"姓名 "<<setw(8)<<addrbook->PerArray[ret].name
        <<"年龄 "<<setw(4)<<addrbook->PerArray[ret].age
        <<"性别 "<<setw(4)<<(addrbook->PerArray[ret].gender==1? "男" : "女")
        <<"电话 "<<setw(13)<<addrbook->PerArray[ret].phone
        <<"地址 "<<addrbook->PerArray[ret].adress
        <<endl;
        //姓名
        string name;
        cout<<"请输入姓名:";
        cin>>name;
        addrbook->PerArray[ret].name=name;

        //年龄
        int age;
        cout<<"请输入年龄:";
        cin>>age;
        addrbook->PerArray[ret].age=age;
        //性别 1男 2女
        int gender;
        
       
        while(true){
            cout<<"1---男"<<endl;
            cout<<"2---女"<<endl;
            cout<<"请输入性别:";
             cin>>gender; 
             //如果输入1或者2，则退出。否则继续
            if(gender==1||gender==2){
            addrbook->PerArray[ret].gender=gender;  
            break;
            }   
            else{
                cout<<"输入错误"<<endl;
                cout<<"请重新输入:";
            }
        }
        //电话
        string phone;
        cout<<"请输入电话号码:";
        cin>>phone;
        addrbook->PerArray[ret].phone=phone;
        //住址
        string adress;
        cout<<"请输入住址:";
        cin>>adress;
        addrbook->PerArray[ret].adress=adress;
       


    }
    else{
        cout<<"没有找到该联系人"<<endl;
    }
     cout << "按回车键继续..." << endl;
         cin.ignore();
        cin.get();
        system("clear"); //Mac清屏
}
 //6.清空所有联系人
 void cleanperson(personbook *addrbook){
    addrbook->size=0;
    cout<<"通讯录已清空"<<endl;
    cout << "按回车键继续..." << endl;
         cin.ignore();
        cin.get();
        system("clear"); //Mac清屏
 }

int main(){
    //创建一个通讯录
    personbook abs;
    //初始化人员个数
    abs.size=0;
    int select=0;//用户初始选择数字
    
    while (true)
    {
        //菜单调用
        showMenu();

        cin >> select;

        switch (select)
        {
            case 1: // 1、添加联系人
                cout << "添加联系人" << endl;
                addperson(&abs);//利用地址，才可以去修改实参
                break;
            case 2: // 2、显示联系人
                cout << "显示联系人" << endl;
                showperson(&abs);
                break;
            case 3: // 3、删除联系人
               delperson(&abs);
                break;
            case 4: // 4、查找联系人
                cout << "查找联系人" << endl;
                findperson(&abs);
                break;
            case 5: // 5、修改联系人
                cout << "修改联系人" << endl;
                modifyperson(&abs);
                break;
            case 6: // 6、清空联系人
                cout << "清空联系人" << endl;
                cleanperson(&abs);
                break;
            case 0: // 0、退出通讯录
                cout << "退出通讯录，再见！" << endl;
                return 0; //直接结束程序
                break;
            default: //输入不是0~6的数字
                cout << "输入错误，请重新选择！" << endl;
                break;
        }
    }
    return 0;
}
