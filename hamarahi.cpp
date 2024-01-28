#include<iostream>
using namespace std;

// Burst Time of each individual item
int items_bt[8] = {5, 5, 5, 10, 5, 15, 5, 20};

// Function to display items list
void display_items()
{
    cout<<"\nBelow are items with time needed to complete the checkout";
    cout<<"\n1. Bread (5s)\n2. Snacks (5s)\n3. Motor Oil (5s)\n4. Childern Toy (10s)\n5. Stationery (5s)\n6. Sporting Good (15s)\n7. Kitchenware (5s)\n8. Furniture Items (20s)";
}

int main()
{
    // Heading
    cout<<"------------------ Superstore Checkout Simulation ------------------"<<endl;

    // cust_count is number of customers
    // item_num is input user enters while selecting item
    // item_quantity is count of an item customer has
    // item_index will be used for index in items_bt array
    // total_cust_time is total time being consumed
    int cust_count, item_num, item_quantity, item_index, total_cust_time=0;

    cout<<"\nTell us number of customers: ";
    cin>>cust_count;

    // All of these will be of size customer count
    int burst_time[cust_count], waiting_time[cust_count], turnaround_time[cust_count], completion_time[cust_count];

    display_items();

    for (int i=0; i<cust_count; i++)
    {
        again:

        // As index start from 0 so i+1 will start customer count from 1
        cout<<"\nFor Customer No "<<i+1<<" Select Item Number: ";
        cin>>item_num;

        // In case user enters an input which is out of range of items list
        if (item_num < 1 || item_num > 8)
        {
            cout<<"Invalid Input";
            // Inputs will be taken again for that customer
            goto again;
        }

        // Subtracting 1 from item_num as index in array starts from 0
        item_index = item_num - 1;
        cout<<"Write Item Quantity: ";
        cin>>item_quantity;

        burst_time[i] = item_quantity * items_bt[item_index];

        select_again:

        // In case customer wants to select another item
        cout<<"Select another item for Customer "<<i+1<<" (Type 0 to go to next customer): ";
        cin>>item_num;

        // If customer wants to select another item
        if (item_num != 0)
        {
            if (item_num > 8)
            {
                cout<<"Invalid Input";
                goto again;
            }

            cout<<"Write Item Quantity: ";
            cin>>item_quantity;

            item_index = item_num - 1;

            burst_time[i] += item_quantity * items_bt[item_index];

            // Keep on selecting items until all items of customer are selected
            goto select_again;
        }
    }

    for (int i=0; i<cust_count; i++)
    {
        // For second customers and more
        if (i!=0)
        {
            total_cust_time += burst_time[i-1];
            completion_time[i] = total_cust_time + burst_time[i];

            turnaround_time[i] = completion_time[i];
            waiting_time[i] = turnaround_time[i] - burst_time[i];
        }
        // For first customer
        else
        {
            completion_time[i] = burst_time[i];
            turnaround_time[i] = completion_time[i];
            waiting_time[i] = turnaround_time[i] - burst_time[i];
        }
    }


    // Now displaying data after checkout
    cout<<"\nCheckout completed. Now time to see each customer's data";

    for (int i=0; i<cust_count; i++)
    {
        // As index start from 0 so i+1 will start customer count from 1
        cout<<"\nFor Customer No "<<i+1<<": BT (Burst Time) = "<<burst_time[i]<<"s, CT (Completion Time) = "<<completion_time[i]<<"s, TAT (Turnaround Time) = "<<turnaround_time[i]<<"s, WT (Waiting Time) = "<<waiting_time[i]<<"s";
    }
}




