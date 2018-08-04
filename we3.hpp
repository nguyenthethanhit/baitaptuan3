#include <iostream>
#include <sqlite3.h>
#include<bits/stdc++.h>


using namespace std;
class User{
	public:
		int  id;
		char *username;
		char *password;
		char *birthday;
		int flag ; //danh dau dang nhap

	public :
        User(){};
		void SignUp();
        void SignIn();
        bool isSignIn(); // kiem tra da dang nhap chua
        void SignOut();
        bool Check(User u);
        void ShowMess(int);
        void ShowMessDetail(int);
        void SendMess(int);
        void AddFriend(int);
        void ShowFriend(int);
        void BlockFriend(int);

};

class ConnectSQlite{
    public:
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        const char *szSQL;
        const char *pzTest;
        sqlite3_stmt *stmt;
        list<string> answer;
   // int countRow; //dem so hang o cau lenh select
    public :
        static int callback(void *,int,char **,char **);
        void Open();
        void RunInsertParamSQL(sqlite3 *db,char *, char *,char *);
        int RunSelectParamSQL(sqlite3 *db, char *fn, char *ln);
        int TransNameToId(char *frien);
        void SelectMessenger(sqlite3 *db, int id);
        void ShowMessDetail(sqlite3 *db,int id1,int id2);
        bool CheckBlock(sqlite3 *db,int id1, int id2);
        void WriteToMess(sqlite3 *db,int id1, int id2,char *mes,char *time);
        bool CheckFriend(sqlite3 *db, int id1,int id2);
        void WriteToFriend(sqlite3 *db,int id1, int id2);
        void ShowFriend(sqlite3 *db,int id1);
        void BlockFriend(sqlite3 *db,int id1, int id2);

};
