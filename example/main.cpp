#include <iostream>
#include <qsql/pq/model>
using namespace std;

int main()
{
    qql::pq::Model<int> User {"user", "postgresql://user:pass@localhost/db"};


    for(auto user : User.findAll()){s
        cout << user["firstName"] << std::endl;
    }

    User.update(1,
                {
                    "firstName", "John Doe"
                });

    return 0;
}
