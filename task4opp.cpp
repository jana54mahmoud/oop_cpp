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
     virtual void display_information() const = 0; 
    void set_name(const string& n) {
        name = n;
    }
    void set_id(const string& i) {
        id = i;
    }
    virtual ~person() {}
};
class Student :  virtual public person {
private:
    string major;
    friend class  UniversityAdmin;
    public:
    Student( const string& n, const string& i, const string& m) : person(n, i){
        major = m;
    }
    void set_major(const string& m) {
        major = m;
    }
     string getMajor() const { return major; }
    void display_information() const override {
        cout << "Student\n";
        cout << "Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Major: " << major << "\n";
    }
};
class Employee : virtual public person {
    private:
    double salary;
        friend void compareSalaries(const Employee& e1, const Employee& e2);

    public:
    Employee( const string& n, const string& i, double s) : person(n, i){
        salary = s;
    }
    void set_salary(double s) {
        salary = s;
    }
     double getSalary() const { return salary; }
     void display_information() const override {
        cout << "Employee\n";
        cout << "Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Salary: " << salary << "\n";
    }
};
class TeachingAssistant : public Student, public Employee {
   
    public:
    TeachingAssistant( const string& n, const string& i, const string& m, double s) :person(n, i), Student(n, i, m), Employee(n, i, s) {}
    void display_information() const override {
        cout << "Teaching Assistant\n";
        cout << "Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Major: " << getMajor() << "\n";
        cout << "Salary: " << getSalary() << "\n";
    }

};
void compareSalaries(const Employee& e1, const Employee& e2) {
    cout << e1.name << " salary: " << e1.salary << "\n";
    cout << e2.name << " salary: " << e2.salary << "\n";
 
    if (e1.salary > e2.salary)
        cout << e1.name << " earns more than " << e2.name << ".\n";
    else if (e2.salary > e1.salary)
        cout << e2.name << " earns more than " << e1.name << ".\n";
    else
        cout << "Both earn the same salary.\n";
}
class UniversityAdmin {
public:
    void showStudentInfo(const Student& s) const {
        cout << "Admin view\n";
        cout << "Name: " << s.name << "\n";
        cout << "ID: " << s.id << "\n";
        cout << "Major: " << s.major << "\n";
    }
};

int main() {
 person* ptr;
  Student s1("mai", "S001", "Mathematics");
  Employee e1("mohmed", "Eebd", 60000.0);
  TeachingAssistant ta1("youssef", "ef4wj", "Physics", 30000.0);
  ptr = &s1;
  ptr->display_information();
  ptr = &e1;
  ptr->display_information();
  ptr = &ta1;
    ptr->display_information();
    cout<<endl;
    Employee emp("Sara", "E002", 45000.0);
    TeachingAssistant ta("Omar", "dfmas", "Engineering", 28000.0);
    compareSalaries(emp, ta);
    UniversityAdmin admin;
    Student st("Jana", "dthgb", "Computer Science");
    admin.showStudentInfo(st);
return 0;
}