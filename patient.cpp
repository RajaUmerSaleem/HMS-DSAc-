#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
int getMaxIDFromFile(const string &filename)
{
    int maxID = 0;
    ifstream file(filename.c_str());
    if (file.is_open())
    {
        int id, age, doctorID, roomID;
        string name, gender, disease;
        time_t arrivalTime;
        bool checkoutStatus;
        char delimiter;

        while (file >> id >> delimiter)
        {
            getline(file, name, ',');
            file >> age >> delimiter;
            getline(file, gender, ',');
            getline(file, disease, ',');
            file >> doctorID >> delimiter >> roomID >> delimiter >> arrivalTime >> delimiter >> checkoutStatus;

            if (id > maxID)
            {
                maxID = id;
            }
        }
        file.close();
    }
    return maxID;
}

class Patient
{
public:
    static int idCounter;
    int patientID;
    string name;
    int age;
    string gender;
    string diseaseDescription;
    int assignedDoctorID;
    int roomID;
    time_t arrivalTime;
    bool checkoutStatus;

    Patient(string name, int age, string gender, string disease, int doctorID, int roomID)
        : name(name), age(age), gender(gender), diseaseDescription(disease), assignedDoctorID(doctorID), roomID(roomID)
    {
        cout << "idCounter: " << idCounter << endl;
        patientID = idCounter++;
        arrivalTime = time(0);
        checkoutStatus = false;
    }

    Patient(int id, string name, int age, string gender, string disease, int doctorID, int roomID, time_t arrivalTime, bool status)
        : patientID(id), name(name), age(age), gender(gender), diseaseDescription(disease), assignedDoctorID(doctorID), roomID(roomID), arrivalTime(arrivalTime), checkoutStatus(status)
    {}

    void saveToFile()
    {
        ofstream file;
        file.open("appointment.txt", ios::app);
        file << patientID << "," << name << "," << age << "," << gender << "," << diseaseDescription << "," << assignedDoctorID << "," << roomID << "," << arrivalTime << "," << checkoutStatus << endl;
        file.close();
    }

    void saveToHistory()
    {
        ofstream file;
        file.open("history.txt", ios::app);
        file << patientID << "," << name << "," << age << "," << gender << "," << diseaseDescription << "," << assignedDoctorID << "," << roomID << "," << arrivalTime << "," << checkoutStatus << endl;
        file.close();
    }

    static Patient *readFromFile(ifstream &file)
    {
        int id, age, doctorID, roomID;
        string name, gender, disease;
        time_t arrivalTime;
        bool checkoutStatus;
        char delimiter;

        file >> id >> delimiter;
        getline(file, name, ',');
        file >> age >> delimiter;
        getline(file, gender, ',');
        getline(file, disease, ',');
        file >> doctorID >> delimiter >> roomID >> delimiter >> arrivalTime >> delimiter >> checkoutStatus;
        return new Patient(id, name, age, gender, disease, doctorID, roomID, arrivalTime, checkoutStatus);
    }

    string getFormattedArrivalTime() const
    {
        char buffer[20];
        struct tm *timeinfo = localtime(&arrivalTime);
        strftime(buffer, sizeof(buffer), "%d:%m:%Y-%H:%M", timeinfo);
        return string(buffer);
    }
};
int Patient::idCounter = 0;

class node
{
public:
    Patient *data;
    node *next;
    node *pre;
    node(Patient *value)
    {
        data = value;
        next = NULL;
        pre = NULL;
    }
};

class linked_list
{
public:
    node *front;
    node *rear;
    linked_list()
    {
        front = NULL;
        rear = NULL;
    }
    bool Empty()
    {
        return rear == NULL && front == NULL;
    }
    void enque(Patient *value, bool fromFile = false)
    {
        cout << "Enque" << endl;
        node *temp = new node(value);
        if (Empty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            temp->pre = rear;
            rear = temp;
        }
        if (!fromFile)
        {
            value->saveToFile();
        }
    }
    Patient *deque()
    {
        if (Empty())
        {
            return NULL;
        }
        else if (rear == front)
        {
            cout << "Deque" << endl;
            Patient *d = front->data;
            delete front;
            front = NULL;
            rear = NULL;
            return d;
        }
        else
        {
            cout << "Deque" << endl;
            node *temp = front;
            front = front->next;
            Patient *d = temp->data;
            delete temp;
            removeFromFile(d->patientID);
            return d;
        }
    }

    void display()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << "ID: " << temp->data->patientID << ", Name: " << temp->data->name << ", Age: " << temp->data->age << ", Gender: " << temp->data->gender << ", Disease: " << temp->data->diseaseDescription << ", Doctor ID: " << temp->data->assignedDoctorID << ", Room ID: " << temp->data->roomID << ", Date of Admission: " << temp->data->getFormattedArrivalTime() << ", Checkout Status: " << (temp->data->checkoutStatus ? "Checked out" : "Not checked out") << endl;
            temp = temp->next;
        }
    }
    void removeFromFile(int patientID)
    {
        ifstream file("appointment.txt");
        ofstream tempFile("temp.txt");
        int id, age, doctorID, roomID;
        string name, gender, disease;
        time_t arrivalTime;
        bool checkoutStatus;
        char delimiter;

        while (file >> id >> delimiter)
        {
            getline(file, name, ',');
            file >> age >> delimiter;
            getline(file, gender, ',');
            getline(file, disease, ',');
            file >> doctorID >> delimiter >> roomID >> delimiter >> arrivalTime >> delimiter >> checkoutStatus;

            // If the ID does not match the patientID to be removed, write to tempFile
            if (id != patientID)
            {
                tempFile << id << "," << name << "," << age << "," << gender << ","
                         << disease << "," << doctorID << "," << roomID << ","
                         << arrivalTime << "," << checkoutStatus << endl;
            }
        }

        file.close();
        tempFile.close();

        // Replace original file with updated file
        remove("appointment.txt");
        rename("temp.txt", "appointment.txt");
    }
};

