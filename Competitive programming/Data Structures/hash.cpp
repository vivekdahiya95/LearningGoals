/**
 * @file hash.cpp
 * @brief string-> string
 * key-> max 64 chars
 * value-> max 128 chars
 * 
 */
#include<stdio.h>
#include<string.h>
#include<memory.h>

#define maxKey 64
#define maxVal 128
#define maxContainer 4096

typedef struct{
    char key[maxKey];
    char value[maxVal];
}Hash;

Hash container[maxContainer];

unsigned long hash(const char *str){
    //calculate teh hash value
    unsigned long hash=4007; //some large prime number maybe
    int c;

    while(c=*str++){
        hash=(((hash<<5)+hash)+c)%maxContainer;
    }
    return hash%maxContainer;
}

int find(const char* key, char* val){
    unsigned long h=hash(key);
    int cnt=maxContainer;
    while(container[h].key[0]!=0 && cnt--){//we don't want to keep looping even after checking all of the places that's why cnt--
        if(strcmp(container[h].key,key)==0){
            strcpy(val,container[h].value);
            return 1;
        }
        h=(h+1)%maxContainer;
    }
    return 0;
}

int add(const char* key, const char* val){
    unsigned long h=hash(key);

    while(container[h].key[0]!=0){
        // if the current key place is not empty
        // and if it is the same key then return a duplicate meaning you can't add it
        if(strcmp(container[h].key,key)==0){
            return 0;
        }
        h=(h+1)%maxContainer;
    }
    strcpy(container[h].key,key);
    strcpy(container[h].value,val);
    return 1;

}

int main(int argc,char* argv[]){
    memset(container,0,sizeof(container));
    char k[maxKey+1];
    char v[maxVal+1];
    scanf("%s",&k);
    scanf("%s",&v);
    add(k,v);
    char tempV[maxVal+1];
    char tempK[maxKey+1];
    scanf("%s",&tempK);
    find(tempK,tempV);
    printf("%s\n",tempV);
    return 0;
}
