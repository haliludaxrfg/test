#include <stdio.h>
#include <iostream>
#include <cstring>
//打开 fopen(Filename,mode)
//关闭 fclose
//读取 fread
//写入 fwrite 先写入缓冲区，当缓冲区满/调用fclose/进程退出才能正式写入文件
//文件指针偏移 fseek 手动控制指针位置fseek(文件句柄，偏移量，偏移开始位置)
//获取文件偏移量 ftell(文件句柄) 可用于计算文件大小
//清空文件缓冲区 fflush 实时响应 主动，常用日志文件



int main(){
    /*  mode:rb,wb,ab
        rb:返回NULL/返回句柄
        wb:创建/清空文件内容
        ab:创建/文件指针偏移到末尾
     */
    FILE* fp = fopen("otto.c","a+");
    if(fp == NULL){
        std::cout<<"file open failed"<<std::endl;
        exit(-1);
    }
    std::cout<<"file open success"<<std::endl;

    char buffer[]="我喜欢你你喜欢我\n";
    fwrite(buffer,1,strlen(buffer),fp);
    fflush(fp);
    //开始位置，写入大小（默认一），写入次数，文件句柄 fwrite fread同理
    size_t ret = fread(buffer,1,6,fp);
    std::cout<<buffer<<" "<<ret<<std::endl;
    fseek(fp,0,SEEK_SET);
    std::cout<<buffer<<std::endl;
    fclose(fp);
    return 0;

}