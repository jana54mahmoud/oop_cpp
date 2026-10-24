#include <iostream>
#include <string>
using namespace std;
class person {
protected:
    string name,id;
    public:
    person() {
        name = "Unknown";
        id = "0000";
    }
    person( const string& n, const string& i){
        name=n;
        id=i;
    }
     virtual void display_information() const {
        cout << "Name: " << name << "\n";
        cout << "ID: " << id << "\n";
    }
    void set_name(const string& n) {
        name = n;
    }
    void set_id(const string& i) {
        id = i;
    }
    virtual ~person() {}
};
class Student :  virtual public person {
protected:
    string major;
    public:
    Student( const string& n, const string& i, const string& m) : person(n, i){
        major = m;
    }
    void set_major(const string& m) {
        major = m;
    }
    void display_information() const override {
        person::display_information();
        cout << "Major: " << major << "\n";
    }
};
class Employee : virtual public person {
    protected:
    double salary;
    public:
    Employee( const string& n, const string& i, double s) : person(n, i){
        salary = s;
    }
    void set_salary(double s) {
        salary = s;
    }
    void display_information() const override {
        person::display_information();
        cout << "Salary: " << salary << "\n";
    }
};
class student_employee : public Student, public Employee {
   
    public:
    student_employee( const string& n, const string& i, const string& m, double s) :person(n, i), Student(n, i, m), Employee(n, i, s) {}
    void display_information() const override {
        Student::display_information();
        cout << "Salary: " << salary << "\n";
    }
};
int main() {
  person* ptr;
  Student s1("mai", "S001", "Mathematics");
  Employee e1("mohmed", "E001", 60000.0);
  student_employee se1("youssef", "SE001", "Physics", 30000.0);
  ptr = &s1;
  ptr->display_information();
  ptr = &e1;    
  ptr->display_information();
  ptr = &se1;
  ptr->display_information();
  s1.set_name("jana");
  s1.set_id("03ud");
  e1.set_name("ahmed");
e1.set_id("PLK02");
  se1.set_name("sara");
  se1.set_id("SEdb2");
  se1.set_major("Information Technology");
  ptr = &s1;
  ptr->display_information();       
    ptr = &e1;
    ptr->display_information();
    ptr = &se1;
    ptr->display_information();
person* ptr1 = new Student("sama", "S123", "Computer Science");
person* ptr2 = new Employee("Aya", "E456", 50000.0);
ptr1->display_information();    
ptr2->display_information();
delete ptr1;
delete ptr2;
    return 0;
}