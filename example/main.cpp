#include <iostream>
#include <qsql/pq/model>
using namespace std;

int main()
try
{
    qql::pq::model<int> User {"user", "postgresql://user:pass@localhost/db"};


    for(auto user : User.find_all()){
        cout << user["firstName"] << std::endl;
    }

    User.update(1,
                {
                    "name", "John Doe"
                });
    User.commit();
    return 0;
}
catch (std::exception& e)
{
    cout << e.what() << endl;
}
