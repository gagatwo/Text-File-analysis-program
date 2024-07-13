#include<stdio.h>
#include<ctype.h>

int c=0;
int newline=0;//varible to count newlines
int word=0;//variable to count words
int character=0;//variable to count characters
int state=1;

void case0(void)//running on state0(inside word) 
{
    if(c=='\n')
    {
        newline++;
        character++;
        state=1;//go to oursideword
    }
    else if(isspace(c)) 
    {
        character++;
        state=1;//go to outside word
    }
    else if(c=='/')
    {
        character++;
        state=3;//go to outside word
    }
    else
    {
        character++;//stay at inside word
    }
}

void case1(void)//running on state1(outside word)
{
    if(c=='\n')
    {
        newline++;
        character++;//stay at outside word
    }
    else if(isspace(c))
    {
        character++;//stay at outside word
    }
    else if(c=='/')
    {
        character++;
        state=2;//go to comment2 that situation where '/' is entered
    }
    else 
    { 
        word++;
        character++;
        state=0;//go to inside word
    }
}

void case2(void)//running on state2(comment2 that situation where '/' is entered in outside word)
{
    if(c=='\n')
    {
        newline++;
        word++;
        character++;
        state=1;//go back to outside word
    }
    else if(isspace(c)) 
    {
        word++;
        character++;
        state=1;//go back to outside word
    }
    else if(c=='/')
    {
        character--;
        state=4;//go to coment type '//'
    }
    else if(c=='*')
    {
        state=5;//go to coment type '/*'
    }
    else
    {
        word++;
        character++;
        state=0;//go to inside word
    }
}

void case3(void)//running on state3(comment1 that situation where '/' is entered in inside word)
{
    if(c=='\n')
    {
        newline++;
        character++;
        state=1;//go to outside word
    }
    else if(isspace(c)) 
    {
        character++;
        state=1;//go to outside word
    }
    else if(c=='/')
    {
        character--;
        state=4;//go to coment type '//'
    }
    else if(c=='*')
    {
        state=5;//go to coment type '/*'
    }
    else
    {
        character++;
        state=0;//go back to insdie word
    }
}

void case4(void)//running on state4(coment type '//')
{
    if(c=='\n')
    {
        newline++;
        character++;
        state=1;//get out of comment & go to outside word
    }
}

void case5(void)//running on state5(comment type '/*')
{
    if(c=='\n')
    {
        newline++;
        character++;//stay in comment
    }
    else if(c=='*') 
    {
        state=6;//go to state 6 that '*' is entered in comment
    }
}

void case6(void)//running on state6(situation where '*' is entered in comment type'/*')
{
    if(c=='/')
    {
        state=1;//get out of comment & go to outside word
    }
    else if(c=='\n')
    {
        newline++;
        character++;
        state=5;//go back to state 5
    }
    else
    {
        state=5;//go back to state 5
    }
}

int main(void)//main fuction
{
    while((c=getchar())!=EOF)//repeat until the end of the text
        {
            switch(state)
            {
                case 0: //inside word
                    case0();//run case0 function
                    break;
                case 1: //outside word
                    case1();//run case1 function
                    break;
                case 2://comment2 that situation where '/' is entered in outside word
                    case2();//run case2 function
                    break;
                case 3://comment1 that situation where '/' is entered in inside word
                    case3();//run case3 function
                    break;  
                case 4://coment type '//'
                    case4();//run case4 function
                    break;
                case 5://coment type '/*'
                    case5();//run case5 function
                    break;
                case 6:// '*' is entered in comment type '/*'
                    case6();//run case6 function
                    break;
            }               

        }

    printf("%d %d %d\n", newline, word, character);
    return 0;
}