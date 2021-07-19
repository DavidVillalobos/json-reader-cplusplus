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