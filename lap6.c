#include<stdio.h>
#define n 11

void fifo(int matrix[][n], int pages, int frames, int default_page)
{
        int page_fault=0;
        int temp[frames];
        for(int i=0;i<frames;i++)
                temp[i]=-1;
        for(int i=0;i<pages;i++)
        {
                int s=0;
                for(int j=0;j<frames;j++)
                {
                   if(matrix[0][i]==temp[j])
                   {
                        s++;
                        page_fault--;

                   }

                }
                page_fault++;
                if(page_fault<=frames &&s==0)
                {
                        temp[i]=matrix[0][i];
                }
                else if (s==0)
                {
                        temp[(page_fault-1)%frames]=matrix[0][i];
                }

                for(int j=0;j<frames;j++)
                 {
                       
                    matrix[j+1][i]=temp[j];

                 }



        }
         for(int i=0;i<(frames+1);i++)
        {
                for(int j=0;j<pages;j++)
                {
                        if(matrix[i][j]==-1)
                                printf("\t");
                        else
                        {
                                printf("%d\t",matrix[i][j]);
                        }
                }
                printf("\n");
        }
        //in pagefaults
        printf("\n\t number of pagefaults: %d",page_fault);


}
void LRU(int matrix[][n], int pages, int frames, int default_page)
{
        int page_fault=0;
        int temp[frames];
        for(int i=0;i<frames;i++)
                temp[i]=-1;
        for(int i=0;i<pages;i++)
        {
                int s=0;
                int flag;
                for(int j=0;j<frames;j++)
                {
                   if(matrix[0][i]==temp[j])
                   {
                        s++;
                        page_fault--;

                   }

                }
                page_fault++;

                if(page_fault<=frames &&s==0)
                {
                        temp[i]=matrix[0][i];
                }
                else if (s==0)
                {
                        //int pos;
                        flag=0;
                        int j;
                        // temp[(page_fault-1)%frames]=matrix[0][i];
                        for(int k=0;k<i;k++)
                        {
                           
                                for( j=0;j<frames;j++)
                                {
                                        if(matrix[0][k]==temp[j])
                                        {
                                            
                                                flag=1;
                                                break;
                                                
                                                
                                        }
                                        
                                }
                                if(flag==1)
                                {
                                    temp[j]=matrix[0][i];
                                    break;
                                }
                                
                        }

                        

                }

                for(int j=0;j<frames;j++)
                 {
                       
                    matrix[j+1][i]=temp[j];

                 }



        }
         for(int i=0;i<(frames+1);i++)
        {
                for(int j=0;j<pages;j++)
                {
                        if(matrix[i][j]==-1)
                                printf("\t");
                        else
                        {
                                printf("%d\t",matrix[i][j]);
                        }
                }
                printf("\n");
        }

        printf("\n\t number of pagefaults: %d",page_fault);


}
void OPT(int matrix[][n], int pages, int frames, int default_page)
{
        int page_fault=0;
        int temp[frames];
        int array[frames];
        for(int i=0;i<frames;i++)
                temp[i]=-1;
        
        int flag1, flag2,flag3;
        int pos,max;
        for(int i = 0; i < pages; ++i){
            flag1 = flag2 = 0;
        
            for(int j = 0; j < frames; ++j){
                if(temp[j] == matrix[0][i]){
                   flag1 = flag2 = 1;
                   break;
                }
            }
        
            if(flag1 == 0){
                for(int j = 0; j < frames; ++j){
                    if(temp[j] == -1){
                        page_fault++;
                        temp[j] = matrix[0][i];
                        flag2 = 1;
                        break;
                        }
                }    
            }
            
            if(flag2 == 0){
             flag3 =0;
            
                for(int j = 0; j < frames; ++j){
                    array[j] = -1;
                
                    for(int k = i + 1; k < pages; ++k){
                        if(temp[j] == matrix[0][k]){
                            array[j] = k;
                            break;
                        }
                    }
                }
                
                for(int j = 0; j < frames; ++j){
                    if(array[j] == -1){
                        pos = j;
                         flag3 = 1;
                         break;
                    }
                }
                
                if(flag3 ==0){
                     max = array[0];
                     pos = 0;
                    
                     for(int j = 1; j < frames; ++j){
                         if(array[j] > max){
                             max = array[j];
                             pos = j;
                        }
                     }            
                }
                temp[pos] = matrix[0][i];
                page_fault++;
            }
            //nhập dữ liệu vô ma trận
            for(int j=0;j<frames;j++)
            {
                           
                matrix[j+1][i]=temp[j];
    
            }



        }
        //in ma trận ra màn hình
         for(int i=0;i<(frames+1);i++)
        {
                for(int j=0;j<pages;j++)
                {
                        if(matrix[i][j]==-1)
                                printf("\t");
                        else
                        {
                                printf("%d\t",matrix[i][j]);
                        }
                }
                printf("\n");
        }
         printf("\n\t number of pagefaults: %d",page_fault);


}




int main()
{
        int choice;
        int frames;
        int pagefault=0;
        printf("\t--- Page Replacement algorithm ---\n\t1. Default referenced sequence\n\t2. Manual input sequence\n");
        scanf("%d",&choice);
        if(choice==1)
        {
              
                printf("\t--input frames\n");
                scanf("%d",&frames);
                int matrix[frames+1][n];
                int array[n]={2,0,5,2,1,1,4,3,0,0,7};
                for(int i=0;i<11;i++)
                                matrix[0][i]=array[i];
                printf("\t--- Page Replacement algorithm ---\n\t1. FIFO algorithm\n\t2. OPT algorithm\n\t3. LRU algorithm\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    { 
                        fifo(matrix,11,3,pagefault);
                       
                        break;
                    

                    }
                    case 2:
                    { 
                        OPT(matrix,11,3,pagefault);
                        break;
                    

                    }
                    case 3:
                    { 
                         LRU(matrix,11,3,pagefault);
                        break;
                    

                    }
                }

               

        }
        else
        {
                
                printf("\t--input frames\n");
                scanf("%d",&frames);
                int matrix[frames+1][n];
                printf("\t input pages: ");
                for(int i=0;i<n;i++)
                {
                        scanf("%d", &matrix[0][i]);
                }
                printf("\t--- Page Replacement algorithm ---\n\t1. FIFO algorithm\n\t2. OPT algorithm\n\t3. LRU algorithm\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    { 
                        fifo(matrix,11,3,pagefault);
                        break;
                    

                    }
                    case 2:
                    { 
                        OPT(matrix,11,3,pagefault);
                        break;
                    

                    }
                    case 3:
                    { 
                        LRU(matrix,11,3,pagefault);
                        break;
                    

                    }
                }
                
               
                

        }
}
