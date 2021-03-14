# Json cplusplus

Json reader for c++, allows to generate a structure JSON in c++ from a json file.

### Example example.json

```json
{
    "firstName": "Rack",
    "lastName": "Jackon",
    "gender": "man",
    "age": 24,
    "address": {
        "streetAddress": "126",
        "city": "San Jone",
        "state": "CA",
        "postalCode": "394221"
    },
    "phoneNumbers": [
        { "type": "home", "number": "7383627627" },
        { "type": "office", "number": "8462945527" }
    ]
}
```

```c++
#include<iostream>
using namespace std;

#include"JsonReader.h" // include this file

int main(int argc, char** argv){
    // build a Object Json
	Json file("file.json"); // path to json file
    // Get properties like -> file["path_to_property"]
    cout << "The name is " << file["firstName"] << ' ' << file["lastName"] << endl;
    cout << "The city is " << file["address/city"] << endl;
    cout << "The phone office is " << file["phoneNumbers/1/number"] << endl;
}
```