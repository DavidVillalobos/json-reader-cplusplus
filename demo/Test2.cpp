#include<iostream>
using namespace std;

#include"../src/JsonReader.h"

int main(int argc, char** argv){
	Json bill("invoice.json"); 
	std::cout << "Purchase details" << std::endl;
	std::cout << "Due date: " << bill["DueDate"] << std::endl;
	std::cout << "Invoice number: " << bill["InvoiceNumber"] << std::endl;
	std::cout << "Status: " << bill["Status"] << std::endl;
	std::cout << "Costumber: " << bill["customer"]["name"] << ' ' << bill["customer"]["lastName"] << std::endl;
	double total = 0, subTotalLine;
	std::cout << "ID\tDescription\t\tAmount\tPrice\t Discount\tTotal" << std::endl;
	Json purchaseDetail = bill["purchaseDetail"];
	for(size_t i = 0 ; i < purchaseDetail.size(); i++){
		std::cout << i << ".\t" << purchaseDetail[i]["description"];
		std::cout.width(12);
		std::cout << "\t" << purchaseDetail[i]["amount"];
		std::cout << "\t" << purchaseDetail[i]["price"];
		subTotalLine = (double) purchaseDetail[i]["amount"] * (double) purchaseDetail[i]["price"];
		if(purchaseDetail[i]["discount"]){
			std::cout << "\t YES";
			subTotalLine -= subTotalLine * (double) bill["discount"];
		} else {
			std::cout << "\t NOT";
		}
		std::cout.width(10);
		std::cout << "\t" << subTotalLine << std::endl;
		total += subTotalLine;
	}
	std::cout << "Total: " << total << std::endl;
	std::cout << "Thanks for your purchase" << std::endl;
}