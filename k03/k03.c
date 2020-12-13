#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{int OriginalLong=0;
 int KeyLong=0;
 int i,j;
  while(StrOriginal[OriginalLong]!='\0')OriginalLong++;
  while(StrKey[KeyLong]!='\0')KeyLong++;
  for(i=0;i<OriginalLong;i++){
      for(j=0;j<KeyLong;j++){
              if(text[i+j]!=StrKey[j]){
              break;
              }

          }
        if(j==KeyLong){
            return text+i;
        }
      }
      return NULL;
  }

char* BMSearch(char text[], char key[])
{   int OriginalLong;
    int KeyLong=0; 
    int index;
    int table[256];
    int i,j;
    int newindex;

    for(i=0;text[i]!='\0';i++){
        OriginalLong=OriginalLong+1;
    }
    for(j=0;key[j]!='\0';j++){
        KeyLong=KeyLong+1;
    }
    for(i=0;i<=255;i++){
        table[i]=KeyLong;
    }
    for(i=0;i<KeyLong;i++){
        table[key[i]]=KeyLong-i-1;
    }

    index=KeyLong-1;
    while(index<=OriginalLong-1){
        
            for(i=0;i<=KeyLong-1;i++){
            if(text[index-i]==key[KeyLong-i-1]){
                if (i==KeyLong-1){
                    return text + index-(KeyLong-1);
                }
                else
                {}    
            }
            else
            {
                break;
            }
                
            }
    newindex=index-i+table[text[index-i]];
    if(newindex>index){
        index=newindex;
    }
    else{
        index=index+1;
    }
    }   
return NULL;
}
    


int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}