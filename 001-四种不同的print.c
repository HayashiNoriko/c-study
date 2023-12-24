#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//四种不同的print

int main() {
    // 1、printf
    // 用于格式化输出到标准输出（通常是控制台或屏幕）
    int num = 10;
    float pi = 3.14;
    char ch = 'A';
    printf("整数: %d，浮点数: %.2f，字符: %c\n", num, pi, ch);
    // 整数: 10，浮点数: 3.14，字符: A

    // 2、sprintf
    // 将格式化的输出写入字符串，而不是标准输出
    char buffer[50];
    int n = 10;
    sprintf(buffer, "The number is %d", n);
    printf("Buffer: %s\n", buffer);
    // Buffer: The number is 10

    // 3、fprintf
    // 将格式化的输出写入文件
    // 注意这里最好用绝对路径，因为在Clion中，编译好的可执行文件是在cmake-build-debug文件夹下的
    // 那么程序就会在那个文件夹里去找output.txt，并输出在那个文件夹里
    FILE *file = fopen("/Users/fxy/Documents/学习/C Study/c-study/output.txt", "w");
    if (file != NULL) {
        printf("文件打开成功\n");
        fprintf(file, "Hello, File!\n");
        fclose(file);
        printf("文件已写入\n");

        // 打印文件的绝对路径
        char resolved_path[PATH_MAX];
        if (realpath("output.txt", resolved_path) != NULL) {
            printf("文件路径: %s\n", resolved_path);
        } else {
            perror("找不到文件路径");
        }
    } else {
        perror("文件打开失败");
    }
    // 文件打开成功
    // 文件已写入
    // 文件路径: /Users/fxy/Documents/学习/C Study/c-study/cmake-build-debug/output.txt

    // 4、snprinft
    // 类似于 sprintf，但它允许限制输出的最大长度
    char buffer2[10];
    snprintf(buffer, sizeof(buffer2), "1234567890123456");
    printf("Buffer: %s\n", buffer); // 只会打印出前9个字符加上终止符
    // Buffer: 123456789

    // 5、puts
    // 简单地打印字符串，并在末尾自动添加换行符
    char *str = "Hello World";
    // char str[] = "Hello World!";
    puts(str);
    // Hello World!

    // 6、putchar
    // 用于打印单个字符
    char ch1 = 'A';
    putchar(ch1);
    putchar('\n');
    // A

    return 0;
}
