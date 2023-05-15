#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void RemoveDuplicate(int arr[],int Size)
{
    for (int i = 0; i < Size; i++)
	{
		for(int j = i + 1; j < Size; j++)
		{
    		if(arr[i] == arr[j])
    		{
    			for(int k = j; k < Size; k++)
    			{
    				arr[k] = arr[k + 1];
				}
				Size--;
				j--;
			}
		}
	}
}

void MakingNull(int a[],int size)
{
    for(int i=0; i<size; i++)
    {
        a[i]=NULL;
    }
}

   int i, j,indexOfEqualSign = 0;
   char NameOfArrays2[10][10];
   int ArrayIndex = 0;
   int colomIndex = 0;
   char set1[50];
   int Values[10][100];
   char new1[20];

   int TempIndex=0;
   int Validation[100];
   int Answer[100];

int main()
{


      //making all the elements null



        for(i=0; i<10 ; i++){
           for(j=0; j<10; j++){
            NameOfArrays2[i][j]= '$';
        }
      }

        for(i=0; i<10 ; i++){
           for(j=0; j<10; j++){
            Values[i][j]= NULL;
        }
      }

       while (1)
              {


          MakingNull(set1, 50);
          //taking the sets
          printf(">>>");
          scanf("%s", &set1[0]);


         if(set1[0] == '^')
         {
            break;
         }



         //index of equal sign
          for(i=0 ; i<=50; i++) {
            if (set1[i] == '=' ) {
                indexOfEqualSign = i;
                break;
            }
          }

          // store the name of the first set in array
          for(i=0; i<indexOfEqualSign ; i++)
          {
              NameOfArrays2[ArrayIndex][i]= set1[i];
              if (set1[i]=='='){
                break;
              }
          }

          int IndexOfStart = indexOfEqualSign+1;
          int IndexOfEnd = 0;
            int temp[5]={0,0,0,0,0};




          colomIndex=0;

           MakingNull(Validation, 100);

          for (i= indexOfEqualSign+2 ; i<50; i++)//ONE ELEMENT IN VALIDATION
          {
            if( set1[i] == ',' || set1[i] == '}')
            {
                    IndexOfEnd = i;
                 //   printf("end at %d \n" , IndexOfEnd);
                int k=4;
                for(j=IndexOfEnd-1 ; j>IndexOfStart; j--)//EACH VALUES OF TEMP
                {
                    temp[k] =(int)(set1[j]-48);
                    k--;
                }
                 printf("\n");

                Validation[colomIndex]= temp[4]+ (10*temp[3])+ (100*temp[2])+
                           (1000*temp[1])+ (10000*temp[0]);
                            colomIndex++;
                    IndexOfStart = IndexOfEnd;

            }


          }
           for (i=0; i<100; i++)
                  {
                      for(j=0; j<100; j++)
                      {
                          if ( Validation[j] == Validation[i] && i!=j)
                           Validation [i] = NULL;

                      }
                  }

                  printf("\n");

        for(i=0; i<100; i++)
        {
            if(Validation[i] != NULL)
            {
                 Values[ArrayIndex][i] = Validation[i];

            }

        }

        for(i=0; i<10; i++)
        {
            printf("%d \n",Values[ArrayIndex][i]);

        }

          ArrayIndex++;

       //   colomIndex=0;

    printf("\n");
}

     while (1)
     {
          char TempArray[20]={'$','$','$','$','$','$','$','$','$','$'};
          int OperationIndex = -1;
          char TempName[10]={'$','$','$','$','$','$','$','$','$','$'};
          char TempName2[10]={'$','$','$','$','$','$','$','$','$','$'};
          int OperatorIndex = -1;
          int OperatorIndex2 = -1;
          int flag=0;
          int WhatToDo=0;

         for(i=0; i<10; i++)
         {
             TempArray[i]= '$';
         }

         printf("\n>>>");
         scanf("%s", &TempArray[0]);



         if (TempArray[0] == '^')
         {
             break;
         }
       // searching for operators
         for (i=0; i<10; i++)
         {

             if (TempArray[i]== '+')
             {
                 WhatToDo=1;
                 break;
             }
             else if (TempArray[i] == '*')
             {
                 WhatToDo=2;
                 break;
             }
             else if (TempArray[i]== '$')
             {
                 WhatToDo=3;
             }

             else if (TempArray[0] == 'U')
             {
                 WhatToDo=5;
                 break;
             }
             else if (TempArray[0] == '-')
             {
                 WhatToDo=6;
                 break;
             }
             else if (TempArray[i] == '-')
             {
                 WhatToDo=4;
                 break;
             }


         }







      if (WhatToDo == 1)
      {

          // finding equal sign
         for(i=0; i<10; i++)
         {
            if ( TempArray[i] == '+' )
            {
               OperationIndex = i;
              //  printf("index of plus is %d\n", PluIndex);
                break;
            }
         }

         // storing name before +
         for (i=0 ; i<10; i++)
         {
             if ( i == OperationIndex){
                break;
                }
             TempName[i] = TempArray[i];
           //   printf("\n tempname1 : %c\t", TempName[i]);
         }

         int k=0;
         // storing name after +
         for (i = OperationIndex+1; i<10; i++)
         {
               if (TempArray[i] == '$')
                {
                  break;
                }
             TempName2[k] = TempArray[i];
         //   printf("\n tempname2 : %c\t", TempName2[k]);
             k++;
         }


         // matching the name and finding the index
        flag =0;
         for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
           //      printf("looking for %c\t", TempName[j]);
             //    printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempName[j+1] == '$') // enter makes \n
                    {
                        OperatorIndex = i;
                  //      printf(" operator index is %d \n", OperatorIndex);
                        flag=1;
                        break;

                    }

                 else if (TempName[j] != NameOfArrays2[i][j] )
                 {
                  //   printf("not matched breaking\n");
                    break;
                 }

             }
             if (flag == 1)
             {
              //   printf("breaked here\n");
                 break;
             }

         }


        // matching the second set
          flag = 0;
          for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
                 //printf("looking for %c\t", TempName2[j]);
               //  printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempName2[j+1] == '$') // enter makes \n
                    {
                        OperatorIndex2 = i;
                     //   printf(" operator index2 is  %d \n", i);
                        flag=1;
                        break;

                    }

                 else if (TempName2[j] != NameOfArrays2[i][j] )
                 {
              //       printf("not matched breaking\n");
                    break;
                 }

             }
         //    printf("i is: %d\n", i);
         //    printf("flag is: %d\n", flag);
             if (flag == 1)
             {
         //        printf("breaked here\n");
                 break;
             }

         }


        // sending the the members to the answer array
          k=0;
         for (j=0 ; j<100; j++)
         {
             if (Values[OperatorIndex][j]== NULL){
                k = j;
                break;
             }
             Answer[j] = Values[OperatorIndex][j];

         }


          for (j=0; j<100; j++)
          {
               flag = 0;
               if( Values[OperatorIndex2][j] == NULL)
              {
                  break;
              }
              for (i=0; i<100; i++)
              {
                  if(Values[OperatorIndex2][j] == Answer[i])
                  {
                      flag=1;
                      break;
                  }
              }
             if (flag ==1)
             {
                    continue;
             }
             else
             {
                 Answer[k] = Values[OperatorIndex2][j];
             //    printf("k: %d\n", k);
                 k++;
             }
          }


           printf("{");
          for (i=0; i<100; i++)
          {
              if(Answer[i] != NULL && i==0)
              {
                  printf("%d", Answer[i]);
                  continue;
              }
               if(Answer[i] != NULL || i==0)
              printf(",%d", Answer[i]);
          }
           printf("}");

          MakingNull(Answer, 100);

             }








         else if (WhatToDo==3)
         {

         int PrintArrayIndex = -1;
         int bag=0;
         for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
                // printf("looking for %c\t", TempArray[j]);
                 //printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempArray[j+1] == '$') // enter makes \n
                    {
                   //     printf(" FOUND %d \n", i);
                        PrintArrayIndex = i;
                        bag=1;
                        break;

                    }

                 else if (TempArray[j] != NameOfArrays2[i][j] )
                 {
                     //printf("not matched breaking\n");
                    break;
                 }

             }
            // printf("the bag is: %d", bag);
             if (bag == 1)
             {
              //   printf("breaked here\n");
                 break;
             }

         }




             printf("{");
             for(j=0; j<100; j++)
             {
                if( Values[PrintArrayIndex][j] != NULL && j==0)
                {
                    printf("%d", Values[PrintArrayIndex][j]);
                    continue;
                }
                if( Values[PrintArrayIndex][j] != NULL)
                {
                    printf(",%d", Values[PrintArrayIndex][j]);
                }
             }
              printf("}");



         }
         else if (WhatToDo==2)
         {

             // finding equal sign
         for(i=0; i<10; i++)
         {
            if ( TempArray[i] == '*' )
            {
               OperationIndex = i;
             //  printf("index of star is %d\n", OperationIndex);
                break;
            }
         }

         // storing name before *
         for (i=0 ; i<10; i++)
         {
             if ( i == OperationIndex){
                break;
                }
             TempName[i] = TempArray[i];
           //  printf("\n tempname1 : %c\t", TempName[i]);
         }

         int k=0;
          // storing name after +
         for (i = OperationIndex+1; i<10; i++)
         {
               if (TempArray[i] == '$')
                {
                  break;
                }
             TempName2[k] = TempArray[i];
         //   printf("\n tempname2 : %c\t", TempName2[k]);
             k++;
         }

          // matching the name and finding the index
        flag =0;
         for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
       //          printf("\n looking for %c\t", TempName[j]);
          //       printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempName[j+1] == '$') // enter makes \n
                    {
                        OperatorIndex = i;
                  //     printf(" operator index is %d \n", OperatorIndex);
                        flag=1;
                        break;

                    }

                 else if (TempName[j] != NameOfArrays2[i][j] )
                 {
                  //  printf("not matched breaking\n");
                    break;
                 }

             }
             if (flag == 1)
             {
                // printf("breaked here\n");
                 break;
             }

         }



          flag = 0;
          for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
               //  printf("looking for %c\t", TempName2[j]);
              //   printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempName2[j+1] == '$') // enter makes \n
                    {
                        OperatorIndex2 = i;
                    //    printf(" operator index2 is  %d \n", i);
                        flag=1;
                        break;

                    }

                 else if (TempName2[j] != NameOfArrays2[i][j] )
                 {
            //       printf("not matched breaking\n");
                    break;
                 }

             }
          //  printf("i is: %d\n", i);
        //     printf("flag is: %d\n", flag);
             if (flag == 1)
             {
            //     printf("breaked here\n");
                 break;
             }

         }

         k=0;
         for (i=0; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
                 if(Values[OperatorIndex][i] == Values[OperatorIndex2][j] && Values[OperatorIndex][j] != NULL)
                 {
                     Answer[k]=Values[OperatorIndex][i];
                     k++;
                 }
             }
         }


         printf("{");
         for(i=0; i<100; i++)
         {
             if(Answer[i] != NULL && i==0)
             {
                 printf("%d", Answer[i]);
                 continue;
             }
             if(Answer[i] != NULL || i==0)
             {
                 printf(",%d", Answer[i]);
             }

         }
           printf("}");

          MakingNull(Answer, 100);
         }





         else if (WhatToDo == 4)
         {
             // finding equal sign
         for(i=0; i<10; i++)
         {
            if ( TempArray[i] == '-' )
            {
               OperationIndex = i;
             //  printf("index of star is %d\n", OperationIndex);
                break;
            }
         }

         // storing name before *
         for (i=0 ; i<10; i++)
         {
             if ( i == OperationIndex){
                break;
                }
             TempName[i] = TempArray[i];
           //  printf("\n tempname1 : %c\t", TempName[i]);
         }

         int k=0;
          // storing name after +
         for (i = OperationIndex+1; i<10; i++)
         {
               if (TempArray[i] == '$')
                {
                  break;
                }
             TempName2[k] = TempArray[i];
         //   printf("\n tempname2 : %c\t", TempName2[k]);
             k++;
         }

          // matching the name and finding the index
        flag =0;
         for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
       //          printf("\n looking for %c\t", TempName[j]);
          //       printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempName[j+1] == '$') // enter makes \n
                    {
                        OperatorIndex = i;
                  //     printf(" operator index is %d \n", OperatorIndex);
                        flag=1;
                        break;

                    }

                 else if (TempName[j] != NameOfArrays2[i][j] )
                 {
                  //  printf("not matched breaking\n");
                    break;
                 }

             }
             if (flag == 1)
             {
                // printf("breaked here\n");
                 break;
             }

         }



          flag = 0;
          for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
               //  printf("looking for %c\t", TempName2[j]);
             //    printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempName2[j+1] == '$') // enter makes \n
                    {
                        OperatorIndex2 = i;
                 //       printf(" operator index2 is  %d \n", i);
                        flag=1;
                        break;

                    }

                 else if (TempName2[j] != NameOfArrays2[i][j] )
                 {
            //       printf("not matched breaking\n");
                    break;
                 }

             }
          //  printf("i is: %d\n", i);
        //     printf("flag is: %d\n", flag);
             if (flag == 1)
             {
            //     printf("breaked here\n");
                 break;
             }

         }

         k=0;
         for(i=0; i<10; i++)
         {

             flag=0;
             for(j=0; j<10; j++)
             {
                 if(Values[OperatorIndex][i] == Values[OperatorIndex2][j])
                 {
                     flag=1;
                     break;
                 }

             }
             if (flag==1)
                continue;

            else if (flag == 0)
            {
                Answer[k] = Values[OperatorIndex][i];
                   //  printf("\n k is %d\n ", Answer[k]);
                     k++;

            }

         }


         printf("{");
         for(i=0; i<100; i++)
         {
             if (Answer[i] != NULL && i==0)
            {
                printf("%d", Answer[i]);
                continue;
            }
            if (Answer[i] != NULL || i==0)
            {
                printf(",%d", Answer[i]);
            }
         }
         printf("}");

          MakingNull(Answer, 100);


         }


         if (WhatToDo == 5)
         {
             int values2[1000];


             for(i=0; i<10; i++)
             {
                 for(j=0; j<100; j++)
                 {
                     values2[i*100+j]= Values[i][j];
                 }
             }


             RemoveDuplicate(values2, 1000);

             printf("{");
             for(i=0; i<1000; i++)
             {
                 if(values2[i]<100 && values2[i]>0 && i==0)
               {
                  printf("%d", values2[i]);
                  continue;
               }
               if(values2[i]<100 && values2[i]>0 || i==0)
               {
                  printf(",%d", values2[i]);
               }
             }
             printf("}");

                MakingNull(values2, 1000);
         }



         if(WhatToDo == 6)
         {

            int values2[1000];
            MakingNull (values2, 1000);
            for(i=0; i<10; i++)
         {
            if ( TempArray[i] == '-' )
            {
               OperationIndex = i;
                break;
            }
         }

         int k=0;
           // storing name after +
         for (i = OperationIndex+1; i<10; i++)
         {
               if (TempArray[i] == '$')
                {
                  break;
                }
             TempName[k] = TempArray[i];
         //   printf("\n tempname2 : %c\t", TempName2[k]);
             k++;
         }

         flag =0;
         for(i=0 ; i<10; i++)
         {
             for(j=0; j<10; j++)
             {
             //    printf("\n looking for %c\t", TempName[j]);
            //     printf("searching %c\n", NameOfArrays2[i][j]);

                 if ( NameOfArrays2[i][j] == '$' && TempName[j+1] == '$') // enter makes \n
                    {
                        OperatorIndex = i;
                 //      printf(" operator index is %d \n", OperatorIndex);
                        flag=1;
                        break;

                    }

                 else if (TempName[j] != NameOfArrays2[i][j] )
                 {
                  //  printf("not matched breaking\n");
                    break;
                 }

             }
             if (flag == 1)
             {
              //   printf("breaked here\n");
                 break;
             }

         }

            flag =0;
            for(i=0; i<10; i++)
             {
                 for(j=0; j<100; j++)
                 {
                     if(OperatorIndex == i)
                     {
                     flag = 1;
                     break;
                     }
                     values2[i*100+j]= Values[i][j];
                 }
            if (flag == 1)
            {
              //  printf("index is %d\n", i);
                continue;
            }
             }

             RemoveDuplicate(values2, 1000);

             printf("{");
             for(i=0; i<1000; i++)
             {
                 if(values2[i]<100 && values2[i]>0 && i==0 && i!=NULL)
                 {
                     printf("%d", values2[i]);
                     continue;
                 }
                 if(values2[i]<100 && values2[i]>0 || i==0 && i!=NULL)
                 {
                     printf(",%d", values2[i]);
                 }

             }
             printf("}");

                MakingNull(values2, 1000);


         }




         }

         return 0;

         }














