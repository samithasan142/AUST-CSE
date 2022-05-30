#include <stdio.h>

int que[20];
int top = -1;

bool push(int x)
{
    //implement the push function here
    //return true if it is inserted successfully into the queue
    //otherwise return false
    if(top<19)
    {
        top++;
        que[top]=x;
        return true;
    }
    else
        return false;
}

int pop()
{
    //implement the pop function here
    //return -1 if the queue is empty
    if(top!=-1)
    {
        int temp=que[0];
        top--;
        for(int i=0; i<=top; i++)
            que[i]=que[i+1];
        return temp;
    }
    else return -1;
}

bool isEmpty()
{
    //return true if the queue is empty
    //otherwise return false
    if(top<0)
        return true;
    else return false;
}

int queSize()
{
    //return queue size
    return top+1;
}

void printAll()
{
    for(int i=0; i<=top; i++)
    {
        printf(" %d ",que[i]);
    }
    printf("\n");
}
void printOptions()
{
    printf("\n\n1.Push\n2.Pop\n3.IsEmpty?\n4.Queue Size?\n5.Print all\n6.End\n");
    printf("Provide your choice: ");
}

int main()
{
    while(true)
    {
        int choice;
        bool needEnd = false;
        printOptions();
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
        {
            int x;
            scanf("%d",&x);

            if(push(x))
                printf("Successfully pushed\n");
            else
                printf("Queue is full\n");

            break;
        }
        case 2:
        {
            int x = pop();
            if(x>=0)
                printf("Successfully poped %d\n",x);
            else
                printf("Queue is empty\n");

            break;
        }
        case 3:
        {
            if(isEmpty())
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        }
        case 4:
        {
            printf("Queue size %d\n",queSize());
            break;
        }
        case 5:
        {
            printAll();
            break;
        }
        case 6:
        {
            needEnd = true;
            break;
        }
        default:
            printf("Invalid choice try Again.");
        }

        if(needEnd)
            break;
    }

    return 0;
}