class AVLNode
{
public:
    Patient *data;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(Patient *value)
    {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVLTree
{
public:
    AVLNode *root;
    AVLTree()
    {
        root = NULL;
    }
    int height(AVLNode *n)
    {
        return (n == NULL) ? 0 : n->height;
    }
    int getBalanceFactor(AVLNode *n)
    {
        return (n == NULL) ? 0 : height(n->left) - height(n->right);
    }
    AVLNode *rightRotate(AVLNode *unbalancedNode)
    {
        AVLNode *leftChild = unbalancedNode->left;
        AVLNode *leftRightSubtree = leftChild->right;

        leftChild->right = unbalancedNode;
        unbalancedNode->left = leftRightSubtree;

        unbalancedNode->height = max(height(unbalancedNode->left), height(unbalancedNode->right)) + 1;
        leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

        return leftChild;
    }
    AVLNode *leftRotate(AVLNode *unbalancedNode)
    {
        AVLNode *rightChild = unbalancedNode->right;
        AVLNode *rightLeftSubtree = rightChild->left;

        rightChild->left = unbalancedNode;
        unbalancedNode->right = rightLeftSubtree;

        unbalancedNode->height = max(height(unbalancedNode->left), height(unbalancedNode->right)) + 1;
        rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

        return rightChild;
    }
    AVLNode *insert(AVLNode *root, Patient *value, bool saveToFile = false)
    {
        if (root == NULL)
        {
            if (saveToFile)
            {
                value->saveToHistory(); // Save only if explicitly asked
            }
            return new AVLNode(value);
        }

        if (value->patientID < root->data->patientID)
        {
            root->left = insert(root->left, value, saveToFile);
        }
        else if (value->patientID > root->data->patientID)
        {
            root->right = insert(root->right, value, saveToFile);
        }
        else
        {
            cout << "Duplicate values are not allowed in AVL tree.\n";
            return root;
        }

        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = getBalanceFactor(root);

        if (balance > 1 && value->patientID < root->left->data->patientID)
        {
            return rightRotate(root);
        }
        if (balance < -1 && value->patientID > root->right->data->patientID)
        {
            return leftRotate(root);
        }
        if (balance > 1 && value->patientID > root->left->data->patientID)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && value->patientID < root->right->data->patientID)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
    void inorder(AVLNode *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << "ID: " << root->data->patientID << ", Name: " << root->data->name << ", Age: " << root->data->age << ", Date of Admission: " << root->data->getFormattedArrivalTime() << endl;
            inorder(root->right);
        }
    }
};
void loadAppointments(linked_list &appointments)
{
    ifstream file("appointment.txt");
    while (file)
    {
        Patient *patient = Patient::readFromFile(file);
        if (file)
        {
            appointments.enque(patient, true);
        }
    }
    file.close();
}
void loadHistory(AVLTree &avl)
{
    ifstream file("history.txt");
    while (file)
    {
        Patient *patient = Patient::readFromFile(file);
        if (file)
        {
            avl.root = avl.insert(avl.root, patient);
        }
    }
    file.close();
}
int main()
{
    // Find the maximum ID in both files
    int maxIDInAppointments = getMaxIDFromFile("appointment.txt");
    int maxIDInHistory = getMaxIDFromFile("history.txt");
    Patient::idCounter = max(maxIDInAppointments, maxIDInHistory) + 1;
    linked_list appointments;
    loadAppointments(appointments);
    AVLTree avl;
    loadHistory(avl);

    // Add new patients
    int numPatients;
    cout << "Enter the number of patients to add: ";
    cin >> numPatients;
    for (int i = 0; i < numPatients; ++i)
    {
        int age, doctorID, roomID;
        string name, gender, disease;
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter patient age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter patient gender: ";
        getline(cin, gender);
        cout << "Enter disease description: ";
        getline(cin, disease);
        cout << "Enter assigned doctor ID: ";
        cin >> doctorID;
        cout << "Enter room ID: ";
        cin >> roomID;

        appointments.enque(new Patient(name, age, gender, disease, doctorID, roomID));
    }

    appointments.display();

    // Dequeue from linked list and insert into AVL tree
    while (!appointments.Empty())
    {
        Patient *patient = appointments.deque();
        avl.root = avl.insert(avl.root, patient, true); // Save to history only during dequeuing
    }

    if (appointments.Empty())
    {
        cout << "\nAll appointments processed." << endl;
    }

    cout << "Inorder Traversal of AVL Tree:\n";
    avl.inorder(avl.root);

    return 0;
}
