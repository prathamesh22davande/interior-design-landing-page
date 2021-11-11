#include<iostream>
using namespace std;

class Hospital{
    string hospital_id;
    string hospital_name;
    string hospital_rating;


    public:
    Hospital(){}
    Hospital(string hospital_id, string hospital_name, string hospital_rating){
        this->hospital_id = hospital_id;
        this->hospital_name =hospital_name;
        this->hospital_rating =hospital_rating;
    }

    Hospital(Hospital &hospital){
        this->hospital_id =hospital.hospital_id;
        this->hospital_name =hospital.hospital_name;
        this->hospital_rating =hospital.hospital_rating;

    }

    string getHospitalId(){
        return hospital_id;
    }
    string getHospitalName(){
        return hospital_name;
    }
    string getHospitalRating(){
        return hospital_rating;
    }
};

class Doctor:public Hospital{
    string doctor_id;
    string doctor_name;
    string doctor_speciality;
    string registerd_hospital_name;
    float doctor_fees;

    
    public:
    Doctor(){}
    Doctor(string doctor_id, string doctor_name, string doctor_speciality,string registerd_hospital_name,float doctor_fees){
        this->doctor_id = doctor_id;
        this->doctor_name = doctor_name;
        this->doctor_speciality = doctor_speciality;
        this->registerd_hospital_name = registerd_hospital_name;
        this->doctor_fees = doctor_fees;
    }

    string getDoctorId(){
        return doctor_id;
    }
    string getDoctorName(){
        return doctor_name;
    }
    string getDoctorSpeciality(){
        return doctor_speciality;
    }
    string getRegisteredHospitalName(){
        return registerd_hospital_name;
    }
    float getDoctorFees(){
        return doctor_fees;
    }

    float calculateTax(){
        return doctor_fees *20/100;
    }


};

int main(){
    int noOfHospitals;
    cout<<"Enter no of hospitals : ";
    cin>>noOfHospitals;
    Hospital hospitals_arr[noOfHospitals];
    for (int i=0;i<noOfHospitals;i++){
        string hospital_id;
        cout<<"Hospital ID : ";
        cin>>hospital_id;
        string hospital_name;
        cout<<"Hospital Name : ";
        cin>>hospital_name;
        string hospital_rating;
        cout<<"Hospital Rating : ";
        cin>>hospital_rating;
        hospitals_arr[i] = new Hospital(hospital_id,hospital_name,hospital_rating);

    }
    int noOfDoctors;
    cout<<"Enter no of Doctors : ";
    cin>>noOfDoctors;
    Doctor doctors_arr[noOfDoctors];
    for (int i=0;i<noOfDoctors;i++){
        string doctor_id;
        cout<<"Enter Doctor ID : ";
        cin>>doctor_id;
        string doctor_name;
        cout<<"Enter Doctor Name : ";
        cin>>doctor_name;
        string doctor_speciality;
        cout<<"ENter Doctor Speciality : ";
        cin>>doctor_speciality;
        string registerd_hospital_name;
        cout<<"Enter Doctor Registered Hospital Name : ";
        cin>>registerd_hospital_name;
        float doctor_fees;
        cout<<"Enter Doctor Fees : ";
        cin>>doctor_fees;

        doctors_arr[i] = new Doctor(doctor_id, doctor_name, doctor_speciality, registerd_hospital_name,doctor_fees);
    }

    cout<<"Highest Fees Doctor: ";
    Doctor d = doctors_arr[0];
    for (int i=1;i<noOfDoctors;i++){
        if (d.getDoctorFees()<doctors_arr[i].getDoctorFees()){
            d=doctors_arr[i];
        }
    }
    cout<<d.getDoctorName()<<endl;
    cout<<"Tax for the doctor : "<<d.calculateTax()<<endl;

    cout<<"Enter doctor name : ";
    string doctor_name;
    cin>>doctor_name;
    for (Doctor d:doctors_arr){
        if (d.getDoctorName().compare(doctor_name)==0){
            cout<<"Hospital for Dr. "<<doctor_name<<" is : "<<d.getRegisteredHospitalName()<<endl;
            break;
        }
    }

    cout<<"Enter rating : ";
    string rating;
    cin>>rating;

    cout<<"Hospitals with "<<rating<<" are: "<<endl;
    for (Hospital h:hospitals_arr){
        if (h.getHospitalRating().compare(rating)){
            cout<<h.getHospitalName()<<endl;
        }
    }
}