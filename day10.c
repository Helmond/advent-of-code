#include <stdio.h>
#include <stdlib.h>
#include <math.h>//pow


int input[104]={
79,
142,
139,
33,
56,
133,
138,
61,
125,
88,
158,
123,
65,
69,
105,
6,
81,
31,
60,
70,
159,
114,
71,
15,
13,
72,
118,
14,
9,
93,
162,
140,
165,
1,
80,
148,
32,
53,
102,
5,
68,
101,
111,
85,
45,
25,
16,
59,
131,
23,
91,
92,
115,
103,
166,
22,
145,
161,
108,
155,
135,
55,
86,
34,
37,
78,
28,
75,
7,
104,
121,
24,
153,
167,
95,
87,
94,
134,
154,
84,
151,
124,
62,
49,
38,
39,
54,
109,
128,
19,
2,
98,
122,
132,
141,
168,
8,
160,
50,
42,
46,
110,
12,
152};

int i,j,q;
int valid=0;
int wrong_line=0;
long test_result=0;


long lowest=0;
long highest=0;
unsigned long pt2_result=0;
long pt1_result=0;
int size=0;

int groups_1=0;
int groups_2=0;
int groups_3=0;
int groups_4=0;


int jolts=0;//starting with 0 jotls

int diff_1=0;
int diff_2=0;
int diff_3=1;//becouse of end

int skip=0;

long possibilities=1;// always 1 possibility

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    
    while(i<105)
    {
        for(j=0;j<105;j++)
        {
            if(input[j]==jolts+1)
            {
                //printf("1: %d en %d en %d\n",jolts,input[j],j);
                jolts=input[j];
                diff_1++;
                skip=1;
            }
        }
        if(skip==0)
        {
            for(j=0;j<105;j++)
            {
                if (input[j]==jolts+2)
                {
                    //printf("2: %d en %d en %d\n",jolts,input[j],j);
                    jolts=input[j];
                    diff_2++;
                    skip=1;
                }
            }
        }
        if(skip==0)
        {
            for(j=0;j<105;j++)
            {
                if(skip==0)
                {
                    if (input[j]==jolts+3)
                    {
                        //printf("3: %d en %d en %d\n",jolts,input[j],j);
                        jolts=input[j];
                        diff_3++;
                        skip=1;
                    }
                }
            }
        }
        i++;
        skip=0;  
    }
    pt1_result=diff_1*diff_3;
    jolts+=3;//internal adapter
    printf ("pt 1 final jolts %d 1diff %d 2diff %d 3diff %d result =%lu\n",jolts, diff_1, diff_2, diff_3,pt1_result);
    
    
    //pt2
    qsort(input, 104, sizeof(int), compare);//toch maar sorten scheelt misschien
    for (i=0; i<104; i++)
    {
        //printf ("%d diff with next:%d , 2 next:%d , 3 next:%d\n",input[i],(input[i+1]-input[i]),(input[i+2]-input[i]),(input[i+3]-input[i]));
        //printf ("%d,\n",(input[i+1]-input[i]));
    }
    //count zero's
    for(i=0;i<106;i++)
    {
        if ((input[i+1]-input[i]==1))//two 1
        {
            //printf ("1\n");
            if((input[i+2])-input[i+1]==1)//two 1's
            {
                //printf ("2\n");
                if((input[i+3]-input[i+2])==1)//three 1's
                {
                   // printf ("3\n");
                    if((input[i+4]-input[i+3])==1)//four 1's analysis of input shows never more than 4 1's 
                    {
                        //printf ("4\n");
                        groups_4++;
                        i+=2;//i+=3;
                    }
                    else// so surely 3 1's
                    {
                        groups_3++;
                        i+=1;//i+=2;
                    }
                
                }
                else// there are 2 but not 3
                {
                    groups_3++;
                    //i+=1;
                }
                
            }
            else//only 1
            {
                groups_1++;
            }
        }
        
    }
    pt2_result= pow(1,groups_1)*pow(2,groups_2)* pow(4,groups_3) * pow(7,groups_4);
    printf ("pt 2 groups1 %d groups2 %d groups3 %d groups4 %d result =%lu\n",groups_1, groups_2, groups_3, groups_4 ,pt2_result);
    
   
   return 0;
}
