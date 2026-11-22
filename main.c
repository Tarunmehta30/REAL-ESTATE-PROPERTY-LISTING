#include <stdio.h>
#include <string.h>

#define MAX 100

struct Property {
    int id;
    char city[50];
    char type[20]; 
    float area;
    int rooms;
    float price;
};

struct Property properties[MAX];
int count = 0;

// Function Declarations
void addProperty();
void displayAll();
void searchProperty();
void filterPrice();
void filterType();
void updateProperty();
void deleteProperty();
void highLowPrice();

int main() {
    int choice;
    while (1) {
        printf("\n--- Real Estate Property Listing System ---\n");
        printf("1. Add a new property\n");
        printf("2. Display all properties\n");
        printf("3. Search by ID or city\n");
        printf("4. Filter by price range\n");
        printf("5. Filter by property type\n");
        printf("6. Update property\n");
        printf("7. Delete property\n");
        printf("8. Display Highest and Lowest Priced\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 9) break;

        switch (choice) {
            case 1: addProperty(); break;
            case 2: displayAll(); break;
            case 3: searchProperty(); break;
            case 4: filterPrice(); break;
            case 5: filterType(); break;
            case 6: updateProperty(); break;
            case 7: deleteProperty(); break;
            case 8: highLowPrice(); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addProperty() {
    if (count >= MAX) {
        printf("Storage full!\n");
        return;
    }
    printf("Enter Property ID: ");
    scanf("%d", &properties[count].id);
    printf("Enter City: ");
    scanf("%s", properties[count].city);
    printf("Enter Type (Flat/Villa/Plot): ");
    scanf("%s", properties[count].type);
    printf("Enter Area (sq ft): ");
    scanf("%f", &properties[count].area);
    printf("Enter No. of Rooms: ");
    scanf("%d", &properties[count].rooms);
    printf("Enter Price: ");
    scanf("%f", &properties[count].price);
    count++;
    printf("Property Added Successfully!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No properties found.\n");
        return;
    }
    printf("\nID\tCity\t\tType\tArea\tRooms\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t%.2f\t%d\t%.2f\n",
            properties[i].id, properties[i].city, properties[i].type,
            properties[i].area, properties[i].rooms, properties[i].price);
    }
}

void searchProperty() {
    int option;
    printf("1. Search by ID  2. Search by City: ");
    scanf("%d", &option);
    int found = 0;
    if (option == 1) {
        int id;
        printf("Enter ID to search: ");
        scanf("%d", &id);
        for (int i = 0; i < count; i++) {
            if (properties[i].id == id) {
                printf("Found: %d %s %s %.2f %d %.2f\n",
                    properties[i].id, properties[i].city, properties[i].type,
                    properties[i].area, properties[i].rooms, properties[i].price);
                found = 1;
            }
        }
    } else {
        char city[50];
        printf("Enter City to search: ");
        scanf("%s", city);
        for (int i = 0; i < count; i++) {
            if (strcmp(properties[i].city, city) == 0) {
                printf("Found: %d %s %s %.2f %d %.2f\n",
                    properties[i].id, properties[i].city, properties[i].type,
                    properties[i].area, properties[i].rooms, properties[i].price);
                found = 1;
            }
        }
    }
    if (!found) printf("No property found.\n");
}

void filterPrice() {
    float min, max;
    printf("Enter min price and max price: ");
    scanf("%f %f", &min, &max);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (properties[i].price >= min && properties[i].price <= max) {
            printf("%d %s %s %.2f %d %.2f\n",
                properties[i].id, properties[i].city, properties[i].type,
                properties[i].area, properties[i].rooms, properties[i].price);
            found = 1;
        }
    }
    if (!found) printf("No property in this price range.\n");
}

void filterType() {
    char type[20];
    printf("Enter type to filter: ");
    scanf("%s", type);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(properties[i].type, type) == 0) {
            printf("%d %s %s %.2f %d %.2f\n",
                properties[i].id, properties[i].city, properties[i].type,
                properties[i].area, properties[i].rooms, properties[i].price);
            found = 1;
        }
    }
    if (!found) printf("No property of this type.\n");
}

void updateProperty() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (properties[i].id == id) {
            printf("Enter new City, Type, Area, Rooms, Price: ");
            scanf("%s %s %f %d %f", properties[i].city, properties[i].type,
                  &properties[i].area, &properties[i].rooms, &properties[i].price);
            printf("Updated Successfully!\n");
            return;
        }
    }
    printf("ID not found.\n");
}

void deleteProperty() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (properties[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                properties[j] = properties[j + 1];
            }
            count--;
            printf("Deleted Successfully!\n");
            return;
        }
    }
    printf("ID not found.\n");
}

void highLowPrice() {
    if (count == 0) {
        printf("No properties.\n");
        return;
    }
    int high = 0, low = 0;
    for (int i = 1; i < count; i++) {
        if (properties[i].price > properties[high].price) high = i;
        if (properties[i].price < properties[low].price) low = i;
    }
    printf("Highest Priced: %d %s %.2f\n", properties[high].id, properties[high].city, properties[high].price);
    printf("Lowest Priced: %d %s %.2f\n", properties[low].id, properties[low].city, properties[low].price);
}