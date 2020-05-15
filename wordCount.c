#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int i = 0;
    int n = 0;//记录要求记录的个数
    int fd = open(argv[2],O_RDONLY);//以只读方式打开文件
    char buf[BUFSIZ];//建立一个缓冲区，放置文件内容
    read(fd,buf,BUFSIZ);//内容读入文件
    if(!strcmp("-c",argv[1])){
        printf("字符数量是%d\n",(int)strlen(buf));
    }//处理字符数
    else {
        while(i != strlen(buf))
        {
            if(buf[i] == ',' || buf[i] == ' ')
                n++;
            i++;
        }
		if(buf[i - 1] != ',') n++;
       printf("单词数量是%d\n",n);
    }//处理单词数
    return 0;
}
