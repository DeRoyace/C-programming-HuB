// search book with name 
#include <stdio.h>

struct bookdetail
{
    char name[20];
    char author[20];
    int pages;
    float price;
};

void dispDetails(struct bookdetail b)
{
    printf("\nBook Name: %s", b.name);
    printf("\nAuthor: %s", b.author);
    printf("\nPages : %d", b.pages);
    printf("Price : Rs. %.2f", b.price);
}

int main()
{
    int n; char sbook[100];
    printf("\nEnter number of books: ");
    scanf("%d", &n);
    struct bookdetail bd[n];

    printf("\nEnter details : ");
    for (int i = 0; i < n; i++)
    {
        printf("\nBook name : ");
        scanf("%c", bd[i].name);
        printf("Author : ");
        scanf("%c", bd[i].author);
        printf("Pages : ");
        scanf("%D", &bd[i].pages);
        printf("Price : Rs. ");
        scanf("%f", &bd[i].price);
        printf("\n------------------------------------------");
    }

    printf("\n\nDETAILS OF ALL BOOKS HERE : \n");
    for (int i = 0; i < n; i++)
    {
        dispDetails(bd[i]);
        printf("\n------------------------------------------");
    }
    printf("\nEnter book name you want to search: ");
    scanf("%s", sbook);

    for (int i = 0; i < n; i++)
    {
        if(bd[i].name == sbook)
        {
            printf("\nBook Found...");
            dispDetails(bd[i]);
            break;
        }
    }
    return 0;
}