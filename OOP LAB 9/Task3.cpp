#include <iostream>
#include <string>
using namespace std;

class Doctor;
class Billing;

class PatientRecord {
private:
    string* history;
    int historySize;
    string* currentTreatments;
    int treatmentSize;

    string name;
    string ID;
    string DOB;

    string billingDetails;

public:
    PatientRecord(string n, string id, string dob, string* his, string* curtreat, int hsize, int tsize)
        : name(n), ID(id), DOB(dob), historySize(hsize), treatmentSize(tsize) {
        history = new string[historySize];
        for (int i = 0; i < historySize; i++) {
            history[i] = his[i];
        }
        currentTreatments = new string[treatmentSize];
        for (int i = 0; i < treatmentSize; i++) {
            currentTreatments[i] = curtreat[i];
        }
    }

    ~PatientRecord() {
        delete[] history;
        delete[] currentTreatments;
    }

    void getPublicData() {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Date of Birth: " << DOB << endl;
    }

    void getMedicalData() {
        cout << "Medical History:\n";
        for (int i = 0; i < historySize; i++) {
            cout << "- " << history[i] << endl;
        }
        cout << "Current Treatments:\n";
        for (int i = 0; i < treatmentSize; i++) {
            cout << "- " << currentTreatments[i] << endl;
        }
    }

    void updateMedicalHistory(string* newHistory, int newSize) {
        delete[] history;
        historySize = newSize;
        history = new string[historySize];
        for (int i = 0; i < historySize; i++) {
            history[i] = newHistory[i];
        }
    }

    void addBillingDetails(string details) {
        billingDetails = details;
    }

    void getBillingDetails() {
        cout << "Billing Info: " << billingDetails << endl;
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
public:
    void viewMedicalInfo(PatientRecord& p) {
        p.getMedicalData();
    }

    void modifyMedicalHistory(PatientRecord& p, string* newHistory, int size) {
        p.updateMedicalHistory(newHistory, size);
    }

    void viewBasicInfo(PatientRecord& p) {
        p.getPublicData();
    }
};

class Billing {
public:
    void addBilling(PatientRecord& p, string details) {
        p.addBillingDetails(details);
    }

    void viewBilling(PatientRecord& p) {
        p.getBillingDetails();
    }

    void viewBasicInfo(PatientRecord& p) {
        p.getPublicData();
    }
};

class Receptionist {
public:
    void tryToAccess(PatientRecord& p) {
        cout << "Receptionist can only view public data:\n";
        p.getPublicData();
    }
};

int main() {
    string history[] = { "HeadAche", "Fever" };
    string treatments[] = { "penadol", "Calpol" };

    PatientRecord patient("Wasim", "P001", "12-7-2001", history, treatments, 2, 2);

    Doctor doc;
    Billing bill;
    Receptionist rec;

    cout << "Doctor Access\n";
    doc.viewBasicInfo(patient);
    doc.viewMedicalInfo(patient);

    string newHistory[] = { "HeadAches are less", "Vitamin D deficiency" };
    doc.modifyMedicalHistory(patient, newHistory, 2);

    cout << "\nBilling Access\n";
    bill.viewBasicInfo(patient);
    bill.addBilling(patient, "Total due: 1500");
    bill.viewBilling(patient);

    cout << "\nReceptionist Access\n";
    rec.tryToAccess(patient);

    return 0;
}

