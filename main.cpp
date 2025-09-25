#include <iostream>
#include "item.h"
#include <cstring>

void add_item(Item *item_list, double price,const char *sku,const char *category,const char *name, int index);

void free_items(Item *item_list, int size);

double average_price(Item *item_list, int size);

void print_items(Item *item_list, int size);


int main(int argc, char** argv){
    const char*search = argv[1];

    Item *item_list;
    item_list = new Item[5];

    add_item(item_list, 11.52, "CVBOOT", "Axles", "CV Boot", 0);
    add_item(item_list, 7.99, "OILFILTER", "Engine", "Oil Filter", 1);
    add_item(item_list, 13.39, "AIRFILTER", "Engine", "Engine Air Filter", 2);
    add_item(item_list, 29.99, "SPARKPLUGS", "Ignition", "Spark Plugs - Set of 4", 3);
    add_item(item_list, 19.99, "AIRLOCKERS", "Differential", "Toyota ARB Clamshell Air Lockers", 4);

    print_items(item_list, 5);

    double avg_price = average_price(item_list, 5);
    std::cout<<"average price: "<<avg_price<<std::endl;

   

int count = 0;
    while(count < 5 && strcmp(argv[1], item_list[count].sku)!=0){
        count++;
    }
    if(count < 5){
        std::cout<<"Item found: "<<item_list[count].name<<std::endl;
	std::cout<<"sku: "<<item_list[count].sku<<std::endl;
	std::cout<<"price "<<item_list[count].price<<std::endl;
	std::cout<<"category "<<item_list[count].category<<std::endl;
    } else {
        std::cout<<"Item not found"<<std::endl;
    }

free_items(item_list, 5);
    return 0;
}

void add_item(Item *item_list, double price,const char *sku,const char *category,const char *name, int index)
{
        item_list[index].price = price;

        item_list[index].sku = new char[strlen(sku)+1];
        strcpy(item_list[index].sku, sku);

        item_list[index].category = new char[strlen(category)+1];
        strcpy(item_list[index].category, category);

        item_list[index].name = new char[strlen(name)+1];
        strcpy(item_list[index].name, name);


}

void free_items(Item *item_list, int size)
{
    for(int count = 0; count < size; count++){
        delete[] item_list[count].sku;
        delete[] item_list[count].category;
        delete[] item_list[count].name;
        
    }
    delete[] item_list;
    
}

double average_price(Item *item_list, int size)
{
    int running_total = 0;
    for(int count = 0; count < size; count++){
        running_total = running_total + item_list[count].price;
    }
    double average = running_total / size;
    return average;
    
}

void print_items(Item *item_list, int size)
{
    for(int count = 0; count < size; count++){

        std::cout<<"Item name: "<<item_list[count].name<<std::endl;
        std::cout<<"sku: "<<item_list[count].sku<<std::endl;
        std::cout<<"category: "<<item_list[count].category<<std::endl;
        std::cout<<"Price: "<<item_list[count].price<<std::endl;

    }
}
