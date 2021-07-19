<img src="res/MainTitle.png" width="550">   

Json reader for c++, allows to generate a structure "Json" in c++ from a simple json file.  
build with c++ only, using the fstream and regex libraries.
# Usage
1.	Include JsonReader ``` #include"path/to/JsonReader.h"```
2.	Create a the Json object  ``` Json file("path/to/file.json"); // path to json file ```
3.	Get property like ``` file["path"]["to"]["property"]```  if is array put the number like ``` file["array"][9]["property"]```
    
From the following json file:  
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
The following code must be used:  
```c++
#include<iostream>
using namespace std;
#include"../src/JsonReader.h" // include this file

int main(int argc, char** argv){
    // build a Object Json
    Json file("file.json"); // path to json file
    // Get properties like -> file["path"]["to"]["property"]
    cout << "The name is " << file["firstName"] << ' ' << file["lastName"] << endl;
    cout << "The city is " << file["address"]["city"] << ", " << file["address"]["state"] << endl;
    cout << "The phone office is " << file["phoneNumbers"][1]["number"] << endl;
}
```
The result per console is as follows:  
<img src="res/ResultTest.png" width="450">   

Another example iterating over an array:  

From the following json file:  
```json
{
	"DueDate": "2021-07-18",
	"InvoiceNumber": "83172212392",
	"Status": "Paid out",
	"discount": 0.10,
	"customer" : {
		"id" : "111",
		"name" : "Mike",
		"lastName" : "Anderson"
	},
	"purchaseDetail" : [
		{
			"productId" : "12345",
			"description" : "Low fat milk",
			"amount" : 3,
			"price": 1.45,
			"discount" : true
		}, {
			"productId" : "54321",
			"description" : "Butter",
			"amount" : 2,
			"price" : 1.05,
			"discount" : false
		}, {
			"productId" : "15243",
			"description" : "Flour",
			"amount" : 1,
			"price" : 2.15,
			"discount" : false
		}, {
			"productId" : "52341",
			"description" : "sugar",
			"amount" : 2,
			"price" : 2.0,
			"discount" : true
		}
	]
}
```
The following code must be used:  
```c++
#include<iostream>
using std::cout;
using std::endl;

#include"../src/JsonReader.h"

int main(int argc, char** argv){
	Json bill("invoice.json"); 
	cout << "Purchase details" << endl;
	cout << "Due date: " << bill["DueDate"] << endl;
	cout << "Invoice number: " << bill["InvoiceNumber"] << endl;
	cout << "Status: " << bill["Status"] << endl;
	cout << "Costumber: " << bill["customer"]["name"] << ' ' << bill["customer"]["lastName"] << endl;
	double total = 0, subTotalLine;
	double discount = bill["discount"];
	cout << "Discount: " << discount * 100 << "%" << endl;
	cout << "ID\tDescription\t\tAmount\tPrice\t Discount\tTotal" << endl;
	Json purchaseDetail = bill["purchaseDetail"];
	for(size_t i = 0 ; i < purchaseDetail.size(); i++){
		cout << i << ".\t" << purchaseDetail[i]["description"];
		cout.width(12);
		cout << "\t" << purchaseDetail[i]["amount"];
		cout << "\t" << purchaseDetail[i]["price"];
		subTotalLine = (double) purchaseDetail[i]["amount"] * (double) purchaseDetail[i]["price"];
		if(purchaseDetail[i]["discount"]){
			cout << "\t YES";
			subTotalLine -= subTotalLine * discount;
		} else {
			cout << "\t NOT";
		}
		cout.width(10);
		cout << "\t" << subTotalLine << endl;
		total += subTotalLine;
	}
	cout << "Total: " << total << endl;
	cout << "Thanks for your purchase" << endl;
}
```
The result per console is as follows:  
<img src="res/ResultTest2.png" width="450">   


### Author 

* **[DavidVillalobos](https://github.com/DavidVillalobos)** 

### Contributing

For new changes, please open an issue first to discuss what you would like to change.  
You can contact me at 📫 : villalobosgonzalezluisdavid@gmail.com  

## License
The project is licensed by  ![License](https://img.shields.io/apm/l/vim-mode)
