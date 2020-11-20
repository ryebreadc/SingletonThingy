#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// Datastore as a Singleton
// PRIVATE constructor
// PUBLIC method that RETURNS pointer to the object.
class DataStore {

  private:
    static DataStore *instance;
    string data;
  
    // Private constructor so that no objects can be created.
    DataStore() {
        data = "";
    }

   public:
    static DataStore *getInstance() {
        if (!instance) {
          instance = new DataStore;
        }
        return instance;
    }

    string getData() {
        return data;
    }

    void setData(string newData) {
        data = newData;
    }

    void addData(string newData) {
      data = data + newData;
    }
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance()
// sort of sucks to have to do this, but in C++, we have to do it this way
DataStore *DataStore::instance = nullptr;

int main(){

  vector<string> precheck;
  vector<string> finalpush;
  string line;
  fstream myfile("flashcards.txt");
  while(getline(myfile, line)) {
    precheck.push_back(line);
  } 
  
  for(int i = 0; i < precheck.size(); i++) {

    DataStore *d = d->getInstance();
    d->setData(precheck[i]);
    cout << d->getData() << endl;
    finalpush.push_back(d->getData());

    string input;
    DataStore *f = f->getInstance();
    cin >> input;
    f->setData(input);
    finalpush.push_back(f->getData());
  }

  for(int i = 0; i < finalpush.size(); i++) {
    cout << finalpush[i] << endl;
    //This wont write to file for some reason..
    //myfile << finalpush[i];
  }


  myfile.close();
 

  return 0;
}