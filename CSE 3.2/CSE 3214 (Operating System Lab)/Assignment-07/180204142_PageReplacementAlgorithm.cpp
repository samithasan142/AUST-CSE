#include<bits/stdc++.h>
using namespace std;

int number_of_pages;
int ref_string_size;
int ref_string[100];
int frame_size;
int frames[100];

void resetFrames()
{
    for(int i=0; i<100; i++)
    {
        frames[i] = -1;
    }
}

void FIFO()
{
    resetFrames();
    int position = 0;
    int fifo_fault_count = 0;

    for(int i=0; i<ref_string_size; i++)
    {
        bool hit = 0;
        for(int j=0; j<frame_size; j++)
        {
            if(ref_string[i] == frames[j])
            {
                hit = true;
                break;
            }
        }

        if(!hit)
        {
            if(position>=frame_size)
                position = 0;

            frames[position] = ref_string[i];
            position++;
            fifo_fault_count++;
        }
    }

    cout << "Number of pages fault using FIFO Page Replacement Algorithm: ";
    cout << fifo_fault_count << endl;
    cout << "Pages Fault Rate: ";
    cout << ((fifo_fault_count*1.0/ref_string_size)*100.0) << " %" << endl << endl;
}

void Optimal()
{
    resetFrames();
    int optimal_fault_count = 0;

    for(int i=0; i<ref_string_size; i++)
    {
        bool hit = 0;
        for(int j=0; j<frame_size; j++)
        {
            if(ref_string[i] == frames[j])
            {
                hit = true;
                break;
            }
        }

        if(!hit)
        {
            optimal_fault_count++;
            int remove_page_index = -1;
            int furthest_page_index = -1;

            for(int j =0; j<frame_size; j++)
            {
                if(frames[j]==-1)
                {
                    remove_page_index = j;
                    break;
                }

                int dist = -1;
                for(int k=i+1; k<ref_string_size; k++)
                {
                    if(frames[j]==ref_string[k])
                    {
                        dist = k;
                        break;
                    }
                }

                if(dist>furthest_page_index)
                {
                    furthest_page_index = dist;
                    remove_page_index = j;
                }

                if(dist==-1)
                {
                    remove_page_index = j;
                    break;
                }
            }

            frames[remove_page_index] = ref_string[i];
        }
    }

    cout << "Number of pages fault using Optimal Page Replacement Algorithm: ";
    cout << optimal_fault_count << endl;
    cout << "Pages Fault Rate: ";
    cout << ((optimal_fault_count*1.0/ref_string_size)*100.0) << " %" << endl << endl;
}

void LRU()
{
    resetFrames();
    int lru_fault_count = 0;

    for(int i=0; i<ref_string_size; i++)
    {
        bool hit = 0;
        for(int j=0; j<frame_size; j++)
        {
            if(ref_string[i] == frames[j])
            {
                hit = true;
                break;
            }
        }

        if(!hit)
        {
            lru_fault_count++;
            int least_used_page_index = -1;
            int furthest_page_index = INT_MAX;

            for(int j =0; j<frame_size; j++)
            {
                if(frames[j]==-1)
                {
                    least_used_page_index = j;
                    break;
                }

                int dist = INT_MAX;
                for(int k=i-1; k>=0; k--)
                {
                    if(ref_string[k]==frames[j])
                    {
                        dist = k;
                        break;
                    }
                }

                if(dist<furthest_page_index)
                {
                    furthest_page_index = dist;
                    least_used_page_index = j;
                }
            }

            frames[least_used_page_index] = ref_string[i];

        }
    }

    cout << "Number of pages fault using Least Recently Used Page Replacement Algorithm: ";
    cout << lru_fault_count << endl;
    cout << "Pages Fault Rate: ";
    cout << ((lru_fault_count*1.0/ref_string_size)*100.0) << " %" << endl << endl;
}

int main()
{
    cout << "Numbers of pages : ";
    cin >> number_of_pages;
    cout << "Number of Page References : ";
    cin >> ref_string_size;
    cout << "Reference String : ";
    for(int i=0; i<ref_string_size; i++)
    {
        cin >> ref_string[i];
    }

    cout << "Number of Memory Page Frame : ";
    cin >> frame_size;
    cout << endl;

    FIFO();
    Optimal();
    LRU();

    return 0;
}

//8 22 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1 3
