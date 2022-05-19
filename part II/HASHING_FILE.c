#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size 1405
#define LINE_SIZE 1405
#define FALSE 0
#define N 10

struct table_data
{
    struct tm date;
    double T_degC;
};

typedef struct DataItem
{
    struct table_data data;
    int key;
    struct node *next;
};

struct node *chain[size];

void begin()
{
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}

int hash_function(struct DataItem *node, char *data_str)
{
    int i;
    int sum;
    int key;
    for (i = 0; i <= N; i++)
    {
        sum += (int)data_str[i];
    }
    key = sum % N;
    return key;
}

struct DataItem *insert_node(struct DataItem *node, struct table_data value)
{
    char *filename;
    struct DataItem *node;
        // create a newnode with value
        struct DataItem *newNode = malloc(sizeof(struct DataItem));
    newNode->data = value;
    newNode->next = NULL;

    // calculate hash key
    int key = hash_file(*filename, node);

    // check if chain[key] is empty
    if (chain[key] == NULL)
        chain[key] = newNode;
    // collision
    else
    {
        // add the node at the end of chain[key].
        struct DataItem *temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    return node;
}

int *hash_file(char *filename, struct DataItem *node)
{
    FILE *fp = NULL;
    struct table_data temp;
    char *pinakas = (char *)malloc(sizeof(char) * LINE_SIZE);
    char *date_str = (char *)malloc(sizeof(char) * (10 + 1));
    if (check_allocation((char *)pinakas) == FALSE)
        return FALSE;
    if (check_allocation((char *)date_str) == FALSE)
        return FALSE;

    fp = fopen(filename, "r");
    if (!fp)
    {
        fprintf(stderr, "Error opening file!\n");
        return NULL;
    }

    pinakas = fgets(pinakas, LINE_SIZE - 1, fp);      // Διαβάζουμε την πρώτη γραμμή του
                                                      // αρχείου με τις επικεφαλίδες κάθε τιμής
    while (fgets(pinakas, LINE_SIZE - 1, fp) != NULL) // Η while εκτελέιται εώς ότου
                                                      // φτάσουμε στο τέλος του αρχείου
    {
        strcpy(date_str, strtok(pinakas, ","));
        temp.T_degC = atof(strtok(NULL, ","));
        temp.date.tm_mon = atoi(strtok(date_str, "/")) - 1; /* month, range 0 to 11             */
        temp.date.tm_mday = atoi(strtok(NULL, "/"));        /* day of the month, range 1 to 31  */
        temp.date.tm_year = atoi(strtok(NULL, "/")) - 1900; /* The number of years since 1900   */
        temp.date.tm_sec = 0;                               /* seconds,  range 0 to 59          */
        temp.date.tm_min = 0;                               /* minutes, range 0 to 59           */
        temp.date.tm_hour = 0;                              /* hours, range 0 to 23             */
        temp.date.tm_wday = 0;                              /* day of the week, range 0 to 6    */
        temp.date.tm_yday = 0;                              /* day in the year, range 0 to 365  */
        temp.date.tm_isdst = -1;                            /* daylight saving time             */
        node = insert(node, temp);
    }
    int key = hash_function(node, *date_str);
    fclose(fp);
    free(pinakas);
    free(date_str);

    return key;
}

void print(struct DataItem node)
{
    int i;

    for (i = 0; i < size; i++)
    {
        struct DataItem *temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
  struct  DataItem *node = NULL;
    begin();
    node = insert_from_file("ocean.csv", node);
     print(*node);
    clean();
   

    exit(0);
}

