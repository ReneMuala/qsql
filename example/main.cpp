#include <iostream>
#include <qsql/pq/model>
using namespace std;

int main()
{
    qql::pq::Model<int> User {"usuario", "postgresql://postgres:crzilians@localhost/playDB"};


    for(auto user : User.findAll()){
        cout << user["firstName"] << std::endl;
    }

    User.update(1,
                {
                    "firstName", "John Doe"
                });

    return 0;
}
