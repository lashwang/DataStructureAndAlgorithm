#include <iostream>
#include <list> 

using namespace std;

typedef struct{
    char name[10];
    int age;
    int value;
}People;

static list<People> s_people_list;

int main()
{   
    int n,k;
    cin>>n;
    cin>>k;
    
    for(int i = 0;i < n;i++){
        People p;
        cin>>p.name;
        cin>>p.age;
        cin>>p.value;
        cout<<p.name<<p.age<<p.value;
    }
}



